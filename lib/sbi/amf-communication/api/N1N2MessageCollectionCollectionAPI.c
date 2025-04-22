#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "N1N2MessageCollectionCollectionAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// Namf_Communication N1N2 Message Transfer (UE Specific) service Operation
//
n1_n2_message_transfer_rsp_data_t *
N1N2MessageCollectionCollectionAPI_n1N2MessageTransfer(
	apiClient_t				*apiClient,
	char					*ueContextId,
	n1_n2_message_transfer_req_data_t	*n1_n2_message_transfer_req_data)
{
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}/n1-n2-messages") +
	                  1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/n1-n2-messages");


	// Path Params
	long sizeOfPathParams_ueContextId = strlen(ueContextId) + 3 + strlen(
		"{ ueContextId }");
	if(ueContextId == NULL) {
		goto end;
	}
	char *localVarToReplace_ueContextId = malloc(
		sizeOfPathParams_ueContextId);
	sprintf(localVarToReplace_ueContextId, "{%s}", "ueContextId");

	localVarPath = strReplace(localVarPath, localVarToReplace_ueContextId,
	                          ueContextId);



	// Body Param
	cJSON *localVarSingleItemJSON_n1_n2_message_transfer_req_data = NULL;
	if(n1_n2_message_transfer_req_data != NULL) {
		// string
		localVarSingleItemJSON_n1_n2_message_transfer_req_data =
			n1_n2_message_transfer_req_data_convertToJSON(
				n1_n2_message_transfer_req_data);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_n1_n2_message_transfer_req_data);
	}
	list_addElement(localVarHeaderType, "application/json"); // produces
	list_addElement(localVarHeaderType, "application/problem+json"); // produces
	list_addElement(localVarContentType, "application/json"); // consumes
	list_addElement(localVarContentType, "multipart/related"); // consumes
	apiClient_invoke(apiClient,
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarHeaderType,
	                 localVarContentType,
	                 localVarBodyParameters,
	                 "POST");

	// uncomment below to debug the error response
	// if (apiClient->response_code == 202) {
	// printf("%s\n","N1N2 Message Transfer accepted.");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 200) {
	// printf("%s\n","N1N2 Message Transfer successfully initiated.");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 307) {
	// printf("%s\n","Temporary Redirect");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 308) {
	// printf("%s\n","Permanent Redirect");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 400) {
	// printf("%s\n","Bad request");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 401) {
	// printf("%s\n","Unauthorized");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 403) {
	// printf("%s\n","Forbidden");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 404) {
	// printf("%s\n","Not Found");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 409) {
	// printf("%s\n","Conflicts");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 411) {
	// printf("%s\n","Length Required");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 413) {
	// printf("%s\n","Content Too Large");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 415) {
	// printf("%s\n","Unsupported Media Type");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 429) {
	// printf("%s\n","Too Many Requests");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 500) {
	// printf("%s\n","Internal Server Error");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 502) {
	// printf("%s\n","Bad Gateway");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 503) {
	// printf("%s\n","Service Unavailable");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 504) {
	// printf("%s\n","Gateway Timeout");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 0) {
	// printf("%s\n","Unexpected error");
	// }
	// nonprimitive not container
	cJSON *N1N2MessageCollectionCollectionAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	n1_n2_message_transfer_rsp_data_t *elementToReturn =
		n1_n2_message_transfer_rsp_data_parseFromJSON(
			N1N2MessageCollectionCollectionAPIlocalVarJSON);
	cJSON_Delete(N1N2MessageCollectionCollectionAPIlocalVarJSON);
	if(elementToReturn == NULL) {
		// return 0;
	}

	// return type
	if(apiClient->dataReceived) {
		free(apiClient->dataReceived);
		apiClient->dataReceived = NULL;
		apiClient->dataReceivedLen = 0;
	}



	list_freeList(localVarHeaderType);
	list_freeList(localVarContentType);
	free(localVarPath);
	free(localVarToReplace_ueContextId);
	if(localVarSingleItemJSON_n1_n2_message_transfer_req_data) {
		cJSON_Delete(
			localVarSingleItemJSON_n1_n2_message_transfer_req_data);
		localVarSingleItemJSON_n1_n2_message_transfer_req_data = NULL;
	}
	free(localVarBodyParameters);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}
