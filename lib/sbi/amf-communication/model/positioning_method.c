#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_method.h"

positioning_method_t *positioning_method_create() {
	positioning_method_t *positioning_method_local_var =
		malloc(sizeof(positioning_method_t));


	return positioning_method_local_var;
}

void positioning_method_free(positioning_method_t *positioning_method) {
	lnode_t *node = NULL;

	if(NULL == positioning_method) {
		return;
	}
	free(positioning_method);
}

cJSON *positioning_method_convertToJSON(
	positioning_method_t *positioning_method) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(positioning_method == NULL) {
		printf(
			"positioning_method_convertToJSON() failed [PositioningMethod]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

positioning_method_t *positioning_method_parseFromJSON(
	cJSON *positioning_methodJSON) {
	positioning_method_t *positioning_method_local_var = NULL;
	lnode_t *node = NULL;
	positioning_method_local_var = positioning_method_create(
		);

	return positioning_method_local_var;
end:
	return NULL;
}

positioning_method_t *positioning_method_copy(positioning_method_t	*dst,
                                              positioning_method_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = positioning_method_convertToJSON(src);
	if(!item) {
		printf("positioning_method_convertToJSON() failed");
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

	positioning_method_free(dst);
	dst = positioning_method_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
