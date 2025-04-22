#include "sbi-client.h"

/*
 * Callback function to receive HTTP/2 header response data 
 */
size_t
getHTTPHeaderResponse(char *buf, size_t size, size_t nmemb, struct http_list **hdr)
{
	char *target = 0;

	/*Detect last header line: 0x0d 0x0a*/
	if(size*nmemb == 2 && buf[0] == 0x0d && buf[1] == 0x0a)
	{
		return size*nmemb;
	}

	/*
	 * Copy buffer to new allocated buffer
	 *
	 * NOTE: Remove the last two bytes because these are 0x0d 0x0a ...
	 */
	if(size*nmemb == 0 || (target = calloc(size*nmemb-1, sizeof(char))) == NULL)
	{
		return size*nmemb;
	}
	memcpy(target, buf, size*nmemb-2);

	/*Insert header field into list*/
	if((*hdr)->cnt == 0)
	{
		(*hdr)->first = calloc(1, sizeof(struct http_entry));
		(*hdr)->first->data = target;
		(*hdr)->last = (*hdr)->first;
	}
	else
	{
		(*hdr)->last->next = calloc(1, sizeof(struct http_entry));
		(*hdr)->last = (*hdr)->last->next;
		(*hdr)->last->data = target;
	}

	/*Increase list counter*/
	(*hdr)->cnt++;

	return size*nmemb;
}

/*
 * Callback function to receive HTTP/2 response data
 *
 * return: JSON data structure
 */
size_t
getHTTPResponse(void *ptr, size_t size, size_t nmemb, cJSON **res)
{
	if((*res = cJSON_ParseWithLength(ptr, nmemb*size)) == NULL)
	{
		return size*nmemb;
	}

	return size*nmemb;
}

/*
 * Namf_Communication_N1N2MessageSubscribe service - subscribe for UE specific N2 data
 *
 * @uri: callback URI that is used by the AMF for N2 message transfer
 * @nfid: NF ID of this LMF
 * @ctx: User Context ID, e.g. IMSI
 *
 * return: 0 on success, -1 otherwise
 * TODO: extend signature so that it can be subscribed for both: N1 and N2 class
 */
int
namf_comm_n1n2msgsubscribe(char *uri, char *nfid, ue_ctx_t *ctx)
{
	/*Variables*/
	CURL *handle = 0;
	struct curl_slist *hdr = 0;
	char url[BMAX] = {0};
	volatile uint16_t status = 0;
	int i, j;
	volatile int retry = 3;

	ue_n1_n2_info_subscription_create_data_t *subdata = 0;
	ue_n1_n2_info_subscription_created_data_t *resp = 0;
	problem_details_t *pd = 0;
	cJSON *jbody = 0, *res = 0;
	char *body = 0, *tmp = 0, *token = 0;

	struct http_list *root = 0;
	struct http_entry *entry = 0;

	/*Check passed input parameter*/
	if(!uri || !nfid || !ctx || !ctx->supi || strstr(uri, LMF_BASE_URI) != uri)
	{
		return -1;
	}

	/*Allocate memory for HTTP response header*/
	if((root = calloc(1, sizeof(struct http_list))) == NULL)
	{
		return -1;
	}

	/*Initializing of CURL handle*/
	if((handle = curl_easy_init()) == 0)
	{
		goto err;
	}

	/*Create and set SBI service URL*/
	snprintf(url, BMAX, "https://%s:54321/namf-comm/v1/ue-contexts/%s/n1-n2-messages/subscriptions", AMF_HNAME, ctx->supi);

	if(curl_easy_setopt(handle, CURLOPT_URL, url) != CURLE_OK)
	{
		goto err;
	}

	/*Initialize and set HTTP header*/
	if((hdr = curl_slist_append(hdr, "Accept: application/json,application/problem+json")) == NULL)
	{
		goto err;
	}

	if((hdr = curl_slist_append(hdr, "Content-Type: application/json")) == NULL)
	{
		goto err;
	}

	if((hdr = curl_slist_append(hdr, "User-Agent: LMF-msgsub")) == NULL)
	{
		goto err;
	}
	if(curl_easy_setopt(handle, CURLOPT_HTTPHEADER, hdr) != CURLE_OK)
	{
		goto err;
	}

	/*Creation of the JSON body: UeN1N2InfoSubscriptionCreateData (see: 3GPP TS 29.518, 6.1.3.3.3.1)*/
	if((subdata = ue_n1_n2_info_subscription_create_data_create(n2_information_class_NRPPa, strdup(uri), n1_message_class_NULL, NULL, strdup(nfid), NULL, NULL)) == NULL)
	{
		goto err;
	}

	/*Convert subcription data to: JSON -> string*/
	if((jbody = ue_n1_n2_info_subscription_create_data_convertToJSON(subdata)) == NULL)
	{
		goto err;
	}
	ue_n1_n2_info_subscription_create_data_free(subdata);
	subdata = 0;

	if((body = cJSON_Print(jbody)) == NULL)
	{
		goto err;
	}
	cJSON_Delete(jbody);
	jbody = 0;

	/*Add JSON data to request*/
	if(curl_easy_setopt(handle, CURLOPT_POSTFIELDS, body) != CURLE_OK)
	{
		goto err;
	}

	/*Add directory of TLS certificate and the file itself*/
	if(curl_easy_setopt(handle, CURLOPT_CAPATH, TLS_DIR) != CURLE_OK || curl_easy_setopt(handle, CURLOPT_CAINFO, AMF_TLS_CRT) != CURLE_OK)
	{
		goto err;
	}

	/*Set callback functions for getting response data*/
	if(curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, getHTTPHeaderResponse) != CURLE_OK) /*is called for every HTTP/2 header field*/
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_HEADERDATA, &root) != CURLE_OK)
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, getHTTPResponse) != CURLE_OK)
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res) != CURLE_OK)
	{
		goto err;
	}

