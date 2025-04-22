#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_method_mdt.h"

positioning_method_mdt_t *positioning_method_mdt_create() {
	positioning_method_mdt_t *positioning_method_mdt_local_var = malloc(
		sizeof(positioning_method_mdt_t));


	return positioning_method_mdt_local_var;
}

void positioning_method_mdt_free(
	positioning_method_mdt_t *positioning_method_mdt) {
	lnode_t *node = NULL;

	if(NULL == positioning_method_mdt) {
		return;
	}
	free(positioning_method_mdt);
}

cJSON *positioning_method_mdt_convertToJSON(
	positioning_method_mdt_t *positioning_method_mdt) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(positioning_method_mdt == NULL) {
		printf(
			"positioning_method_mdt_convertToJSON() failed [PositioningMethodMdt]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

positioning_method_mdt_t *positioning_method_mdt_parseFromJSON(
	cJSON *positioning_method_mdtJSON) {
	positioning_method_mdt_t *positioning_method_mdt_local_var = NULL;
	lnode_t *node = NULL;
	positioning_method_mdt_local_var = positioning_method_mdt_create(
		);

	return positioning_method_mdt_local_var;
end:
	return NULL;
}

positioning_method_mdt_t *positioning_method_mdt_copy(
	positioning_method_mdt_t *dst, positioning_method_mdt_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = positioning_method_mdt_convertToJSON(src);
	if(!item) {
		printf("positioning_method_mdt_convertToJSON() failed");
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

	positioning_method_mdt_free(dst);
	dst = positioning_method_mdt_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
