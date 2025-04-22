#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_ue_context_403_response.h"

create_ue_context_403_response_t *create_ue_context_403_response_create(
	ue_context_create_error_t	*json_data,
	binary_t			*binary_data_n2_information) {
	create_ue_context_403_response_t *
	        create_ue_context_403_response_local_var =
		malloc(sizeof(create_ue_context_403_response_t));

	create_ue_context_403_response_local_var->json_data = json_data;
	create_ue_context_403_response_local_var->binary_data_n2_information =
		binary_data_n2_information;

	return create_ue_context_403_response_local_var;
}

void create_ue_context_403_response_free(
	create_ue_context_403_response_t *create_ue_context_403_response) {
	lnode_t *node = NULL;

	if(NULL == create_ue_context_403_response) {
		return;
	}
	if(create_ue_context_403_response->json_data) {
		ue_context_create_error_free(
			create_ue_context_403_response->json_data);
		create_ue_context_403_response->json_data = NULL;
	}
	if(create_ue_context_403_response->binary_data_n2_information) {
		free(
			create_ue_context_403_response->binary_data_n2_information->data);
		create_ue_context_403_response->binary_data_n2_information =
			NULL;
	}
	free(create_ue_context_403_response);
}

cJSON *create_ue_context_403_response_convertToJSON(
	create_ue_context_403_response_t *create_ue_context_403_response) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(create_ue_context_403_response == NULL) {
		printf(
			"create_ue_context_403_response_convertToJSON() failed [CreateUEContext_403_response]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(create_ue_context_403_response->json_data) {
		cJSON *json_data_local_JSON =
			ue_context_create_error_convertToJSON(
				create_ue_context_403_response->json_data);
		if(json_data_local_JSON == NULL) {
			printf(
				"create_ue_context_403_response_convertToJSON() failed [json_data]");
			goto end;
		}
		cJSON_AddItemToObject(item, "jsonData", json_data_local_JSON);
		if(item->child == NULL) {
			printf(
				"create_ue_context_403_response_convertToJSON() failed [json_data]");
			goto end;
		}
	}

	if(create_ue_context_403_response->binary_data_n2_information) {
		char *encoded_str_binary_data_n2_information = base64encode(
			create_ue_context_403_response->binary_data_n2_information->data,
			create_ue_context_403_response->binary_data_n2_information->len);
		if(cJSON_AddStringToObject(item, "binaryDataN2Information",
		                           encoded_str_binary_data_n2_information)
		   == NULL)
		{
			printf(
				"create_ue_context_403_response_convertToJSON() failed [binary_data_n2_information]");
			goto end;
		}
		free(encoded_str_binary_data_n2_information);
	}

end:
	return item;
}

create_ue_context_403_response_t *create_ue_context_403_response_parseFromJSON(
	cJSON *create_ue_context_403_responseJSON) {
	create_ue_context_403_response_t *
	        create_ue_context_403_response_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *json_data = NULL;
	ue_context_create_error_t *json_data_local_nonprim = NULL;
	cJSON *binary_data_n2_information = NULL;
	binary_t *decoded_str_binary_data_n2_information = NULL;
	json_data = cJSON_GetObjectItemCaseSensitive(
		create_ue_context_403_responseJSON, "jsonData");
	if(json_data) {
		json_data_local_nonprim = ue_context_create_error_parseFromJSON(
			json_data);
		if(!json_data_local_nonprim) {
			printf(
				"ue_context_create_error_parseFromJSON failed [json_data]");
			goto end;
		}
	}

	binary_data_n2_information = cJSON_GetObjectItemCaseSensitive(
		create_ue_context_403_responseJSON, "binaryDataN2Information");
	if(binary_data_n2_information) {
		decoded_str_binary_data_n2_information =
			malloc(sizeof(binary_t));

		if(!cJSON_IsString(binary_data_n2_information)) {
			printf(
				"create_ue_context_403_response_parseFromJSON() failed [binary_data_n2_information]");
			goto end;
		}
		decoded_str_binary_data_n2_information->data = base64decode(
			binary_data_n2_information->valuestring,
			strlen(
				binary_data_n2_information->valuestring),
			&decoded_str_binary_data_n2_information->len);
		if(!decoded_str_binary_data_n2_information->data) {
			printf(
				"create_ue_context_403_response_parseFromJSON() failed [binary_data_n2_information]");
			goto end;
		}
	}

	create_ue_context_403_response_local_var =
		create_ue_context_403_response_create(
			json_data ? json_data_local_nonprim : NULL,
			binary_data_n2_information ? decoded_str_binary_data_n2_information : NULL
			);

	return create_ue_context_403_response_local_var;
end:
	if(json_data_local_nonprim) {
		ue_context_create_error_free(json_data_local_nonprim);
		json_data_local_nonprim = NULL;
	}
	return NULL;
}

create_ue_context_403_response_t *create_ue_context_403_response_copy(
	create_ue_context_403_response_t	*dst,
	create_ue_context_403_response_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = create_ue_context_403_response_convertToJSON(src);
	if(!item) {
		printf("create_ue_context_403_response_convertToJSON() failed");
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

	create_ue_context_403_response_free(dst);
	dst = create_ue_context_403_response_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
