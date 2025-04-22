#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "LocationMeasureAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// PRU location measurement
//
loc_measurement_resp_t *LocationMeasureAPI_locationMeasure(
	apiClient_t *apiClient, loc_measurement_req_t *loc_measurement_req) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/measure-location") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath, "/measure-location");




	// Body Param
	cJSON *localVarSingleItemJSON_loc_measurement_req = NULL;
	if(loc_measurement_req != NULL) {
		// string
		localVarSingleItemJSON_loc_measurement_req =
			loc_measurement_req_convertToJSON(loc_measurement_req);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_loc_measurement_req);
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
	// if (apiClient->response_code == 200) {
	// printf("%s\n","Expected response to a valid request");
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
	// nonprimitive not container
	cJSON *LocationMeasureAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	loc_measurement_resp_t *elementToReturn =
		loc_measurement_resp_parseFromJSON(
			LocationMeasureAPIlocalVarJSON);
	cJSON_Delete(LocationMeasureAPIlocalVarJSON);
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
	if(localVarSingleItemJSON_loc_measurement_req) {
		cJSON_Delete(localVarSingleItemJSON_loc_measurement_req);
		localVarSingleItemJSON_loc_measurement_req = NULL;
	}
	free(localVarBodyParameters);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}
