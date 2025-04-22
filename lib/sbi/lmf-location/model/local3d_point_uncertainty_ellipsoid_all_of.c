#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local3d_point_uncertainty_ellipsoid_all_of.h"

local3d_point_uncertainty_ellipsoid_all_of_t *
local3d_point_uncertainty_ellipsoid_all_of_create(local_origin_t *local_origin,
                                                  relative_cartesian_location_t *point, uncertainty_ellipsoid_t *uncertainty_ellipsoid,
                                                  int confidence) {
	local3d_point_uncertainty_ellipsoid_all_of_t *
	        local3d_point_uncertainty_ellipsoid_all_of_local_var =
		malloc(sizeof(local3d_point_uncertainty_ellipsoid_all_of_t));

	local3d_point_uncertainty_ellipsoid_all_of_local_var->local_origin =
		local_origin;
	local3d_point_uncertainty_ellipsoid_all_of_local_var->point = point;
	local3d_point_uncertainty_ellipsoid_all_of_local_var->
	uncertainty_ellipsoid = uncertainty_ellipsoid;
	local3d_point_uncertainty_ellipsoid_all_of_local_var->confidence =
		confidence;

	return local3d_point_uncertainty_ellipsoid_all_of_local_var;
}

void local3d_point_uncertainty_ellipsoid_all_of_free(
	local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of)
{
	lnode_t *node = NULL;

	if(NULL == local3d_point_uncertainty_ellipsoid_all_of) {
		return;
	}
	if(local3d_point_uncertainty_ellipsoid_all_of->local_origin) {
		local_origin_free(
			local3d_point_uncertainty_ellipsoid_all_of->local_origin);
		local3d_point_uncertainty_ellipsoid_all_of->local_origin = NULL;
	}
	if(local3d_point_uncertainty_ellipsoid_all_of->point) {
		relative_cartesian_location_free(
			local3d_point_uncertainty_ellipsoid_all_of->point);
		local3d_point_uncertainty_ellipsoid_all_of->point = NULL;
	}
	if(local3d_point_uncertainty_ellipsoid_all_of->uncertainty_ellipsoid) {
		uncertainty_ellipsoid_free(
			local3d_point_uncertainty_ellipsoid_all_of->uncertainty_ellipsoid);
		local3d_point_uncertainty_ellipsoid_all_of->
		uncertainty_ellipsoid = NULL;
	}
	free(local3d_point_uncertainty_ellipsoid_all_of);
}

cJSON *local3d_point_uncertainty_ellipsoid_all_of_convertToJSON(
	local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(local3d_point_uncertainty_ellipsoid_all_of == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [Local3dPointUncertaintyEllipsoid_allOf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!local3d_point_uncertainty_ellipsoid_all_of->local_origin) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [local_origin]");
		return NULL;
	}
	cJSON *local_origin_local_JSON = local_origin_convertToJSON(
		local3d_point_uncertainty_ellipsoid_all_of->local_origin);
	if(local_origin_local_JSON == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [local_origin]");
		goto end;
	}
	cJSON_AddItemToObject(item, "localOrigin", local_origin_local_JSON);
	if(item->child == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [local_origin]");
		goto end;
	}

	if(!local3d_point_uncertainty_ellipsoid_all_of->point) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [point]");
		return NULL;
	}
	cJSON *point_local_JSON = relative_cartesian_location_convertToJSON(
		local3d_point_uncertainty_ellipsoid_all_of->point);
	if(point_local_JSON == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [point]");
		goto end;
	}
	cJSON_AddItemToObject(item, "point", point_local_JSON);
	if(item->child == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [point]");
		goto end;
	}

	if(!local3d_point_uncertainty_ellipsoid_all_of->uncertainty_ellipsoid) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [uncertainty_ellipsoid]");
		return NULL;
	}
	cJSON *uncertainty_ellipsoid_local_JSON =
		uncertainty_ellipsoid_convertToJSON(
			local3d_point_uncertainty_ellipsoid_all_of->uncertainty_ellipsoid);
	if(uncertainty_ellipsoid_local_JSON == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}
	cJSON_AddItemToObject(item, "uncertaintyEllipsoid",
	                      uncertainty_ellipsoid_local_JSON);
	if(item->child == NULL) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [uncertainty_ellipsoid]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "confidence",
	                           local3d_point_uncertainty_ellipsoid_all_of->
	                           confidence) == NULL)
	{
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed [confidence]");
		goto end;
	}

end:
	return item;
}

local3d_point_uncertainty_ellipsoid_all_of_t *
local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON(
	cJSON *local3d_point_uncertainty_ellipsoid_all_ofJSON) {
	local3d_point_uncertainty_ellipsoid_all_of_t *
	        local3d_point_uncertainty_ellipsoid_all_of_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *local_origin = NULL;
	local_origin_t *local_origin_local_nonprim = NULL;
	cJSON *point = NULL;
	relative_cartesian_location_t *point_local_nonprim = NULL;
	cJSON *uncertainty_ellipsoid = NULL;
	uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_nonprim = NULL;
	cJSON *confidence = NULL;
	local_origin = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoid_all_ofJSON, "localOrigin");
	if(!local_origin) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON() failed [local_origin]");
		goto end;
	}
	local_origin_local_nonprim = local_origin_parseFromJSON(local_origin);
	if(!local_origin_local_nonprim) {
		printf("local_origin_parseFromJSON failed [local_origin]");
		goto end;
	}

	point = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoid_all_ofJSON, "point");
	if(!point) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON() failed [point]");
		goto end;
	}
	point_local_nonprim = relative_cartesian_location_parseFromJSON(point);
	if(!point_local_nonprim) {
		printf(
			"relative_cartesian_location_parseFromJSON failed [point]");
		goto end;
	}

	uncertainty_ellipsoid = cJSON_GetObjectItemCaseSensitive(
		local3d_point_uncertainty_ellipsoid_all_ofJSON,
		"uncertaintyEllipsoid");
	if(!uncertainty_ellipsoid) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON() failed [uncertainty_ellipsoid]");
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
		local3d_point_uncertainty_ellipsoid_all_ofJSON, "confidence");
	if(!confidence) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON() failed [confidence]");
		goto end;
	}
	if(!cJSON_IsNumber(confidence)) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON() failed [confidence]");
		goto end;
	}

	local3d_point_uncertainty_ellipsoid_all_of_local_var =
		local3d_point_uncertainty_ellipsoid_all_of_create(
			local_origin_local_nonprim,
			point_local_nonprim,
			uncertainty_ellipsoid_local_nonprim,

			confidence->valuedouble
			);

	return local3d_point_uncertainty_ellipsoid_all_of_local_var;
end:
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

local3d_point_uncertainty_ellipsoid_all_of_t *
local3d_point_uncertainty_ellipsoid_all_of_copy(
	local3d_point_uncertainty_ellipsoid_all_of_t	*dst,
	local3d_point_uncertainty_ellipsoid_all_of_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = local3d_point_uncertainty_ellipsoid_all_of_convertToJSON(src);
	if(!item) {
		printf(
			"local3d_point_uncertainty_ellipsoid_all_of_convertToJSON() failed");
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

	local3d_point_uncertainty_ellipsoid_all_of_free(dst);
	dst = local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
