#include "sbi-handler.h"

/*
 * json_read_callback - transfer JSON formatted string to final buffer
 *
 * @source->ptr: contains reference to JSON formatted response data (see 3GPP TS 29.518, 6.1.3.5.3.1)
 */
nghttp2_ssize
json_read_callback(nghttp2_session *session, int32_t stream_id, uint8_t *buf, size_t length, uint32_t *data_flags, nghttp2_data_source *source, void *user_data)
{
	/*Variables*/
	char* src = (char*) source->ptr;
	ssize_t ret;
	(void)session;
	(void)stream_id;
	(void)user_data;

	/*Checking if buffer is large enough*/
	if((ret = strlen(src)) > length)
	{
		free(src);
		return NGHTTP2_ERR_TEMPORAL_CALLBACK_FAILURE;
	}

#ifdef DEBUG
	fprintf(stderr, "json_read_callback():\n%s\n", src);
#endif

	/*Copy data to output buffer*/
	memcpy((void*)buf, (void*)src, ret);

	/*Set END FLAG and free memory*/
	*data_flags |= NGHTTP2_DATA_FLAG_EOF;
	free(src);

	return (nghttp2_ssize)ret;
}

/*
 * forwardN2DatatoGNB - send N2 data to the target gNB
 *
 * @type: N2 information class
 * @target: LCS session information
 * @data: NGAP ASN.1 encoded PDU
 * @size: size [B] of @data
 *
 * return: HTTP response code
 */
static int
forwardN2DatatoGNB(n2_information_class_e type, rentry_t *target, uint8_t *data, uint64_t size)
{
	/*Variables*/
	NGAP_NRPPa_PDU_t *nrppa = 0;
	ngapmsg_t *msg = 0;

	/*Check passed input parameter*/
	if(!target || !data || !size)
	{
		return 500;
	}

	/*Decode ASN.1 PER encoded NGAP PDU depending on @type + forwarding*/
	switch(type)
	{
		case n2_information_class_NRPPa:
			if((nrppa = getNGAPNRPPafromSBI(data, size)) == NULL)
			{
				return 400;
			}
			
			/*Create NGAP PDU with Downlink UE Associated NRPPa Transport message type (Class 2 procedure)*/
			if((msg = createNGAPforNRPPaTransport(NGAP_ProcedureCode_id_DownlinkUEAssociatedNRPPaTransport, nrppa->buf, nrppa->size, target->ngap_amf_id, target->ngap_ran_id, target->nfid.buf)) == NULL)
			{
				printf("Error: createNGAPforNRPPaTransport\n");
				return 500;
			}

			/*
			 * Send data to target gNB
			 */
			if(sctpcli(target->gnb->sockfd, &target->gnb->con, false, msg->enc, msg->size, NULL) != 0)
			{
				freeNGAPMessage(msg);
				return 500;
			}

			/*Free memory*/
			freeNGAPMessage(msg);
			//freeNGAPNRPPaSBI(nrppa); /*... did not work ... :-/*/
			
			break;

		default: return 501;
	}
	

	return 200;
}

/*
 * N1N2MessageTransfer - 3GPP TS 29.518, 5.2.2.3.1
 *
 * /namf-comm/v1/ue_contexts/{ueContextID}/n1-n2-messages
 *
 * return: 0 on success, otherwise -1
 *
 * NOTE: -1 results in the HTTP response message: 500 INTERNAL SERVER ERROR with ProblemDetails.cause = SYSTEM_FAILURE
 */
