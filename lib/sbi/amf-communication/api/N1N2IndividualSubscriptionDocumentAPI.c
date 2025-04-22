#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "N1N2IndividualSubscriptionDocumentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// Namf_Communication N1N2 Message UnSubscribe (UE Specific) service Operation
//
void N1N2IndividualSubscriptionDocumentAPI_n1N2MessageUnSubscribe(
	apiClient_t *apiClient, char *ueContextId, char *subscriptionId) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = NULL;
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen(
		"/ue-contexts/{ueContextId}/n1-n2-messages/subscriptions/{subscriptionId}")
	                  + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/n1-n2-messages/subscriptions/{subscriptionId}");


	// Path Params
	long sizeOfPathParams_ueContextId = strlen(ueContextId) + 3 + strlen(
		subscriptionId) + 3 + strlen("{ ueContextId }");
	if(ueContextId == NULL) {
		goto end;
	}
	char *localVarToReplace_ueContextId = malloc(
		sizeOfPathParams_ueContextId);
	sprintf(localVarToReplace_ueContextId, "{%s}", "ueContextId");

	localVarPath = strReplace(localVarPath, localVarToReplace_ueContextId,
	                          ueContextId);

	// Path Params
	long sizeOfPathParams_subscriptionId = strlen(ueContextId) + 3 + strlen(
		subscriptionId) + 3 + strlen("{ subscriptionId }");
	if(subscriptionId == NULL) {
		goto end;
	}
	char *localVarToReplace_subscriptionId = malloc(
		sizeOfPathParams_subscriptionId);
	sprintf(localVarToReplace_subscriptionId, "{%s}", "subscriptionId");

	localVarPath = strReplace(localVarPath,
	                          localVarToReplace_subscriptionId,
	                          subscriptionId);


	list_addElement(localVarHeaderType, "application/json"); // produces
	list_addElement(localVarHeaderType, "application/problem+json"); // produces
	apiClient_invoke(apiClient,
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarHeaderType,
	                 localVarContentType,
	                 localVarBodyParameters,
	                 "DELETE");

	// uncomment below to debug the error response
	// if (apiClient->response_code == 204) {
	// printf("%s\n","N1N2 Message Subscription successfully removed.");
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
	// No return type
end:
	if(apiClient->dataReceived) {
		free(apiClient->dataReceived);
		apiClient->dataReceived = NULL;
		apiClient->dataReceivedLen = 0;
	}



	list_freeList(localVarHeaderType);

	free(localVarPath);
	free(localVarToReplace_ueContextId);
	free(localVarToReplace_subscriptionId);
}
