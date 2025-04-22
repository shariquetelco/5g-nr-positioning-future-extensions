#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "IndividualUeContextDocumentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[256]; \
		snprintf(dst, 256, "%ld", (long int) (src)); \
	}while(0)


// Namf_Communication CancelRelocateUEContext service Operation
//
void IndividualUeContextDocumentAPI_cancelRelocateUEContext(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_cancel_relocate_data_t *jsonData,
	binary_t *binaryDataGtpcMessage) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = list_createList();
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}/cancel-relocate") +
	                  1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/cancel-relocate");


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



	// form parameters
	char *keyForm_jsonData = NULL;
	ue_context_cancel_relocate_data_t *valueForm_jsonData = 0;
	keyValuePair_t *keyPairForm_jsonData = 0;
	if(jsonData != NULL) {
		keyForm_jsonData = strdup("jsonData");
		valueForm_jsonData = (jsonData);
		keyPairForm_jsonData = keyValuePair_create(keyForm_jsonData,
		                                           &valueForm_jsonData);
		list_addElement(localVarFormParameters, keyPairForm_jsonData);
	}

	// form parameters
	char *keyForm_binaryDataGtpcMessage = NULL;
	binary_t *valueForm_binaryDataGtpcMessage = 0;
	keyValuePair_t *keyPairForm_binaryDataGtpcMessage = 0;
	if(binaryDataGtpcMessage != NULL) {
		keyForm_binaryDataGtpcMessage = strdup("binaryDataGtpcMessage");
		valueForm_binaryDataGtpcMessage = binaryDataGtpcMessage;
		keyPairForm_binaryDataGtpcMessage = keyValuePair_create(
			keyForm_binaryDataGtpcMessage,
			&valueForm_binaryDataGtpcMessage);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataGtpcMessage);                // file adding
	}
	list_addElement(localVarHeaderType, "application/json"); // produces
	list_addElement(localVarHeaderType, "application/problem+json"); // produces
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
	// if (apiClient->response_code == 204) {
	// printf("%s\n","UE Context successfully released");
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
	// No return type
end:
	if(apiClient->dataReceived) {
		free(apiClient->dataReceived);
		apiClient->dataReceived = NULL;
		apiClient->dataReceivedLen = 0;
	}


	list_freeList(localVarFormParameters);
	list_freeList(localVarHeaderType);
	list_freeList(localVarContentType);
	free(localVarPath);
	free(localVarToReplace_ueContextId);
	if(keyForm_jsonData) {
		free(keyForm_jsonData);
		keyForm_jsonData = NULL;
	}
	free(keyPairForm_jsonData);
	if(keyForm_binaryDataGtpcMessage) {
		free(keyForm_binaryDataGtpcMessage);
		keyForm_binaryDataGtpcMessage = NULL;
	}
// free(fileVar_binaryDataGtpcMessage->data);
// free(fileVar_binaryDataGtpcMessage);
}

