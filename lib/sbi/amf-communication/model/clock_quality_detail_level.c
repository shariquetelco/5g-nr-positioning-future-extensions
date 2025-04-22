#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "clock_quality_detail_level.h"

clock_quality_detail_level_t *clock_quality_detail_level_create() {
	clock_quality_detail_level_t *clock_quality_detail_level_local_var =
		malloc(sizeof(clock_quality_detail_level_t));


	return clock_quality_detail_level_local_var;
}

void clock_quality_detail_level_free(
	clock_quality_detail_level_t *clock_quality_detail_level) {
	lnode_t *node = NULL;

	if(NULL == clock_quality_detail_level) {
		return;
	}
	free(clock_quality_detail_level);
}

cJSON *clock_quality_detail_level_convertToJSON(
	clock_quality_detail_level_t *clock_quality_detail_level) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(clock_quality_detail_level == NULL) {
		printf(
			"clock_quality_detail_level_convertToJSON() failed [ClockQualityDetailLevel]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

clock_quality_detail_level_t *clock_quality_detail_level_parseFromJSON(
	cJSON *clock_quality_detail_levelJSON) {
	clock_quality_detail_level_t *clock_quality_detail_level_local_var =
		NULL;
	lnode_t *node = NULL;
	clock_quality_detail_level_local_var =
		clock_quality_detail_level_create(
			);

	return clock_quality_detail_level_local_var;
end:
	return NULL;
}

clock_quality_detail_level_t *clock_quality_detail_level_copy(
	clock_quality_detail_level_t *dst, clock_quality_detail_level_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = clock_quality_detail_level_convertToJSON(src);
	if(!item) {
		printf("clock_quality_detail_level_convertToJSON() failed");
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

	clock_quality_detail_level_free(dst);
	dst = clock_quality_detail_level_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
