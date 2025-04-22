#include <http2/nghttp2srv.h>
#include "amfd.h"
#include "sbi-handler.h"

/*
 * send_response - transmit response to client
 *
 * @nva: header field list
 * @data_prd: data structure that references the response payload for DATA frame and a suitable callback function
 *
 * NOTE: If @data_prd == NULL, only a HEADERS frame is sent to client!
 */
int
send_response(nghttp2_session *session, int32_t stream_id, nghttp2_nv *nva, size_t nvlen, nghttp2_data_provider2 *data_prd)
{
	int rv;
	
	/*Sending of frames HEADERS and DATA*/
	if(data_prd)
	{
		rv = nghttp2_submit_response2(session, stream_id, nva, nvlen, data_prd);
	}
	else
	{
		rv = nghttp2_submit_response2(session, stream_id, nva, nvlen, NULL);
	}

	if (rv != 0)
	{
		warnx("Fatal error: %s", nghttp2_strerror(rv));
		return -1;
	}
	return 0;
}

/*
 * TODO: HTTP_400_INVURL -> ProblemDetails.invalidParams has to be initialized!! 
 *
 * error_response - generate HTTP/2 response for a specific HTTP error code
 *
 * @session: HTTP/2 session
 * @stream_data: target HTTP/2 stream data
 * @err: HTTP error code
 * @cause: error message according to 3GPP TS 29.518, Table 5.2.7.2-1
 *
 * return: 0 on success, otherwise -1
 */
int
error_response(nghttp2_session *session, http2_stream_data *stream_data, int err, char *cause)
{
	/*Variables*/
	cJSON *data = 0;
	uint16_t num = 0;
	char buf[100] = {0}, *jstr = 0;
	
	nghttp2_nv *nva = 0;
	size_t nvlen = 0;
	problem_details_t *pb = 0;

	nghttp2_data_provider2 data_prd;

	/*Check passed input parameters*/
	if(err != 501 && err != 415 && err != 413 && !cause)
	{
		return -1;
	}

	/*HTTP error handling*/
	switch(err)
	{
		case 400:
		case 404:
		case 411:
		case 500:

			/*Preparation of ProblemDetails*/
			if((pb = problem_details_create(strdup(stream_data->request_path), NULL, false, 0, NULL, NULL, strdup(cause), NULL, NULL, NULL, NULL, NULL, NULL, NULL)) == NULL || (data = problem_details_convertToJSON(pb)) == NULL)
			{
				if(pb)
				{
					problem_details_free(pb);
				}
				return -1;
			}

			problem_details_free(pb);

			jstr = cJSON_Print(data);
			cJSON_Delete(data);

			if(!jstr)
			{
				return -1;
			}

			/*Set references for DATA frame*/
			explicit_bzero(&data_prd, sizeof(data_prd));
			data_prd.source.ptr = (void*)jstr;
			data_prd.read_callback = json_read_callback;

		case 413:
		case 415:
		case 501:
			(err == 501 || err == 415 || err == 413) ? (num = 1) : (num = 3);

			/*Allocate memory for header fields*/
			if((nva = calloc(num, sizeof(nghttp2_nv))) == NULL)
			{
				if(jstr)
				{
					free(jstr);
				}
				return -1;
			}
			nvlen = num;
			
			/*Status code*/
			nva->name = (uint8_t*) strdup(":status");
			nva->namelen = strlen(":status");
			snprintf(buf, 99, "%d", err);
			nva->value = (uint8_t*) strdup(buf);
			nva->valuelen = strlen(nva->value);

			if(err != 501 && err != 415 && err != 413)
			{
				/*Content-Type*/
				(nva + 1)->name = (uint8_t*) strdup("content-type");
				(nva + 1)->namelen = strlen("content-type");
				(nva + 1)->value = (uint8_t*) strdup("application/problem+json");
				(nva + 1)->valuelen = strlen((nva + 1)->value);
				
				/*Content-length*/
				(nva + 2)->name = (uint8_t*) strdup("content-length");
				(nva + 2)->namelen = strlen("content-length");
				snprintf(buf, 99, "%ld", strlen(jstr));
				(nva + 2)->value = (uint8_t*) strdup(buf);
				(nva + 2)->valuelen = strlen((nva + 2)->value);
				
				/*Send error message to client*/
				if (send_response(session, stream_data->stream_id, nva, nvlen, &data_prd) != 0)
				{
					return -1;
				}
			}

			/*No content for HTTP error codes 415 and 501*/
			else
			{
				/*Send error message to client*/
				if (send_response(session, stream_data->stream_id, nva, nvlen, NULL) != 0)
				{
					return -1;
				}
			}
			break;

		default:
			return -1;
	}

	return 0;
}

