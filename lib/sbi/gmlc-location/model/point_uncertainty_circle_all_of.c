#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_uncertainty_circle_all_of.h"

point_uncertainty_circle_all_of_t *point_uncertainty_circle_all_of_create(
	geographical_coordinates_t *point, float uncertainty) {
	point_uncertainty_circle_all_of_t *
	        point_uncertainty_circle_all_of_local_var =
		malloc(sizeof(point_uncertainty_circle_all_of_t));

	point_uncertainty_circle_all_of_local_var->point = point;
	point_uncertainty_circle_all_of_local_var->uncertainty = uncertainty;

	return point_uncertainty_circle_all_of_local_var;
}

void point_uncertainty_circle_all_of_free(
	point_uncertainty_circle_all_of_t *point_uncertainty_circle_all_of) {
	lnode_t *node = NULL;

	if(NULL == point_uncertainty_circle_all_of) {
		return;
	}
	if(point_uncertainty_circle_all_of->point) {
		geographical_coordinates_free(
			point_uncertainty_circle_all_of->point);
		point_uncertainty_circle_all_of->point = NULL;
	}
	free(point_uncertainty_circle_all_of);
}

cJSON *point_uncertainty_circle_all_of_convertToJSON(
	point_uncertainty_circle_all_of_t *point_uncertainty_circle_all_of) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(point_uncertainty_circle_all_of == NULL) {
		printf(
			"point_uncertainty_circle_all_of_convertToJSON() failed [PointUncertaintyCircle_allOf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!point_uncertainty_circle_all_of->point) {
		printf(
			"point_uncertainty_circle_all_of_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = geographical_coordinates_convertToJSON(
		point_uncertainty_circle_all_of->point);
	if(point_local_JSON == NULL) {
		printf(
			"point_uncertainty_circle_all_of_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf(
			"point_uncertainty_circle_all_of_convertToJSON() failed [point]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "uncertainty",
	                           point_uncertainty_circle_all_of->uncertainty)
	   == NULL)
	{
		printf(
			"point_uncertainty_circle_all_of_convertToJSON() failed [uncertainty]");
		goto end;
	}

end:
	return item;
}

point_uncertainty_circle_all_of_t *point_uncertainty_circle_all_of_parseFromJSON(
	cJSON *point_uncertainty_circle_all_ofJSON) {
	point_uncertainty_circle_all_of_t *
	        point_uncertainty_circle_all_of_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	cJSON *uncertainty = NULL;
	point = cJSON_GetObjectItemCaseSensitive(
		point_uncertainty_circle_all_ofJSON, "point");
	if(!point) {
		printf(
			"point_uncertainty_circle_all_of_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = geographical_coordinates_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf("geographical_coordinates_parseFromJSON failed [point]");
		goto end;
	}

	uncertainty = cJSON_GetObjectItemCaseSensitive(
		point_uncertainty_circle_all_ofJSON, "uncertainty");
	if(!uncertainty) {
		printf(
			"point_uncertainty_circle_all_of_parseFromJSON() failed [uncertainty]");
		goto end;
	}
	if(!cJSON_IsNumber(uncertainty)) {
		printf(
			"point_uncertainty_circle_all_of_parseFromJSON() failed [uncertainty]");
		goto end;
	}

	point_uncertainty_circle_all_of_local_var =
		point_uncertainty_circle_all_of_create(
			point_local_nonprim,

			uncertainty->valuedouble
			);

	return point_uncertainty_circle_all_of_local_var;
end:
	if(point_local_nonprim) {
		geographical_coordinates_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	return NULL;
}

point_uncertainty_circle_all_of_t *point_uncertainty_circle_all_of_copy(
	point_uncertainty_circle_all_of_t	*dst,
	point_uncertainty_circle_all_of_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = point_uncertainty_circle_all_of_convertToJSON(src);
	if(!item) {
		printf("point_uncertainty_circle_all_of_convertToJSON() failed");
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

	point_uncertainty_circle_all_of_free(dst);
	dst = point_uncertainty_circle_all_of_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
