#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_relocate_ue_context_request.h"

cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request_create(
	ue_context_cancel_relocate_data_t	*json_data,
	binary_t				*binary_data_gtpc_message) {
	cancel_relocate_ue_context_request_t *
	        cancel_relocate_ue_context_request_local_var =
		malloc(sizeof(cancel_relocate_ue_context_request_t));

	cancel_relocate_ue_context_request_local_var->json_data = json_data;
	cancel_relocate_ue_context_request_local_var->binary_data_gtpc_message =
		binary_data_gtpc_message;

	return cancel_relocate_ue_context_request_local_var;
}

void cancel_relocate_ue_context_request_free(
	cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request)
{
	lnode_t *node = NULL;

	if(NULL == cancel_relocate_ue_context_request) {
		return;
	}
	if(cancel_relocate_ue_context_request->json_data) {
		ue_context_cancel_relocate_data_free(
			cancel_relocate_ue_context_request->json_data);
		cancel_relocate_ue_context_request->json_data = NULL;
	}
	if(cancel_relocate_ue_context_request->binary_data_gtpc_message) {
		free(
			cancel_relocate_ue_context_request->binary_data_gtpc_message->data);
		cancel_relocate_ue_context_request->binary_data_gtpc_message =
			NULL;
	}
	free(cancel_relocate_ue_context_request);
}

cJSON *cancel_relocate_ue_context_request_convertToJSON(
	cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cancel_relocate_ue_context_request == NULL) {
		printf(
			"cancel_relocate_ue_context_request_convertToJSON() failed [CancelRelocateUEContext_request]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cancel_relocate_ue_context_request->json_data) {
		cJSON *json_data_local_JSON =
			ue_context_cancel_relocate_data_convertToJSON(
				cancel_relocate_ue_context_request->json_data);
		if(json_data_local_JSON == NULL) {
			printf(
				"cancel_relocate_ue_context_request_convertToJSON() failed [json_data]");
			goto end;
		}
		cJSON_AddItemToObject(item, "jsonData", json_data_local_JSON);
		if(item->child == NULL) {
			printf(
				"cancel_relocate_ue_context_request_convertToJSON() failed [json_data]");
			goto end;
		}
	}

	if(cancel_relocate_ue_context_request->binary_data_gtpc_message) {
		char *encoded_str_binary_data_gtpc_message = base64encode(
			cancel_relocate_ue_context_request->binary_data_gtpc_message->data,
			cancel_relocate_ue_context_request->binary_data_gtpc_message->len);
		if(cJSON_AddStringToObject(item, "binaryDataGtpcMessage",
		                           encoded_str_binary_data_gtpc_message)
		   == NULL)
		{
			printf(
				"cancel_relocate_ue_context_request_convertToJSON() failed [binary_data_gtpc_message]");
			goto end;
		}
		free(encoded_str_binary_data_gtpc_message);
	}

end:
	return item;
}

cancel_relocate_ue_context_request_t *
cancel_relocate_ue_context_request_parseFromJSON(
	cJSON *cancel_relocate_ue_context_requestJSON) {
	cancel_relocate_ue_context_request_t *
	        cancel_relocate_ue_context_request_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *json_data = NULL;
	ue_context_cancel_relocate_data_t *json_data_local_nonprim = NULL;
	cJSON *binary_data_gtpc_message = NULL;
	binary_t *decoded_str_binary_data_gtpc_message = NULL;
	json_data = cJSON_GetObjectItemCaseSensitive(
		cancel_relocate_ue_context_requestJSON, "jsonData");
	if(json_data) {
		json_data_local_nonprim =
			ue_context_cancel_relocate_data_parseFromJSON(json_data);
		if(!json_data_local_nonprim) {
			printf(
				"ue_context_cancel_relocate_data_parseFromJSON failed [json_data]");
			goto end;
		}
	}

	binary_data_gtpc_message = cJSON_GetObjectItemCaseSensitive(
		cancel_relocate_ue_context_requestJSON,
		"binaryDataGtpcMessage");
	if(binary_data_gtpc_message) {
		decoded_str_binary_data_gtpc_message = malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_gtpc_message)) {
			printf(
				"cancel_relocate_ue_context_request_parseFromJSON() failed [binary_data_gtpc_message]");
			goto end;
		}
		decoded_str_binary_data_gtpc_message->data = base64decode(
			binary_data_gtpc_message->valuestring,
			strlen(
				binary_data_gtpc_message->valuestring),
			&decoded_str_binary_data_gtpc_message->len);
		if(!decoded_str_binary_data_gtpc_message->data) {
			printf(
				"cancel_relocate_ue_context_request_parseFromJSON() failed [binary_data_gtpc_message]");
			goto end;
		}
	}

	cancel_relocate_ue_context_request_local_var =
		cancel_relocate_ue_context_request_create(
			json_data ? json_data_local_nonprim : NULL,
			binary_data_gtpc_message ? decoded_str_binary_data_gtpc_message : NULL
			);

	return cancel_relocate_ue_context_request_local_var;
end:
	if(json_data_local_nonprim) {
		ue_context_cancel_relocate_data_free(json_data_local_nonprim);
		json_data_local_nonprim = NULL;
	}
	return NULL;
}

cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request_copy(
	cancel_relocate_ue_context_request_t	*dst,
	cancel_relocate_ue_context_request_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cancel_relocate_ue_context_request_convertToJSON(src);
	if(!item) {
		printf(
			"cancel_relocate_ue_context_request_convertToJSON() failed");
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

	cancel_relocate_ue_context_request_free(dst);
	dst = cancel_relocate_ue_context_request_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