int
namf_comm_n1n2msgtransfer(nghttp2_session *session, http2_stream_data *stream_data, rentry_t *entry)
{
	/*Variables*/
	int i, j;
	bool isLast = false;
	n1_n2_message_transfer_rsp_data_t *resp = 0;
	n1_n2_message_transfer_req_data_t *req = 0;
	cJSON *n2data = 0, *in = 0, *err_json = 0;
	char *jstr = 0, *bound_ptr = 0, *cont_id[2] = {0};
	uint8_t *idx = 0, *idx2 = 0, *tmp = 0, *bin[2] = {0}, buf[100] = {0};
	uint64_t bsize[2] = {0};
	uuid_t nfid = {0};

	nghttp2_nv *nva = 0;
	size_t nvlen = 0;
	nghttp2_data_provider2 data_prd;

	/*Check 1: Content-type has to be multipart/related (3GPP TS 29.518, 6.1.2.4)*/
	if(strstr(stream_data->ctype, "multipart/related") != stream_data->ctype)
	{
		/*Wenn content type falsch ist, HTTP Error 415 unsupported media (TS 29.500, 5.2.7.2)*/
		printf("[AMF-sbi] Invalid content-type (%s) for requested path %s!\n", stream_data->ctype, stream_data->request_path);

		if(error_response(session, stream_data, 415, NULL) != 0)
		{
			return -1;
		}
		return 0;
	}

	/*Check 2: SBI consumer (client) has to be accept: application/json,application/problem+json*/
	if(strcmp(stream_data->accept, "application/json,application/problem+json") != 0)
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		printf("[AMF-sbi] Invalid accept value (%s) in request header!\n", stream_data->accept);

		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}

	/*Reference boundary pattern from Content-Type*/
	if((bound_ptr = strstr(stream_data->ctype, "boundary=")) == NULL)
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}
	bound_ptr += strlen("boundary=");

	/*Check 3: Exceed limit of Content-Type length*/
	if(bound_ptr - stream_data->ctype >= strlen(stream_data->ctype))
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}


	/*
	 * Parsing of multipart data
	 *
	 * Structure of body:
	 *
	 * (1) ---------- 48753945309\r\n (first boundary, 42 B (libcurl v7.8.1) | 48 B (libcurl v8.8.0) without \r\n)
	 * (2) Content-Type: application/json (30 B)
	 * (3) SKIPPED (double \r\n expected)
	 * (4) JSON data
	 * (5) ---------- 48753945309\r\n (boundary, 42 B without \r\n, first binary (N1 or N2 data))
	 * (6) Content-Type: application/vnd.3gpp.ngap (39 B) oder Content-Type: application/vnd.3gpp.5gnas (40 B)
	 * (7) Content-ID: XXX
	 * (8) SKIPPED (double \r\n expected)
	 * (9) N1 or N2 binary data
	 * (10) ---------- 48753945309--\r\n (last boundary, 44 B (libcurl v7.8.1) | 48 B (libcurl v8.8.0) without \r\n) OR
	 *		---------- 48753945309\r\n (boundary, 42 B without \r\n, second binary (N1 or N2 data))
	 * (11+) Steps (6) - (10) can be repeated once. HOWEVER, after the last binary data, the last boundary identifier has a length of +2!
	 */
	for(idx = memchr(stream_data->data, 0x0d, stream_data->size), idx2 = 0, j = 0; idx - stream_data->data < stream_data->size && idx != NULL;)
	{
		/*If next byte is not 0x0a -> skip and continue searching*/
		if(idx[1] != 0x0a)
		{
			idx = memchr(idx + 1, 0x0d, stream_data->size - (idx + 1 - stream_data->data));
			continue;
		}

		/*Examine found token*/
		if(!idx2 && idx-stream_data->data > 2)
		{
			tmp = calloc(idx-stream_data->data+1, sizeof(uint8_t));
			memcpy(tmp, stream_data->data, idx-stream_data->data);
			tmp[idx-stream_data->data] = 0;
#ifdef DEBUG
			fprintf(stderr, "Token %d [%d B]:\n", j+1, idx-stream_data->data);
			for(i = 0; i < idx-stream_data->data; i++)
			{
				if(i%15 == 0)
				{
					fprintf(stderr, "\n%.2x ", tmp[i]);
				}
				else{
					fprintf(stderr, "%.2x ", tmp[i]);
				}
			}
#endif
		}
#ifdef DEBUG
		else if(idx - idx2 < 3)
		{
			printf("-- Token %d [%d B] skipped --\n", j+1, idx-idx2);
		}
#endif
		else if(idx - idx2 > 2)
		{
			tmp = calloc(idx-idx2+1, sizeof(uint8_t));
			memcpy(tmp, idx2, idx-idx2);
			tmp[idx-idx2] = 0;
#ifdef DEBUG			
			fprintf(stderr, "Token %d [%d B]:\n", j+1, idx-idx2);
			for(i = 0; i < idx-idx2; i++)
			{
				if(i%20 == 0)
				{
					fprintf(stderr, "\n%.2x ", tmp[i]);
				}
				else{
					fprintf(stderr, "%.2x ", tmp[i]);
				}
			}
#endif
		}

		/*Processing of token according to expected body structure*/
		switch(j)
		{
			/*Token 1: First boundary identifier*/
			case 0:
				if(!tmp || strstr(tmp, bound_ptr) == NULL)
				{
					if(tmp)
					{
						free(tmp);
					}
					goto end;
				}
				//printf("Token 1: successful!\n");
				break;

			/*Token 2: Content-Type = application/json*/
			case 1:
				if(idx-idx2 != 30 || memcmp(tmp, (uint8_t*)"Content-Type: application/json", 30) != 0)
				{
					free(tmp);
					goto end;
				}
				//printf("Token 2: successful!\n");
				break;
			
			/*-- Token 3/8/13 skipped --*/
			case 2:
			case 7:
			case 12: //printf("Token 3, 8, 13: skipped!\n");
					 break;

			/*Token 4: JSON data (N1N2MessageTransferRequestData)*/
			case 3:
				if(idx - idx2 < 3 || (in = cJSON_ParseWithLength(tmp, idx-idx2)) == NULL || (req = n1_n2_message_transfer_req_data_parseFromJSON(in)) == NULL)
				{
					if(in)
					{
						cJSON_Delete(in);
					}
					if(tmp)
					{
						free(tmp);
					}
					goto end;
				}
				//printf("Token 4: successful!\n");
				cJSON_Delete(in);
				break;

			/*Token 5: Second boundary identifier*/
			case 4:
				if(!tmp || strstr(tmp, bound_ptr) == NULL)
				{
					if(req)
					{
						n1_n2_message_transfer_req_data_free(req);
					}
					if(tmp)
					{
						free(tmp);
					}
					goto end;
				}
				//printf("Token 5: successful!\n");
				break;

			/*Token 6/11: Content-Type == N1 or N2 data*/
			case 5:
			case 10:
				if(j==10 && isLast)
				{
					free(tmp);
					goto end;
				}
				if(!(idx-idx2 == 39 && memcmp(tmp, (uint8_t*)"Content-Type: application/vnd.3gpp.ngap", 39) == 0) && !(idx-idx2 == 40 && memcmp(tmp, (uint8_t*)"Content-Type: application/vnd.3gpp.5gnas", 40) == 0))
				{
					free(tmp);
					goto end;
				}
				//printf("Token 6/11: successful!\n");
				break;

			/*Token 7/12: Content-Id == N1 or N2*/
			case 6:
			case 11:
				(j == 6) ? (i = 0) : (i = 1);
				if(idx-idx2 < strlen("Content-Id: ") + 1)
				{
					if(req)
					{
						n1_n2_message_transfer_req_data_free(req);
					}
					free(tmp);
					goto end;
				}

				/*Convert raw data to string and check its semantic*/
				if((jstr = calloc(idx-idx2+1, sizeof(char))) == NULL)
				{
					if(req)
					{
						n1_n2_message_transfer_req_data_free(req);
					}
					free(tmp);
					goto end;
				}
				memcpy(jstr, tmp, idx-idx2);

				if(strstr(jstr, "Content-Id: ") != jstr)
				{
					free(jstr);
					if(req)
					{
						n1_n2_message_transfer_req_data_free(req);
					}
					free(tmp);
					goto end;
				}

				if((cont_id[i] = calloc(idx-idx2+1-strlen("Content-Id: "), sizeof(char))) == NULL)
				{
					free(jstr);
					if(req)
					{
						n1_n2_message_transfer_req_data_free(req);
					}
					free(tmp);
					goto end;
				}

				memcpy(cont_id[i], jstr+strlen("Content-Id: "), idx-idx2-strlen("Content-Id: "));
				free(jstr);
				//printf("Token 7/12: successful!\n");

				break;

			/*Token 9/14: N1 or N2 binary data*/
			case 8:
			case 13:
				if(!tmp)
				{
					goto end;
				}
				(j == 8) ? (i = 0) : (i = 1);
				bin[i] = tmp;
				tmp = 0;
				bsize[i] = idx-idx2;
				//printf("Token 9/14: successful!\n");
				break;

			/*Token 10/15: Boundary identifier (maybe last!)*/
			case 9:
			case 14:
				if(tmp && strstr(tmp, bound_ptr) != NULL && strlen(tmp+strlen(bound_ptr)+2) >= 2 && tmp[strlen(bound_ptr)+2] == '-' && tmp[strlen(bound_ptr)+3] == '-')
				{
					isLast = true;
				}

				else if(j == 9 && strstr(tmp, bound_ptr) == NULL)
				{
					if(cont_id[0])
					{
						free(cont_id[0]);
						cont_id[0] = 0;
					}
					if(bin[0])
					{
						free(bin[0]);
						bin[0] = 0;
					}
					if(req)
					{
						n1_n2_message_transfer_req_data_free(req);
						req = 0;
					}
					free(tmp);
					tmp = 0;
					goto end;
				}
				else
				{
					free(tmp);
					tmp = 0;
					goto end;
				}
				//printf("Token 10/15: successful!\n");
				break;

			case 15:
				j = 16;
				goto end;
		}

		/*Free memory*/
		if(tmp)
		{
			free(tmp);
			tmp = 0;
		}

		//printf("\n");

		/*Update address pointer for next iteration*/
		idx2 = idx + 2;
		idx = memchr(idx2, 0x0d, stream_data->size - (idx2 - stream_data->data));
		j++;
	}

