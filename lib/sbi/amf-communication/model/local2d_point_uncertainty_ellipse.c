#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local2d_point_uncertainty_ellipse.h"

local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_create(
	supported_gad_shapes_t *shape, local_origin_t *local_origin,
	relative_cartesian_location_t *point,
	uncertainty_ellipse_t *uncertainty_ellipse, int confidence) {
	local2d_point_uncertainty_ellipse_t *
	        local2d_point_uncertainty_ellipse_local_var =
		malloc(sizeof(local2d_point_uncertainty_ellipse_t));

	local2d_point_uncertainty_ellipse_local_var->shape = shape;
	local2d_point_uncertainty_ellipse_local_var->local_origin =
		local_origin;
	local2d_point_uncertainty_ellipse_local_var->point = point;
	local2d_point_uncertainty_ellipse_local_var->uncertainty_ellipse =
		uncertainty_ellipse;
	local2d_point_uncertainty_ellipse_local_var->confidence = confidence;

	return local2d_point_uncertainty_ellipse_local_var;
}

void local2d_point_uncertainty_ellipse_free(
	local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse)
{
	lnode_t *node = NULL;

	if(NULL == local2d_point_uncertainty_ellipse) {
		return;
	}
	if(local2d_point_uncertainty_ellipse->shape) {
		supported_gad_shapes_free(
			local2d_point_uncertainty_ellipse->shape);
		local2d_point_uncertainty_ellipse->shape = NULL;
	}
	if(local2d_point_uncertainty_ellipse->local_origin) {
		local_origin_free(
			local2d_point_uncertainty_ellipse->local_origin);
		local2d_point_uncertainty_ellipse->local_origin = NULL;
	}
	if(local2d_point_uncertainty_ellipse->point) {
		relative_cartesian_location_free(
			local2d_point_uncertainty_ellipse->point);
		local2d_point_uncertainty_ellipse->point = NULL;
	}
	if(local2d_point_uncertainty_ellipse->uncertainty_ellipse) {
		uncertainty_ellipse_free(
			local2d_point_uncertainty_ellipse->uncertainty_ellipse);
		local2d_point_uncertainty_ellipse->uncertainty_ellipse = NULL;
	}
	free(local2d_point_uncertainty_ellipse);
}

cJSON *local2d_point_uncertainty_ellipse_convertToJSON(
	local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(local2d_point_uncertainty_ellipse == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [Local2dPointUncertaintyEllipse]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!local2d_point_uncertainty_ellipse->shape) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [shape]");
		return NULL;
	}
	cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(
		local2d_point_uncertainty_ellipse->shape);
	if(shape_local_JSON == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [shape]");
		goto end;
	}
	cJSON_AddItemToObject(item, "shape", shape_local_JSON);
	if(item->child == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [shape]");
		goto end;
	}

	if(!local2d_point_uncertainty_ellipse->local_origin) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [local_origin]");
		return NULL;
	}
	cJSON *local_origin_local_JSON = local_origin_convertToJSON(
		local2d_point_uncertainty_ellipse->local_origin);
	if(local_origin_local_JSON == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [local_origin]");
		goto end;
	}
	cJSON_AddItemToObject(item, "localOrigin", local_origin_local_JSON);
	if(item->child == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [local_origin]");
		goto end;
	}

	if(!local2d_point_uncertainty_ellipse->point) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = relative_cartesian_location_convertToJSON(
		local2d_point_uncertainty_ellipse->point);
	if(point_local_JSON == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [point]");
		goto end;
	}

	if(!local2d_point_uncertainty_ellipse->uncertainty_ellipse) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [uncertainty_ellipse]");
		return NULL;
	}
	cJSON *uncertainty_ellipse_local_JSON =
		uncertainty_ellipse_convertToJSON(
			local2d_point_uncertainty_ellipse->uncertainty_ellipse);
	if(uncertainty_ellipse_local_JSON == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	cJSON_AddItemToObject(item, "uncertaintyEllipse",
	                      uncertainty_ellipse_local_JSON);
	if(item->child == NULL) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [uncertainty_ellipse]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "confidence",
	                           local2d_point_uncertainty_ellipse->confidence)
	   == NULL)
	{
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed [confidence]");
		goto end;
	}

