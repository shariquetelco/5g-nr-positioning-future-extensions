#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_privacy_ver_result.h"

location_privacy_ver_result_t *location_privacy_ver_result_create() {
	location_privacy_ver_result_t *location_privacy_ver_result_local_var =
		malloc(sizeof(location_privacy_ver_result_t));


	return location_privacy_ver_result_local_var;
}

void location_privacy_ver_result_free(
	location_privacy_ver_result_t *location_privacy_ver_result) {
	lnode_t *node = NULL;

	if(NULL == location_privacy_ver_result) {
		return;
	}
	free(location_privacy_ver_result);
}

cJSON *location_privacy_ver_result_convertToJSON(
	location_privacy_ver_result_t *location_privacy_ver_result) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(location_privacy_ver_result == NULL) {
		printf(
			"location_privacy_ver_result_convertToJSON() failed [LocationPrivacyVerResult]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

location_privacy_ver_result_t *location_privacy_ver_result_parseFromJSON(
	cJSON *location_privacy_ver_resultJSON) {
	location_privacy_ver_result_t *location_privacy_ver_result_local_var =
		NULL;
	lnode_t *node = NULL;
	location_privacy_ver_result_local_var =
		location_privacy_ver_result_create(
			);

	return location_privacy_ver_result_local_var;
end:
	return NULL;
}

location_privacy_ver_result_t *location_privacy_ver_result_copy(
	location_privacy_ver_result_t	*dst,
	location_privacy_ver_result_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = location_privacy_ver_result_convertToJSON(src);
	if(!item) {
		printf("location_privacy_ver_result_convertToJSON() failed");
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

	location_privacy_ver_result_free(dst);
	dst = location_privacy_ver_result_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
