#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geographic_area.h"

geographic_area_t *geographic_area_create(supported_gad_shapes_e shape,
                                          geographical_coordinates_t *point,
                                          float uncertainty,
                                          uncertainty_ellipse_t *uncertainty_ellipse, int confidence, list_t *point_list, double altitude, float uncertainty_altitude, bool is_v_confidence, int v_confidence, int inner_radius, float uncertainty_radius, int offset_angle,
                                          int included_angle) {
	geographic_area_t *geographic_area_local_var =
		malloc(sizeof(geographic_area_t));

	geographic_area_local_var->shape = shape;
	geographic_area_local_var->point = point;
	geographic_area_local_var->uncertainty = uncertainty;
	geographic_area_local_var->uncertainty_ellipse = uncertainty_ellipse;
	geographic_area_local_var->confidence = confidence;
	geographic_area_local_var->point_list = point_list;
	geographic_area_local_var->altitude = altitude;
	geographic_area_local_var->uncertainty_altitude = uncertainty_altitude;
	geographic_area_local_var->is_v_confidence = is_v_confidence;
	geographic_area_local_var->v_confidence = v_confidence;
	geographic_area_local_var->inner_radius = inner_radius;
	geographic_area_local_var->uncertainty_radius = uncertainty_radius;
	geographic_area_local_var->offset_angle = offset_angle;
	geographic_area_local_var->included_angle = included_angle;

	return geographic_area_local_var;
}

void geographic_area_free(geographic_area_t *geographic_area) {
	lnode_t *node = NULL;

	if(NULL == geographic_area) {
		return;
	}
	if(geographic_area->point) {
		geographical_coordinates_free(geographic_area->point);
		geographic_area->point = NULL;
	}
	if(geographic_area->uncertainty_ellipse) {
		uncertainty_ellipse_free(geographic_area->uncertainty_ellipse);
		geographic_area->uncertainty_ellipse = NULL;
	}
	if(geographic_area->point_list) {
		list_for_each(geographic_area->point_list, node) {
			geographical_coordinates_free(node->data);
		}
		list_free(geographic_area->point_list);
		geographic_area->point_list = NULL;
	}
	free(geographic_area);
}