// Namf_Communication CreateUEContext service Operation
//
ue_context_created_data_t *IndividualUeContextDocumentAPI_createUEContext(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_create_data_t *jsonData, binary_t *binaryDataN2Information,
	binary_t *binaryDataN2InformationExt1,
	binary_t *binaryDataN2InformationExt2,
	binary_t *binaryDataN2InformationExt3,
	binary_t *binaryDataN2InformationExt4,
	binary_t *binaryDataN2InformationExt5,
	binary_t *binaryDataN2InformationExt6,
	binary_t *binaryDataN2InformationExt7,
	binary_t *binaryDataN2InformationExt8,
	binary_t *binaryDataN2InformationExt9,
	binary_t *binaryDataN2InformationExt10,
	binary_t *binaryDataN2InformationExt11,
	binary_t *binaryDataN2InformationExt12,
	binary_t *binaryDataN2InformationExt13,
	binary_t *binaryDataN2InformationExt14,
	binary_t *binaryDataN2InformationExt15,
	binary_t *binaryDataN2InformationExt16,
	binary_t *binaryDataN2InformationExt17) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = list_createList();
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath, "/ue-contexts/{ueContextId}");


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



	// form parameters
	char *keyForm_jsonData = NULL;
	ue_context_create_data_t *valueForm_jsonData = 0;
	keyValuePair_t *keyPairForm_jsonData = 0;
	if(jsonData != NULL) {
		keyForm_jsonData = strdup("jsonData");
		valueForm_jsonData = (jsonData);
		keyPairForm_jsonData = keyValuePair_create(keyForm_jsonData,
		                                           &valueForm_jsonData);
		list_addElement(localVarFormParameters, keyPairForm_jsonData);
	}

	// form parameters
	char *keyForm_binaryDataN2Information = NULL;
	binary_t *valueForm_binaryDataN2Information = 0;
	keyValuePair_t *keyPairForm_binaryDataN2Information = 0;
	if(binaryDataN2Information != NULL) {
		keyForm_binaryDataN2Information = strdup(
			"binaryDataN2Information");
		valueForm_binaryDataN2Information = binaryDataN2Information;
		keyPairForm_binaryDataN2Information = keyValuePair_create(
			keyForm_binaryDataN2Information,
			&valueForm_binaryDataN2Information);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2Information);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt1 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt1 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt1 = 0;
	if(binaryDataN2InformationExt1 != NULL) {
		keyForm_binaryDataN2InformationExt1 = strdup(
			"binaryDataN2InformationExt1");
		valueForm_binaryDataN2InformationExt1 =
			binaryDataN2InformationExt1;
		keyPairForm_binaryDataN2InformationExt1 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt1,
			&valueForm_binaryDataN2InformationExt1);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt1);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt2 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt2 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt2 = 0;
	if(binaryDataN2InformationExt2 != NULL) {
		keyForm_binaryDataN2InformationExt2 = strdup(
			"binaryDataN2InformationExt2");
		valueForm_binaryDataN2InformationExt2 =
			binaryDataN2InformationExt2;
		keyPairForm_binaryDataN2InformationExt2 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt2,
			&valueForm_binaryDataN2InformationExt2);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt2);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt3 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt3 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt3 = 0;
	if(binaryDataN2InformationExt3 != NULL) {
		keyForm_binaryDataN2InformationExt3 = strdup(
			"binaryDataN2InformationExt3");
		valueForm_binaryDataN2InformationExt3 =
			binaryDataN2InformationExt3;
		keyPairForm_binaryDataN2InformationExt3 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt3,
			&valueForm_binaryDataN2InformationExt3);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt3);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt4 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt4 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt4 = 0;
	if(binaryDataN2InformationExt4 != NULL) {
		keyForm_binaryDataN2InformationExt4 = strdup(
			"binaryDataN2InformationExt4");
		valueForm_binaryDataN2InformationExt4 =
			binaryDataN2InformationExt4;
		keyPairForm_binaryDataN2InformationExt4 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt4,
			&valueForm_binaryDataN2InformationExt4);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt4);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt5 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt5 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt5 = 0;
	if(binaryDataN2InformationExt5 != NULL) {
		keyForm_binaryDataN2InformationExt5 = strdup(
			"binaryDataN2InformationExt5");
		valueForm_binaryDataN2InformationExt5 =
			binaryDataN2InformationExt5;
		keyPairForm_binaryDataN2InformationExt5 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt5,
			&valueForm_binaryDataN2InformationExt5);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt5);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt6 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt6 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt6 = 0;
	if(binaryDataN2InformationExt6 != NULL) {
		keyForm_binaryDataN2InformationExt6 = strdup(
			"binaryDataN2InformationExt6");
		valueForm_binaryDataN2InformationExt6 =
			binaryDataN2InformationExt6;
		keyPairForm_binaryDataN2InformationExt6 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt6,
			&valueForm_binaryDataN2InformationExt6);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt6);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt7 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt7 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt7 = 0;
	if(binaryDataN2InformationExt7 != NULL) {
		keyForm_binaryDataN2InformationExt7 = strdup(
			"binaryDataN2InformationExt7");
		valueForm_binaryDataN2InformationExt7 =
			binaryDataN2InformationExt7;
		keyPairForm_binaryDataN2InformationExt7 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt7,
			&valueForm_binaryDataN2InformationExt7);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt7);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt8 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt8 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt8 = 0;
	if(binaryDataN2InformationExt8 != NULL) {
		keyForm_binaryDataN2InformationExt8 = strdup(
			"binaryDataN2InformationExt8");
		valueForm_binaryDataN2InformationExt8 =
			binaryDataN2InformationExt8;
		keyPairForm_binaryDataN2InformationExt8 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt8,
			&valueForm_binaryDataN2InformationExt8);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt8);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt9 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt9 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt9 = 0;
	if(binaryDataN2InformationExt9 != NULL) {
		keyForm_binaryDataN2InformationExt9 = strdup(
			"binaryDataN2InformationExt9");
		valueForm_binaryDataN2InformationExt9 =
			binaryDataN2InformationExt9;
		keyPairForm_binaryDataN2InformationExt9 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt9,
			&valueForm_binaryDataN2InformationExt9);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt9);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt10 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt10 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt10 = 0;
	if(binaryDataN2InformationExt10 != NULL) {
		keyForm_binaryDataN2InformationExt10 = strdup(
			"binaryDataN2InformationExt10");
		valueForm_binaryDataN2InformationExt10 =
			binaryDataN2InformationExt10;
		keyPairForm_binaryDataN2InformationExt10 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt10,
			&valueForm_binaryDataN2InformationExt10);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt10);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt11 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt11 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt11 = 0;
	if(binaryDataN2InformationExt11 != NULL) {
		keyForm_binaryDataN2InformationExt11 = strdup(
			"binaryDataN2InformationExt11");
		valueForm_binaryDataN2InformationExt11 =
			binaryDataN2InformationExt11;
		keyPairForm_binaryDataN2InformationExt11 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt11,
			&valueForm_binaryDataN2InformationExt11);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt11);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt12 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt12 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt12 = 0;
	if(binaryDataN2InformationExt12 != NULL) {
		keyForm_binaryDataN2InformationExt12 = strdup(
			"binaryDataN2InformationExt12");
		valueForm_binaryDataN2InformationExt12 =
			binaryDataN2InformationExt12;
		keyPairForm_binaryDataN2InformationExt12 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt12,
			&valueForm_binaryDataN2InformationExt12);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt12);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt13 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt13 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt13 = 0;
	if(binaryDataN2InformationExt13 != NULL) {
		keyForm_binaryDataN2InformationExt13 = strdup(
			"binaryDataN2InformationExt13");
		valueForm_binaryDataN2InformationExt13 =
			binaryDataN2InformationExt13;
		keyPairForm_binaryDataN2InformationExt13 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt13,
			&valueForm_binaryDataN2InformationExt13);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt13);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt14 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt14 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt14 = 0;
	if(binaryDataN2InformationExt14 != NULL) {
		keyForm_binaryDataN2InformationExt14 = strdup(
			"binaryDataN2InformationExt14");
		valueForm_binaryDataN2InformationExt14 =
			binaryDataN2InformationExt14;
		keyPairForm_binaryDataN2InformationExt14 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt14,
			&valueForm_binaryDataN2InformationExt14);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt14);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt15 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt15 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt15 = 0;
	if(binaryDataN2InformationExt15 != NULL) {
		keyForm_binaryDataN2InformationExt15 = strdup(
			"binaryDataN2InformationExt15");
		valueForm_binaryDataN2InformationExt15 =
			binaryDataN2InformationExt15;
		keyPairForm_binaryDataN2InformationExt15 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt15,
			&valueForm_binaryDataN2InformationExt15);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt15);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt16 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt16 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt16 = 0;
	if(binaryDataN2InformationExt16 != NULL) {
		keyForm_binaryDataN2InformationExt16 = strdup(
			"binaryDataN2InformationExt16");
		valueForm_binaryDataN2InformationExt16 =
			binaryDataN2InformationExt16;
		keyPairForm_binaryDataN2InformationExt16 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt16,
			&valueForm_binaryDataN2InformationExt16);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt16);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt17 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt17 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt17 = 0;
	if(binaryDataN2InformationExt17 != NULL) {
		keyForm_binaryDataN2InformationExt17 = strdup(
			"binaryDataN2InformationExt17");
		valueForm_binaryDataN2InformationExt17 =
			binaryDataN2InformationExt17;
		keyPairForm_binaryDataN2InformationExt17 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt17,
			&valueForm_binaryDataN2InformationExt17);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt17);                // file adding
	}
	list_addElement(localVarHeaderType, "application/json"); // produces
	list_addElement(localVarHeaderType, "multipart/related"); // produces
	list_addElement(localVarHeaderType, "application/problem+json"); // produces
	list_addElement(localVarContentType, "multipart/related"); // consumes
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
	// if (apiClient->response_code == 201) {
	// printf("%s\n","UE context successfully created.");
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
	// printf("%s\n","Bad Request");
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
	cJSON *IndividualUeContextDocumentAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	ue_context_created_data_t *elementToReturn =
		ue_context_created_data_parseFromJSON(
			IndividualUeContextDocumentAPIlocalVarJSON);
	cJSON_Delete(IndividualUeContextDocumentAPIlocalVarJSON);
	if(elementToReturn == NULL) {
		// return 0;
	}

	// return type
	if(apiClient->dataReceived) {
		free(apiClient->dataReceived);
		apiClient->dataReceived = NULL;
		apiClient->dataReceivedLen = 0;
	}


	list_freeList(localVarFormParameters);
	list_freeList(localVarHeaderType);
	list_freeList(localVarContentType);
	free(localVarPath);
	free(localVarToReplace_ueContextId);
	if(keyForm_jsonData) {
		free(keyForm_jsonData);
		keyForm_jsonData = NULL;
	}
	free(keyPairForm_jsonData);
	if(keyForm_binaryDataN2Information) {
		free(keyForm_binaryDataN2Information);
		keyForm_binaryDataN2Information = NULL;
	}
