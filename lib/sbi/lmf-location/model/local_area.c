#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local_area.h"

local_area_t *local_area_create(supported_gad_shapes_e		shape,
                                local_origin_t			*local_origin,
                                relative_cartesian_location_t	*point,
                                uncertainty_ellipse_t		*uncertainty_ellipse,
                                int				confidence,
                                uncertainty_ellipsoid_t		*uncertainty_ellipsoid)
{
	local_area_t *local_area_local_var = malloc(sizeof(local_area_t));

	local_area_local_var->shape = shape;
	local_area_local_var->local_origin = local_origin;
	local_area_local_var->point = point;
	local_area_local_var->uncertainty_ellipse = uncertainty_ellipse;
	local_area_local_var->confidence = confidence;
	local_area_local_var->uncertainty_ellipsoid = uncertainty_ellipsoid;

	return local_area_local_var;
}

void local_area_free(local_area_t *local_area) {
	lnode_t *node = NULL;

	if(NULL == local_area) {
		return;
	}
	if(local_area->local_origin) {
		local_origin_free(local_area->local_origin);
		local_area->local_origin = NULL;
	}
	if(local_area->point) {
		relative_cartesian_location_free(local_area->point);
		local_area->point = NULL;
	}
	if(local_area->uncertainty_ellipse) {
		uncertainty_ellipse_free(local_area->uncertainty_ellipse);
		local_area->uncertainty_ellipse = NULL;
	}
	if(local_area->uncertainty_ellipsoid) {
		uncertainty_ellipsoid_free(local_area->uncertainty_ellipsoid);
		local_area->uncertainty_ellipsoid = NULL;
	}
	free(local_area);
}

