#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local3d_point_uncertainty_ellipsoid.h"

local3d_point_uncertainty_ellipsoid_t *
local3d_point_uncertainty_ellipsoid_create(
	supported_gad_shapes_t		*shape,
	local_origin_t			*local_origin,
	relative_cartesian_location_t	*point,
	uncertainty_ellipsoid_t		*uncertainty_ellipsoid,
	int				confidence)
{
	local3d_point_uncertainty_ellipsoid_t *
	        local3d_point_uncertainty_ellipsoid_local_var =
		malloc(sizeof(local3d_point_uncertainty_ellipsoid_t));

	local3d_point_uncertainty_ellipsoid_local_var->shape = shape;
	local3d_point_uncertainty_ellipsoid_local_var->local_origin =
		local_origin;
	local3d_point_uncertainty_ellipsoid_local_var->point = point;
	local3d_point_uncertainty_ellipsoid_local_var->uncertainty_ellipsoid =
		uncertainty_ellipsoid;
	local3d_point_uncertainty_ellipsoid_local_var->confidence = confidence;

	return local3d_point_uncertainty_ellipsoid_local_var;
}

void local3d_point_uncertainty_ellipsoid_free(
	local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid)
{
	lnode_t *node = NULL;

	if(NULL == local3d_point_uncertainty_ellipsoid) {
		return;
	}
	if(local3d_point_uncertainty_ellipsoid->shape) {
		supported_gad_shapes_free(
			local3d_point_uncertainty_ellipsoid->shape);
		local3d_point_uncertainty_ellipsoid->shape = NULL;
	}
	if(local3d_point_uncertainty_ellipsoid->local_origin) {
		local_origin_free(
			local3d_point_uncertainty_ellipsoid->local_origin);
		local3d_point_uncertainty_ellipsoid->local_origin = NULL;
	}
	if(local3d_point_uncertainty_ellipsoid->point) {
		relative_cartesian_location_free(
			local3d_point_uncertainty_ellipsoid->point);
		local3d_point_uncertainty_ellipsoid->point = NULL;
	}
	if(local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid) {
		uncertainty_ellipsoid_free(
			local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid);
		local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid =
			NULL;
	}
	free(local3d_point_uncertainty_ellipsoid);
}

cJSON *local3d_point_uncertainty_ellipsoid_convertToJSON(
	local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(local3d_point_uncertainty_ellipsoid == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [Local3dPointUncertaintyEllipsoid]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!local3d_point_uncertainty_ellipsoid->shape) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [shape]");
		return NULL;
	}
	cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(
		local3d_point_uncertainty_ellipsoid->shape);
	if(shape_local_JSON == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [shape]");
		goto end;
	}
	cJSON_AddItemToObject(item, "shape", shape_local_JSON);
	if(item->child == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [shape]");
		goto end;
	}

	if(!local3d_point_uncertainty_ellipsoid->local_origin) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [local_origin]");
		return NULL;
	}
	cJSON *local_origin_local_JSON = local_origin_convertToJSON(
		local3d_point_uncertainty_ellipsoid->local_origin);
	if(local_origin_local_JSON == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [local_origin]");
		goto end;
	}
	cJSON_AddItemToObject(item, "localOrigin", local_origin_local_JSON);
	if(item->child == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [local_origin]");
		goto end;
	}

	if(!local3d_point_uncertainty_ellipsoid->point) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = relative_cartesian_location_convertToJSON(
		local3d_point_uncertainty_ellipsoid->point);
	if(point_local_JSON == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [point]");
		goto end;
	}

	if(!local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [uncertainty_ellipsoid]");
		return NULL;
	}
	cJSON *uncertainty_ellipsoid_local_JSON =
		uncertainty_ellipsoid_convertToJSON(
			local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid);
	if(uncertainty_ellipsoid_local_JSON == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}
	cJSON_AddItemToObject(item, "uncertaintyEllipsoid",
	                      uncertainty_ellipsoid_local_JSON);
	if(item->child == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "confidence",
	                           local3d_point_uncertainty_ellipsoid->
	                           confidence) == NULL)
	{
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed [confidence]");
		goto end;
	}

