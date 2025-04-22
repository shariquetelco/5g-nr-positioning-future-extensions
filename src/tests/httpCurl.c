#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

/*SBI HTTP Client API*/
#include <api/N1N2MessageCollectionCollectionAPI.h>

#include <nrppa/nrppa_create.h>
#include <ngap/ngap_create.h>

/*
 * Custom header fields for Namf_Communication service: No. (3GPP TS 29.518, 6.1.2.3)
 * UE context ID pattern: 3GPP TS 29.518, 6.1.3.5.2
 * HTTP Request Body: 29.518, 6.1.3.5.3.1 -> here: N2 Information
 * HTTP Response Body: 29.518, 6.1.3.5.3.2 -> here: N2 Response Data structure
 */
#define SBI_NAMF_COMM "https://amfd.5gc:54321/namf-comm/v1/ue-contexts/imsi-001010003201001/n1-n2-messages"
//#define SBI_NAMF_COMM "https://amfd.5gc:54321/namf-comm/v1/ue-contexts/imsi-001010003201001/n1-n2-messages/subscriptions"

/*
 * http_list - linked list to store HTTP header fields from a HTTP/2 response
 */
struct http_list
{
	struct http_entry *first, *last;
	uint64_t cnt;
};

struct http_entry
{
	char *data;
	struct http_entry *next;
};

struct http_hdr
{
	uint32_t status;
	char *ctype;
	uint64_t clen;
	char *loc;
	char *custom_nfid;
};

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

