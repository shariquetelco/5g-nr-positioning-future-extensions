#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "expected_analytics_type.h"

expected_analytics_type_t *expected_analytics_type_create() {
	expected_analytics_type_t *expected_analytics_type_local_var = malloc(
		sizeof(expected_analytics_type_t));


	return expected_analytics_type_local_var;
}

void expected_analytics_type_free(
	expected_analytics_type_t *expected_analytics_type) {
	lnode_t *node = NULL;

	if(NULL == expected_analytics_type) {
		return;
	}
	free(expected_analytics_type);
}

cJSON *expected_analytics_type_convertToJSON(
	expected_analytics_type_t *expected_analytics_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(expected_analytics_type == NULL) {
		printf(
			"expected_analytics_type_convertToJSON() failed [ExpectedAnalyticsType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

expected_analytics_type_t *expected_analytics_type_parseFromJSON(
	cJSON *expected_analytics_typeJSON) {
	expected_analytics_type_t *expected_analytics_type_local_var = NULL;
	lnode_t *node = NULL;
	expected_analytics_type_local_var = expected_analytics_type_create(
		);

	return expected_analytics_type_local_var;
end:
	return NULL;
}

expected_analytics_type_t *expected_analytics_type_copy(
	expected_analytics_type_t *dst, expected_analytics_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = expected_analytics_type_convertToJSON(src);
	if(!item) {
		printf("expected_analytics_type_convertToJSON() failed");
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

	expected_analytics_type_free(dst);
	dst = expected_analytics_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
