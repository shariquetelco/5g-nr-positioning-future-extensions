#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supported_gad_shapes.h"

supported_gad_shapes_t *supported_gad_shapes_create() {
	supported_gad_shapes_t *supported_gad_shapes_local_var =
		malloc(sizeof(supported_gad_shapes_t));


	return supported_gad_shapes_local_var;
}

void supported_gad_shapes_free(supported_gad_shapes_t *supported_gad_shapes) {
	lnode_t *node = NULL;

	if(NULL == supported_gad_shapes) {
		return;
	}
	free(supported_gad_shapes);
}

cJSON *supported_gad_shapes_convertToJSON(
	supported_gad_shapes_t *supported_gad_shapes) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(supported_gad_shapes == NULL) {
		printf(
			"supported_gad_shapes_convertToJSON() failed [SupportedGADShapes]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

supported_gad_shapes_t *supported_gad_shapes_parseFromJSON(
	cJSON *supported_gad_shapesJSON) {
	supported_gad_shapes_t *supported_gad_shapes_local_var = NULL;
	lnode_t *node = NULL;
	supported_gad_shapes_local_var = supported_gad_shapes_create(
		);

	return supported_gad_shapes_local_var;
end:
	return NULL;
}

supported_gad_shapes_t *supported_gad_shapes_copy(
	supported_gad_shapes_t	*dst,
	supported_gad_shapes_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = supported_gad_shapes_convertToJSON(src);
	if(!item) {
		printf("supported_gad_shapes_convertToJSON() failed");
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

	supported_gad_shapes_free(dst);
	dst = supported_gad_shapes_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
