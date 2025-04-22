#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_broadcast_assistance_types_data.h"

lcs_broadcast_assistance_types_data_t *
lcs_broadcast_assistance_types_data_create(binary_t *location_assistance_type) {
	lcs_broadcast_assistance_types_data_t *
	        lcs_broadcast_assistance_types_data_local_var =
		malloc(sizeof(lcs_broadcast_assistance_types_data_t));

	lcs_broadcast_assistance_types_data_local_var->location_assistance_type
	        = location_assistance_type;

	return lcs_broadcast_assistance_types_data_local_var;
}

void lcs_broadcast_assistance_types_data_free(
	lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data)
{
	lnode_t *node = NULL;

	if(NULL == lcs_broadcast_assistance_types_data) {
		return;
	}
	if(lcs_broadcast_assistance_types_data->location_assistance_type) {
		free(
			lcs_broadcast_assistance_types_data->location_assistance_type->data);
		lcs_broadcast_assistance_types_data->location_assistance_type =
			NULL;
	}
	free(lcs_broadcast_assistance_types_data);
}

cJSON *lcs_broadcast_assistance_types_data_convertToJSON(
	lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(lcs_broadcast_assistance_types_data == NULL) {
		printf(
			"lcs_broadcast_assistance_types_data_convertToJSON() failed [LcsBroadcastAssistanceTypesData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!lcs_broadcast_assistance_types_data->location_assistance_type) {
		printf(
			"lcs_broadcast_assistance_types_data_convertToJSON() failed [location_assistance_type]");
		return NULL;
	}
	char *encoded_str_location_assistance_type = base64encode(
		lcs_broadcast_assistance_types_data->location_assistance_type->data,
		lcs_broadcast_assistance_types_data->location_assistance_type->len);
	if(cJSON_AddStringToObject(item, "locationAssistanceType",
	                           encoded_str_location_assistance_type) ==
	   NULL)
	{
		printf(
			"lcs_broadcast_assistance_types_data_convertToJSON() failed [location_assistance_type]");
		goto end;
	}
	free(encoded_str_location_assistance_type);

end:
	return item;
}

lcs_broadcast_assistance_types_data_t *
lcs_broadcast_assistance_types_data_parseFromJSON(
	cJSON *lcs_broadcast_assistance_types_dataJSON) {
	lcs_broadcast_assistance_types_data_t *
	        lcs_broadcast_assistance_types_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *location_assistance_type = NULL;
	binary_t *decoded_str_location_assistance_type = NULL;
	location_assistance_type = cJSON_GetObjectItemCaseSensitive(
		lcs_broadcast_assistance_types_dataJSON,
		"locationAssistanceType");
	if(!location_assistance_type) {
		printf(
			"lcs_broadcast_assistance_types_data_parseFromJSON() failed [location_assistance_type]");
		goto end;
	}
	decoded_str_location_assistance_type = malloc(sizeof(binary_t));

	if(!cJSON_IsString(location_assistance_type)) {
		printf(
			"lcs_broadcast_assistance_types_data_parseFromJSON() failed [location_assistance_type]");
		goto end;
	}
	decoded_str_location_assistance_type->data = base64decode(
		location_assistance_type->valuestring,
		strlen(
			location_assistance_type->valuestring),
		&decoded_str_location_assistance_type->len);
	if(!decoded_str_location_assistance_type->data) {
		printf(
			"lcs_broadcast_assistance_types_data_parseFromJSON() failed [location_assistance_type]");
		goto end;
	}

	lcs_broadcast_assistance_types_data_local_var =
		lcs_broadcast_assistance_types_data_create(
			decoded_str_location_assistance_type
			);

	return lcs_broadcast_assistance_types_data_local_var;
end:
	return NULL;
}

lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_copy(
	lcs_broadcast_assistance_types_data_t	*dst,
	lcs_broadcast_assistance_types_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = lcs_broadcast_assistance_types_data_convertToJSON(src);
	if(!item) {
		printf(
			"lcs_broadcast_assistance_types_data_convertToJSON() failed");
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

	lcs_broadcast_assistance_types_data_free(dst);
	dst = lcs_broadcast_assistance_types_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