int
main()
{
	CURL *handle = 0;
	curl_mime *mime = 0;
	curl_mimepart *part = 0;
	struct curl_slist *hdr = 0, *hdr_bin = 0;
	struct http_list *root = 0;
	struct http_entry *entry = 0;
	struct http_hdr header;

	ssize_t size[2] = {0};
	uint8_t *nrppa[2] = {0};
	uint8_t rid[16];
	char *hdr_data = 0, *tmp = 0, *token = 0;
	int i = 0, j = 0;

	n1_n2_message_transfer_rsp_data_t *resp = 0;
	n1_n2_message_transfer_req_data_t *req = 0;
	problem_details_t *pd = 0;
	n2_info_container_t *n2 = 0;
	ref_to_binary_data_t payload;
	char *lcsid = 0;
	cJSON *n2data = 0;

	/*libcurl initialization*/
	if((handle = curl_easy_init()) == 0)
	{
		perror("curl_easy_ini()");
		return EXIT_FAILURE;
	}

	/*header generation - main*/
	curl_easy_setopt(handle, CURLOPT_URL, SBI_NAMF_COMM);
	hdr = curl_slist_append(hdr, "Accept: application/json,application/problem+json");
	hdr = curl_slist_append(hdr, "Content-Type: multipart/related");
	hdr = curl_slist_append(hdr, "User-Agent: LMF-n2msg");
	curl_easy_setopt(handle, CURLOPT_HTTPHEADER, hdr);

	/*NRPPa PDU generation*/
	NRPPa_ECID_Measurement_Termination(12345,54333,43535, nrppa, size);
	if(!nrppa[0] || !size[0])
	{
		printf("NRPPa_ECID_Measurement_Initiation_Request()\n");
		goto err;
	}

	/*Generate NGAP "IE" as a wrapper for the NRPPa PDU*/
	createNGAPforNRPPaTransportSBI(nrppa[0], size[0], nrppa+1, size+1);
	if(!nrppa[1] || !size[1])
	{
		printf("createNGAPforNRPPaTransport()\n");
		goto err;
	}

	/*
	 * Creation of a N2 container
	 *
	 * NOTE: Enumeration values/initialization values are described in 3GPP TS 29.518, 6.1.6
	 * NOTE: nfID in nrppa_information (UUID) corresponds to the Routing ID that is used in AMF to identify the target LMF. It is add to the forwarded NGAP message! (3GPP TS 29.518, Table 6.1.6.2.12-1)
	 *
	 * @content_id: ngap-nrppa -> is used for a cross-reference between JSON object and encoded PDU (see 3GPP TS 29.518, 6.1.2.4)
	 */
	explicit_bzero(&payload, sizeof(payload));
	payload.content_id = (char*) calloc(strlen("ngap-nrppa")+1, sizeof(char));
	strncpy(payload.content_id, "ngap-nrppa", strlen("ngap-nrppa"));

	if((n2 = n2_info_container_create(n2_information_class_NRPPa, 0, 0, nrppa_information_create("3a552bca-988e-21aa-f3f4-197cd5ea7633", n2_info_content_create(false, 0, ngap_ie_type_NRPPA_PDU, &payload), NULL), 0, 0, 0, 0, 0, 0)) == 0)
	{
		perror("n2_info_container_create()");
		goto err;
	}

	/*
	 * Creation of N1N2MessageTransferRequestData
	 *
	 * According to 3GPP TS 29.518, 6.1.6.2.18
	 */
	lcsid = (char*) calloc(strlen("12345")+1, sizeof(char)); /*LCS Correlation ID: see 3GPP TS 29.572, 6.1.6.3.2*/
	strcpy(lcsid, "12345");
	req = n1_n2_message_transfer_req_data_create(NULL, n2, NULL, false, 0, false, 0, false, 0, lcsid, false, 0, NULL, false, 0, NULL, false, 0, NULL, NULL, NULL, false, 0, false, 0, access_type_NULL, NULL, n1_n2_message_transfer_req_data_PRUIND_NULL);

	/*Convert N2 data to JSON*/
	n2data = n1_n2_message_transfer_req_data_convertToJSON(req);

	/*
	 * Multipart body
	 *
	 * According to 3GPP TS 29.518, 6.1.2.2.2:
	 * (1) JSON N2 container
	 * (2) ASN.1 PER encoded NRPPa PDU -> content type: vnd.3gpp.ngap
	 */
	if((mime = curl_mime_init(handle)) == NULL)
	{
		perror("curl_mime_init()");
		goto err;
	}

	/*(1) JSON N2 message*/
	part = curl_mime_addpart(mime);
	if(curl_mime_type(part, "application/json") != CURLE_OK)
	{
		perror("curl_mime_type()");
		goto err;
	}
	if(curl_mime_data(part, cJSON_Print(n2data), CURL_ZERO_TERMINATED) != CURLE_OK)
	{
		perror("curl_mime_data()");
		goto err;
	}
	free(n2data);
	n2data = 0;

	/*
	 * (2) Encoded "NGAP" NRPPa PDU
	 *
	 * - add header data -> cross reference to JSON member -> content_id
	 * - add binary data (NGAP NRPPa PDU)
	 */
	if((part = curl_mime_addpart(mime)) == NULL)
	{
		perror("curl_mime_addpaert()");
		goto err;
	}

	hdr_bin = curl_slist_append(hdr_bin, "Content-Id: ngap-nrppa");
	hdr_bin = curl_slist_append(hdr_bin, "Content-Type: application/vnd.3gpp.ngap");
	if(curl_mime_headers(part, hdr_bin, 1) != CURLE_OK)
	{
		perror("curl_mime_headers()");
		goto err;
	}

	if(curl_mime_data(part, nrppa[1], size[1]) != CURLE_OK)
	{
		perror("curl_mime_data()");
		goto err;
	}

	/*Add data to request*/
	curl_easy_setopt(handle, CURLOPT_MIMEPOST, mime);
	//curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L); // debug

	/*Add directory of TLS certificate and the file itself*/
	curl_easy_setopt(handle, CURLOPT_CAPATH, "../tls/");
	curl_easy_setopt(handle, CURLOPT_CAINFO, "../tls/amf.crt");

	/*Set callback function and the target buffer for obtaining the response data*/
	if((root = calloc(1, sizeof(struct http_list))) == NULL)
	{
		goto err;
	}

	curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, getHTTPHeaderResponse); //Will called for every HTTP/2 header field
	curl_easy_setopt(handle, CURLOPT_HEADERDATA, &root);
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, getHTTPResponse);
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, &n2data);

	/*Send HTTP data*/
	if(curl_easy_perform(handle) != CURLE_OK)
	{
		printf("curl_easy_perform()\n");
		goto err;
	}

	/*
	 * Checking response data:
	 *
	 * (I) Header data
	 * (II) Response body -> Body data is returned for the N1N2MessageTransfer service (see 3GPP TS 29.518, 6.1.3.5.3.1) in most cases (except 501 NOT IMPLEMENTED, 415 UNSUPPORTED MEDIA TYPE)!
	 */

	if(root)
	{
		explicit_bzero(&header, sizeof(header));
		for(i = 1, entry = root->first; entry != NULL ; entry = root->first, i++)
		{
			switch (i)
			{
				/*Status Code*/
				case 1:
					if((hdr_data = strdup(entry->data)) == NULL)
					{
						goto err;
					}
					tmp = hdr_data;
					for(token = strtok(tmp, " "), j = 0; token != NULL; token = strtok(NULL, " "), j++)
					{
						if(token)
						{
							if(!j && strstr(token, "HTTP/2") != token)
							{
								printf("Invalid HTTP status identifier\n");
								free(hdr_data);
								goto err;
							}
							else if(j == 1 && (header.status = atoi(token)) == 0)
							{
								printf("Invalid HTTP response code\n");
								free(hdr_data);
								goto err;
							}
							else if(j > 1)
							{
								printf("Invalid HTTP status field %s\n", token);
								free(hdr_data);
								goto err;
							}
						}
					}
					
					printf("HTTP/2 Response Code: %d\n", header.status);
					free(hdr_data);
					
					/*Break, if a certain error code is returned*/
					if(header.status == 501 || header.status == 413 || header.status == 415)
					{
						if(root->cnt > 1)
						{
							printf("Too many header fields!");
						}
						goto err;
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
						if((header.status >= 400 && strcmp(tmp, "application/problem+json") != 0) || (header.status < 400 && strcmp(tmp, "application/json") != 0))
						{
							printf("Content-Type is invalid!\n");
							goto err;
						}
					}
					else if(strstr(entry->data, "content-length: ") == entry->data && strlen(entry->data) > strlen("content-length: ") + 1)
					{
						if((header.clen = atoi(entry->data + strlen("content-length: "))) == 0)
						{
							printf("Content-Length is invalid!\n");
							goto err;
						}
					}

					/*
					 * Location field could be available: 3GPP TS 29.518, 6.1.3.5.3.1
					 */
					else if((header.status == 202 || header.status == 307 || header.status == 308) && strstr(entry->data, "location: ") == entry->data)
					{
						/*TODO: implementation is open*/
					}

					/*
					 * Custom header field could be available: 3gpp-Sbi-Target-Nf-Id -> see: 3GPP TS 29.518, 6.1.3.5.3.1
					 */
					else if((header.status == 307 || header.status == 308) && strstr(entry->data, "3gpp-Sbi-Target-Nf-Id: ") == entry->data)
					{
						/*TODO: implementation is open*/
					}
					
					else
					{
						printf("Header field %s is not expected!\n", entry->data);
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

	/*
	 * Interpretation of HTTP response body depending on the HTTP response code
	 *
	 * according to: 3GPP TS 29.518, 6.1.3.5.3.1
	 */
	if(n2data)
	{
		switch(header.status)
		{
			/*N1N2MessageTransferRspData structure expected*/
			case 200:
			case 202:
				if((resp = n1_n2_message_transfer_rsp_data_parseFromJSON(n2data)) == NULL)
				{
					printf("N1N2MessageTransferResponseData couldn't be parsed from JSON...\n");
					goto err;
				}
				
				printf("N1N2Message Response:\nCause: %s\nSupported Features: %s\n", n1_n2_message_transfer_cause_ToString(resp->cause), resp->supported_features);
				break;
			
			/*RedirectResponse structure expected*/
			case 307:
			case 308:
				/*TODO: Implementation open*/
				break;
			
			/*N1N2MessageTransferError structure expected*/
			case 409:
			case 504:
				/*TODO: Implementation open*/
				break;
			
			/*ProblemDetails structure expected*/
			default:
				if((pd = problem_details_parseFromJSON(n2data)) == NULL)
				{
					printf("ProblemDetails couldn't be parsed from JSON...\n");
					goto err;
				}
				printf("ProblemDetails:\nType: %s\nCause: %s\n", pd->type, pd->cause);
		}
	}

fin:
	/*Free memory */
	free(n2data);
	curl_easy_cleanup(handle);
	curl_mime_free(mime);
	curl_slist_free_all(hdr);

	return EXIT_SUCCESS;

err:

	/*TODO: free memory of ALL dynamically allocated data structures*/
	if(n2data)
	{
		free(n2data);
	}
	
	if(handle)
	{
		curl_easy_cleanup(handle);
	}
	
	if(mime)
	{
		curl_mime_free(mime);
	}
	
	if(hdr)
	{
		curl_slist_free_all(hdr);
	}

	return EXIT_FAILURE;

}
