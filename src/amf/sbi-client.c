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
 * Namf_Communication_N2InfoNotify service - send UE specific N2 data to the target LMF
 *
 * @msg: NRPPa message structure that contains the ASN.1 PER encoded NRPPA PDU
 * @uri: callback URI that is used by the AMF for N2 message transfer
 * @nfid: NF ID of this LMF
 * @lcsid: LCS Correlation ID
 *
 * return: 0 on success, -1 otherwise
 *
 * NOTE: The passed encoded NRPPa PDU has to be wrapped by the corresponding NGAP IE by using createNGAPforNRPPaTransportSBI() (e.g. see /src/lmf/sbi-client.c).
 */
int
namf_comm_n2InfoNotify(nrppamsg_t *msg, const char *uri, char *nfid, char *lcsid, char *sub_id)
{
	/*Variables*/
	CURL *handle = 0;
	struct curl_slist *hdr = 0, *hdr_bin = 0;
	curl_mime *mime = 0;
	curl_mimepart *part = 0;
	char *body = 0, *tmp = 0, *token = 0;
	uint16_t status = 0;
	int i, j;
	volatile int retry = 5;

	ngapmsg_t *ngap = 0;

	n2_information_notification_t *req = 0;
	problem_details_t *pd = 0;
	guami_t *guami = 0;
	n2_info_container_t *n2 = 0;
	ref_to_binary_data_t *payload = 0;
	cJSON *jbody = 0, *res = 0;

	struct http_list *root = 0;
	struct http_entry *entry = 0;

	/*Check passed input parameter*/
	if(!uri || !nfid || strstr(uri, SBI_LMF_BASE_URI) != uri || !lcsid || !sub_id || !msg)
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

	//curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);

	/*Create and set SBI service URL*/
	if(curl_easy_setopt(handle, CURLOPT_URL, uri) != CURLE_OK)
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

	if((hdr = curl_slist_append(hdr, "User-Agent: AMF-n2msg")) == NULL)
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

	/*Creation of N2InformationNotification structure*/
	if((payload = calloc(1, sizeof(ref_to_binary_data_t))) == NULL || (payload->content_id = strdup("ngap-nrppa")) == NULL)
	{
		goto err;
	}
	/*GUAMI == Global Unique AMF Identifier -> structure of AMFI member: 3GPP TS 23.003, 2.10.1 == 3 B that has to be printed as 6 hex characters.*/
	guami = guami_copy(guami, amf);
	if((req = n2_information_notification_create(strdup(sub_id), n2_info_container_create(n2_information_class_NRPPa, 0, 0, nrppa_information_create(strdup(nfid), n2_info_content_create(false, 0, ngap_ie_type_NRPPA_PDU, payload), NULL), 0, 0, 0, 0, 0, 0), NULL, strdup(lcsid), n2_info_notify_reason_NULL, NULL, NULL, NULL, NULL, NULL, guami, false, 0, NULL)) == NULL)
	{
		goto err;
	}

	/*Convert N2InformationNotification to JSON and then to string*/
	if((jbody = n2_information_notification_convertToJSON(req)) == NULL)
	{
		goto err;
	}
	n2_information_notification_free(req);
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
	if(curl_easy_setopt(handle, CURLOPT_CAPATH, TLS_LMF_CERTDIR) != CURLE_OK || curl_easy_setopt(handle, CURLOPT_CAINFO, TLS_LMF_CERT) != CURLE_OK)
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
	/*Send HTTP/2 request to LMF*/
	if((i=curl_easy_perform(handle)) != CURLE_OK)
	{
		//printf("curl_easy_perform(): %d\n", i);
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
					free(body);
					body = 0;

					/*Break, if a certain error code is returned*/
					if(status == 204)
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
					 * Location field could be available: 3GPP TS 29.518, 6.1.5.5.3.1
					 */
					else if((status == 307 || status == 308) && strstr(entry->data, "location: ") == entry->data)
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

	if(body)
	{
		free(body);
	}

hbody:
	/*
	 * Interpretation of HTTP response body depending on the HTTP response code
	 *
	 * according to: 3GPP TS 29.518, 6.1.5.5.3.1
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
#ifndef RESEARCH
				printf("[AMF-sbi] N2InfoNotify (LMF: %s) error (HTTP/2 %d):\n-> Type: %s\n-> Cause: %s\n", nfid, status, pd->type, pd->cause);
#endif
		}
		cJSON_Delete(res);
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

	if(status != 204)
	{
		return -1;
	}

	return 0;

err:
	/*Free memory*/
	if(msg)
	{
		freeNRPPaMessage(msg);
	}

	if(req)
	{
		n2_information_notification_free(req);
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

/*
 * Nlmf_Location_DetermineLocation service - request the position of a target UE from the LMF
 *
 * TODO: Extend signature of this function so that LPP messages can also included!
 *
 * compliant with: 3GPP TS 29.572, 5.2.2.2
 */
int
nlmf_loc_determineLocation(const char *supi, const char *lcsid, const char *nfid)
{
	/*Variables*/
	CURL *handle = 0;
	struct curl_slist *hdr = 0, *hdr_bin = 0;
	curl_mime *mime = 0;
	curl_mimepart *part = 0;
	char *body = 0, *tmp = 0, *token = 0;
	uint16_t status = 0;
	int i, j;
	volatile int retry = 3;
	char buf[100] = {0};

	input_data_t *req = 0;
	location_data_ext_t *resp = 0;
	problem_details_t *pd = 0;
	cJSON *jbody = 0, *res = 0;

	struct http_list *root = 0;
	struct http_entry *entry = 0;

	/*Check passed input parameter*/
	if(!nfid || !lcsid || !supi)
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

	//curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);

	/*Create and set SBI service URL*/
	snprintf(buf, 99, "https://%s:54321/nlmf-loc/v1/determine-location", LMF_HNAME);

	if(curl_easy_setopt(handle, CURLOPT_URL, buf) != CURLE_OK)
	{
		goto err;
	}

	/*Initialize and set HTTP header*/
	if((hdr = curl_slist_append(hdr, "Accept: application/json,application/problem+json")) == NULL)
	{
		goto err;
	}

	if((hdr = curl_slist_append(hdr, "Content-Type: application/json")) == NULL)	//TODO: If LPP messages can also passed to this function, Content-Type has to be set to multipart/related!
	{
		goto err;
	}

	if((hdr = curl_slist_append(hdr, "User-Agent: AMF-detloc")) == NULL)
	{
		goto err;
	}
	if(curl_easy_setopt(handle, CURLOPT_HTTPHEADER, hdr) != CURLE_OK)
	{
		goto err;
	}

	/*
	 * Creation of InputData JSON object
	 *
	 * Here: For emergency services (LCS Service Type = 0, acc. to 3GPP TS 29.002, 17.7.8) with normal LCS client priority.
	 */
	if((req = input_data_create(external_client_type_EMERGENCY_SERVICES, strdup(lcsid), strdup(AMF_NFID), NULL, NULL, strdup(supi), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, lcs_priority_NORMAL_PRIORITY, velocity_requested_VELOCITY_IS_NOT_REQUESTED,
								NULL, true, 0, ldr_type_NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, ue_location_service_ind_NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false, 0,
								NULL, false, 0, NULL, input_data_UEUNAWAREIND_NULL, false, 0, false, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, false, 0, NULL)) == NULL)
	{
		goto err;
	}

	if((jbody = input_data_convertToJSON(req)) == NULL)
	{
		goto err;
	}
	input_data_free(req);
	req = 0;

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
	if(curl_easy_setopt(handle, CURLOPT_CAPATH, TLS_LMF_CERTDIR) != CURLE_OK || curl_easy_setopt(handle, CURLOPT_CAINFO, TLS_LMF_CERT) != CURLE_OK)
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

	//curl_easy_setopt(handle, CURLOPT_CONNECTTIMEOUT, 3L);
	//curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1L);

again:
	/*Send HTTP/2 request to AMF*/
	//curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);
	if((i = curl_easy_perform(handle)) != CURLE_OK)
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
					 * Location field could be available: 3GPP TS 29.518, 6.1.3.3.3.1
					 */
					else if((status == 307 || status == 308) && strstr(entry->data, "location: ") == entry->data)
					{
						/*TODO: implementation is open*/
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
			/*LocationDataExt expected*/
			case 200:
				if((resp = location_data_ext_parseFromJSON(res)) == NULL)
				{
					goto err;
				}
				printf("[AMF-sbi] DetermineLocation was successfully executed\n");
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
				printf("[AMF-sbi] DetermineLocation error (HTTP/2 %d):\n-> Type: %s\n-> Cause: %s\n", status, pd->type, pd->cause);
		}
	}

	/*Free memory*/
	if(res)
	{
		free(res);
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

	return 0;

err:
	/*Free memory*/
	if(req)
	{
		input_data_free(req);
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

	return -1;
}