end:
	/*
	 * Check 4: Was structure of the HTTP/2 DATA frame complete?
	 *
	 * 10 tokens were expected if N1 OR N2 data was sent by client.
	 * 15 tokens were expected if N1 AND N2 data was sent by client.
	 */
	if(j != 10 && j != 15)
	{
		printf("[AMF-sbi] Error while parsing of request data!\n");
		if(error_response(session, stream_data, 400, HTTP_400_INVFORM) != 0)
		{
			goto err;
		}
		goto fin;
	}

	/*
	 * Interpretation of data
	 *
	 * NOTE: Easier if HTTP/2 User-Agent: field was sent by client.
	 */
	if(stream_data->user_agent)
	{
		/*LMF*/
		if(strstr(stream_data->user_agent, "LMF") == stream_data->user_agent)
		{
			/*Check for mandatory IEs*/
			if(j == 15 && (req->n1_message_container == NULL || req->n2_info_container == NULL))
			{
				/*HTTP error 400 BAD REQUEST + ProblemDetails.cause == MANDATORY_IE_MISSING */
				if(error_response(session, stream_data, 400, HTTP_400_MANIEMIS) != 0)
				{
					goto err;
				}

				goto fin;
			}

			else if(j == 10 && req->n1_message_container == NULL && req->n2_info_container == NULL)
			{
				/*HTTP error 400 BAD REQUEST + ProblemDetails.cause == MANDATORY_IE_MISSING */
				if(error_response(session, stream_data, 400, HTTP_400_MANIEMIS) != 0)
				{
					goto err;
				}

				goto fin;
			}

			else if(!req->lcs_correlation_id && (req->n1_message_container && (req->n1_message_container->n1_message_class == n1_message_class_LPP ||
				req->n1_message_container->n1_message_class == n1_message_class_LCS || req->n1_message_container->n1_message_class == n1_message_class_UPP_CM)))
			{
				/*HTTP error 400 BAD REQUEST + ProblemDetails.cause == MANDATORY_IE_MISSING */
				if(error_response(session, stream_data, 400, HTTP_400_MANIEMIS) != 0)
				{
					goto err;
				}

				goto fin;
			}

			else if(!req->lcs_correlation_id && (req->n2_info_container && (req->n2_info_container->n2_information_class == n2_information_class_NRPPa)))
			{
				/*HTTP error 400 BAD REQUEST + ProblemDetails.cause == MANDATORY_IE_MISSING */
				if(error_response(session, stream_data, 400, HTTP_400_MANIEMIS) != 0)
				{
					goto err;
				}

				goto fin;
			}

			/*Examine N1 Message Container - if available*/
			if(j == 10 && req->n1_message_container)
			{
				/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}

				goto fin;
			}

			/*Examine N2 Information Container - if available*/
			else if(j == 10 && req->n2_info_container)
			{
				/*Forwarding a NRPPa message*/
				if(req->n2_info_container->n2_information_class == n2_information_class_NRPPa)
				{
					/*Compare the target UE's LCS Correlation ID with the requested one*/
					if(strcmp(entry->lcs_id, req->lcs_correlation_id) != 0)
					{
						/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = OPTIONAL_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
						if(error_response(session, stream_data, 400, HTTP_400_OPTIEINC) != 0)
						{
							goto err;
						}

						goto fin;
					}

					/*Break if LCS session is not "complete"*/
					if(!entry->isComplete)
					{
						printf("LCS entry is not complete!\n");
						goto err;
					}

					/*Check for mandatory missing IE*/
					if(req->n2_info_container->nrppa_info == NULL || req->n2_info_container->nrppa_info->nf_id == NULL || req->n2_info_container->nrppa_info->nrppa_pdu == NULL || req->n2_info_container->nrppa_info->nrppa_pdu->ngap_data == NULL)
					{
						/*HTTP error 400 BAD REQUEST + ProblemDetails.cause == MANDATORY_IE_MISSING */
						if(error_response(session, stream_data, 400, HTTP_400_MANIEMIS) != 0)
						{
							goto err;
						}

						goto fin;
					}

					/*Check for mandatory incorrect IE*/
					else if(req->n2_info_container->nrppa_info->nrppa_pdu->ngap_ie_type != ngap_ie_type_NRPPA_PDU || strcmp(req->n2_info_container->nrppa_info->nrppa_pdu->ngap_data->content_id, cont_id[0]) != 0 || uuid_parse(req->n2_info_container->nrppa_info->nf_id, nfid) != 0)
					{
						/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
						if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
						{
							goto err;
						}

						goto fin;
					}

					/*
					 * NETWORK TRIGGERED SERVICE REQUEST
					 *
					 * here: Currently, it is assumed that the UE is always in CM-CONNECTED state.
					 */


					/*
					 * Check if for the target UE a subscription was already requested (Routing ID to the corresponding LCS session)
					 *
					 * NOTE: An alternative could be asking the NRF (3GPP TS 29.518, 5.2.2.3.6.3) but this NF is currently not implemented!
					 */
					if(!entry->nfid.buf || memcmp(entry->nfid.buf, nfid, 16) != 0)
					{
						/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
						if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
						{
							goto err;
						}

						goto fin;
					}

					/*Forwarding N2 message to target gNB*/
					if((i = forwardN2DatatoGNB(n2_information_class_NRPPa, entry, bin[0], bsize[0])) != 200)
					{
						switch(i)
						{
							case 400:
								/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
								if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
								{
									goto err;
								}

								goto fin;

							case 500:
								/*HTTP error 500 INTERNAL SERVER ERROR + ProblemDetails.cause = SYSTEM_FAILURE*/
								goto err;

							case 501:
								/*HTTP error code: 501 NOT IMPLEMENTED*/
								if(error_response(session, stream_data, 501, NULL) != 0)
								{
									goto err;
								}

								goto fin;
						}
					}

					/*Creation of N2MessageResponseData*/
					if((resp = n1_n2_message_transfer_rsp_data_create(n1_n2_message_transfer_cause_N1_N2_TRANSFER_INITIATED, NULL)) == NULL)
					{
						goto err;
					}

					/*Converting to JSON string*/
					if((n2data = n1_n2_message_transfer_rsp_data_convertToJSON(resp)) == NULL || (jstr = cJSON_Print(n2data)) == NULL)
					{
						if(n2data)
						{
							cJSON_Delete(n2data);
						}

						n1_n2_message_transfer_rsp_data_free(resp);

						goto err;
					}

					cJSON_Delete(n2data);
					n2data = 0;
					n1_n2_message_transfer_rsp_data_free(resp);
					resp = 0;

					/*Initialize header fields*/
					if((nva = calloc(3, sizeof(nghttp2_nv))) == NULL)
					{
						if(jstr)
						{
							free(jstr);
						}
						goto err;
					}
					nvlen = 3;

					/*(1) Status code*/
					nva->name = (uint8_t*) strdup(":status");
					nva->namelen = strlen(":status");
					nva->value = (uint8_t*) strdup("200");
					nva->valuelen = strlen(nva->value);

					/*(2) Content-Type*/
					(nva + 1)->name = (uint8_t*) strdup("content-type");
					(nva + 1)->namelen = strlen("content-type");
					(nva + 1)->value = (uint8_t*) strdup("application/json");
					(nva + 1)->valuelen = strlen((nva + 1)->value);

					/*(3) Content-length*/
					(nva + 2)->name = (uint8_t*) strdup("content-length");
					(nva + 2)->namelen = strlen("content-length");
					snprintf(buf, 99, "%ld", strlen(jstr));
					(nva + 2)->value = (uint8_t*) strdup(buf);
					(nva + 2)->valuelen = strlen((nva + 2)->value);

					/*Initialize data structure for DATA frame callback function*/
					explicit_bzero(&data_prd, sizeof(data_prd));

					/*Assign data source and its callback function*/
					data_prd.source.ptr = (void*)jstr;
					data_prd.read_callback = json_read_callback;

					/*Sending response data*/
					if (send_response(session, stream_data->stream_id, nva, nvlen, &data_prd) != 0)
					{
						goto err;
					}
				}
				else
				{
					/*HTTP error code: 501 NOT IMPLEMENTED*/
					if(error_response(session, stream_data, 501, NULL) != 0)
					{
						goto err;
					}

					goto fin;
				}
			}

			/*Both N1 and N2 data has to be processed*/
			else
			{
				/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}

				goto fin;
			}

		}

		/*
		 * TODO: Other NF handlings are currently not implemented (compare with Table 5.1-1 in 3GPP TS 29.518).
		 *
		 * return: HTTP error code: 501 NOT IMPLEMENTED
		 */
		else if(strstr(stream_data->user_agent, "AMF") == stream_data->user_agent || strstr(stream_data->user_agent, "SMF") == stream_data->user_agent || strstr(stream_data->user_agent, "PCF") == stream_data->user_agent || strstr(stream_data->user_agent, "SMSF") == stream_data->user_agent)
		{
			/*HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}

			goto fin;
		}

		/*
		 * User-Agent field not correct!
		 */
		else
		{
			/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = OPTIONAL_IE_INCORRECT (TS 29.500, 5.2.7.2)*/	
			if(error_response(session, stream_data, 400, HTTP_400_OPTIEINC) != 0)
			{
				goto err;
			}

			goto fin;
		}
	}

	/*Interpretation with out additional information*/
	else
	{
		/*HTTP error code: 501 NOT IMPLEMENTED*/
		if(error_response(session, stream_data, 501, NULL) != 0)
		{
			goto err;
		}

		goto fin;
	}

