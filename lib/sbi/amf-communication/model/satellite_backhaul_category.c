#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "satellite_backhaul_category.h"

satellite_backhaul_category_t *satellite_backhaul_category_create() {
	satellite_backhaul_category_t *satellite_backhaul_category_local_var =
		malloc(sizeof(satellite_backhaul_category_t));


	return satellite_backhaul_category_local_var;
}

void satellite_backhaul_category_free(
	satellite_backhaul_category_t *satellite_backhaul_category) {
	lnode_t *node = NULL;

	if(NULL == satellite_backhaul_category) {
		return;
	}
	free(satellite_backhaul_category);
}

cJSON *satellite_backhaul_category_convertToJSON(
	satellite_backhaul_category_t *satellite_backhaul_category) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(satellite_backhaul_category == NULL) {
		printf(
			"satellite_backhaul_category_convertToJSON() failed [SatelliteBackhaulCategory]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

satellite_backhaul_category_t *satellite_backhaul_category_parseFromJSON(
	cJSON *satellite_backhaul_categoryJSON) {
	satellite_backhaul_category_t *satellite_backhaul_category_local_var =
		NULL;
	lnode_t *node = NULL;
	satellite_backhaul_category_local_var =
		satellite_backhaul_category_create(
			);

	return satellite_backhaul_category_local_var;
end:
	return NULL;
}

satellite_backhaul_category_t *satellite_backhaul_category_copy(
	satellite_backhaul_category_t	*dst,
	satellite_backhaul_category_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = satellite_backhaul_category_convertToJSON(src);
	if(!item) {
		printf("satellite_backhaul_category_convertToJSON() failed");
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

	satellite_backhaul_category_free(dst);
	dst = satellite_backhaul_category_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