cJSON *local_area_convertToJSON(local_area_t *local_area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(local_area == NULL) {
		printf("local_area_convertToJSON() failed [LocalArea]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(local_area->shape == supported_gad_shapes_NULL) {
		printf("local_area_convertToJSON() failed [shape]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "shape",
	                           supported_gad_shapes_ToString(local_area->
	                                                         shape)) ==
	   NULL)
	{
		printf("local_area_convertToJSON() failed [shape]");
		goto end;
	}

	if(!local_area->local_origin) {
		printf("local_area_convertToJSON() failed [local_origin]");
		return NULL;
	}
	cJSON *local_origin_local_JSON = local_origin_convertToJSON(
		local_area->local_origin);
	if(local_origin_local_JSON == NULL) {
		printf("local_area_convertToJSON() failed [local_origin]");
		goto end;
	}
	cJSON_AddItemToObject(item, "localOrigin", local_origin_local_JSON);
	if(item->child == NULL) {
		printf("local_area_convertToJSON() failed [local_origin]");
		goto end;
	}

	if(!local_area->point) {
		printf("local_area_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = relative_cartesian_location_convertToJSON(
		local_area->point);
	if(point_local_JSON == NULL) {
		printf("local_area_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf("local_area_convertToJSON() failed [point]");
		goto end;
	}

	if(!local_area->uncertainty_ellipse) {
		printf("local_area_convertToJSON() failed [uncertainty_ellipse]");
		return NULL;
	}
	cJSON *uncertainty_ellipse_local_JSON =
		uncertainty_ellipse_convertToJSON(
			local_area->uncertainty_ellipse);
	if(uncertainty_ellipse_local_JSON == NULL) {
		printf("local_area_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	cJSON_AddItemToObject(item, "uncertaintyEllipse",
	                      uncertainty_ellipse_local_JSON);
	if(item->child == NULL) {
		printf("local_area_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "confidence",
	                           local_area->confidence) == NULL)
	{
		printf("local_area_convertToJSON() failed [confidence]");
		goto end;
	}

	if(!local_area->uncertainty_ellipsoid) {
		printf(
			"local_area_convertToJSON() failed [uncertainty_ellipsoid]");
		return NULL;
	}
	cJSON *uncertainty_ellipsoid_local_JSON =
		uncertainty_ellipsoid_convertToJSON(
			local_area->uncertainty_ellipsoid);
	if(uncertainty_ellipsoid_local_JSON == NULL) {
		printf(
			"local_area_convertToJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}
	cJSON_AddItemToObject(item, "uncertaintyEllipsoid",
	                      uncertainty_ellipsoid_local_JSON);
	if(item->child == NULL) {
		printf(
			"local_area_convertToJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}

end:
	return item;
}

local_area_t *local_area_parseFromJSON(cJSON *local_areaJSON) {
	local_area_t *local_area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_e shapeVariable = 0;
	cJSON *local_origin = NULL;
	local_origin_t *local_origin_local_nonprim = NULL;
	cJSON *point = NULL;
	relative_cartesian_location_t *point_local_nonprim = NULL;
	cJSON *uncertainty_ellipse = NULL;
	uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;
	cJSON *confidence = NULL;
	cJSON *uncertainty_ellipsoid = NULL;
	uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_nonprim = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "shape");
	if(!shape) {
		printf("local_area_parseFromJSON() failed [shape]");
		goto end;
	}
	if(!cJSON_IsString(shape)) {
		printf("local_area_parseFromJSON() failed [shape]");
		goto end;
	}
	shapeVariable = supported_gad_shapes_FromString(shape->valuestring);

	local_origin = cJSON_GetObjectItemCaseSensitive(local_areaJSON,
	                                                "localOrigin");
	if(!local_origin) {
		printf("local_area_parseFromJSON() failed [local_origin]");
		goto end;
	}
	local_origin_local_nonprim = local_origin_parseFromJSON(local_origin);
	if(!local_origin_local_nonprim) {
		printf("local_origin_parseFromJSON failed [local_origin]");
		goto end;
	}

	point = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "point");
	if(!point) {
		printf("local_area_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = relative_cartesian_location_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf(
			"relative_cartesian_location_parseFromJSON failed [point]");
		goto end;
	}

	uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(local_areaJSON,
	                                                       "uncertaintyEllipse");
	if(!uncertainty_ellipse) {
		printf("local_area_parseFromJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(
		uncertainty_ellipse);
	if(!uncertainty_ellipse_local_nonprim) {
		printf(
			"uncertainty_ellipse_parseFromJSON failed [uncertainty_ellipse]");
		goto end;
	}

	confidence = cJSON_GetObjectItemCaseSensitive(local_areaJSON,
	                                              "confidence");
	if(!confidence) {
		printf("local_area_parseFromJSON() failed [confidence]");
		goto end;
	}
	if(!cJSON_IsNumber(confidence)) {
		printf("local_area_parseFromJSON() failed [confidence]");
		goto end;
	}

	uncertainty_ellipsoid = cJSON_GetObjectItemCaseSensitive(local_areaJSON,
	                                                         "uncertaintyEllipsoid");
	if(!uncertainty_ellipsoid) {
		printf(
			"local_area_parseFromJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}
	uncertainty_ellipsoid_local_nonprim =
		uncertainty_ellipsoid_parseFromJSON(uncertainty_ellipsoid);
	if(!uncertainty_ellipsoid_local_nonprim) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON failed [uncertainty_ellipsoid]");
		goto end;
	}

	local_area_local_var = local_area_create(
		shapeVariable,
		local_origin_local_nonprim,
		point_local_nonprim,
		uncertainty_ellipse_local_nonprim,

		confidence->valuedouble,
		uncertainty_ellipsoid_local_nonprim
		);

	return local_area_local_var;
end:
	if(local_origin_local_nonprim) {
		local_origin_free(local_origin_local_nonprim);
		local_origin_local_nonprim = NULL;
	}
	if(point_local_nonprim) {
		relative_cartesian_location_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	if(uncertainty_ellipse_local_nonprim) {
		uncertainty_ellipse_free(uncertainty_ellipse_local_nonprim);
		uncertainty_ellipse_local_nonprim = NULL;
	}
	if(uncertainty_ellipsoid_local_nonprim) {
		uncertainty_ellipsoid_free(uncertainty_ellipsoid_local_nonprim);
		uncertainty_ellipsoid_local_nonprim = NULL;
	}
	return NULL;
}

local_area_t *local_area_copy(local_area_t *dst, local_area_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = local_area_convertToJSON(src);
	if(!item) {
		printf("local_area_convertToJSON() failed");
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

	local_area_free(dst);
	dst = local_area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