// free(fileVar_binaryDataN2Information->data);
// free(fileVar_binaryDataN2Information);
	free(keyPairForm_binaryDataN2Information);
	if(keyForm_binaryDataN2InformationExt1) {
		free(keyForm_binaryDataN2InformationExt1);
		keyForm_binaryDataN2InformationExt1 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt1->data);
// free(fileVar_binaryDataN2InformationExt1);
	free(keyPairForm_binaryDataN2InformationExt1);
	if(keyForm_binaryDataN2InformationExt2) {
		free(keyForm_binaryDataN2InformationExt2);
		keyForm_binaryDataN2InformationExt2 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt2->data);
// free(fileVar_binaryDataN2InformationExt2);
	free(keyPairForm_binaryDataN2InformationExt2);
	if(keyForm_binaryDataN2InformationExt3) {
		free(keyForm_binaryDataN2InformationExt3);
		keyForm_binaryDataN2InformationExt3 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt3->data);
// free(fileVar_binaryDataN2InformationExt3);
	free(keyPairForm_binaryDataN2InformationExt3);
	if(keyForm_binaryDataN2InformationExt4) {
		free(keyForm_binaryDataN2InformationExt4);
		keyForm_binaryDataN2InformationExt4 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt4->data);
// free(fileVar_binaryDataN2InformationExt4);
	free(keyPairForm_binaryDataN2InformationExt4);
	if(keyForm_binaryDataN2InformationExt5) {
		free(keyForm_binaryDataN2InformationExt5);
		keyForm_binaryDataN2InformationExt5 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt5->data);
// free(fileVar_binaryDataN2InformationExt5);
	free(keyPairForm_binaryDataN2InformationExt5);
	if(keyForm_binaryDataN2InformationExt6) {
		free(keyForm_binaryDataN2InformationExt6);
		keyForm_binaryDataN2InformationExt6 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt6->data);
