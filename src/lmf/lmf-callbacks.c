#include <http2/nghttp2srv.h>
#include "lmfd.h"
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
		case 403:
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

/*
 * on_request_receive - evaluate client HTTP request URL and select SBI service function
 */
static int
on_request_recv(nghttp2_session *session, http2_session_data *session_data, http2_stream_data *stream_data)
{
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

	/*
	 * Parse requested Nlmf SBI Service URL and select service handler function
	 *
	 * @LMF_NLMF_LOC: Nlmf_Location Service ("/nlmf-loc/v1")
	 * @LMF_NLMF_BCAST: Nlmf_Broadcast Service ("/nlmf-broadcast/v1")
	 */
	if(strstr(stream_data->request_path, LMF_NLMF_LOC) == stream_data->request_path)
	{
		/*Check 3: Check requested API version*/
		if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC) - 2, "v1") != stream_data->request_path + strlen(LMF_NLMF_LOC) - 2)
		{
			/*HTTP error code 400, with included ProblemDetails.cause = INVALID_API , TS 29.500, 5.2.7.2*/
			if(error_response(session, stream_data, 400, HTTP_400_INVAPI) != 0)
			{
					goto err;
			}
							
			return 0;
		}
	 	
	 	/*
	     * (1) DetermineLocation
	 	 *
	 	 * 3GPP TS 29.572, 5.2.2.2
	 	 *
	 	 * /nlmf-loc/v1/determine-location
	 	 */
		if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC), "/determine-location") == stream_data->request_path + strlen(LMF_NLMF_LOC))
		{
			/*Increase thread pool size and start migration due to long service time*/
			pthpool_t *old = session_data->app_ctx->tpool[0];
			if(!pthpool_inc_size(old, 1))
			{
				printf("[LMF-sbi] No thread(s) couldn't be added to thread pool %p\n", session_data->app_ctx->tpool);
				goto err;
			}

			else if(!pthpool_migrate(session_data->app_ctx->tpool, tpool_ue))
			{
				printf("[LMF-sbi] Current thread couldn't be migrated: %p -> %p\n", session_data->app_ctx->tpool, tpool_ue);
				goto err;
			}

#ifndef RESEARCH
			printf("[LMF-sbi] Thread pool migration successfully completed\n");
#endif
			/*Run SBI service handler function*/
			if(nlmf_loc_determineLocation(session, stream_data) != 0)
			{
				goto err;
			}
		}
		
		/*
	 	 * (2) CancelLocation  
	 	 *
	 	 * 3GPP TS 29.572, 5.2.2.4
	 	 *
	 	 * /nlmf-loc/v1/cancel-location
	 	 */
		else if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC), "/cancel-location") == stream_data->request_path + strlen(LMF_NLMF_LOC))
		{
			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}		
		}
		
		/*
	 	 * (3) LocationContextTransfer
	 	 *
	 	 * 3GPP TS 29.572, 5.2.2.5
	 	 *
	 	 * /nlmf-loc/v1/location-context-transfer
	 	 */
		else if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC), "/location-context-transfer") == stream_data->request_path + strlen(LMF_NLMF_LOC))
		{
			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}		
		}
	
		
		/*
	 	 * (4) MeasurementData
	 	 *
	 	 * 3GPP TS 29.572, 5.2.2.6
	 	 *
	 	 * /nlmf-loc/v1/measure-location
	 	 */
		else if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC), "/measure-location") == stream_data->request_path + strlen(LMF_NLMF_LOC))
		{
			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}		
		}

		/*
	 	 * (5) UPConfig
	 	 *
	 	 * 3GPP TS 29.572, 5.2.2.9
	 	 *
	 	 * /nlmf-loc/v1/configure-up
	 	 */
		else if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC), "/configure-up") == stream_data->request_path + strlen(LMF_NLMF_LOC))
		{
			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}		
		}

		/*
	 	 * (6) UPSubscribe
	 	 *
	 	 * 3GPP TS 29.572, 5.2.2.7
	 	 *
	 	 * /nlmf-loc/v1/up-subscriptions
	 	 */
		else if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC), "/up-subscriptions") == stream_data->request_path + strlen(LMF_NLMF_LOC))
		{
			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}		
		}

		/*
	 	 * (7) UPSubscribe
	 	 *
	 	 * 3GPP TS 29.572, 5.2.2.7
	 	 *
	 	 * /nlmf-loc/v1/up-subscriptions/{subscriptionID}
	 	 */
		else if(strstr(stream_data->request_path + strlen(LMF_NLMF_LOC), "/up-subscriptions/") == stream_data->request_path + strlen(LMF_NLMF_LOC))
		{
			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}		
		}

		else
		{
			/*HTTP error code 400 BAD REQUEST: Invalid API*/
			if(error_response(session, stream_data, 400, HTTP_400_INVAPI) != 0)
			{
				goto err;
			}
			return 0;
		}
	}

	else if(strstr(stream_data->request_path, LMF_NLMF_BCAST) == stream_data->request_path)
	{
		/*Check 3: Check requested API version*/
		if(strstr(stream_data->request_path + strlen(LMF_NLMF_BCAST) - 2, "v1") != stream_data->request_path + strlen(LMF_NLMF_BCAST) - 2)
		{
			/*HTTP error code 400, with included ProblemDetails.cause = INVALID_API , TS 29.500, 5.2.7.2*/
			if(error_response(session, stream_data, 400, HTTP_400_INVAPI) != 0)
			{
					goto err;
			}
							
			return 0;
		}

		/*
	 	 * (1) CipheringKeyData
	 	 *
	 	 * 3GPP TS 29.572, 5.3.2.2
	 	 *
	 	 * /nlmf-broadcast/v1/cipher-key-data
	 	 */
		if(strstr(stream_data->request_path + strlen(LMF_NLMF_BCAST), "/cipher-key-data") == stream_data->request_path + strlen(LMF_NLMF_BCAST))
		{
			
		}
		else
		{
			/*TODO: HTTP error code: 501 NOT IMPLEMENTED*/
			if(error_response(session, stream_data, 501, NULL) != 0)
			{
				goto err;
			}
		}
	}

	/*
	 * LMF Notify Callback URI for AMF Notifications
	 */
	else if(strstr(stream_data->request_path, "/n2-ue-messages") == stream_data->request_path)
	{
		/*
		 * N2InfoNotify
		 */
		if(namf_comm_N2InfoNotify(session, stream_data) != 0)
		{
			goto err;
		}
	}

	else if(strstr(stream_data->request_path, "/n2-nonue-messages") == stream_data->request_path)
	{
		/*
		 * NonUeN2InfoNotify
		 */
		printf("[LMF-sbi] Handler for Non UE N2 notifications selected\n");
	}

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