fin:
	/*Free memory*/
	if(req)
	{
		n1_n2_message_transfer_req_data_free(req);
	}

	for(i = 0; i < 2; i++)
	{
		if(cont_id[i])
		{
			free(cont_id[i]);
		}

		if(bin[i])
		{
			free(bin[i]);
		}
	}

	return 0;

err:
	/*Free memory*/
	if(req)
	{
		n1_n2_message_transfer_req_data_free(req);
	}

	for(i = 0; i < 2; i++)
	{
		if(cont_id[i])
		{
			free(cont_id[i]);
		}

		if(bin[i])
		{
			free(bin[i]);
		}
	}


	return -1;
}


/*
 * N1N2MessageSubscribe - 3GPP TS 29.518, 5.2.2.3.3
 *
 * /namf-comm/v1/ue_contexts/{ueContextID}/n1-n2-messages/subscriptions
 *
 * return: 0 on success, otherwise -1
 */
int
namf_comm_n1n2msgsubscribe(nghttp2_session *session, http2_stream_data *stream_data, rentry_t *entry)
{
	/*Variables*/
	ue_n1_n2_info_subscription_create_data_t *req = 0;
	ue_n1_n2_info_subscription_created_data_t *resp = 0;
	cJSON *jbody = 0;
	char *sub_id = 0, *jstr = 0;
	uint8_t buf[100] = {0};
	int acc_n1 = -1, acc_n2 = -1;

	nghttp2_nv *nva = 0;
	size_t nvlen = 0;
	nghttp2_data_provider2 data_prd;

	/*Check 1: Content-type has to be application/json*/
	if(strstr(stream_data->ctype, "application/json") != stream_data->ctype)
	{
		/*Wenn content type falsch ist, HTTP Error 415 unsupported media (TS 29.500, 5.2.7.2)*/
		printf("[AMF-sbi] Invalid content-type (%s) for requested path %s!\n", stream_data->ctype, stream_data->request_path);

		if(error_response(session, stream_data, 415, NULL) != 0)
		{
			return -1;
		}
		return 0;
	}

	/*Check 2: SBI consumer (client) has to be accept: application/json,application/problem+json*/
	if(strcmp(stream_data->accept, "application/json,application/problem+json") != 0)
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		printf("[AMF-sbi] Invalid accept value (%s) in request header!\n", stream_data->accept);

		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}

	/*Parse JSON body and create expected subscription data structure*/
	if((jbody = cJSON_ParseWithLength(stream_data->data, stream_data->size)) == NULL || (req = ue_n1_n2_info_subscription_create_data_parseFromJSON(jbody)) == NULL)
	{
		if(jbody)
		{
			cJSON_Delete(jbody);
		}

		if(error_response(session, stream_data, 400, HTTP_400_INVFORM) != 0)
		{
			return -1;
		}

		return 0;
	}
	cJSON_Delete(jbody);
	jbody = 0;

	/*
	 * Check request data: UeN1N2InforSubscriptionDataCreate
	 *
	 * According to: 3GPP TS 29.518, 6.1.6.2.12
	 */
	if(req->n2_information_class == n2_information_class_NULL && req->n1_message_class == n1_message_class_NULL)
	{
		/*Error: no message class selected*/
		return -1;
	}

	else if(req->n2_information_class != n2_information_class_NULL && !req->n2_notify_callback_uri)
	{
		/*Error: no Callback URI inserted*/
		return -1;
	}

	else if(req->n1_message_class != n1_message_class_NULL && !req->n1_notify_callback_uri)
	{
		/*Error: no Callback URI inserted*/
		return -1;
	}

	else if(!req->nf_id && (req->n2_information_class == n2_information_class_NRPPa || req->n1_message_class == n1_message_class_LPP))
	{
		/*Error: no NF ID (Routing ID) for response N1/N2 positioning information forwarding*/
		return -1;
	}

	/*Enter critical section*/
	if(pthread_mutex_lock(&entry->lock) != 0)
	{
		goto err;
	}

	/*Add subscription data to target UE context entry*/
	if((req->n2_information_class == n2_information_class_NRPPa || req->n1_message_class == n1_message_class_LPP) && !entry->nfid.buf)
	{
		/*Allocate memory for Routing ID*/
		entry->nfid.size = 16;
		if((entry->nfid.buf = calloc(16, sizeof(uint8_t))) == NULL)
		{
			pthread_mutex_unlock(&entry->lock);
			goto err;
		}

		/*Convert UUID (NF ID) from string to byte representation*/
		if(uuid_parse(req->nf_id, entry->nfid.buf) != 0)
		{
			pthread_mutex_unlock(&entry->lock);
			goto err;
		}
	}

	/*N2 Class*/
	if(req->n2_information_class != n2_information_class_NULL)
	{
		/*Check if it was already subscribed for target N2 information class*/
		if(entry->sub_n2[req->n2_information_class-1])
		{
			pthread_mutex_unlock(&entry->lock);

			/*
			 * HTTP error code: 303 See other (3GPP TS 29.500, 5.2.7.2)
			 */
			printf("[AMF-sbi] Requested resource for subscription (https://%s%s/%s) already exists\n", AMF_HNAME, stream_data->request_path, entry->sub_n2_id[req->n2_information_class-1]);

			/*Initialize header fields*/
			if((nva = calloc(2, sizeof(nghttp2_nv))) == NULL)
			{
				goto err;
			}
			nvlen = 2;

			/*(1) Status code*/
			nva->name = (uint8_t*) strdup(":status");
			nva->namelen = strlen(":status");
			nva->value = (uint8_t*) strdup("303");
			nva->valuelen = strlen(nva->value);

			/*(2) Location*/
			(nva + 1)->name = (uint8_t*) strdup("location");
			(nva + 1)->namelen = strlen("location");
			snprintf(buf, 99, "https://%s%s/%s", AMF_HNAME, stream_data->request_path, entry->sub_n2_id[req->n2_information_class-1]);
			(nva + 1)->value = (uint8_t*) strdup(buf);
			(nva + 1)->valuelen = strlen((nva + 1)->value);

			ue_n1_n2_info_subscription_create_data_free(req);

			send_response(session, stream_data->stream_id, nva, nvlen, NULL);

			return 0;
		}

		/*Add subscription data to UE context entry and mark it as complete*/
		else
		{
			acc_n2 = req->n2_information_class-1;
			entry->sub_n2[req->n2_information_class-1] = req;
			if(req->n2_information_class == n2_information_class_NRPPa && entry->gnb)
			{
				entry->isComplete = true;
			}

			/*Generate subscription ID: Use N2 Class string*/
			entry->sub_n2_id[req->n2_information_class-1] = strdup(n2_information_class_ToString(req->n2_information_class));
			sub_id = entry->sub_n2_id[req->n2_information_class-1];
		}
	}

	/*... analog for target N1 message class*/
	else if(req->n1_message_class != n1_message_class_NULL)
	{
		/*Check if it was already subscribed for target N1 information class*/
		if(entry->sub_n1[req->n1_message_class-1])
		{
			pthread_mutex_unlock(&entry->lock);

			/*
			 * HTTP error code: 303 See other (3GPP TS 29.500, 5.2.7.2)
			 */
			printf("[AMF-sbi] Requested resource for subscription (https://%s%s/%s) already exists\n", AMF_HNAME, stream_data->request_path, entry->sub_n1_id[req->n1_message_class-1]);

			/*Initialize header fields*/
			if((nva = calloc(2, sizeof(nghttp2_nv))) == NULL)
			{
				goto err;
			}
			nvlen = 2;

			/*(1) Status code*/
			nva->name = (uint8_t*) strdup(":status");
			nva->namelen = strlen(":status");
			nva->value = (uint8_t*) strdup("303");
			nva->valuelen = strlen(nva->value);
		
			/*(2) Location*/
			(nva + 1)->name = (uint8_t*) strdup("location");
			(nva + 1)->namelen = strlen("location");
			snprintf(buf, 99, "https://%s%s/%s", AMF_HNAME, stream_data->request_path, entry->sub_n1_id[req->n1_message_class-1]);
			(nva + 1)->value = (uint8_t*) strdup(buf);
			(nva + 1)->valuelen = strlen((nva + 1)->value);

			ue_n1_n2_info_subscription_create_data_free(req);

			send_response(session, stream_data->stream_id, nva, nvlen, NULL);

			return 0;
		}
		
		else
		{
			acc_n1 = req->n1_message_class - 1;
			entry->sub_n1[req->n1_message_class-1] = req;
			if(req->n1_message_class == n1_message_class_LPP && entry->gnb)
			{
				entry->isComplete = true;
			}

			/*Generate subscription ID: Use N1 Class string*/
			entry->sub_n1_id[req->n1_message_class-1] = strdup(n1_message_class_ToString(req->n1_message_class));
			sub_id = entry->sub_n1_id[req->n1_message_class-1];
		}
	}
	else
	{
		pthread_mutex_unlock(&entry->lock);
		goto err;
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&entry->lock);

	/*Creation of UeN1N2SubscriptionCreatedData*/
	if((resp = ue_n1_n2_info_subscription_created_data_create(strdup(sub_id), NULL)) == NULL)
	{
		goto err;
	}

	/*Converting to JSON string*/
	if((jbody = ue_n1_n2_info_subscription_created_data_convertToJSON(resp)) == NULL || (jstr = cJSON_Print(jbody)) == NULL)
	{
		goto err;
	}

	cJSON_Delete(jbody);
	jbody = 0;
	ue_n1_n2_info_subscription_created_data_free(resp);
	resp = 0;

	/*Initialize header fields*/
	if((nva = calloc(4, sizeof(nghttp2_nv))) == NULL)
	{
		goto err;
	}
	nvlen = 4;

	/*(1) Status code*/
	nva->name = (uint8_t*) strdup(":status");
	nva->namelen = strlen(":status");
	nva->value = (uint8_t*) strdup("201");
	nva->valuelen = strlen(nva->value);

	/*(2) Content-Type*/
	(nva + 1)->name = (uint8_t*) strdup("content-type");
	(nva + 1)->namelen = strlen("content-type");
	(nva + 1)->value = (uint8_t*) strdup("application/json");
	(nva + 1)->valuelen = strlen((nva + 1)->value);

	/*(3) Content-length*/
	(nva + 2)->name = (uint8_t*) strdup("content-length");
	(nva + 2)->namelen = strlen("content-length");
	snprintf(buf, 99, "%ld", strlen(jstr));
	(nva + 2)->value = (uint8_t*) strdup(buf);
	(nva + 2)->valuelen = strlen((nva + 2)->value);

	/*(4) Location*/
	(nva + 3)->name = (uint8_t*) strdup("location");
	(nva + 3)->namelen = strlen("location");
	snprintf(buf, 99, "https://%s%s/%s", AMF_HNAME, stream_data->request_path, sub_id);
	(nva + 3)->value = (uint8_t*) strdup(buf);
	(nva + 3)->valuelen = strlen((nva + 3)->value);

	/*Initialize data structure for DATA frame callback function*/
	explicit_bzero(&data_prd, sizeof(data_prd));

	/*Assign data source and its callback function*/
	data_prd.source.ptr = (void*)jstr;
	data_prd.read_callback = json_read_callback;

	/*Sending response data*/
	if (send_response(session, stream_data->stream_id, nva, nvlen, &data_prd) != 0)
	{
		goto err;
	}

	return 0;