again:
	/*Send HTTP/2 request to AMF*/
	if((i=curl_easy_perform(handle)) != CURLE_OK)
	{
		if(retry)
		{
			retry--;
			goto again;
		}
		goto err;
	}
	free(body);
	body = 0;

	/*
	 * Checking response data:
	 *
	 * (I) Header data
	 * (II) Response body
	 */
	if(root)
	{
		for(i = 1, entry = root->first; entry != NULL ; entry = root->first, i++)
		{
			switch (i)
			{
				/*Status Code*/
				case 1:
					if((body = strdup(entry->data)) == NULL)
					{
						goto err;
					}
					tmp = body;
					for(token = strtok(tmp, " "), j = 0; token != NULL; token = strtok(NULL, " "), j++)
					{
						if(token)
						{
							if(!j && strstr(token, "HTTP/2") != token)
							{
								goto err;
							}
							else if(j == 1 && (status = atoi(token)) == 0)
							{
								goto err;
							}
							else if(j > 1)
							{
								goto err;
							}
						}
					}

					/*Break, if a certain error code is returned*/
					if(status == 501 || status == 413 || status == 415)
					{
						if(root->cnt > 1)
						{
							goto err;
						}
						goto hbody;
					}

					/*Free list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}

					break;

				/*Further possible header fields*/
				case 2:
				case 3:
				case 4:
				case 5:
					if(strstr(entry->data, "content-type: ") == entry->data && strlen(entry->data) > strlen("content-type: ") + 1)
					{
						tmp = entry->data + strlen("content-type: ");

						/*Content-Type depends on the received HTTP error code*/
						if((status >= 400 && strcmp(tmp, "application/problem+json") != 0) || (status < 400 && strcmp(tmp, "application/json") != 0))
						{
							goto err;
						}
					}
					else if(strstr(entry->data, "content-length: ") == entry->data && strlen(entry->data) > strlen("content-length: ") + 1)
					{
						if(atoi(entry->data + strlen("content-length: ")) == 0)
						{
							goto err;
						}
					}

					/*
					 * Location field could be available: 3GPP TS 29.518, 6.1.3.3.3.1
					 */
					else if((status == 201 || status == 303 || status == 307 || status == 308) && strstr(entry->data, "location: ") == entry->data)
					{
						/*If already subscribe, check resource URI*/
						if(status == 303)
						{
							snprintf(url, BMAX, "https://amfd.5gc/namf-comm/v1/ue-contexts/%s/n1-n2-messages/subscriptions", ctx->supi);
							if((tmp = strstr(entry->data, url)) == NULL)
							{
								goto err;
							}
							tmp += strlen(url) + 1;

							/*Reassign N2 Subscription ID*/
							if(!ctx->n2subid)
							{
								ctx->n2subid = strdup(tmp);
							}
							else if(strcmp(tmp, ctx->n2subid) != 0)
							{
								goto err;
							}
						}
						else
						{
							/*TODO: implementation is open*/
						}
					}

					/*
					 * Custom header field could be available: 3gpp-Sbi-Target-Nf-Id -> see: 3GPP TS 29.518, 6.1.3.3.3.1
					 */
					else if((status == 307 || status == 308) && strstr(entry->data, "3gpp-Sbi-Target-Nf-Id: ") == entry->data)
					{
						/*TODO: implementation is open*/
					}

					else
					{
						goto err;
					}

					/*Delete list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}

					break;

				default:
					/*Delete list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}
					break;
			}
		}
	}

hbody:
	/*
	 * Interpretation of HTTP response body depending on the HTTP response code
	 *
	 * according to: 3GPP TS 29.518, 6.1.3.3.3.1
	 */
	if(res)
	{
		switch(status)
		{
			/*UeN1N2InfoSubscriptionCreatedData expected*/
			case 201:
				if((resp = ue_n1_n2_info_subscription_created_data_parseFromJSON(res)) == NULL || resp->n1n2_notify_subscription_id == NULL || pthread_mutex_lock(&ctx->lock) != 0)
				{
					goto err;
				}

				ctx->n2_clb_uri = strdup(uri);
				ctx->n2subid = strdup(resp->n1n2_notify_subscription_id);

				pthread_mutex_unlock(&ctx->lock);
				//printf("[LMF-sbi] Subscription (NF: %s) was successfully created: %s\n", nfid, resp->n1n2_notify_subscription_id);
				break;

			/*RedirectResponse structure expected*/
			case 307:
			case 308:
				/*Implementation open*/
				return -1;
				break;

			/*ProblemDetails structure expected*/
			default:
				if((pd = problem_details_parseFromJSON(res)) == NULL)
				{
					goto err;
				}
				printf("[LMF-sbi] Subscription (NF: %s) error (HTTP/2 %d):\n-> Type: %s\n-> Cause: %s\n", nfid, status, pd->type, pd->cause);
		}
	}

	/*Free memory*/
	if(resp)
	{
		ue_n1_n2_info_subscription_created_data_free(resp);
	}

	if(res)
	{
		cJSON_Delete(res);
	}

	if(body)
	{
		free(body);
	}

	if(root)
	{
		freeHTTPList(root);
	}

	if(hdr)
	{
		curl_slist_free_all(hdr);
	}

	if(handle)
	{
		curl_easy_cleanup(handle);
	}

	if(pd)
	{
		problem_details_free(pd);
	}

	if(status != 201 && status != 303)
	{
		return -1;
	}

	return 0;

err:
	/*Free memory*/
	if(root)
	{
		freeHTTPList(root);
	}
	if(hdr)
	{
		curl_slist_free_all(hdr);
	}
	if(handle)
	{
		curl_easy_cleanup(handle);
	}
	if(subdata)
	{
		ue_n1_n2_info_subscription_create_data_free(subdata);
	}
	if(jbody)
	{
		cJSON_Delete(jbody);
	}
	if(body)
	{
		free(body);
	}
	if(res)
	{
		cJSON_Delete(res);
	}

	if(pd)
	{
		problem_details_free(pd);
	}

	return -1;
}

/*
 * Namf_Communication_N1N2MessageUnsubscribe service - unsubscribe for UE specific N2 data
 *
 * @ctx: Target UE context which is unsubscribed.
 *
 * return: 0 on success, -1 otherwise
 */
int
namf_comm_n1n2msgunsubscribe(ue_ctx_t *ctx)
{
	/*Variables*/
	CURL *handle = 0;
	struct curl_slist *hdr = 0;
	char url[BMAX] = {0};
	volatile uint16_t status = 0;
	int i, j;
	volatile int retry = 3;

	problem_details_t *pd = 0;
	cJSON *jbody = 0, *res = 0;
	char *body = 0, *tmp = 0, *token = 0;

	struct http_list *root = 0;
	struct http_entry *entry = 0;

	/*Check passed input parameter*/
	if(!ctx || !ctx->n2subid || !ctx->supi)
	{
		return -1;
	}

	/*Allocate memory for HTTP response header*/
	if((root = calloc(1, sizeof(struct http_list))) == NULL)
	{
		return -1;
	}

	/*Initializing of CURL handle*/
	if((handle = curl_easy_init()) == 0)
	{
		goto err;
	}

	/*Create and set SBI service URL*/
	snprintf(url, BMAX, "https://%s:54321/namf-comm/v1/ue-contexts/%s/n1-n2-messages/subscriptions/%s", AMF_HNAME, ctx->supi, ctx->n2subid);

	if(curl_easy_setopt(handle, CURLOPT_URL, url) != CURLE_OK)
	{
		goto err;
	}

	/*Set HTTP method to DELETE*/
	if(curl_easy_setopt(handle, CURLOPT_CUSTOMREQUEST, "DELETE") != CURLE_OK)
	{
		goto err;
	}

	/*Initialize and set HTTP header*/
	if((hdr = curl_slist_append(hdr, "Accept: application/json,application/problem+json")) == NULL)
	{
		goto err;
	}

	if((hdr = curl_slist_append(hdr, "User-Agent: LMF-msgunsub")) == NULL)
	{
		goto err;
	}
	if(curl_easy_setopt(handle, CURLOPT_HTTPHEADER, hdr) != CURLE_OK)
	{
		goto err;
	}

	/*Add directory of TLS certificate and the file itself*/
	if(curl_easy_setopt(handle, CURLOPT_CAPATH, TLS_DIR) != CURLE_OK || curl_easy_setopt(handle, CURLOPT_CAINFO, AMF_TLS_CRT) != CURLE_OK)
	{
		goto err;
	}

	/*Set callback functions for getting response data*/
	if(curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, getHTTPHeaderResponse) != CURLE_OK) /*is called for every HTTP/2 header field*/
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_HEADERDATA, &root) != CURLE_OK)
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, getHTTPResponse) != CURLE_OK)
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res) != CURLE_OK)
	{
		goto err;
	}

