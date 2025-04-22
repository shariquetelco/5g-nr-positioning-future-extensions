#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_filter.h"

location_filter_t *location_filter_create() {
	location_filter_t *location_filter_local_var =
		malloc(sizeof(location_filter_t));


	return location_filter_local_var;
}

void location_filter_free(location_filter_t *location_filter) {
	lnode_t *node = NULL;

	if(NULL == location_filter) {
		return;
	}
	free(location_filter);
}

cJSON *location_filter_convertToJSON(location_filter_t *location_filter) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(location_filter == NULL) {
		printf("location_filter_convertToJSON() failed [LocationFilter]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

location_filter_t *location_filter_parseFromJSON(cJSON *location_filterJSON) {
	location_filter_t *location_filter_local_var = NULL;
	lnode_t *node = NULL;
	location_filter_local_var = location_filter_create(
		);

	return location_filter_local_var;
end:
	return NULL;
}

location_filter_t *location_filter_copy(location_filter_t	*dst,
                                        location_filter_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = location_filter_convertToJSON(src);
	if(!item) {
		printf("location_filter_convertToJSON() failed");
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

	location_filter_free(dst);
	dst = location_filter_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