err:
	if(req) /*NOTE: NEVER clear @req if processing is successful!!*/
	{
		ue_n1_n2_info_subscription_create_data_free(req);
	}

	if(jbody)
	{
		cJSON_Delete(jbody);
	}

	if(jstr)
	{
		free(jstr);
	}

	if(resp)
	{
		ue_n1_n2_info_subscription_created_data_free(resp);
	}

	/*Reset changes in UE context structure*/
	pthread_mutex_lock(&entry->lock);

	if(acc_n1 >= 0 && acc_n1 < AMF_SUB_N1_MAX)
	{
		if(entry->sub_n1[acc_n1])
		{
			free(entry->sub_n1[acc_n1]);
			entry->sub_n1[acc_n1] = 0;
		}

		if(entry->sub_n1_id[acc_n1])
		{
			free(entry->sub_n1_id[acc_n1]);
			entry->sub_n1_id[acc_n1] = 0;
		}
		entry->isComplete = false;
	}

	if(acc_n2 >= 0 && acc_n2 < AMF_SUB_N2_MAX)
	{
		if(entry->sub_n2[acc_n2])
		{
			free(entry->sub_n2[acc_n2]);
			entry->sub_n2[acc_n2] = 0;
		}

		if(entry->sub_n2_id[acc_n2])
		{
			free(entry->sub_n2_id[acc_n2]);
			entry->sub_n2_id[acc_n2] = 0;
		}
		entry->isComplete = false;
	}

	pthread_mutex_unlock(&entry->lock);

	return -1;
}