again:
	/*Send HTTP/2 request to AMF*/
	if((i=curl_easy_perform(handle)) != CURLE_OK)
	{
		if(retry)
		{
			retry--;
			goto again;
		}
		goto err;
	}
	free(body);
	body = 0;

	/*
	 * Checking response data:
	 *
	 * (I) Header data
	 * (II) Response body
	 */
	if(root)
	{
		for(i = 1, entry = root->first; entry != NULL ; entry = root->first, i++)
		{
			switch (i)
			{
				/*Status Code*/
				case 1:
					if((body = strdup(entry->data)) == NULL)
					{
						goto err;
					}
					tmp = body;
					for(token = strtok(tmp, " "), j = 0; token != NULL; token = strtok(NULL, " "), j++)
					{
						if(token)
						{
							if(!j && strstr(token, "HTTP/2") != token)
							{
								goto err;
							}
							else if(j == 1 && (status = atoi(token)) == 0)
							{
								goto err;
							}
							else if(j > 1)
							{
								goto err;
							}
						}
					}

					/*Break, if a certain error code is returned*/
					if(status == 501 || status == 413 || status == 415 || status == 204)
					{
						if(root->cnt > 1)
						{
							goto err;
						}
						goto hbody;
					}

					/*Free list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}

					break;

				/*Further possible header fields*/
				case 2:
				case 3:
				case 4:
				case 5:
					if(strstr(entry->data, "content-type: ") == entry->data && strlen(entry->data) > strlen("content-type: ") + 1)
					{
						tmp = entry->data + strlen("content-type: ");

						/*Content-Type depends on the received HTTP error code*/
						if((status >= 400 && strcmp(tmp, "application/problem+json") != 0) || (status < 400 && strcmp(tmp, "application/json") != 0))
						{
							goto err;
						}
					}
					else if(strstr(entry->data, "content-length: ") == entry->data && strlen(entry->data) > strlen("content-length: ") + 1)
					{
						if(atoi(entry->data + strlen("content-length: ")) == 0)
						{
							goto err;
						}
					}

					/*
					 * Location field could be available: 3GPP TS 29.518, 6.1.3.4.3.1
					 */
					else if((status == 307 || status == 308) && strstr(entry->data, "location: ") == entry->data)
					{
						/*TODO: implementation is open*/
					}

					/*
					 * Custom header field could be available: 3gpp-Sbi-Target-Nf-Id -> see: 3GPP TS 29.518, 6.1.3.4.3.1
					 */
					else if((status == 307 || status == 308) && strstr(entry->data, "3gpp-Sbi-Target-Nf-Id: ") == entry->data)
					{
						/*TODO: implementation is open*/
					}
					
					else
					{
						goto err;
					}
					
					/*Delete list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}
					
					break;

				default:
					/*Delete list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}
					break;
			}
		}
	}

hbody:
	if(body)
	{
		free(body);
		body = 0;
	}

	/*
	 * Interpretation of HTTP response body depending on the HTTP response code
	 *
	 * according to: 3GPP TS 29.518, 6.1.3.4.3.1
	 */
	if(res)
	{
		switch(status)
		{
			/*RedirectResponse structure expected*/
			case 307:
			case 308:
				/*Implementation open*/
				return -1;
				break;

			/*ProblemDetails structure expected*/
			default:
				if((pd = problem_details_parseFromJSON(res)) == NULL)
				{
					goto err;
				}
				printf("[LMF-sbi] N1N2MessageUnsubscribe error (HTTP/2 %d):\n-> Type: %s\n-> Cause: %s\n", status, pd->type, pd->cause);
		}

		cJSON_Delete(res);
		res = 0;
	}

	/*Free memory*/
	if(pd)
	{
		problem_details_free(pd);
	}

	if(root)
	{
		freeHTTPList(root);
	}

	if(hdr)
	{
		curl_slist_free_all(hdr);
	}

	if(handle)
	{
		curl_easy_cleanup(handle);
	}

	if(jbody)
	{
		cJSON_Delete(jbody);
	}

	if(body)
	{
		free(body);
	}

	if(res)
	{
		cJSON_Delete(res);
	}

	if(status != 204)
	{
		return -1;
	}

	return 0;

err:

	if(root)
	{
		freeHTTPList(root);
	}

	if(handle)
	{
		curl_easy_cleanup(handle);
	}

	if(jbody)
	{
		cJSON_Delete(jbody);
	}

	if(body)
	{
		free(body);
	}

	if(hdr)
	{
		curl_slist_free_all(hdr);
	}

	if(res)
	{
		cJSON_Delete(res);
	}

	if(pd)
	{
		problem_details_free(pd);
	}

	return -1;
}



/*
 * Namf_Communication_N1N2MessageTransfer service - send UE specific N1 and N2 data (here: only NRPPa PDUs)
 *
 * @msg: ASN.1 PER encoded NRPPa PDU and its size [B]
 * @nfid: NF ID of this LMF
 * @lcsid: LCS Correlation Identifier
 * @ctx: User Context ID, e.g. IMSI
 *
 * return: 0 on success; -1 otherwise
 *
 * NOTE: Precondition: The LMF has already subscribed to the AMF using the Namf_Communication_N1N2MessageSubscribe service to get the corresponding N2 response data.
 */
int
namf_comm_n1n2msgtransfer(nrppamsg_t *msg, char *nfid, char *lcsid, char *ctx)
{
	/*Variables*/
	CURL *handle = 0;
	struct curl_slist *hdr = 0, *hdr_bin = 0;
	curl_mime *mime = 0;
	curl_mimepart *part = 0;
	char url[BMAX] = {0};
	char *body = 0, *tmp = 0, *token = 0;
	uint16_t status = 0;
	int i, j;
	volatile int retry = 3;

	ngapmsg_t *ngap = 0;

	n1_n2_message_transfer_rsp_data_t *resp = 0;
	n1_n2_message_transfer_req_data_t *req = 0;
	problem_details_t *pd = 0;
	n2_info_container_t *n2 = 0;
	ref_to_binary_data_t *payload = 0;
	cJSON *jbody = 0, *res = 0;

	struct http_list *root = 0;
	struct http_entry *entry = 0;

	/*Check passed input parameters*/
	if(!msg || !msg->enc || !msg->size || !nfid || !lcsid)
	{
		return -1;
	}

	/*Allocate memory for HTTP response header*/
	if((root = calloc(1, sizeof(struct http_list))) == NULL)
	{
		return -1;
	}

	/*Initializing of CURL handle*/
	if((handle = curl_easy_init()) == 0)
	{
		goto err;
	}

	/*Create and set SBI service URL*/
	snprintf(url, BMAX, "https://%s:54321/namf-comm/v1/ue-contexts/%s/n1-n2-messages", AMF_HNAME, ctx);

	if(curl_easy_setopt(handle, CURLOPT_URL, url) != CURLE_OK)
	{
		goto err;
	}

	//curl_easy_setopt(handle, CURLOPT_DNS_CACHE_TIMEOUT, -1);

	/*Initialize and set HTTP header*/
	if((hdr = curl_slist_append(hdr, "Accept: application/json,application/problem+json")) == NULL)
	{
		goto err;
	}

	if((hdr = curl_slist_append(hdr, "Content-Type: multipart/related")) == NULL)
	{
		goto err;
	}

	if((hdr = curl_slist_append(hdr, "User-Agent: LMF-n2msg")) == NULL)
	{
		goto err;
	}
	if(curl_easy_setopt(handle, CURLOPT_HTTPHEADER, hdr) != CURLE_OK)
	{
		goto err;
	}

	/*Generate NGAP IE as a wrapper of the passed NRPPa PDU*/
	if((ngap = (ngapmsg_t*) calloc(1, sizeof(ngapmsg_t))) == NULL)
	{
		goto err;
	}
	createNGAPforNRPPaTransportSBI(msg->enc, msg->size, &ngap->enc, (size_t*) &ngap->size);
	if(!ngap->enc || !ngap->size)
	{
		goto err;
	}
	freeNRPPaMessage(msg);
	msg = 0;

	/*
	 * Creation of N1N2MessageTransferRequestData
	 *
	 * NOTE: nfID in nrppa_information (UUID) corresponds to the Routing ID that is used in AMF to identify the target LMF.
	 *		 It is add to the forwarded NGAP message (3GPP TS 29.518, Table 6.1.6.2.12-1).
	 *
	 * @content_id: ngap-nrppa -> is used as a cross-reference between JSON object and encoded PDU (see 3GPP TS 29.518, 6.1.2.4).
	 */
	if((payload = calloc(1, sizeof(ref_to_binary_data_t))) == NULL || (payload->content_id = (char*) calloc(strlen("ngap-nrppa")+1, sizeof(char))) == NULL)
	{
		goto err;
	}
	strncpy(payload->content_id, "ngap-nrppa", strlen("ngap-nrppa"));

	if((req = n1_n2_message_transfer_req_data_create(NULL, n2_info_container_create(n2_information_class_NRPPa, 0, 0, nrppa_information_create(strdup(nfid), n2_info_content_create(false, 0, ngap_ie_type_NRPPA_PDU, payload), NULL), 0, 0, 0, 0, 0, 0), NULL, false, 0, false, 0, false, 0, strdup(lcsid), false, 0, NULL, false, 0, NULL, false, 0, NULL, NULL, NULL, false, 0, false, 0, access_type_NULL, NULL, n1_n2_message_transfer_req_data_PRUIND_NULL)) == NULL)
	{
		goto err;
	}

	/*Convert N1N2MessageTransferRequestData to JSON -> string*/
	if((jbody = n1_n2_message_transfer_req_data_convertToJSON(req)) == NULL)
	{
		goto err;
	}
	n1_n2_message_transfer_req_data_free(req);
	req = 0;

	if((body = cJSON_Print(jbody)) == NULL)
	{
		goto err;
	}
	cJSON_Delete(jbody);
	jbody = 0;

	/*
	 * Multipart body
	 *
	 * According to 3GPP TS 29.518, 6.1.2.2.2:
	 * (1) JSON N2 container
	 * (2) ASN.1 PER encoded NRPPa PDU with Content-Type: vnd.3gpp.ngap
	 */
	if((mime = curl_mime_init(handle)) == NULL)
	{
		goto err;
	}

	/*(1) JSON N2 message*/
	if((part = curl_mime_addpart(mime)) == NULL || curl_mime_type(part, "application/json") != CURLE_OK)
	{
		goto err;
	}

	if(curl_mime_data(part, body, CURL_ZERO_TERMINATED) != CURLE_OK)
	{
		goto err;
	}

	/*
	 * (2) Encoded "NGAP" NRPPa PDU
	 *
	 * - add header data -> cross reference to JSON member -> content_id
	 * - add binary data (NGAP NRPPa PDU)
	 */
	if((part = curl_mime_addpart(mime)) == NULL)
	{
		goto err;
	}

	if((hdr_bin = curl_slist_append(hdr_bin, "Content-Id: ngap-nrppa")) == NULL)
	{
		goto err;
	}

	if((hdr_bin = curl_slist_append(hdr_bin, "Content-Type: application/vnd.3gpp.ngap")) == NULL)
	{
		goto err;
	}

	if(curl_mime_headers(part, hdr_bin, 1) != CURLE_OK) /*Header list is freed automatically!*/
	{
		goto err;
	}

	if(curl_mime_data(part, ngap->enc, ngap->size) != CURLE_OK)
	{
		goto err;
	}
	if(curl_easy_setopt(handle, CURLOPT_MIMEPOST, mime) != CURLE_OK)
	{
		goto err;
	}

	/*Add directory of TLS certificate and the file itself*/
	if(curl_easy_setopt(handle, CURLOPT_CAPATH, TLS_DIR) != CURLE_OK || curl_easy_setopt(handle, CURLOPT_CAINFO, AMF_TLS_CRT) != CURLE_OK)
	{
		goto err;
	}

	/*Set callback functions for getting response data*/
	if(curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, getHTTPHeaderResponse) != CURLE_OK) /*is called for every HTTP/2 header field*/
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_HEADERDATA, &root) != CURLE_OK)
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, getHTTPResponse) != CURLE_OK)
	{
		goto err;
	}

	if(curl_easy_setopt(handle, CURLOPT_WRITEDATA, &res) != CURLE_OK)
	{
		goto err;
	}

