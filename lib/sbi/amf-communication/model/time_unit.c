#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_unit.h"

time_unit_t *time_unit_create() {
	time_unit_t *time_unit_local_var = malloc(sizeof(time_unit_t));


	return time_unit_local_var;
}

void time_unit_free(time_unit_t *time_unit) {
	lnode_t *node = NULL;

	if(NULL == time_unit) {
		return;
	}
	free(time_unit);
}

cJSON *time_unit_convertToJSON(time_unit_t *time_unit) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(time_unit == NULL) {
		printf("time_unit_convertToJSON() failed [TimeUnit]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

time_unit_t *time_unit_parseFromJSON(cJSON *time_unitJSON) {
	time_unit_t *time_unit_local_var = NULL;
	lnode_t *node = NULL;
	time_unit_local_var = time_unit_create(
		);

	return time_unit_local_var;
end:
	return NULL;
}

time_unit_t *time_unit_copy(time_unit_t *dst, time_unit_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = time_unit_convertToJSON(src);
	if(!item) {
		printf("time_unit_convertToJSON() failed");
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

	time_unit_free(dst);
	dst = time_unit_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