/*
 * nghttp2_on_header_callback - called when nghttp2 library emits single header name/value pair
 *
 * @name: HTTP/2 attribute
 * @namelen: string length of @name
 * @value: assigned value of @name
 * @valuelen: string length of @value
 */
int
on_header_callback(nghttp2_session *session, const nghttp2_frame *frame, const uint8_t *name, size_t namelen, const uint8_t *value, size_t valuelen, uint8_t flags, void *user_data)
{
	/*Variables*/
	http2_stream_data *stream_data;
  	(void)flags;
	(void)user_data;

	switch (frame->hd.type)
	{
		case NGHTTP2_HEADERS:
			if (frame->headers.cat != NGHTTP2_HCAT_REQUEST)
			{
				break;
			}
			stream_data = nghttp2_session_get_stream_user_data(session, frame->hd.stream_id);

#ifdef DEBUG
			fprintf(stderr, "%s %s\n", name, value);
#endif

			if (!stream_data)
			{
				break;
			}

			/*:path*/
			if (strcmp(name, ":path") == 0 && !stream_data->request_path)
			{
				/*Store value in @stream_data*/
				stream_data->request_path = strdup(value);
			}

			/*:method*/
			else if(strcmp(name, ":method") == 0 && !stream_data->method)
			{
				stream_data->method = strdup(value);
			}

			/*user-agent*/
			else if(strcmp(name, "user-agent") == 0 && !stream_data->user_agent)
			{
				stream_data->user_agent = strdup(value);
			}

			/*accept*/
			else if(strcmp(name, "accept") == 0 && !stream_data->accept)
			{
				stream_data->accept = strdup(value);
			}

			/*content-type*/
			else if(strcmp(name, "content-type") == 0 && !stream_data->ctype)
			{
				stream_data->ctype = strdup(value);
			}

			/*content-length*/
			else if(strcmp(name, "content-length") == 0 && !stream_data->clength)
			{
				stream_data->clength = atoi(value);
			}
			break;
	}

	return 0;
}