// free(fileVar_binaryDataN2InformationExt6);
	free(keyPairForm_binaryDataN2InformationExt6);
	if(keyForm_binaryDataN2InformationExt7) {
		free(keyForm_binaryDataN2InformationExt7);
		keyForm_binaryDataN2InformationExt7 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt7->data);
// free(fileVar_binaryDataN2InformationExt7);
	free(keyPairForm_binaryDataN2InformationExt7);
	if(keyForm_binaryDataN2InformationExt8) {
		free(keyForm_binaryDataN2InformationExt8);
		keyForm_binaryDataN2InformationExt8 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt8->data);
// free(fileVar_binaryDataN2InformationExt8);
	free(keyPairForm_binaryDataN2InformationExt8);
	if(keyForm_binaryDataN2InformationExt9) {
		free(keyForm_binaryDataN2InformationExt9);
		keyForm_binaryDataN2InformationExt9 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt9->data);
// free(fileVar_binaryDataN2InformationExt9);
	free(keyPairForm_binaryDataN2InformationExt9);
	if(keyForm_binaryDataN2InformationExt10) {
		free(keyForm_binaryDataN2InformationExt10);
		keyForm_binaryDataN2InformationExt10 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt10->data);
// free(fileVar_binaryDataN2InformationExt10);
	free(keyPairForm_binaryDataN2InformationExt10);
	if(keyForm_binaryDataN2InformationExt11) {
		free(keyForm_binaryDataN2InformationExt11);
		keyForm_binaryDataN2InformationExt11 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt11->data);
// free(fileVar_binaryDataN2InformationExt11);
	free(keyPairForm_binaryDataN2InformationExt11);
	if(keyForm_binaryDataN2InformationExt12) {
		free(keyForm_binaryDataN2InformationExt12);
		keyForm_binaryDataN2InformationExt12 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt12->data);
// free(fileVar_binaryDataN2InformationExt12);
	free(keyPairForm_binaryDataN2InformationExt12);
	if(keyForm_binaryDataN2InformationExt13) {
		free(keyForm_binaryDataN2InformationExt13);
		keyForm_binaryDataN2InformationExt13 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt13->data);
// free(fileVar_binaryDataN2InformationExt13);
	free(keyPairForm_binaryDataN2InformationExt13);
	if(keyForm_binaryDataN2InformationExt14) {
		free(keyForm_binaryDataN2InformationExt14);
		keyForm_binaryDataN2InformationExt14 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt14->data);
// free(fileVar_binaryDataN2InformationExt14);
	free(keyPairForm_binaryDataN2InformationExt14);
	if(keyForm_binaryDataN2InformationExt15) {
		free(keyForm_binaryDataN2InformationExt15);
		keyForm_binaryDataN2InformationExt15 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt15->data);
// free(fileVar_binaryDataN2InformationExt15);
	free(keyPairForm_binaryDataN2InformationExt15);
	if(keyForm_binaryDataN2InformationExt16) {
		free(keyForm_binaryDataN2InformationExt16);
		keyForm_binaryDataN2InformationExt16 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt16->data);
// free(fileVar_binaryDataN2InformationExt16);
	free(keyPairForm_binaryDataN2InformationExt16);
	if(keyForm_binaryDataN2InformationExt17) {
		free(keyForm_binaryDataN2InformationExt17);
		keyForm_binaryDataN2InformationExt17 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt17->data);
// free(fileVar_binaryDataN2InformationExt17);
	free(keyPairForm_binaryDataN2InformationExt17);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}

// Namf_Communication EBI Assignment service Operation
//
assigned_ebi_data_t *IndividualUeContextDocumentAPI_eBIAssignment(
	apiClient_t *apiClient, char *ueContextId,
	assign_ebi_data_t *assign_ebi_data) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}/assign-ebi") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/assign-ebi");


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
	cJSON *localVarSingleItemJSON_assign_ebi_data = NULL;
	if(assign_ebi_data != NULL) {
		// string
		localVarSingleItemJSON_assign_ebi_data =
			assign_ebi_data_convertToJSON(assign_ebi_data);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_assign_ebi_data);
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
	// printf("%s\n","EBI Assignment successfully performed.");
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
	// printf("%s\n","Bad Request");
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
	// printf("%s\n","Conflict");
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
	cJSON *IndividualUeContextDocumentAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	assigned_ebi_data_t *elementToReturn = assigned_ebi_data_parseFromJSON(
		IndividualUeContextDocumentAPIlocalVarJSON);
	cJSON_Delete(IndividualUeContextDocumentAPIlocalVarJSON);
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
	if(localVarSingleItemJSON_assign_ebi_data) {
		cJSON_Delete(localVarSingleItemJSON_assign_ebi_data);
		localVarSingleItemJSON_assign_ebi_data = NULL;
	}
	free(localVarBodyParameters);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}

