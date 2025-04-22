#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_altitude.h"

point_altitude_t *point_altitude_create(supported_gad_shapes_t		*shape,
                                        geographical_coordinates_t	*point,
                                        double				altitude)
{
	point_altitude_t *point_altitude_local_var =
		malloc(sizeof(point_altitude_t));

	point_altitude_local_var->shape = shape;
	point_altitude_local_var->point = point;
	point_altitude_local_var->altitude = altitude;

	return point_altitude_local_var;
}

void point_altitude_free(point_altitude_t *point_altitude) {
	lnode_t *node = NULL;

	if(NULL == point_altitude) {
		return;
	}
	if(point_altitude->shape) {
		supported_gad_shapes_free(point_altitude->shape);
		point_altitude->shape = NULL;
	}
	if(point_altitude->point) {
		geographical_coordinates_free(point_altitude->point);
		point_altitude->point = NULL;
	}
	free(point_altitude);
}

cJSON *point_altitude_convertToJSON(point_altitude_t *point_altitude) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(point_altitude == NULL) {
		printf("point_altitude_convertToJSON() failed [PointAltitude]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!point_altitude->shape) {
		printf("point_altitude_convertToJSON() failed [shape]");
		return NULL;
	}
	cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(
		point_altitude->shape);
	if(shape_local_JSON == NULL) {
		printf("point_altitude_convertToJSON() failed [shape]");
		goto end;
	}
	cJSON_AddItemToObject(item, "shape", shape_local_JSON);
	if(item->child == NULL) {
		printf("point_altitude_convertToJSON() failed [shape]");
		goto end;
	}

	if(!point_altitude->point) {
		printf("point_altitude_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = geographical_coordinates_convertToJSON(
		point_altitude->point);
	if(point_local_JSON == NULL) {
		printf("point_altitude_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf("point_altitude_convertToJSON() failed [point]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "altitude",
	                           point_altitude->altitude) == NULL)
	{
		printf("point_altitude_convertToJSON() failed [altitude]");
		goto end;
	}

end:
	return item;
}

point_altitude_t *point_altitude_parseFromJSON(cJSON *point_altitudeJSON) {
	point_altitude_t *point_altitude_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_t *shape_local_nonprim = NULL;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	cJSON *altitude = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(point_altitudeJSON, "shape");
	if(!shape) {
		printf("point_altitude_parseFromJSON() failed [shape]");
		goto end;
	}
	shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape);
	if(!shape_local_nonprim) {
		printf("supported_gad_shapes_parseFromJSON failed [shape]");
		goto end;
	}

	point = cJSON_GetObjectItemCaseSensitive(point_altitudeJSON, "point");
	if(!point) {
		printf("point_altitude_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = geographical_coordinates_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf("geographical_coordinates_parseFromJSON failed [point]");
		goto end;
	}

	altitude = cJSON_GetObjectItemCaseSensitive(point_altitudeJSON,
	                                            "altitude");
	if(!altitude) {
		printf("point_altitude_parseFromJSON() failed [altitude]");
		goto end;
	}
	if(!cJSON_IsNumber(altitude)) {
		printf("point_altitude_parseFromJSON() failed [altitude]");
		goto end;
	}

	point_altitude_local_var = point_altitude_create(
		shape_local_nonprim,
		point_local_nonprim,

		altitude->valuedouble
		);

	return point_altitude_local_var;
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

point_altitude_t *point_altitude_copy(point_altitude_t	*dst,
                                      point_altitude_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = point_altitude_convertToJSON(src);
	if(!item) {
		printf("point_altitude_convertToJSON() failed");
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

	point_altitude_free(dst);
	dst = point_altitude_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