static namfc_t*
parseComURL(char *path, rentry_t **entry)
{
	struct namf_comm_url *map = 0;
	char *tmp = 0, *cur = 0, *saveptr = 0;
	int i;

	/*Allocate path bit field*/
	if(entry == NULL || (map = (namfc_t*) calloc(1, sizeof(namfc_t))) == NULL)
	{
		return NULL;
	}

	/*
	 * Traverse through given URL path
	 *
	 * 3GPP TS 29.518, 6.1.3.1: path layer 2
	 */
	if(strstr(path + strlen(AMF_NAMF_COMM), "/ue-contexts") == path + strlen(AMF_NAMF_COMM))
	{
		map->L1_ue_contexts = 1;

		/*
		 * 3GPP TS 29.518, 6.1.3.1: path layer 3.1
		 *
		 * /namf-comm/v1/ue-contexts/{ueContextID}
		 */
		if((tmp = strdup(path + strlen(AMF_NAMF_COMM) + strlen("/ue-contexts") + 1)) == NULL)
		{
			goto err;
		}
#ifdef DEBUG
		fprintf(stderr, "[AMF-sbi] Path parser reached /namf-comm/v1/ue-contexts layer. Left: %s\n", tmp);
#endif

		/*Tokenize next layers*/
		for(i = 0, cur = strtok_r(tmp, "/", &saveptr); cur != NULL; cur = strtok_r(NULL, "/", &saveptr), i++)
		{
			switch(i)
			{
				case 0:
					/*Layer 3.2: ueContextID*/
					map->L2_uectxid = 1;
					if((*entry = getEntry(ue_ctx, cur)) == NULL)
					{
						goto err;
					}

					break;

				case 1:
					/*Layer 3.3*/
					if(strcmp(cur, "assign-ebi") == 0)
					{
						map->L3_assign = 1;
					}
					else if(strcmp(cur, "transfer") == 0)
					{
						map->L3_transfer = 1;
					}
					else if(strcmp(cur, "release") == 0)
					{
						map->L3_release = 1;
					}
					else if(strcmp(cur, "transfer-update") == 0)
					{
						map->L3_transupt = 1;
					}
					else if(strcmp(cur, "relocate") == 0)
					{
						map->L3_relocate = 1;
					}
					else if(strcmp(cur, "cancel-relocate") == 0)
					{
						map->L3_canreloc = 1;
					}
					else if(strcmp(cur, "n1-n2-messages") == 0)
					{
						map->L3_n1n2msg = 1;
					}
					else
					{
						goto err;
					}
					break;

				case 2:
					/*Layer 3.4*/
					if(map->L3_n1n2msg && strcmp(cur, "subscriptions") == 0)
					{
						map->L4_subscriptions = 1;
					}
					else if(map->L3_n1n2msg)
					{
						map->L4_n1n2msgid = 1;
						
						//TODO: store N1N2Message ID...
					}
					else
					{
						goto err;
					}
					break;

				case 3:
					/*Layer 3.5*/
					if(map->L3_n1n2msg && map->L4_subscriptions)
					{
						map->L5_subscripid = 1;
						map->subid = strdup(cur);
					}
					else
					{
						goto err;
					}
					break;
					
				default:
					goto err;
			}

			//free(tmp);
		}
	}
	else if(strstr(path + strlen(AMF_NAMF_COMM), "/subscriptions") == path + strlen(AMF_NAMF_COMM))
	{
		/*
		 * 3GPP TS 29.518, 6.1.3.1: path layer 3.1
		 *
		 * /namf-comm/v1/subscriptions/{subscriptionsID}
		 */

		map->L1_subscriptions = 1;

		if((tmp = strdup(path + strlen(AMF_NAMF_COMM) + strlen("/subscriptions") + 1)) == NULL)
		{
			goto err;
		}

#ifdef DEBUG
		fprintf(stderr, "[AMF-sbi] Path parser reached /namf-comm/v1/subscriptions layer. Left: %s\n", tmp);
#endif

		/*Tokenize next layers*/
		for(i = 0, cur = strtok_r(tmp, "/", &saveptr); cur != NULL; cur = strtok_r(NULL, "/", &saveptr), i++)
		{
			if(i == 0)
			{
				//TODO: store subscriptions ID ...
			}
			else
			{
				goto err;
			}
		}
		
	}
	else if(strstr(path + strlen(AMF_NAMF_COMM), "/non-ue-n2-messages") == path + strlen(AMF_NAMF_COMM))
	{
		/*
		 * 3GPP TS 29.518, 6.1.3.1: path layer 3.1
		 *
		 * /namf-comm/v1/non-ue-n2-messages/...
		 */
	
		map->L1_nonuen1n2msg = 1;
		
		if((tmp = strdup(path + strlen(AMF_NAMF_COMM) + strlen("/non-ue-n2-messages") + 1)) == NULL)
		{
			goto err;
		}

#ifdef DEBUG
		fprintf(stderr, "[AMF-sbi] Path parser reached /namf-comm/v1/non-ue-n2-messages layer. Left: %s\n", tmp);
#endif

		/*Tokenize next layers*/
		for(i = 0, cur = strtok_r(tmp, "/", &saveptr); cur != NULL; cur = strtok_r(NULL, "/", &saveptr), i++)
		{
			switch(i)
			{
				/*Layer 3.2*/
				case 0:
					if(strcmp(cur, "transfer") == 0)
					{
						map->L2_nonuetrans = 1;
					}
					else if(strcmp(cur, "subscriptions") == 0)
					{
						map->L2_subscription = 1;
					}
					else
					{
						goto err;
					}
					break;
				
				case 1:
					/*Layer 3.2*/
					if(map->L2_subscription)
					{
						map->L3_n2notifyid = 1;
						map->n2notfiysubid = strdup(cur);
					}
					else
					{
						goto err;
					}
					break;
					
				default:
					goto err;
			}
		}
	}
	else
	{
		goto err;
	}

	return map;

err:
	if(map)
	{
		free(map);
	}

	return NULL;
}