/*
 * N1N2MessageUnsubscribe - 3GPP TS 29.518, 5.2.2.3.4
 *
 * /namf-comm/v1/ue_contexts/{ueContextID}/n1-n2-messages/subscriptions/{subscriptionID}
 *
 * return: 0 on success, otherwise -1
 */
int
namf_comm_n1n2msgunsubscribe(nghttp2_session *session, http2_stream_data *stream_data, rentry_t *entry, char *subid)
{
	/*Variables*/
	nghttp2_nv *nva = 0;
	size_t nvlen = 0;

	/*Check passed input parameter*/
	if(!session || !stream_data || !entry || !subid)
	{
		return -1;
	}

	/*Check 1: SBI consumer (client) has to be accept: application/json,application/problem+json*/
	if(strcmp(stream_data->accept, "application/json,application/problem+json") != 0)
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		printf("[AMF-sbi] Invalid accept value (%s) in request header!\n", stream_data->accept);

		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}

	/*
	 * Decode subscription ID for N1N2MessageSubscriptions
	 *
	 * NOTE: Because this AMF uses the string format of a NX message class as subscription ID, the decoding back to class number is everything thas has to be done. :-)
	 */
	if(n1_message_class_FromString(subid) != n1_message_class_NULL)
	{
		if(pthread_mutex_lock(&entry->lock) != 0)
		{
			goto err;
		}
		if(!entry->sub_n1_id[n1_message_class_FromString(subid) - 1] || !entry->sub_n1[n1_message_class_FromString(subid) - 1])
		{
			pthread_mutex_unlock(&entry->lock);
			goto err;
		}
		pthread_mutex_unlock(&entry->lock);
	}

	else if(n2_information_class_FromString(subid) != n2_information_class_NULL)
	{
		if(pthread_mutex_lock(&entry->lock) != 0)
		{
			goto err;
		}

		if(!entry->sub_n2_id[n2_information_class_FromString(subid) - 1] || !entry->sub_n2[n2_information_class_FromString(subid) - 1])
		{
			pthread_mutex_unlock(&entry->lock);
			goto err;
		}

		/*Free memory*/
		free(entry->sub_n2[n2_information_class_FromString(subid) - 1]);
		entry->sub_n2[n2_information_class_FromString(subid) - 1] = 0;
		free(entry->sub_n2_id[n2_information_class_FromString(subid) - 1]);
		entry->sub_n2_id[n2_information_class_FromString(subid) - 1] = 0;
		pthread_mutex_unlock(&entry->lock);
	}
	else
	{
		goto err;
	}