// Namf_Communication RegistrationStatusUpdate service Operation
//
ue_reg_status_update_rsp_data_t *
IndividualUeContextDocumentAPI_registrationStatusUpdate(
	apiClient_t			*apiClient,
	char				*ueContextId,
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data)
{
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}/transfer-update") +
	                  1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/transfer-update");


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
	cJSON *localVarSingleItemJSON_ue_reg_status_update_req_data = NULL;
	if(ue_reg_status_update_req_data != NULL) {
		// string
		localVarSingleItemJSON_ue_reg_status_update_req_data =
			ue_reg_status_update_req_data_convertToJSON(
				ue_reg_status_update_req_data);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_ue_reg_status_update_req_data);
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
	// printf("%s\n","UE context transfer status successfully updated.");
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
	// printf("%s\n","Generic Error");
	// }
	// nonprimitive not container
	cJSON *IndividualUeContextDocumentAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	ue_reg_status_update_rsp_data_t *elementToReturn =
		ue_reg_status_update_rsp_data_parseFromJSON(
			IndividualUeContextDocumentAPIlocalVarJSON);
	cJSON_Delete(IndividualUeContextDocumentAPIlocalVarJSON);
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
	if(localVarSingleItemJSON_ue_reg_status_update_req_data) {
		cJSON_Delete(
			localVarSingleItemJSON_ue_reg_status_update_req_data);
		localVarSingleItemJSON_ue_reg_status_update_req_data = NULL;
	}
	free(localVarBodyParameters);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}

// Namf_Communication ReleaseUEContext service Operation
//
void IndividualUeContextDocumentAPI_releaseUEContext(
	apiClient_t		*apiClient,
	char			*ueContextId,
	ue_context_release_t	*ue_context_release)
{
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}/release") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/release");


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
	cJSON *localVarSingleItemJSON_ue_context_release = NULL;
	if(ue_context_release != NULL) {
		// string
		localVarSingleItemJSON_ue_context_release =
			ue_context_release_convertToJSON(ue_context_release);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_ue_context_release);
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
	// printf("%s\n","UE Context successfully released");
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
	free(localVarToReplace_ueContextId);
	if(localVarSingleItemJSON_ue_context_release) {
		cJSON_Delete(localVarSingleItemJSON_ue_context_release);
		localVarSingleItemJSON_ue_context_release = NULL;
	}
	free(localVarBodyParameters);
}