again:
	/*Send HTTP/2 request to AMF*/
	//curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);
	if((i=curl_easy_perform(handle)) != CURLE_OK)
	{
		if(retry)
		{
			retry--;
			goto again;
		}
		goto err;
	}

	/*Free memory of request data structures*/
	free(body);
	body = 0;
	curl_easy_cleanup(handle);
	handle = 0;
	curl_mime_free(mime);
	mime = 0;
	curl_slist_free_all(hdr);
	hdr = 0;
	freeNGAPMessage(ngap);
	ngap = 0;

	/*
	 * Checking response data:
	 *
	 * (I) Header data
	 * (II) Response body
	 */
	if(root)
	{
		for(i = 1, entry = root->first; entry != NULL ; entry = root->first, i++)
		{
			switch (i)
			{
				/*Status Code*/
				case 1:
					if((body = strdup(entry->data)) == NULL)
					{
						goto err;
					}
					tmp = body;
					for(token = strtok(tmp, " "), j = 0; token != NULL; token = strtok(NULL, " "), j++)
					{
						if(token)
						{
							if(!j && strstr(token, "HTTP/2") != token)
							{
								goto err;
							}
							else if(j == 1 && (status = atoi(token)) == 0)
							{
								goto err;
							}
							else if(j > 1)
							{
								goto err;
							}
						}
					}

					/*Break, if a certain error code is returned*/
					if(status == 501 || status == 413 || status == 415)
					{
						if(root->cnt > 1)
						{
							goto err;
						}
						goto hbody;
					}

					/*Free list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}

					break;

				/*Further possible header fields*/
				case 2:
				case 3:
				case 4:
				case 5:
					if(strstr(entry->data, "content-type: ") == entry->data && strlen(entry->data) > strlen("content-type: ") + 1)
					{
						tmp = entry->data + strlen("content-type: ");

						/*Content-Type depends on the received HTTP error code*/
						if((status >= 400 && strcmp(tmp, "application/problem+json") != 0) || (status < 400 && strcmp(tmp, "application/json") != 0))
						{
							goto err;
						}
					}
					else if(strstr(entry->data, "content-length: ") == entry->data && strlen(entry->data) > strlen("content-length: ") + 1)
					{
						if(atoi(entry->data + strlen("content-length: ")) == 0)
						{
							goto err;
						}
					}

					/*
					 * Location field could be available: 3GPP TS 29.518, 6.1.3.5.3.1
					 */
					else if((status == 202 || status == 307 || status == 308) && strstr(entry->data, "location: ") == entry->data)
					{
						/*TODO: implementation is open*/
					}

					/*
					 * Custom header field could be available: 3gpp-Sbi-Target-Nf-Id -> see: 3GPP TS 29.518, 6.1.3.5.3.1
					 */
					else if((status == 307 || status == 308) && strstr(entry->data, "3gpp-Sbi-Target-Nf-Id: ") == entry->data)
					{
						/*TODO: implementation is open*/
					}
					
					else
					{
						goto err;
					}
					
					/*Delete list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}
					
					break;

				default:
					/*Delete list element*/
					if(root->cnt > 1)
					{
						root->first = entry->next;
						root->cnt--;
						free(entry);
					}
					else
					{
						free(entry);
						root->first = 0;
						root->last = 0;
						root->cnt = 0;
					}
					break;
			}
		}
	}
	
