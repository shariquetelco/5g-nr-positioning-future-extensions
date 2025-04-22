#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_context_transfer_request.h"

ue_context_transfer_request_t *ue_context_transfer_request_create(
	ue_context_transfer_req_data_t	*json_data,
	binary_t			*binary_data_n1_message) {
	ue_context_transfer_request_t *ue_context_transfer_request_local_var =
		malloc(sizeof(ue_context_transfer_request_t));

	ue_context_transfer_request_local_var->json_data = json_data;
	ue_context_transfer_request_local_var->binary_data_n1_message =
		binary_data_n1_message;

	return ue_context_transfer_request_local_var;
}

void ue_context_transfer_request_free(
	ue_context_transfer_request_t *ue_context_transfer_request) {
	lnode_t *node = NULL;

	if(NULL == ue_context_transfer_request) {
		return;
	}
	if(ue_context_transfer_request->json_data) {
		ue_context_transfer_req_data_free(
			ue_context_transfer_request->json_data);
		ue_context_transfer_request->json_data = NULL;
	}
	if(ue_context_transfer_request->binary_data_n1_message) {
		free(ue_context_transfer_request->binary_data_n1_message->data);
		ue_context_transfer_request->binary_data_n1_message = NULL;
	}
	free(ue_context_transfer_request);
}

cJSON *ue_context_transfer_request_convertToJSON(
	ue_context_transfer_request_t *ue_context_transfer_request) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_context_transfer_request == NULL) {
		printf(
			"ue_context_transfer_request_convertToJSON() failed [UEContextTransfer_request]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_context_transfer_request->json_data) {
		cJSON *json_data_local_JSON =
			ue_context_transfer_req_data_convertToJSON(
				ue_context_transfer_request->json_data);
		if(json_data_local_JSON == NULL) {
			printf(
				"ue_context_transfer_request_convertToJSON() failed [json_data]");
			goto end;
		}
		cJSON_AddItemToObject(item, "jsonData", json_data_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_transfer_request_convertToJSON() failed [json_data]");
			goto end;
		}
	}

	if(ue_context_transfer_request->binary_data_n1_message) {
		char *encoded_str_binary_data_n1_message = base64encode(
			ue_context_transfer_request->binary_data_n1_message->data,
			ue_context_transfer_request->binary_data_n1_message->len);
		if(cJSON_AddStringToObject(item, "binaryDataN1Message",
		                           encoded_str_binary_data_n1_message)
		   == NULL)
		{
			printf(
				"ue_context_transfer_request_convertToJSON() failed [binary_data_n1_message]");
			goto end;
		}
		free(encoded_str_binary_data_n1_message);
	}

end:
	return item;
}

ue_context_transfer_request_t *ue_context_transfer_request_parseFromJSON(
	cJSON *ue_context_transfer_requestJSON) {
	ue_context_transfer_request_t *ue_context_transfer_request_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *json_data = NULL;
	ue_context_transfer_req_data_t *json_data_local_nonprim = NULL;
	cJSON *binary_data_n1_message = NULL;
	binary_t *decoded_str_binary_data_n1_message = NULL;
	json_data = cJSON_GetObjectItemCaseSensitive(
		ue_context_transfer_requestJSON, "jsonData");
	if(json_data) {
		json_data_local_nonprim =
			ue_context_transfer_req_data_parseFromJSON(json_data);
		if(!json_data_local_nonprim) {
			printf(
				"ue_context_transfer_req_data_parseFromJSON failed [json_data]");
			goto end;
		}
	}

	binary_data_n1_message = cJSON_GetObjectItemCaseSensitive(
		ue_context_transfer_requestJSON, "binaryDataN1Message");
	if(binary_data_n1_message) {
		decoded_str_binary_data_n1_message = malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n1_message)) {
			printf(
				"ue_context_transfer_request_parseFromJSON() failed [binary_data_n1_message]");
			goto end;
		}
		decoded_str_binary_data_n1_message->data = base64decode(
			binary_data_n1_message->valuestring,
			strlen(
				binary_data_n1_message->valuestring),
			&decoded_str_binary_data_n1_message->len);
		if(!decoded_str_binary_data_n1_message->data) {
			printf(
				"ue_context_transfer_request_parseFromJSON() failed [binary_data_n1_message]");
			goto end;
		}
	}

	ue_context_transfer_request_local_var =
		ue_context_transfer_request_create(
			json_data ? json_data_local_nonprim : NULL,
			binary_data_n1_message ? decoded_str_binary_data_n1_message : NULL
			);

	return ue_context_transfer_request_local_var;
end:
	if(json_data_local_nonprim) {
		ue_context_transfer_req_data_free(json_data_local_nonprim);
		json_data_local_nonprim = NULL;
	}
	return NULL;
}

ue_context_transfer_request_t *ue_context_transfer_request_copy(
	ue_context_transfer_request_t	*dst,
	ue_context_transfer_request_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_context_transfer_request_convertToJSON(src);
	if(!item) {
		printf("ue_context_transfer_request_convertToJSON() failed");
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

	ue_context_transfer_request_free(dst);
	dst = ue_context_transfer_request_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
