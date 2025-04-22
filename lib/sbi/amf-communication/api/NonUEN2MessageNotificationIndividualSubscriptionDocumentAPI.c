#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// Namf_Communication Non UE N2 Info UnSubscribe service Operation
//
void
NonUEN2MessageNotificationIndividualSubscriptionDocumentAPI_nonUeN2InfoUnSubscribe(
	apiClient_t *apiClient, char *n2NotifySubscriptionId) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = NULL;
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen(
		"/non-ue-n2-messages/subscriptions/{n2NotifySubscriptionId}") +
	                  1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/non-ue-n2-messages/subscriptions/{n2NotifySubscriptionId}");


	// Path Params
	long sizeOfPathParams_n2NotifySubscriptionId = strlen(
		n2NotifySubscriptionId) + 3 + strlen(
		"{ n2NotifySubscriptionId }");
	if(n2NotifySubscriptionId == NULL) {
		goto end;
	}
	char *localVarToReplace_n2NotifySubscriptionId = malloc(
		sizeOfPathParams_n2NotifySubscriptionId);
	sprintf(localVarToReplace_n2NotifySubscriptionId, "{%s}",
	        "n2NotifySubscriptionId");

	localVarPath = strReplace(localVarPath,
	                          localVarToReplace_n2NotifySubscriptionId,
	                          n2NotifySubscriptionId);


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
	// printf("%s\n","Non UE N2 INfo Subscription successfully removed.");
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
	free(localVarToReplace_n2NotifySubscriptionId);
}
