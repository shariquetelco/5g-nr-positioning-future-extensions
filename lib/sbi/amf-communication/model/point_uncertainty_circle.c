#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_uncertainty_circle.h"

point_uncertainty_circle_t *point_uncertainty_circle_create(
	supported_gad_shapes_t *shape, geographical_coordinates_t *point,
	float uncertainty) {
	point_uncertainty_circle_t *point_uncertainty_circle_local_var = malloc(
		sizeof(point_uncertainty_circle_t));

	point_uncertainty_circle_local_var->shape = shape;
	point_uncertainty_circle_local_var->point = point;
	point_uncertainty_circle_local_var->uncertainty = uncertainty;

	return point_uncertainty_circle_local_var;
}

void point_uncertainty_circle_free(
	point_uncertainty_circle_t *point_uncertainty_circle) {
	lnode_t *node = NULL;

	if(NULL == point_uncertainty_circle) {
		return;
	}
	if(point_uncertainty_circle->shape) {
		supported_gad_shapes_free(point_uncertainty_circle->shape);
		point_uncertainty_circle->shape = NULL;
	}
	if(point_uncertainty_circle->point) {
		geographical_coordinates_free(point_uncertainty_circle->point);
		point_uncertainty_circle->point = NULL;
	}
	free(point_uncertainty_circle);
}

cJSON *point_uncertainty_circle_convertToJSON(
	point_uncertainty_circle_t *point_uncertainty_circle) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(point_uncertainty_circle == NULL) {
		printf(
			"point_uncertainty_circle_convertToJSON() failed [PointUncertaintyCircle]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!point_uncertainty_circle->shape) {
		printf("point_uncertainty_circle_convertToJSON() failed [shape]");
		return NULL;
	}
	cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(
		point_uncertainty_circle->shape);
	if(shape_local_JSON == NULL) {
		printf("point_uncertainty_circle_convertToJSON() failed [shape]");
		goto end;
	}
	cJSON_AddItemToObject(item, "shape", shape_local_JSON);
	if(item->child == NULL) {
		printf("point_uncertainty_circle_convertToJSON() failed [shape]");
		goto end;
	}

	if(!point_uncertainty_circle->point) {
		printf("point_uncertainty_circle_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = geographical_coordinates_convertToJSON(
		point_uncertainty_circle->point);
	if(point_local_JSON == NULL) {
		printf("point_uncertainty_circle_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf("point_uncertainty_circle_convertToJSON() failed [point]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "uncertainty",
	                           point_uncertainty_circle->uncertainty) ==
	   NULL)
	{
		printf(
			"point_uncertainty_circle_convertToJSON() failed [uncertainty]");
		goto end;
	}

end:
	return item;
}

point_uncertainty_circle_t *point_uncertainty_circle_parseFromJSON(
	cJSON *point_uncertainty_circleJSON) {
	point_uncertainty_circle_t *point_uncertainty_circle_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_t *shape_local_nonprim = NULL;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	cJSON *uncertainty = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(point_uncertainty_circleJSON,
	                                         "shape");
	if(!shape) {
		printf("point_uncertainty_circle_parseFromJSON() failed [shape]");
		goto end;
	}
	shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape);
	if(!shape_local_nonprim) {
		printf("supported_gad_shapes_parseFromJSON failed [shape]");
		goto end;
	}

	point = cJSON_GetObjectItemCaseSensitive(point_uncertainty_circleJSON,
	                                         "point");
	if(!point) {
		printf("point_uncertainty_circle_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = geographical_coordinates_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf("geographical_coordinates_parseFromJSON failed [point]");
		goto end;
	}

	uncertainty = cJSON_GetObjectItemCaseSensitive(
		point_uncertainty_circleJSON, "uncertainty");
	if(!uncertainty) {
		printf(
			"point_uncertainty_circle_parseFromJSON() failed [uncertainty]");
		goto end;
	}
	if(!cJSON_IsNumber(uncertainty)) {
		printf(
			"point_uncertainty_circle_parseFromJSON() failed [uncertainty]");
		goto end;
	}

	point_uncertainty_circle_local_var = point_uncertainty_circle_create(
		shape_local_nonprim,
		point_local_nonprim,

		uncertainty->valuedouble
		);

	return point_uncertainty_circle_local_var;
end:
	if(shape_local_nonprim) {
		supported_gad_shapes_free(shape_local_nonprim);
		shape_local_nonprim = NULL;
	}
	if(point_local_nonprim) {
		geographical_coordinates_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	return NULL;
}

point_uncertainty_circle_t *point_uncertainty_circle_copy(
	point_uncertainty_circle_t *dst, point_uncertainty_circle_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = point_uncertainty_circle_convertToJSON(src);
	if(!item) {
		printf("point_uncertainty_circle_convertToJSON() failed");
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

	point_uncertainty_circle_free(dst);
	dst = point_uncertainty_circle_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