/*
 * on_request_receive - evaluate client HTTP request URL and select SBI service function
 */
static int
on_request_recv(nghttp2_session *session, http2_session_data *session_data, http2_stream_data *stream_data) {

	/*Variables*/
	char clen[100] = {0};
	namfc_t *map = 0;
	rentry_t *entry = 0;

	/*Checking transmitted header path field*/
	if(!stream_data->request_path || !strlen(stream_data->request_path))
	{
		goto err;
	}

	/*Check 2: Content Length != received data size*/
	if(stream_data->size < stream_data->clength)
	{
		/*HTTP error code 413 CONTENT TOO LARGE, TS 29.500, 5.2.7.2*/
		if(error_response(session, stream_data, 413, 0) != 0)
		{
				goto err;
		}
						
		return 0;
	}
	else if(stream_data->size > stream_data->clength)
	{
		/*HTTP error code 411 LENGTH REQUIRED + ProblemDetails with cause field value: INCORRECT_LENGTH, TS 29.500, 5.2.7.2*/
		if(error_response(session, stream_data, 411, HTTP_411_INCLENG) != 0)
		{
				goto err;
		}
						
		return 0;
	}

#ifdef DEBUG
	fprintf(stderr, "%s %s %s\n", session_data->client_addr, stream_data->method, stream_data->request_path);

	fprintf(stderr, "DATA [%d B | %d B]:\n", stream_data->size, stream_data->clength);
	for(int i = 0; i < stream_data->size; i++)
	{
		if(i%10 == 0)
		{
			fprintf(stderr, "\n%.2x ", stream_data->data[i]);
		}
		else{
			fprintf(stderr, "%.2x ", stream_data->data[i]);
		}
	}

	printf("%s\n", stream_data->data);
#endif

	/*
	 * Parse requested Namf SBI Service URL and select service
	 *
	 * @AMF_NAMF_COMM: Namf_Communication Service ("/namf-comm/v1")
	 * @AMF_NAMF_EVTN: Namf_EventExposure Service ("/namf-evts/v1")
	 * ...
	 */
	if(strstr(stream_data->request_path, AMF_NAMF_COMM) == stream_data->request_path)
	{
		/*Check 3: Check requested API version*/
		if(strstr(stream_data->request_path + strlen(AMF_NAMF_COMM) - 2, "v1") != stream_data->request_path + strlen(AMF_NAMF_COMM) - 2)
		{
			/*HTTP error code 400, with included ProblemDetails.cause = INVALID_API , TS 29.500, 5.2.7.2*/
			if(error_response(session, stream_data, 400, HTTP_400_INVAPI) != 0)
			{
					goto err;
			}
			return 0;
		}
	
		if(!(map = parseComURL(stream_data->request_path, &entry)))
		{
			/*HTTP error code 400 BAD REQUEST: Invalid API*/
			if(error_response(session, stream_data, 400, HTTP_400_INVAPI) != 0)
			{
				goto err;
			}
			return 0;
		}

		/*
	 	 * Using path bitmap to select SBI handler function to process REQUEST
	 	 *
	 	 * NOTE: Only services are considered that are initiated by other NFs (not AMF)!
	 	 * NOTE: The generation of the response is done within the selected SBI handler function.
	 	 */
	 	
	 	/*
	 	 * (1) UE Context and UE N1N2 Specific Message Operations
	 	 */
		if(map->L1_ue_contexts && map->L2_uectxid)
		{
			/*
		 	 * N1N2MessageUnSubscribe - 3GPP TS 29.518, 5.2.2.3.4
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/n1-n2-messages/subscriptions/{subscriptionID}
		 	 */
			if(map->L3_n1n2msg && map->L4_subscriptions && map->L5_subscripid && strcmp(stream_data->method, "DELETE") == 0)
			{
				if(namf_comm_n1n2msgunsubscribe(session, stream_data, entry, map->subid) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * N1N2MessageSubscribe - 3GPP TS 29.518, 5.2.2.3.3
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/n1-n2-messages/subscriptions
		 	 */
			else if(map->L3_n1n2msg && map->L4_subscriptions && strcmp(stream_data->method, "POST") == 0)
			{
				if(namf_comm_n1n2msgsubscribe(session, stream_data, entry) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * N1N2MessageTransfer - 3GPP TS 29.518, 5.2.2.3.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/n1-n2-messages
		 	 */
			else if(map->L3_n1n2msg && strcmp(stream_data->method, "POST") == 0)
			{
				if(namf_comm_n1n2msgtransfer(session, stream_data, entry) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * EBIAssignment - 3GPP TS 29.518, 5.2.2.6.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/assign-ebi
		 	 */
			else if(map->L3_assign && strcmp(stream_data->method, "POST") == 0)
			{
				/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * UEContextTransfer - 3GPP TS 29.518, 5.2.2.2.1.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/transfer
		 	 */
			else if(map->L3_transfer && strcmp(stream_data->method, "POST") == 0)
			{
				/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * ReleaseUEContext - 3GPP TS 29.518, 5.2.2.2.4.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/release
		 	 */
			else if(map->L3_release && strcmp(stream_data->method, "POST") == 0)
			{
				/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * RegistrationStatusUpdate - 3GPP TS 29.518, 5.2.2.2.2.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/transfer-update
		 	 */
			else if(map->L3_transupt && strcmp(stream_data->method, "POST") == 0)
			{
				/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * RelocateUEContext - 3GPP TS 29.518, 5.2.2.2.5.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/relocate
		 	 */
			else if(map->L3_relocate && strcmp(stream_data->method, "POST") == 0)
			{
				/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * CancelRelocateUEContext - 3GPP TS 29.518, 5.2.2.2.6.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}/cancel-relocate
		 	 */
			else if(map->L3_canreloc && strcmp(stream_data->method, "POST") == 0)
			{
				/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
			}
			
			/*
		 	 * CreateUEContext - 3GPP TS 29.518, 5.2.2.2.3.1
		 	 *
		 	 * /namf-comm/v1/ue_contexts/{ueContextID}
		 	 */
			else if(strcmp(stream_data->method, "PUT") == 0)
			{
				/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
			}
			else
			{
				goto err;
			}
		}
		
		/*
	 	 * (2) AMF Status Change Operations
	 	 */
	 	else if(map->L1_subscriptions)
	 	{
	 		/*
		 	 * AMFStatusChangeUnSubscribe - 3GPP TS 29.518, 5.2.2.5.2
		 	 *
		 	 * /namf-comm/v1/subscriptions/{subscriptionID}
		 	 */
	 		if(map->L2_subscrid && strcmp(stream_data->method, "DELETE") == 0)
	 		{
	 			/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
	 		}
	 		
	 		/*
		 	 * AMFStatusChangeSubscribe - 3GPP TS 29.518, 5.2.2.5.1
		 	 *
		 	 * /namf-comm/v1/subscriptions
		 	 */
	 		else if(strcmp(stream_data->method, "POST") == 0)
	 		{
	 			/*HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
	 		}
	 		
	 		else
	 		{
	 			goto err;
	 		}	 		
	 	}
	 	
	 	/*
	 	 * (3) Non-UE N2 Message Operations
	 	 */
	 	else if(map->L1_nonuen1n2msg)
	 	{
	 		/*
		 	 * NonUeN2MessageTransfer - 3GPP TS 29.518, 5.2.2.4.1
		 	 *
		 	 * /namf-comm/v1/non-ue-n2-messages/transfer
		 	 */
	 		if(map->L2_nonuetrans && strcmp(stream_data->method, "POST") == 0)
	 		{
	 			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
	 		}
	 		
	 		/*
		 	 * NonUeN2InfoUnSubscribe - 3GPP TS 29.518, 5.2.2.4.3
		 	 *
		 	 * /namf-comm/v1/non-ue-n2-messages/subscriptions/{n2NotifySubscriptionID}
		 	 */
	 		else if(map->L2_subscription && map->L3_n2notifyid && strcmp(stream_data->method, "DELETE") == 0)
	 		{
	 			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
	 		}
	 		
	 		/*
		 	 * NonUeN2InfoSubscribe - 3GPP TS 29.518, 5.2.2.4.2
		 	 *
		 	 * /namf-comm/v1/non-ue-n2-messages/subscriptions
		 	 */
	 		else if(map->L2_subscription && strcmp(stream_data->method, "POST") == 0)
	 		{
	 			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
				if(error_response(session, stream_data, 501, NULL) != 0)
				{
					goto err;
				}
	 		}

	 		else
	 		{
	 			goto err;
	 		}
	 	}
	 	
	 	/*Free memory*/
	 	if(map->n2notfiysubid)
	 	{
	 		free(map->n2notfiysubid);
	 		map->n2notfiysubid = 0;
	 	}
	 	if(map->subid)
	 	{
	 		free(map->subid);
	 		map->subid = 0;
	 	}
	 	free(map);
	 	map = 0;
	}

	else if(strstr(stream_data->request_path, AMF_NAMF_EVNT) == stream_data->request_path)
	{
		/*Check 3: Check requested API version*/
		if(strstr(stream_data->request_path + strlen(AMF_NAMF_EVNT) - 2, "v1") != stream_data->request_path + strlen(AMF_NAMF_EVNT) - 2)
		{
			/*HTTP error code 400, with included ProblemDetails.cause = INVALID_API , TS 29.500, 5.2.7.2*/
			if(error_response(session, stream_data, 400, HTTP_400_INVAPI) != 0)
			{
					goto err;
			}
			return 0;
		}

		/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
		if(error_response(session, stream_data, 501, NULL) != 0)
		{
			goto err;
		}
	}

	/*TODO: add all other Namf services here!*/

	else
	{
		/*HTTP error code 400 BAD REQUEST: Invalid API*/
		if(error_response(session, stream_data, 400, HTTP_400_INVAPI) != 0)
		{
			goto err;
		}
	}

	return 0;

err:
	/*Free memory*/
	if(map)
	{
		if(map->n2notfiysubid)
	 	{
	 		free(map->n2notfiysubid);
	 	}
	 	if(map->subid)
	 	{
	 		free(map->subid);
	 	}

		free(map);
	}

	/*Send HTTP error message: 500 INTERNAL SERVER ERROR*/
	if(error_response(session, stream_data, 500, HTTP_500_SYSFAIL) != 0)
	{
		return NGHTTP2_ERR_CALLBACK_FAILURE;
	}

	return 0;
}

/*
 * on_frame_recv_callback - callback when a frame was received from the client (invoked after the HTTP/2 HEADERS frame was completely parsed by on_header_callback())
 */
int
on_frame_recv_callback(nghttp2_session *session, const nghttp2_frame *frame, void *user_data)
{
	/*Variables*/
	http2_session_data *session_data = (http2_session_data *)user_data;
	http2_stream_data *stream_data;
	
	/*Entry point to get */
	switch (frame->hd.type)
	{
		case NGHTTP2_DATA:
		case NGHTTP2_HEADERS:
			/* Check that the client request has finished + NK: header fields can not be obtained in this callback because the header value pairs are passed to @stream_data via on_header_callback*/
			if (frame->hd.flags & NGHTTP2_FLAG_END_STREAM)
			{
				stream_data = nghttp2_session_get_stream_user_data(session, frame->hd.stream_id);

				/* For DATA and HEADERS frame, this callback may be called after on_stream_close_callback. Check that stream still alive. */
				if (!stream_data)
				{
					return 0;
				}
				
				/*Prepare response HEADERS frame and send DATA*/
				return on_request_recv(session, session_data, stream_data);
			}
			break;

		default:
			break;
	}

	return 0;
}
