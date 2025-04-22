#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "NonUEN2MessagesSubscriptionsCollectionCollectionAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// Namf_Communication Non UE N2 Info Subscribe service Operation
//
non_ue_n2_info_subscription_created_data_t *
NonUEN2MessagesSubscriptionsCollectionCollectionAPI_nonUeN2InfoSubscribe(
	apiClient_t					*apiClient,
	non_ue_n2_info_subscription_create_data_t	*non_ue_n2_info_subscription_create_data)
{
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/non-ue-n2-messages/subscriptions") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath, "/non-ue-n2-messages/subscriptions");




	// Body Param
	cJSON *localVarSingleItemJSON_non_ue_n2_info_subscription_create_data =
		NULL;
	if(non_ue_n2_info_subscription_create_data != NULL) {
		// string
		localVarSingleItemJSON_non_ue_n2_info_subscription_create_data =
			non_ue_n2_info_subscription_create_data_convertToJSON(
				non_ue_n2_info_subscription_create_data);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_non_ue_n2_info_subscription_create_data);
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
	// if (apiClient->response_code == 201) {
	// printf("%s\n","Non UE N2 Info Subscription successfully created.");
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
	// if (apiClient->response_code == 0) {
	// printf("%s\n","Unexpected error");
	// }
	// nonprimitive not container
	cJSON *NonUEN2MessagesSubscriptionsCollectionCollectionAPIlocalVarJSON =
		cJSON_Parse(apiClient->dataReceived);
	non_ue_n2_info_subscription_created_data_t *elementToReturn =
		non_ue_n2_info_subscription_created_data_parseFromJSON(
			NonUEN2MessagesSubscriptionsCollectionCollectionAPIlocalVarJSON);
	cJSON_Delete(
		NonUEN2MessagesSubscriptionsCollectionCollectionAPIlocalVarJSON);
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
	if(localVarSingleItemJSON_non_ue_n2_info_subscription_create_data) {
		cJSON_Delete(
			localVarSingleItemJSON_non_ue_n2_info_subscription_create_data);
		localVarSingleItemJSON_non_ue_n2_info_subscription_create_data =
			NULL;
	}
	free(localVarBodyParameters);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}