#ifndef RESEARCH
	printf("[AMF-sbi] Resource /namf-comm/v1/ue-contexts/%s/n1-n2-messages/subscriptions/%s was successfully deleted\n", entry->imsi, subid);
#endif

	/*
	 * Initialize HTTP header fields (successful response)
	 *
	 * According to 3GPP TS 29.518, 6.1.3.4.3.1: Only the header :status field is expected.
	 */
	if((nva = calloc(1, sizeof(nghttp2_nv))) == NULL)
	{
		goto err;
	}
	nvlen = 1;

	/*(1) Status code*/
	nva->name = (uint8_t*) strdup(":status");
	nva->namelen = strlen(":status");
	nva->value = (uint8_t*) strdup("204");
	nva->valuelen = strlen(nva->value);

	/*Sending response data*/
	if (send_response(session, stream_data->stream_id, nva, nvlen, NULL) != 0)
	{
		free(nva->name);
		free(nva->value);
		free(nva);
		nva = 0;
		return -1;
	}

	return 0;

err:
	printf("[AMF-sbi] Resource /namf-comm/v1/ue-contexts/%s/n1-n2-messages/subscriptions/%s doesn't exist\n", entry->imsi, subid);

	/*Sending response data*/
	if (error_response(session, stream_data, 404, HTTP_404_SUBNOFND) != 0)
	{
		return -1;
	}

	return 0;
}