cJSON *geographic_area_convertToJSON(geographic_area_t *geographic_area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(geographic_area == NULL) {
		printf("geographic_area_convertToJSON() failed [GeographicArea]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(geographic_area->shape == supported_gad_shapes_NULL) {
		printf("geographic_area_convertToJSON() failed [shape]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "shape",
	                           supported_gad_shapes_ToString(geographic_area
	                                                         ->shape)) ==
	   NULL)
	{
		printf("geographic_area_convertToJSON() failed [shape]");
		goto end;
	}

	if(!geographic_area->point) {
		printf("geographic_area_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = geographical_coordinates_convertToJSON(
		geographic_area->point);
	if(point_local_JSON == NULL) {
		printf("geographic_area_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf("geographic_area_convertToJSON() failed [point]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "uncertainty",
	                           geographic_area->uncertainty) == NULL)
	{
		printf("geographic_area_convertToJSON() failed [uncertainty]");
		goto end;
	}

	if(!geographic_area->uncertainty_ellipse) {
		printf(
			"geographic_area_convertToJSON() failed [uncertainty_ellipse]");
		return NULL;
	}
	cJSON *uncertainty_ellipse_local_JSON =
		uncertainty_ellipse_convertToJSON(
			geographic_area->uncertainty_ellipse);
	if(uncertainty_ellipse_local_JSON == NULL) {
		printf(
			"geographic_area_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	cJSON_AddItemToObject(item, "uncertaintyEllipse",
	                      uncertainty_ellipse_local_JSON);
	if(item->child == NULL) {
		printf(
			"geographic_area_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "confidence",
	                           geographic_area->confidence) == NULL)
	{
		printf("geographic_area_convertToJSON() failed [confidence]");
		goto end;
	}

	if(!geographic_area->point_list) {
		printf("geographic_area_convertToJSON() failed [point_list]");
		return NULL;
	}
	cJSON *point_listList = cJSON_AddArrayToObject(item, "pointList");
	if(point_listList == NULL) {
		printf("geographic_area_convertToJSON() failed [point_list]");
		goto end;
	}
	list_for_each(geographic_area->point_list, node) {
		cJSON *itemLocal = geographical_coordinates_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf(
				"geographic_area_convertToJSON() failed [point_list]");
			goto end;
		}
		cJSON_AddItemToArray(point_listList, itemLocal);
	}

	if(cJSON_AddNumberToObject(item, "altitude",
	                           geographic_area->altitude) == NULL)
	{
		printf("geographic_area_convertToJSON() failed [altitude]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "uncertaintyAltitude",
	                           geographic_area->uncertainty_altitude) ==
	   NULL)
	{
		printf(
			"geographic_area_convertToJSON() failed [uncertainty_altitude]");
		goto end;
	}

	if(geographic_area->is_v_confidence) {
		if(cJSON_AddNumberToObject(item, "vConfidence",
		                           geographic_area->v_confidence) ==
		   NULL)
		{
			printf(
				"geographic_area_convertToJSON() failed [v_confidence]");
			goto end;
		}
	}

	if(cJSON_AddNumberToObject(item, "innerRadius",
	                           geographic_area->inner_radius) == NULL)
	{
		printf("geographic_area_convertToJSON() failed [inner_radius]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "uncertaintyRadius",
	                           geographic_area->uncertainty_radius) == NULL)
	{
		printf(
			"geographic_area_convertToJSON() failed [uncertainty_radius]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "offsetAngle",
	                           geographic_area->offset_angle) == NULL)
	{
		printf("geographic_area_convertToJSON() failed [offset_angle]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "includedAngle",
	                           geographic_area->included_angle) == NULL)
	{
		printf("geographic_area_convertToJSON() failed [included_angle]");
		goto end;
	}

end:
	return item;
}

geographic_area_t *geographic_area_parseFromJSON(cJSON *geographic_areaJSON) {
	geographic_area_t *geographic_area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_e shapeVariable = 0;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	cJSON *uncertainty = NULL;
	cJSON *uncertainty_ellipse = NULL;
	uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;
	cJSON *confidence = NULL;
	cJSON *point_list = NULL;
	list_t *point_listList = NULL;
	cJSON *altitude = NULL;
	cJSON *uncertainty_altitude = NULL;
	cJSON *v_confidence = NULL;
	cJSON *inner_radius = NULL;
	cJSON *uncertainty_radius = NULL;
	cJSON *offset_angle = NULL;
	cJSON *included_angle = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "shape");
	if(!shape) {
		printf("geographic_area_parseFromJSON() failed [shape]");
		goto end;
	}
	if(!cJSON_IsString(shape)) {
		printf("geographic_area_parseFromJSON() failed [shape]");
		goto end;
	}
	shapeVariable = supported_gad_shapes_FromString(shape->valuestring);

	point = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "point");
	if(!point) {
		printf("geographic_area_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = geographical_coordinates_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf("geographical_coordinates_parseFromJSON failed [point]");
		goto end;
	}

	uncertainty = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                               "uncertainty");
	if(!uncertainty) {
		printf("geographic_area_parseFromJSON() failed [uncertainty]");
		goto end;
	}
	if(!cJSON_IsNumber(uncertainty)) {
		printf("geographic_area_parseFromJSON() failed [uncertainty]");
		goto end;
	}

	uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(
		geographic_areaJSON, "uncertaintyEllipse");
	if(!uncertainty_ellipse) {
		printf(
			"geographic_area_parseFromJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(
		uncertainty_ellipse);
	if(!uncertainty_ellipse_local_nonprim) {
		printf(
			"uncertainty_ellipse_parseFromJSON failed [uncertainty_ellipse]");
		goto end;
	}

	confidence = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                              "confidence");
	if(!confidence) {
		printf("geographic_area_parseFromJSON() failed [confidence]");
		goto end;
	}
	if(!cJSON_IsNumber(confidence)) {
		printf("geographic_area_parseFromJSON() failed [confidence]");
		goto end;
	}

	point_list = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                              "pointList");
	if(!point_list) {
		printf("geographic_area_parseFromJSON() failed [point_list]");
		goto end;
	}
	cJSON *point_list_local = NULL;
	if(!cJSON_IsArray(point_list)) {
		printf("geographic_area_parseFromJSON() failed [point_list]");
		goto end;
	}

	point_listList = list_create();

	cJSON_ArrayForEach(point_list_local, point_list) {
		if(!cJSON_IsObject(point_list_local)) {
			printf(
				"geographic_area_parseFromJSON() failed [point_list]");
			goto end;
		}
		geographical_coordinates_t *point_listItem =
			geographical_coordinates_parseFromJSON(point_list_local);
		if(!point_listItem) {
			printf("No point_listItem");
			goto end;
		}
		list_add(point_listList, point_listItem);
	}

	altitude = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                            "altitude");
	if(!altitude) {
		printf("geographic_area_parseFromJSON() failed [altitude]");
		goto end;
	}
	if(!cJSON_IsNumber(altitude)) {
		printf("geographic_area_parseFromJSON() failed [altitude]");
		goto end;
	}

	uncertainty_altitude = cJSON_GetObjectItemCaseSensitive(
		geographic_areaJSON, "uncertaintyAltitude");
	if(!uncertainty_altitude) {
		printf(
			"geographic_area_parseFromJSON() failed [uncertainty_altitude]");
		goto end;
	}
	if(!cJSON_IsNumber(uncertainty_altitude)) {
		printf(
			"geographic_area_parseFromJSON() failed [uncertainty_altitude]");
		goto end;
	}

	v_confidence = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                                "vConfidence");
	if(v_confidence) {
		if(!cJSON_IsNumber(v_confidence)) {
			printf(
				"geographic_area_parseFromJSON() failed [v_confidence]");
			goto end;
		}
	}

	inner_radius = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                                "innerRadius");
	if(!inner_radius) {
		printf("geographic_area_parseFromJSON() failed [inner_radius]");
		goto end;
	}
	if(!cJSON_IsNumber(inner_radius)) {
		printf("geographic_area_parseFromJSON() failed [inner_radius]");
		goto end;
	}

	uncertainty_radius = cJSON_GetObjectItemCaseSensitive(
		geographic_areaJSON, "uncertaintyRadius");
	if(!uncertainty_radius) {
		printf(
			"geographic_area_parseFromJSON() failed [uncertainty_radius]");
		goto end;
	}
	if(!cJSON_IsNumber(uncertainty_radius)) {
		printf(
			"geographic_area_parseFromJSON() failed [uncertainty_radius]");
		goto end;
	}

	offset_angle = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                                "offsetAngle");
	if(!offset_angle) {
		printf("geographic_area_parseFromJSON() failed [offset_angle]");
		goto end;
	}
	if(!cJSON_IsNumber(offset_angle)) {
		printf("geographic_area_parseFromJSON() failed [offset_angle]");
		goto end;
	}

	included_angle = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON,
	                                                  "includedAngle");
	if(!included_angle) {
		printf("geographic_area_parseFromJSON() failed [included_angle]");
		goto end;
	}
	if(!cJSON_IsNumber(included_angle)) {
		printf("geographic_area_parseFromJSON() failed [included_angle]");
		goto end;
	}

	geographic_area_local_var = geographic_area_create(
		shapeVariable,
		point_local_nonprim,

		uncertainty->valuedouble,
		uncertainty_ellipse_local_nonprim,

		confidence->valuedouble,
		point_listList,

		altitude->valuedouble,

		uncertainty_altitude->valuedouble,
		v_confidence ? true : false,
		v_confidence ? v_confidence->valuedouble : 0,

		inner_radius->valuedouble,

		uncertainty_radius->valuedouble,

		offset_angle->valuedouble,

		included_angle->valuedouble
		);

	return geographic_area_local_var;
end:
	if(point_local_nonprim) {
		geographical_coordinates_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	if(uncertainty_ellipse_local_nonprim) {
		uncertainty_ellipse_free(uncertainty_ellipse_local_nonprim);
		uncertainty_ellipse_local_nonprim = NULL;
	}
	if(point_listList) {
		list_for_each(point_listList, node) {
			geographical_coordinates_free(node->data);
		}
		list_free(point_listList);
		point_listList = NULL;
	}
	return NULL;
}

geographic_area_t *geographic_area_copy(geographic_area_t	*dst,
                                        geographic_area_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = geographic_area_convertToJSON(src);
	if(!item) {
		printf("geographic_area_convertToJSON() failed");
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

	geographic_area_free(dst);
	dst = geographic_area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
