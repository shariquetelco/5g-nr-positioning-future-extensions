#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "non_ue_n2_message_transfer_request.h"

non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request_create(
	n2_information_transfer_req_data_t	*json_data,
	binary_t				*binary_data_n2_information) {
	non_ue_n2_message_transfer_request_t *
	        non_ue_n2_message_transfer_request_local_var =
		malloc(sizeof(non_ue_n2_message_transfer_request_t));

	non_ue_n2_message_transfer_request_local_var->json_data = json_data;
	non_ue_n2_message_transfer_request_local_var->binary_data_n2_information
	        = binary_data_n2_information;

	return non_ue_n2_message_transfer_request_local_var;
}

void non_ue_n2_message_transfer_request_free(
	non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request)
{
	lnode_t *node = NULL;

	if(NULL == non_ue_n2_message_transfer_request) {
		return;
	}
	if(non_ue_n2_message_transfer_request->json_data) {
		n2_information_transfer_req_data_free(
			non_ue_n2_message_transfer_request->json_data);
		non_ue_n2_message_transfer_request->json_data = NULL;
	}
	if(non_ue_n2_message_transfer_request->binary_data_n2_information) {
		free(
			non_ue_n2_message_transfer_request->binary_data_n2_information->data);
		non_ue_n2_message_transfer_request->binary_data_n2_information =
			NULL;
	}
	free(non_ue_n2_message_transfer_request);
}

cJSON *non_ue_n2_message_transfer_request_convertToJSON(
	non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(non_ue_n2_message_transfer_request == NULL) {
		printf(
			"non_ue_n2_message_transfer_request_convertToJSON() failed [NonUeN2MessageTransfer_request]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(non_ue_n2_message_transfer_request->json_data) {
		cJSON *json_data_local_JSON =
			n2_information_transfer_req_data_convertToJSON(
				non_ue_n2_message_transfer_request->json_data);
		if(json_data_local_JSON == NULL) {
			printf(
				"non_ue_n2_message_transfer_request_convertToJSON() failed [json_data]");
			goto end;
		}
		cJSON_AddItemToObject(item, "jsonData", json_data_local_JSON);
		if(item->child == NULL) {
			printf(
				"non_ue_n2_message_transfer_request_convertToJSON() failed [json_data]");
			goto end;
		}
	}

	if(non_ue_n2_message_transfer_request->binary_data_n2_information) {
		char *encoded_str_binary_data_n2_information = base64encode(
			non_ue_n2_message_transfer_request->binary_data_n2_information->data,
			non_ue_n2_message_transfer_request->binary_data_n2_information->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2Information",
		                           encoded_str_binary_data_n2_information)
		   == NULL)
		{
			printf(
				"non_ue_n2_message_transfer_request_convertToJSON() failed [binary_data_n2_information]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information);
	}

end:
	return item;
}

non_ue_n2_message_transfer_request_t *
non_ue_n2_message_transfer_request_parseFromJSON(
	cJSON *non_ue_n2_message_transfer_requestJSON) {
	non_ue_n2_message_transfer_request_t *
	        non_ue_n2_message_transfer_request_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *json_data = NULL;
	n2_information_transfer_req_data_t *json_data_local_nonprim = NULL;
	cJSON *binary_data_n2_information = NULL;
	binary_t *decoded_str_binary_data_n2_information = NULL;
	json_data = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_message_transfer_requestJSON, "jsonData");
	if(json_data) {
		json_data_local_nonprim =
			n2_information_transfer_req_data_parseFromJSON(json_data);
		if(!json_data_local_nonprim) {
			printf(
				"n2_information_transfer_req_data_parseFromJSON failed [json_data]");
			goto end;
		}
	}

	binary_data_n2_information = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_message_transfer_requestJSON,
		"binaryDataN2Information");
	if(binary_data_n2_information) {
		decoded_str_binary_data_n2_information =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information)) {
			printf(
				"non_ue_n2_message_transfer_request_parseFromJSON() failed [binary_data_n2_information]");
			goto end;
		}
		decoded_str_binary_data_n2_information->data = base64decode(
			binary_data_n2_information->valuestring,
			strlen(
				binary_data_n2_information->valuestring),
			&decoded_str_binary_data_n2_information->len);
		if(!decoded_str_binary_data_n2_information->data) {
			printf(
				"non_ue_n2_message_transfer_request_parseFromJSON() failed [binary_data_n2_information]");
			goto end;
		}
	}

	non_ue_n2_message_transfer_request_local_var =
		non_ue_n2_message_transfer_request_create(
			json_data ? json_data_local_nonprim : NULL,
			binary_data_n2_information ? decoded_str_binary_data_n2_information : NULL
			);

	return non_ue_n2_message_transfer_request_local_var;
end:
	if(json_data_local_nonprim) {
		n2_information_transfer_req_data_free(json_data_local_nonprim);
		json_data_local_nonprim = NULL;
	}
	return NULL;
}

non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request_copy(
	non_ue_n2_message_transfer_request_t	*dst,
	non_ue_n2_message_transfer_request_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = non_ue_n2_message_transfer_request_convertToJSON(src);
	if(!item) {
		printf(
			"non_ue_n2_message_transfer_request_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	non_ue_n2_message_transfer_request_free(dst);
	dst = non_ue_n2_message_transfer_request_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
