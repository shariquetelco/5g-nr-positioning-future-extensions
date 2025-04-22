#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gad_shape.h"

gad_shape_t *gad_shape_create(supported_gad_shapes_t *shape) {
	gad_shape_t *gad_shape_local_var = malloc(sizeof(gad_shape_t));

	gad_shape_local_var->shape = shape;

	return gad_shape_local_var;
}

void gad_shape_free(gad_shape_t *gad_shape) {
	lnode_t *node = NULL;

	if(NULL == gad_shape) {
		return;
	}
	if(gad_shape->shape) {
		supported_gad_shapes_free(gad_shape->shape);
		gad_shape->shape = NULL;
	}
	free(gad_shape);
}

cJSON *gad_shape_convertToJSON(gad_shape_t *gad_shape) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(gad_shape == NULL) {
		printf("gad_shape_convertToJSON() failed [GADShape]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!gad_shape->shape) {
		printf("gad_shape_convertToJSON() failed [shape]");
		return NULL;
	}
	cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(
		gad_shape->shape);
	if(shape_local_JSON == NULL) {
		printf("gad_shape_convertToJSON() failed [shape]");
		goto end;
	}
	cJSON_AddItemToObject(item, "shape", shape_local_JSON);
	if(item->child == NULL) {
		printf("gad_shape_convertToJSON() failed [shape]");
		goto end;
	}

end:
	return item;
}

gad_shape_t *gad_shape_parseFromJSON(cJSON *gad_shapeJSON) {
	gad_shape_t *gad_shape_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_t *shape_local_nonprim = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(gad_shapeJSON, "shape");
	if(!shape) {
		printf("gad_shape_parseFromJSON() failed [shape]");
		goto end;
	}
	shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape);
	if(!shape_local_nonprim) {
		printf("supported_gad_shapes_parseFromJSON failed [shape]");
		goto end;
	}

	gad_shape_local_var = gad_shape_create(
		shape_local_nonprim
		);

	return gad_shape_local_var;
end:
	if(shape_local_nonprim) {
		supported_gad_shapes_free(shape_local_nonprim);
		shape_local_nonprim = NULL;
	}
	return NULL;
}

gad_shape_t *gad_shape_copy(gad_shape_t *dst, gad_shape_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = gad_shape_convertToJSON(src);
	if(!item) {
		printf("gad_shape_convertToJSON() failed");
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

	gad_shape_free(dst);
	dst = gad_shape_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