hbody:

	if(body)
	{
		free(body);
		body = 0;
	}

	/*
	 * Interpretation of HTTP response body depending on the HTTP response code
	 *
	 * according to: 3GPP TS 29.518, 6.1.3.5.3.1
	 */
	if(res)
	{
		switch(status)
		{
			/*N1N2MessageTransferRspData structure expected*/
			case 200:
			case 202:
				if((resp = n1_n2_message_transfer_rsp_data_parseFromJSON(res)) == NULL)
				{
					goto err;
				}
#ifndef RESEARCH
				printf("[LMF-sbi] N1N2MessageTransfer (NF: %s) was successfully executed: %s\n", nfid, n1_n2_message_transfer_cause_ToString(resp->cause));
#endif
				break;

			/*RedirectResponse structure expected*/
			case 307:
			case 308:
				/*Implementation open*/
				return -1;
				break;

			/*N1N2MessageTransferError structure expected*/
			case 409:
			case 504:
				/*TODO: Implementation open*/
				break;

			/*ProblemDetails structure expected*/
			default:
				if((pd = problem_details_parseFromJSON(res)) == NULL)
				{
					goto err;
				}
				printf("[LMF-sbi] N1N2MessageTransfer (NF: %s) error (HTTP/2 %d):\n-> Type: %s\n-> Cause: %s\n", nfid, status, pd->type, pd->cause);
		}
		
		cJSON_Delete(res);
		res = 0;
	}

	/*Free memory*/
	if(pd)
	{
		problem_details_free(pd);
	}

	if(root)
	{
		freeHTTPList(root);
	}

	if(msg)
	{
		freeNRPPaMessage(msg);
	}

	if(req)
	{
		n1_n2_message_transfer_req_data_free(req);
	}

	if(ngap)
	{
		freeNGAPMessage(ngap);
	}

	if(hdr)
	{
		curl_slist_free_all(hdr);
	}

	if(handle)
	{
		curl_easy_cleanup(handle);
	}

	if(jbody)
	{
		cJSON_Delete(jbody);
	}

	if(body)
	{
		free(body);
	}

	if(res)
	{
		cJSON_Delete(res);
	}

	if(status != 200 && status != 202)
	{
		return -1;
	}

	return 0;

err:
	if(msg)
	{
		freeNRPPaMessage(msg);
	}

	if(req)
	{
		n1_n2_message_transfer_req_data_free(req);
	}

	if(ngap)
	{
		freeNGAPMessage(ngap);
	}

	if(root)
	{
		freeHTTPList(root);
	}

	if(hdr)
	{
		curl_slist_free_all(hdr);
	}

	if(handle)
	{
		curl_easy_cleanup(handle);
	}

	if(jbody)
	{
		cJSON_Delete(jbody);
	}
	if(body)
	{
		free(body);
	}

	if(res)
	{
		cJSON_Delete(res);
	}

	if(pd)
	{
		problem_details_free(pd);
	}

	return -1;
}

