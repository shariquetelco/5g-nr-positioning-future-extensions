#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cipher_response_data.h"

cipher_response_data_t *cipher_response_data_create(
	data_availability_e data_availability) {
	cipher_response_data_t *cipher_response_data_local_var =
		malloc(sizeof(cipher_response_data_t));

	cipher_response_data_local_var->data_availability = data_availability;

	return cipher_response_data_local_var;
}

void cipher_response_data_free(cipher_response_data_t *cipher_response_data) {
	lnode_t *node = NULL;

	if(NULL == cipher_response_data) {
		return;
	}
	free(cipher_response_data);
}

cJSON *cipher_response_data_convertToJSON(
	cipher_response_data_t *cipher_response_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cipher_response_data == NULL) {
		printf(
			"cipher_response_data_convertToJSON() failed [CipherResponseData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cipher_response_data->data_availability == data_availability_NULL) {
		printf(
			"cipher_response_data_convertToJSON() failed [data_availability]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "dataAvailability",
	                           data_availability_ToString(
					   cipher_response_data->
					   data_availability)) ==
	   NULL)
	{
		printf(
			"cipher_response_data_convertToJSON() failed [data_availability]");
		goto end;
	}

end:
	return item;
}

cipher_response_data_t *cipher_response_data_parseFromJSON(
	cJSON *cipher_response_dataJSON) {
	cipher_response_data_t *cipher_response_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *data_availability = NULL;
	data_availability_e data_availabilityVariable = 0;
	data_availability = cJSON_GetObjectItemCaseSensitive(
		cipher_response_dataJSON, "dataAvailability");
	if(!data_availability) {
		printf(
			"cipher_response_data_parseFromJSON() failed [data_availability]");
		goto end;
	}
	if(!cJSON_IsString(data_availability)) {
		printf(
			"cipher_response_data_parseFromJSON() failed [data_availability]");
		goto end;
	}
	data_availabilityVariable = data_availability_FromString(
		data_availability->valuestring);

	cipher_response_data_local_var = cipher_response_data_create(
		data_availabilityVariable
		);

	return cipher_response_data_local_var;
end:
	return NULL;
}

cipher_response_data_t *cipher_response_data_copy(
	cipher_response_data_t	*dst,
	cipher_response_data_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = cipher_response_data_convertToJSON(src);
	if(!item) {
		printf("cipher_response_data_convertToJSON() failed");
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

	cipher_response_data_free(dst);
	dst = cipher_response_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
