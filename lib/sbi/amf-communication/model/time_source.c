#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_source.h"

time_source_t *time_source_create() {
	time_source_t *time_source_local_var = malloc(sizeof(time_source_t));


	return time_source_local_var;
}

void time_source_free(time_source_t *time_source) {
	lnode_t *node = NULL;

	if(NULL == time_source) {
		return;
	}
	free(time_source);
}

cJSON *time_source_convertToJSON(time_source_t *time_source) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(time_source == NULL) {
		printf("time_source_convertToJSON() failed [TimeSource]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

time_source_t *time_source_parseFromJSON(cJSON *time_sourceJSON) {
	time_source_t *time_source_local_var = NULL;
	lnode_t *node = NULL;
	time_source_local_var = time_source_create(
		);

	return time_source_local_var;
end:
	return NULL;
}

time_source_t *time_source_copy(time_source_t *dst, time_source_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = time_source_convertToJSON(src);
	if(!item) {
		printf("time_source_convertToJSON() failed");
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

	time_source_free(dst);
	dst = time_source_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
