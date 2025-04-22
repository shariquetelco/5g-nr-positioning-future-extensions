#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "IndividualSubscriptionDocumentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// Namf_Communication AMF Status Change Subscribe Modify service Operation
//
subscription_data_t *
IndividualSubscriptionDocumentAPI_aMFStatusChangeSubscribeModfy(
	apiClient_t *apiClient, char *subscriptionId,
	subscription_data_t *subscription_data) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/subscriptions/{subscriptionId}") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath, "/subscriptions/{subscriptionId}");


	// Path Params
	long sizeOfPathParams_subscriptionId = strlen(subscriptionId) + 3 +
	                                       strlen("{ subscriptionId }");
	if(subscriptionId == NULL) {
		goto end;
	}
	char *localVarToReplace_subscriptionId = malloc(
		sizeOfPathParams_subscriptionId);
	sprintf(localVarToReplace_subscriptionId, "{%s}", "subscriptionId");

	localVarPath = strReplace(localVarPath,
	                          localVarToReplace_subscriptionId,
	                          subscriptionId);



	// Body Param
	cJSON *localVarSingleItemJSON_subscription_data = NULL;
	if(subscription_data != NULL) {
		// string
		localVarSingleItemJSON_subscription_data =
			subscription_data_convertToJSON(subscription_data);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_subscription_data);
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
	                 "PUT");

	// uncomment below to debug the error response
	// if (apiClient->response_code == 200) {
	// printf("%s\n","Subscription modified successfully");
	// }
	// uncomment below to debug the error response
	// if (apiClient->response_code == 204) {
	// printf("%s\n","Events subscription modification is accepted entirely");
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
	cJSON *IndividualSubscriptionDocumentAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	subscription_data_t *elementToReturn = subscription_data_parseFromJSON(
		IndividualSubscriptionDocumentAPIlocalVarJSON);
	cJSON_Delete(IndividualSubscriptionDocumentAPIlocalVarJSON);
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
	free(localVarToReplace_subscriptionId);
	if(localVarSingleItemJSON_subscription_data) {
		cJSON_Delete(localVarSingleItemJSON_subscription_data);
		localVarSingleItemJSON_subscription_data = NULL;
	}
	free(localVarBodyParameters);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}

// Namf_Communication AMF Status Change UnSubscribe service Operation
//
void IndividualSubscriptionDocumentAPI_aMFStatusChangeUnSubscribe(
	apiClient_t *apiClient, char *subscriptionId) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = NULL;
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/subscriptions/{subscriptionId}") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath, "/subscriptions/{subscriptionId}");


	// Path Params
	long sizeOfPathParams_subscriptionId = strlen(subscriptionId) + 3 +
	                                       strlen("{ subscriptionId }");
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
	// No return type
end:
	if(apiClient->dataReceived) {
		free(apiClient->dataReceived);
		apiClient->dataReceived = NULL;
		apiClient->dataReceivedLen = 0;
	}



	list_freeList(localVarHeaderType);

	free(localVarPath);
	free(localVarToReplace_subscriptionId);
}
