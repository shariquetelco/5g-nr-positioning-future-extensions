#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "CancelLocationAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// request cancellation of periodic or triggered location
//
void CancelLocationAPI_cancelLocation(apiClient_t	*apiClient,
                                      cancel_loc_data_t *cancel_loc_data) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/cancel-location") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath, "/cancel-location");




	// Body Param
	cJSON *localVarSingleItemJSON_cancel_loc_data = NULL;
	if(cancel_loc_data != NULL) {
		// string
		localVarSingleItemJSON_cancel_loc_data =
			cancel_loc_data_convertToJSON(cancel_loc_data);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_cancel_loc_data);
	}
	list_addElement(localVarHeaderType, "application/json"); // produces
	list_addElement(localVarHeaderType, "application/problem+json"); // produces
	list_addElement(localVarContentType, "application/json"); // consumes
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
	// if (apiClient->response_code == 204) {
	// printf("%s\n","Expected response to a successful cancellation");
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
	// printf("%s\n","Generic Error");
	// }
	// No return type
end:
	if(apiClient->dataReceived) {
		free(apiClient->dataReceived);
		apiClient->dataReceived = NULL;
		apiClient->dataReceivedLen = 0;
	}



	list_freeList(localVarHeaderType);
	list_freeList(localVarContentType);
	free(localVarPath);
	if(localVarSingleItemJSON_cancel_loc_data) {
		cJSON_Delete(localVarSingleItemJSON_cancel_loc_data);
		localVarSingleItemJSON_cancel_loc_data = NULL;
	}
	free(localVarBodyParameters);
}