end:
	return item;
}

local2d_point_uncertainty_ellipse_t *
local2d_point_uncertainty_ellipse_parseFromJSON(
	cJSON *local2d_point_uncertainty_ellipseJSON) {
	local2d_point_uncertainty_ellipse_t *
	        local2d_point_uncertainty_ellipse_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_t *shape_local_nonprim = NULL;
	cJSON *local_origin = NULL;
	local_origin_t *local_origin_local_nonprim = NULL;
	cJSON *point = NULL;
	relative_cartesian_location_t *point_local_nonprim = NULL;
	cJSON *uncertainty_ellipse = NULL;
	uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;
	cJSON *confidence = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(
		local2d_point_uncertainty_ellipseJSON, "shape");
	if(!shape) {
		printf(
			"local2d_point_uncertainty_ellipse_parseFromJSON() failed [shape]");
		goto end;
	}
	shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape);
	if(!shape_local_nonprim) {
		printf("supported_gad_shapes_parseFromJSON failed [shape]");
		goto end;
	}

	local_origin = cJSON_GetObjectItemCaseSensitive(
		local2d_point_uncertainty_ellipseJSON, "localOrigin");
	if(!local_origin) {
		printf(
			"local2d_point_uncertainty_ellipse_parseFromJSON() failed [local_origin]");
		goto end;
	}
	local_origin_local_nonprim = local_origin_parseFromJSON(local_origin);
	if(!local_origin_local_nonprim) {
		printf("local_origin_parseFromJSON failed [local_origin]");
		goto end;
	}

	point = cJSON_GetObjectItemCaseSensitive(
		local2d_point_uncertainty_ellipseJSON, "point");
	if(!point) {
		printf(
			"local2d_point_uncertainty_ellipse_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = relative_cartesian_location_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf(
			"relative_cartesian_location_parseFromJSON failed [point]");
		goto end;
	}

	uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(
		local2d_point_uncertainty_ellipseJSON, "uncertaintyEllipse");
	if(!uncertainty_ellipse) {
		printf(
			"local2d_point_uncertainty_ellipse_parseFromJSON() failed [uncertainty_ellipse]");
		goto end;
	}
	uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(
		uncertainty_ellipse);
	if(!uncertainty_ellipse_local_nonprim) {
		printf(
			"uncertainty_ellipse_parseFromJSON failed [uncertainty_ellipse]");
		goto end;
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		local2d_point_uncertainty_ellipseJSON, "confidence");
	if(!confidence) {
		printf(
			"local2d_point_uncertainty_ellipse_parseFromJSON() failed [confidence]");
		goto end;
	}
	if(!cJSON_IsNumber(confidence)) {
		printf(
			"local2d_point_uncertainty_ellipse_parseFromJSON() failed [confidence]");
		goto end;
	}

	local2d_point_uncertainty_ellipse_local_var =
		local2d_point_uncertainty_ellipse_create(
			shape_local_nonprim,
			local_origin_local_nonprim,
			point_local_nonprim,
			uncertainty_ellipse_local_nonprim,

			confidence->valuedouble
			);

	return local2d_point_uncertainty_ellipse_local_var;
end:
	if(shape_local_nonprim) {
		supported_gad_shapes_free(shape_local_nonprim);
		shape_local_nonprim = NULL;
	}
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
	return NULL;
}

local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_copy(
	local2d_point_uncertainty_ellipse_t	*dst,
	local2d_point_uncertainty_ellipse_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = local2d_point_uncertainty_ellipse_convertToJSON(src);
	if(!item) {
		printf(
			"local2d_point_uncertainty_ellipse_convertToJSON() failed");
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

	local2d_point_uncertainty_ellipse_free(dst);
	dst = local2d_point_uncertainty_ellipse_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