// Namf_Communication RelocateUEContext service Operation
//
ue_context_relocated_data_t *IndividualUeContextDocumentAPI_relocateUEContext(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_relocate_data_t *jsonData,
	binary_t *binaryDataForwardRelocationRequest,
	binary_t *binaryDataN2Information,
	binary_t *binaryDataN2InformationExt1,
	binary_t *binaryDataN2InformationExt2,
	binary_t *binaryDataN2InformationExt3,
	binary_t *binaryDataN2InformationExt4,
	binary_t *binaryDataN2InformationExt5,
	binary_t *binaryDataN2InformationExt6,
	binary_t *binaryDataN2InformationExt7,
	binary_t *binaryDataN2InformationExt8,
	binary_t *binaryDataN2InformationExt9,
	binary_t *binaryDataN2InformationExt10,
	binary_t *binaryDataN2InformationExt11,
	binary_t *binaryDataN2InformationExt12,
	binary_t *binaryDataN2InformationExt13,
	binary_t *binaryDataN2InformationExt14,
	binary_t *binaryDataN2InformationExt15,
	binary_t *binaryDataN2InformationExt16) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = list_createList();
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}/relocate") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/relocate");


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



	// form parameters
	char *keyForm_jsonData = NULL;
	ue_context_relocate_data_t *valueForm_jsonData = 0;
	keyValuePair_t *keyPairForm_jsonData = 0;
	if(jsonData != NULL) {
		keyForm_jsonData = strdup("jsonData");
		valueForm_jsonData = (jsonData);
		keyPairForm_jsonData = keyValuePair_create(keyForm_jsonData,
		                                           &valueForm_jsonData);
		list_addElement(localVarFormParameters, keyPairForm_jsonData);
	}

	// form parameters
	char *keyForm_binaryDataForwardRelocationRequest = NULL;
	binary_t *valueForm_binaryDataForwardRelocationRequest = 0;
	keyValuePair_t *keyPairForm_binaryDataForwardRelocationRequest = 0;
	if(binaryDataForwardRelocationRequest != NULL) {
		keyForm_binaryDataForwardRelocationRequest = strdup(
			"binaryDataForwardRelocationRequest");
		valueForm_binaryDataForwardRelocationRequest =
			binaryDataForwardRelocationRequest;
		keyPairForm_binaryDataForwardRelocationRequest =
			keyValuePair_create(
				keyForm_binaryDataForwardRelocationRequest,
				&valueForm_binaryDataForwardRelocationRequest);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataForwardRelocationRequest);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2Information = NULL;
	binary_t *valueForm_binaryDataN2Information = 0;
	keyValuePair_t *keyPairForm_binaryDataN2Information = 0;
	if(binaryDataN2Information != NULL) {
		keyForm_binaryDataN2Information = strdup(
			"binaryDataN2Information");
		valueForm_binaryDataN2Information = binaryDataN2Information;
		keyPairForm_binaryDataN2Information = keyValuePair_create(
			keyForm_binaryDataN2Information,
			&valueForm_binaryDataN2Information);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2Information);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt1 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt1 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt1 = 0;
	if(binaryDataN2InformationExt1 != NULL) {
		keyForm_binaryDataN2InformationExt1 = strdup(
			"binaryDataN2InformationExt1");
		valueForm_binaryDataN2InformationExt1 =
			binaryDataN2InformationExt1;
		keyPairForm_binaryDataN2InformationExt1 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt1,
			&valueForm_binaryDataN2InformationExt1);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt1);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt2 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt2 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt2 = 0;
	if(binaryDataN2InformationExt2 != NULL) {
		keyForm_binaryDataN2InformationExt2 = strdup(
			"binaryDataN2InformationExt2");
		valueForm_binaryDataN2InformationExt2 =
			binaryDataN2InformationExt2;
		keyPairForm_binaryDataN2InformationExt2 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt2,
			&valueForm_binaryDataN2InformationExt2);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt2);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt3 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt3 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt3 = 0;
	if(binaryDataN2InformationExt3 != NULL) {
		keyForm_binaryDataN2InformationExt3 = strdup(
			"binaryDataN2InformationExt3");
		valueForm_binaryDataN2InformationExt3 =
			binaryDataN2InformationExt3;
		keyPairForm_binaryDataN2InformationExt3 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt3,
			&valueForm_binaryDataN2InformationExt3);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt3);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt4 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt4 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt4 = 0;
	if(binaryDataN2InformationExt4 != NULL) {
		keyForm_binaryDataN2InformationExt4 = strdup(
			"binaryDataN2InformationExt4");
		valueForm_binaryDataN2InformationExt4 =
			binaryDataN2InformationExt4;
		keyPairForm_binaryDataN2InformationExt4 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt4,
			&valueForm_binaryDataN2InformationExt4);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt4);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt5 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt5 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt5 = 0;
	if(binaryDataN2InformationExt5 != NULL) {
		keyForm_binaryDataN2InformationExt5 = strdup(
			"binaryDataN2InformationExt5");
		valueForm_binaryDataN2InformationExt5 =
			binaryDataN2InformationExt5;
		keyPairForm_binaryDataN2InformationExt5 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt5,
			&valueForm_binaryDataN2InformationExt5);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt5);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt6 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt6 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt6 = 0;
	if(binaryDataN2InformationExt6 != NULL) {
		keyForm_binaryDataN2InformationExt6 = strdup(
			"binaryDataN2InformationExt6");
		valueForm_binaryDataN2InformationExt6 =
			binaryDataN2InformationExt6;
		keyPairForm_binaryDataN2InformationExt6 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt6,
			&valueForm_binaryDataN2InformationExt6);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt6);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt7 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt7 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt7 = 0;
	if(binaryDataN2InformationExt7 != NULL) {
		keyForm_binaryDataN2InformationExt7 = strdup(
			"binaryDataN2InformationExt7");
		valueForm_binaryDataN2InformationExt7 =
			binaryDataN2InformationExt7;
		keyPairForm_binaryDataN2InformationExt7 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt7,
			&valueForm_binaryDataN2InformationExt7);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt7);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt8 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt8 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt8 = 0;
	if(binaryDataN2InformationExt8 != NULL) {
		keyForm_binaryDataN2InformationExt8 = strdup(
			"binaryDataN2InformationExt8");
		valueForm_binaryDataN2InformationExt8 =
			binaryDataN2InformationExt8;
		keyPairForm_binaryDataN2InformationExt8 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt8,
			&valueForm_binaryDataN2InformationExt8);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt8);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt9 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt9 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt9 = 0;
	if(binaryDataN2InformationExt9 != NULL) {
		keyForm_binaryDataN2InformationExt9 = strdup(
			"binaryDataN2InformationExt9");
		valueForm_binaryDataN2InformationExt9 =
			binaryDataN2InformationExt9;
		keyPairForm_binaryDataN2InformationExt9 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt9,
			&valueForm_binaryDataN2InformationExt9);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt9);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt10 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt10 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt10 = 0;
	if(binaryDataN2InformationExt10 != NULL) {
		keyForm_binaryDataN2InformationExt10 = strdup(
			"binaryDataN2InformationExt10");
		valueForm_binaryDataN2InformationExt10 =
			binaryDataN2InformationExt10;
		keyPairForm_binaryDataN2InformationExt10 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt10,
			&valueForm_binaryDataN2InformationExt10);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt10);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt11 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt11 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt11 = 0;
	if(binaryDataN2InformationExt11 != NULL) {
		keyForm_binaryDataN2InformationExt11 = strdup(
			"binaryDataN2InformationExt11");
		valueForm_binaryDataN2InformationExt11 =
			binaryDataN2InformationExt11;
		keyPairForm_binaryDataN2InformationExt11 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt11,
			&valueForm_binaryDataN2InformationExt11);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt11);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt12 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt12 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt12 = 0;
	if(binaryDataN2InformationExt12 != NULL) {
		keyForm_binaryDataN2InformationExt12 = strdup(
			"binaryDataN2InformationExt12");
		valueForm_binaryDataN2InformationExt12 =
			binaryDataN2InformationExt12;
		keyPairForm_binaryDataN2InformationExt12 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt12,
			&valueForm_binaryDataN2InformationExt12);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt12);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt13 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt13 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt13 = 0;
	if(binaryDataN2InformationExt13 != NULL) {
		keyForm_binaryDataN2InformationExt13 = strdup(
			"binaryDataN2InformationExt13");
		valueForm_binaryDataN2InformationExt13 =
			binaryDataN2InformationExt13;
		keyPairForm_binaryDataN2InformationExt13 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt13,
			&valueForm_binaryDataN2InformationExt13);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt13);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt14 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt14 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt14 = 0;
	if(binaryDataN2InformationExt14 != NULL) {
		keyForm_binaryDataN2InformationExt14 = strdup(
			"binaryDataN2InformationExt14");
		valueForm_binaryDataN2InformationExt14 =
			binaryDataN2InformationExt14;
		keyPairForm_binaryDataN2InformationExt14 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt14,
			&valueForm_binaryDataN2InformationExt14);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt14);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt15 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt15 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt15 = 0;
	if(binaryDataN2InformationExt15 != NULL) {
		keyForm_binaryDataN2InformationExt15 = strdup(
			"binaryDataN2InformationExt15");
		valueForm_binaryDataN2InformationExt15 =
			binaryDataN2InformationExt15;
		keyPairForm_binaryDataN2InformationExt15 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt15,
			&valueForm_binaryDataN2InformationExt15);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt15);                // file adding
	}

	// form parameters
	char *keyForm_binaryDataN2InformationExt16 = NULL;
	binary_t *valueForm_binaryDataN2InformationExt16 = 0;
	keyValuePair_t *keyPairForm_binaryDataN2InformationExt16 = 0;
	if(binaryDataN2InformationExt16 != NULL) {
		keyForm_binaryDataN2InformationExt16 = strdup(
			"binaryDataN2InformationExt16");
		valueForm_binaryDataN2InformationExt16 =
			binaryDataN2InformationExt16;
		keyPairForm_binaryDataN2InformationExt16 = keyValuePair_create(
			keyForm_binaryDataN2InformationExt16,
			&valueForm_binaryDataN2InformationExt16);
		list_addElement(localVarFormParameters,
		                keyPairForm_binaryDataN2InformationExt16);                // file adding
	}
	list_addElement(localVarHeaderType, "application/json"); // produces
	list_addElement(localVarHeaderType, "application/problem+json"); // produces
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
	// if (apiClient->response_code == 201) {
	// printf("%s\n","UE context successfully relocated.");
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
	cJSON *IndividualUeContextDocumentAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	ue_context_relocated_data_t *elementToReturn =
		ue_context_relocated_data_parseFromJSON(
			IndividualUeContextDocumentAPIlocalVarJSON);
	cJSON_Delete(IndividualUeContextDocumentAPIlocalVarJSON);
	if(elementToReturn == NULL) {
		// return 0;
	}

	// return type
	if(apiClient->dataReceived) {
		free(apiClient->dataReceived);
		apiClient->dataReceived = NULL;
		apiClient->dataReceivedLen = 0;
	}


	list_freeList(localVarFormParameters);
	list_freeList(localVarHeaderType);
	list_freeList(localVarContentType);
	free(localVarPath);
	free(localVarToReplace_ueContextId);
	if(keyForm_jsonData) {
		free(keyForm_jsonData);
		keyForm_jsonData = NULL;
	}
	free(keyPairForm_jsonData);
	if(keyForm_binaryDataForwardRelocationRequest) {
		free(keyForm_binaryDataForwardRelocationRequest);
		keyForm_binaryDataForwardRelocationRequest = NULL;
	}
