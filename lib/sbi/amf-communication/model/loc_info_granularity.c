#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_info_granularity.h"

loc_info_granularity_t *loc_info_granularity_create() {
	loc_info_granularity_t *loc_info_granularity_local_var =
		malloc(sizeof(loc_info_granularity_t));


	return loc_info_granularity_local_var;
}

void loc_info_granularity_free(loc_info_granularity_t *loc_info_granularity) {
	lnode_t *node = NULL;

	if(NULL == loc_info_granularity) {
		return;
	}
	free(loc_info_granularity);
}

cJSON *loc_info_granularity_convertToJSON(
	loc_info_granularity_t *loc_info_granularity) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_info_granularity == NULL) {
		printf(
			"loc_info_granularity_convertToJSON() failed [LocInfoGranularity]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

loc_info_granularity_t *loc_info_granularity_parseFromJSON(
	cJSON *loc_info_granularityJSON) {
	loc_info_granularity_t *loc_info_granularity_local_var = NULL;
	lnode_t *node = NULL;
	loc_info_granularity_local_var = loc_info_granularity_create(
		);

	return loc_info_granularity_local_var;
end:
	return NULL;
}

loc_info_granularity_t *loc_info_granularity_copy(
	loc_info_granularity_t	*dst,
	loc_info_granularity_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_info_granularity_convertToJSON(src);
	if(!item) {
		printf("loc_info_granularity_convertToJSON() failed");
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

	loc_info_granularity_free(dst);
	dst = loc_info_granularity_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