end:
	return item;
}

local3d_point_uncertainty_ellipsoid_t *
local3d_point_uncertainty_ellipsoid_parseFromJSON(
	cJSON *local3d_point_uncertainty_ellipsoidJSON) {
	local3d_point_uncertainty_ellipsoid_t *
	        local3d_point_uncertainty_ellipsoid_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_t *shape_local_nonprim = NULL;
	cJSON *local_origin = NULL;
	local_origin_t *local_origin_local_nonprim = NULL;
	cJSON *point = NULL;
	relative_cartesian_location_t *point_local_nonprim = NULL;
	cJSON *uncertainty_ellipsoid = NULL;
	uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_nonprim = NULL;
	cJSON *confidence = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoidJSON, "shape");
	if(!shape) {
		printf(
			"local3d_point_uncertainty_ellipsoid_parseFromJSON() failed [shape]");
		goto end;
	}
	shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape);
	if(!shape_local_nonprim) {
		printf("supported_gad_shapes_parseFromJSON failed [shape]");
		goto end;
	}

	local_origin = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoidJSON, "localOrigin");
	if(!local_origin) {
		printf(
			"local3d_point_uncertainty_ellipsoid_parseFromJSON() failed [local_origin]");
		goto end;
	}
	local_origin_local_nonprim = local_origin_parseFromJSON(local_origin);
	if(!local_origin_local_nonprim) {
		printf("local_origin_parseFromJSON failed [local_origin]");
		goto end;
	}

	point = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoidJSON, "point");
	if(!point) {
		printf(
			"local3d_point_uncertainty_ellipsoid_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = relative_cartesian_location_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf(
			"relative_cartesian_location_parseFromJSON failed [point]");
		goto end;
	}

	uncertainty_ellipsoid = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoidJSON,
		"uncertaintyEllipsoid");
	if(!uncertainty_ellipsoid) {
		printf(
			"local3d_point_uncertainty_ellipsoid_parseFromJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}
	uncertainty_ellipsoid_local_nonprim =
		uncertainty_ellipsoid_parseFromJSON(uncertainty_ellipsoid);
	if(!uncertainty_ellipsoid_local_nonprim) {
		printf(
			"uncertainty_ellipsoid_parseFromJSON failed [uncertainty_ellipsoid]");
		goto end;
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoidJSON, "confidence");
	if(!confidence) {
		printf(
			"local3d_point_uncertainty_ellipsoid_parseFromJSON() failed [confidence]");
		goto end;
	}
	if(!cJSON_IsNumber(confidence)) {
		printf(
			"local3d_point_uncertainty_ellipsoid_parseFromJSON() failed [confidence]");
		goto end;
	}

	local3d_point_uncertainty_ellipsoid_local_var =
		local3d_point_uncertainty_ellipsoid_create(
			shape_local_nonprim,
			local_origin_local_nonprim,
			point_local_nonprim,
			uncertainty_ellipsoid_local_nonprim,

			confidence->valuedouble
			);

	return local3d_point_uncertainty_ellipsoid_local_var;
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
	if(uncertainty_ellipsoid_local_nonprim) {
		uncertainty_ellipsoid_free(uncertainty_ellipsoid_local_nonprim);
		uncertainty_ellipsoid_local_nonprim = NULL;
	}
	return NULL;
}

local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid_copy(
	local3d_point_uncertainty_ellipsoid_t	*dst,
	local3d_point_uncertainty_ellipsoid_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = local3d_point_uncertainty_ellipsoid_convertToJSON(src);
	if(!item) {
		printf(
			"local3d_point_uncertainty_ellipsoid_convertToJSON() failed");
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

	local3d_point_uncertainty_ellipsoid_free(dst);
	dst = local3d_point_uncertainty_ellipsoid_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