// free(fileVar_binaryDataForwardRelocationRequest->data);
// free(fileVar_binaryDataForwardRelocationRequest);
	free(keyPairForm_binaryDataForwardRelocationRequest);
	if(keyForm_binaryDataN2Information) {
		free(keyForm_binaryDataN2Information);
		keyForm_binaryDataN2Information = NULL;
	}
// free(fileVar_binaryDataN2Information->data);
// free(fileVar_binaryDataN2Information);
	free(keyPairForm_binaryDataN2Information);
	if(keyForm_binaryDataN2InformationExt1) {
		free(keyForm_binaryDataN2InformationExt1);
		keyForm_binaryDataN2InformationExt1 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt1->data);
// free(fileVar_binaryDataN2InformationExt1);
	free(keyPairForm_binaryDataN2InformationExt1);
	if(keyForm_binaryDataN2InformationExt2) {
		free(keyForm_binaryDataN2InformationExt2);
		keyForm_binaryDataN2InformationExt2 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt2->data);
// free(fileVar_binaryDataN2InformationExt2);
	free(keyPairForm_binaryDataN2InformationExt2);
	if(keyForm_binaryDataN2InformationExt3) {
		free(keyForm_binaryDataN2InformationExt3);
		keyForm_binaryDataN2InformationExt3 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt3->data);
// free(fileVar_binaryDataN2InformationExt3);
	free(keyPairForm_binaryDataN2InformationExt3);
	if(keyForm_binaryDataN2InformationExt4) {
		free(keyForm_binaryDataN2InformationExt4);
		keyForm_binaryDataN2InformationExt4 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt4->data);
// free(fileVar_binaryDataN2InformationExt4);
	free(keyPairForm_binaryDataN2InformationExt4);
	if(keyForm_binaryDataN2InformationExt5) {
		free(keyForm_binaryDataN2InformationExt5);
		keyForm_binaryDataN2InformationExt5 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt5->data);
// free(fileVar_binaryDataN2InformationExt5);
	free(keyPairForm_binaryDataN2InformationExt5);
	if(keyForm_binaryDataN2InformationExt6) {
		free(keyForm_binaryDataN2InformationExt6);
		keyForm_binaryDataN2InformationExt6 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt6->data);
// free(fileVar_binaryDataN2InformationExt6);
	free(keyPairForm_binaryDataN2InformationExt6);
	if(keyForm_binaryDataN2InformationExt7) {
		free(keyForm_binaryDataN2InformationExt7);
		keyForm_binaryDataN2InformationExt7 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt7->data);
