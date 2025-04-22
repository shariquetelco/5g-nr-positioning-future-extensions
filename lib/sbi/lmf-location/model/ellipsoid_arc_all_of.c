#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ellipsoid_arc_all_of.h"

ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_create(
	geographical_coordinates_t *point, int inner_radius,
	float uncertainty_radius, int offset_angle, int included_angle,
	int confidence) {
	ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_local_var =
		malloc(sizeof(ellipsoid_arc_all_of_t));

	ellipsoid_arc_all_of_local_var->point = point;
	ellipsoid_arc_all_of_local_var->inner_radius = inner_radius;
	ellipsoid_arc_all_of_local_var->uncertainty_radius = uncertainty_radius;
	ellipsoid_arc_all_of_local_var->offset_angle = offset_angle;
	ellipsoid_arc_all_of_local_var->included_angle = included_angle;
	ellipsoid_arc_all_of_local_var->confidence = confidence;

	return ellipsoid_arc_all_of_local_var;
}

void ellipsoid_arc_all_of_free(ellipsoid_arc_all_of_t *ellipsoid_arc_all_of) {
	lnode_t *node = NULL;

	if(NULL == ellipsoid_arc_all_of) {
		return;
	}
	if(ellipsoid_arc_all_of->point) {
		geographical_coordinates_free(ellipsoid_arc_all_of->point);
		ellipsoid_arc_all_of->point = NULL;
	}
	free(ellipsoid_arc_all_of);
}

cJSON *ellipsoid_arc_all_of_convertToJSON(
	ellipsoid_arc_all_of_t *ellipsoid_arc_all_of) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ellipsoid_arc_all_of == NULL) {
		printf(
			"ellipsoid_arc_all_of_convertToJSON() failed [EllipsoidArc_allOf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ellipsoid_arc_all_of->point) {
		printf("ellipsoid_arc_all_of_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = geographical_coordinates_convertToJSON(
		ellipsoid_arc_all_of->point);
	if(point_local_JSON == NULL) {
		printf("ellipsoid_arc_all_of_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf("ellipsoid_arc_all_of_convertToJSON() failed [point]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "innerRadius",
	                           ellipsoid_arc_all_of->inner_radius) == NULL)
	{
		printf(
			"ellipsoid_arc_all_of_convertToJSON() failed [inner_radius]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "uncertaintyRadius",
	                           ellipsoid_arc_all_of->uncertainty_radius) ==
	   NULL)
	{
		printf(
			"ellipsoid_arc_all_of_convertToJSON() failed [uncertainty_radius]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "offsetAngle",
	                           ellipsoid_arc_all_of->offset_angle) == NULL)
	{
		printf(
			"ellipsoid_arc_all_of_convertToJSON() failed [offset_angle]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "includedAngle",
	                           ellipsoid_arc_all_of->included_angle) ==
	   NULL)
	{
		printf(
			"ellipsoid_arc_all_of_convertToJSON() failed [included_angle]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "confidence",
	                           ellipsoid_arc_all_of->confidence) == NULL)
	{
		printf(
			"ellipsoid_arc_all_of_convertToJSON() failed [confidence]");
		goto end;
	}

end:
	return item;
}

ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_parseFromJSON(
	cJSON *ellipsoid_arc_all_ofJSON) {
	ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	cJSON *inner_radius = NULL;
	cJSON *uncertainty_radius = NULL;
	cJSON *offset_angle = NULL;
	cJSON *included_angle = NULL;
	cJSON *confidence = NULL;
	point = cJSON_GetObjectItemCaseSensitive(ellipsoid_arc_all_ofJSON,
	                                         "point");
	if(!point) {
		printf("ellipsoid_arc_all_of_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = geographical_coordinates_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf("geographical_coordinates_parseFromJSON failed [point]");
		goto end;
	}

	inner_radius = cJSON_GetObjectItemCaseSensitive(
		ellipsoid_arc_all_ofJSON, "innerRadius");
	if(!inner_radius) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [inner_radius]");
		goto end;
	}
	if(!cJSON_IsNumber(inner_radius)) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [inner_radius]");
		goto end;
	}

	uncertainty_radius = cJSON_GetObjectItemCaseSensitive(
		ellipsoid_arc_all_ofJSON, "uncertaintyRadius");
	if(!uncertainty_radius) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [uncertainty_radius]");
		goto end;
	}
	if(!cJSON_IsNumber(uncertainty_radius)) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [uncertainty_radius]");
		goto end;
	}

	offset_angle = cJSON_GetObjectItemCaseSensitive(
		ellipsoid_arc_all_ofJSON, "offsetAngle");
	if(!offset_angle) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [offset_angle]");
		goto end;
	}
	if(!cJSON_IsNumber(offset_angle)) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [offset_angle]");
		goto end;
	}

	included_angle = cJSON_GetObjectItemCaseSensitive(
		ellipsoid_arc_all_ofJSON, "includedAngle");
	if(!included_angle) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [included_angle]");
		goto end;
	}
	if(!cJSON_IsNumber(included_angle)) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [included_angle]");
		goto end;
	}

	confidence = cJSON_GetObjectItemCaseSensitive(ellipsoid_arc_all_ofJSON,
	                                              "confidence");
	if(!confidence) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [confidence]");
		goto end;
	}
	if(!cJSON_IsNumber(confidence)) {
		printf(
			"ellipsoid_arc_all_of_parseFromJSON() failed [confidence]");
		goto end;
	}

	ellipsoid_arc_all_of_local_var = ellipsoid_arc_all_of_create(
		point_local_nonprim,

		inner_radius->valuedouble,

		uncertainty_radius->valuedouble,

		offset_angle->valuedouble,

		included_angle->valuedouble,

		confidence->valuedouble
		);

	return ellipsoid_arc_all_of_local_var;
end:
	if(point_local_nonprim) {
		geographical_coordinates_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	return NULL;
}

ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_copy(
	ellipsoid_arc_all_of_t	*dst,
	ellipsoid_arc_all_of_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = ellipsoid_arc_all_of_convertToJSON(src);
	if(!item) {
		printf("ellipsoid_arc_all_of_convertToJSON() failed");
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

	ellipsoid_arc_all_of_free(dst);
	dst = ellipsoid_arc_all_of_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
