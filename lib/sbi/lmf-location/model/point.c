#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point.h"

point_t *point_create(supported_gad_shapes_e		shape,
                      geographical_coordinates_t	*point) {
	point_t *point_local_var = malloc(sizeof(point_t));

	point_local_var->shape = shape;
	point_local_var->point = point;

	return point_local_var;
}

void point_free(point_t *point) {
	lnode_t *node = NULL;

	if(NULL == point) {
		return;
	}
	if(point->point) {
		geographical_coordinates_free(point->point);
		point->point = NULL;
	}
	free(point);
}

cJSON *point_convertToJSON(point_t *point) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(point == NULL) {
		printf("point_convertToJSON() failed [Point]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(point->shape == supported_gad_shapes_NULL) {
		printf("point_convertToJSON() failed [shape]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "shape",
	                           supported_gad_shapes_ToString(point->shape))
	   == NULL)
	{
		printf("point_convertToJSON() failed [shape]");
		goto end;
	}

	if(!point->point) {
		printf("point_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = geographical_coordinates_convertToJSON(
		point->point);
	if(point_local_JSON == NULL) {
		printf("point_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf("point_convertToJSON() failed [point]");
		goto end;
	}

end:
	return item;
}

point_t *point_parseFromJSON(cJSON *pointJSON) {
	point_t *point_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_e shapeVariable = 0;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(pointJSON, "shape");
	if(!shape) {
		printf("point_parseFromJSON() failed [shape]");
		goto end;
	}
	if(!cJSON_IsString(shape)) {
		printf("point_parseFromJSON() failed [shape]");
		goto end;
	}
	shapeVariable = supported_gad_shapes_FromString(shape->valuestring);

	point = cJSON_GetObjectItemCaseSensitive(pointJSON, "point");
	if(!point) {
		printf("point_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = geographical_coordinates_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf("geographical_coordinates_parseFromJSON failed [point]");
		goto end;
	}

	point_local_var = point_create(
		shapeVariable,
		point_local_nonprim
		);

	return point_local_var;
end:
	if(point_local_nonprim) {
		geographical_coordinates_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	return NULL;
}

point_t *point_copy(point_t *dst, point_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = point_convertToJSON(src);
	if(!item) {
		printf("point_convertToJSON() failed");
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

	point_free(dst);
	dst = point_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