// free(fileVar_binaryDataN2InformationExt7);
	free(keyPairForm_binaryDataN2InformationExt7);
	if(keyForm_binaryDataN2InformationExt8) {
		free(keyForm_binaryDataN2InformationExt8);
		keyForm_binaryDataN2InformationExt8 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt8->data);
// free(fileVar_binaryDataN2InformationExt8);
	free(keyPairForm_binaryDataN2InformationExt8);
	if(keyForm_binaryDataN2InformationExt9) {
		free(keyForm_binaryDataN2InformationExt9);
		keyForm_binaryDataN2InformationExt9 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt9->data);
// free(fileVar_binaryDataN2InformationExt9);
	free(keyPairForm_binaryDataN2InformationExt9);
	if(keyForm_binaryDataN2InformationExt10) {
		free(keyForm_binaryDataN2InformationExt10);
		keyForm_binaryDataN2InformationExt10 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt10->data);
// free(fileVar_binaryDataN2InformationExt10);
	free(keyPairForm_binaryDataN2InformationExt10);
	if(keyForm_binaryDataN2InformationExt11) {
		free(keyForm_binaryDataN2InformationExt11);
		keyForm_binaryDataN2InformationExt11 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt11->data);
// free(fileVar_binaryDataN2InformationExt11);
	free(keyPairForm_binaryDataN2InformationExt11);
	if(keyForm_binaryDataN2InformationExt12) {
		free(keyForm_binaryDataN2InformationExt12);
		keyForm_binaryDataN2InformationExt12 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt12->data);
// free(fileVar_binaryDataN2InformationExt12);
	free(keyPairForm_binaryDataN2InformationExt12);
	if(keyForm_binaryDataN2InformationExt13) {
		free(keyForm_binaryDataN2InformationExt13);
		keyForm_binaryDataN2InformationExt13 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt13->data);
// free(fileVar_binaryDataN2InformationExt13);
	free(keyPairForm_binaryDataN2InformationExt13);
	if(keyForm_binaryDataN2InformationExt14) {
		free(keyForm_binaryDataN2InformationExt14);
		keyForm_binaryDataN2InformationExt14 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt14->data);
// free(fileVar_binaryDataN2InformationExt14);
	free(keyPairForm_binaryDataN2InformationExt14);
	if(keyForm_binaryDataN2InformationExt15) {
		free(keyForm_binaryDataN2InformationExt15);
		keyForm_binaryDataN2InformationExt15 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt15->data);
// free(fileVar_binaryDataN2InformationExt15);
	free(keyPairForm_binaryDataN2InformationExt15);
	if(keyForm_binaryDataN2InformationExt16) {
		free(keyForm_binaryDataN2InformationExt16);
		keyForm_binaryDataN2InformationExt16 = NULL;
	}
// free(fileVar_binaryDataN2InformationExt16->data);
// free(fileVar_binaryDataN2InformationExt16);
	free(keyPairForm_binaryDataN2InformationExt16);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}

// Namf_Communication UEContextTransfer service Operation
//
ue_context_transfer_rsp_data_t *IndividualUeContextDocumentAPI_uEContextTransfer(
	apiClient_t *apiClient, char *ueContextId,
	ue_context_transfer_req_data_t *ue_context_transfer_req_data) {
	list_t *localVarQueryParameters = NULL;
	list_t *localVarHeaderParameters = NULL;
	list_t *localVarFormParameters = NULL;
	list_t *localVarHeaderType = list_createList();
	list_t *localVarContentType = list_createList();
	char *localVarBodyParameters = NULL;

	// create the path
	long sizeOfPath = strlen("/ue-contexts/{ueContextId}/transfer") + 1;
	char *localVarPath = malloc(sizeOfPath);
	snprintf(localVarPath, sizeOfPath,
	         "/ue-contexts/{ueContextId}/transfer");


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
	cJSON *localVarSingleItemJSON_ue_context_transfer_req_data = NULL;
	if(ue_context_transfer_req_data != NULL) {
		// string
		localVarSingleItemJSON_ue_context_transfer_req_data =
			ue_context_transfer_req_data_convertToJSON(
				ue_context_transfer_req_data);
		localVarBodyParameters = cJSON_Print(
			localVarSingleItemJSON_ue_context_transfer_req_data);
	}
	list_addElement(localVarHeaderType, "application/json"); // produces
	list_addElement(localVarHeaderType, "multipart/related"); // produces
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
	// if (apiClient->response_code == 200) {
	// printf("%s\n","UE context transfer successfully initiated.");
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
	cJSON *IndividualUeContextDocumentAPIlocalVarJSON = cJSON_Parse(
		apiClient->dataReceived);
	ue_context_transfer_rsp_data_t *elementToReturn =
		ue_context_transfer_rsp_data_parseFromJSON(
			IndividualUeContextDocumentAPIlocalVarJSON);
	cJSON_Delete(IndividualUeContextDocumentAPIlocalVarJSON);
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
	if(localVarSingleItemJSON_ue_context_transfer_req_data) {
		cJSON_Delete(localVarSingleItemJSON_ue_context_transfer_req_data);
		localVarSingleItemJSON_ue_context_transfer_req_data = NULL;
	}
	free(localVarBodyParameters);
	return elementToReturn;
end:
	free(localVarPath);
	return NULL;
}
