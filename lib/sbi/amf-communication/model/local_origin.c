#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local_origin.h"

local_origin_t *local_origin_create(char			*coordinate_id,
                                    geographical_coordinates_t	*point) {
	local_origin_t *local_origin_local_var = malloc(sizeof(local_origin_t));

	local_origin_local_var->coordinate_id = coordinate_id;
	local_origin_local_var->point = point;

	return local_origin_local_var;
}

void local_origin_free(local_origin_t *local_origin) {
	lnode_t *node = NULL;

	if(NULL == local_origin) {
		return;
	}
	if(local_origin->coordinate_id) {
		free(local_origin->coordinate_id);
		local_origin->coordinate_id = NULL;
	}
	if(local_origin->point) {
		geographical_coordinates_free(local_origin->point);
		local_origin->point = NULL;
	}
	free(local_origin);
}

cJSON *local_origin_convertToJSON(local_origin_t *local_origin) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(local_origin == NULL) {
		printf("local_origin_convertToJSON() failed [LocalOrigin]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(local_origin->coordinate_id) {
		if(cJSON_AddStringToObject(item, "coordinateId",
		                           local_origin->coordinate_id) == NULL)
		{
			printf(
				"local_origin_convertToJSON() failed [coordinate_id]");
			goto end;
		}
	}

	if(local_origin->point) {
		cJSON *point_local_JSON =
			geographical_coordinates_convertToJSON(
				local_origin->point);
		if(point_local_JSON == NULL) {
			printf("local_origin_convertToJSON() failed [point]");
			goto end;
		}
		cJSON_AddItemToObject(item, "point", point_local_JSON);
		if(item->child == NULL) {
			printf("local_origin_convertToJSON() failed [point]");
			goto end;
		}
	}

end:
	return item;
}

local_origin_t *local_origin_parseFromJSON(cJSON *local_originJSON) {
	local_origin_t *local_origin_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *coordinate_id = NULL;
	cJSON *point = NULL;
	geographical_coordinates_t *point_local_nonprim = NULL;
	coordinate_id = cJSON_GetObjectItemCaseSensitive(local_originJSON,
	                                                 "coordinateId");
	if(coordinate_id) {
		if(!cJSON_IsString(coordinate_id) &&
		   !cJSON_IsNull(coordinate_id))
		{
			printf(
				"local_origin_parseFromJSON() failed [coordinate_id]");
			goto end;
		}
	}

	point = cJSON_GetObjectItemCaseSensitive(local_originJSON, "point");
	if(point) {
		point_local_nonprim = geographical_coordinates_parseFromJSON(
			point);
		if(!point_local_nonprim) {
			printf(
				"geographical_coordinates_parseFromJSON failed [point]");
			goto end;
		}
	}

	local_origin_local_var = local_origin_create(
		coordinate_id &&
		!cJSON_IsNull(coordinate_id) ? strdup(
			coordinate_id->valuestring) : NULL,
		point ? point_local_nonprim : NULL
		);

	return local_origin_local_var;
end:
	if(point_local_nonprim) {
		geographical_coordinates_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	return NULL;
}

local_origin_t *local_origin_copy(local_origin_t *dst, local_origin_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = local_origin_convertToJSON(src);
	if(!item) {
		printf("local_origin_convertToJSON() failed");
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

	local_origin_free(dst);
	dst = local_origin_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
