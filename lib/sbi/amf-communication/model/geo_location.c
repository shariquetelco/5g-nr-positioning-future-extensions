#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geo_location.h"

geo_location_t *geo_location_create(point_t *point, point_altitude_t *point_alt,
                                    local_origin_t *ref_point,
                                    relative_cartesian_location_t *local_coords)
{
	geo_location_t *geo_location_local_var = malloc(sizeof(geo_location_t));

	geo_location_local_var->point = point;
	geo_location_local_var->point_alt = point_alt;
	geo_location_local_var->ref_point = ref_point;
	geo_location_local_var->local_coords = local_coords;

	return geo_location_local_var;
}

void geo_location_free(geo_location_t *geo_location) {
	lnode_t *node = NULL;

	if(NULL == geo_location) {
		return;
	}
	if(geo_location->point) {
		point_free(geo_location->point);
		geo_location->point = NULL;
	}
	if(geo_location->point_alt) {
		point_altitude_free(geo_location->point_alt);
		geo_location->point_alt = NULL;
	}
	if(geo_location->ref_point) {
		local_origin_free(geo_location->ref_point);
		geo_location->ref_point = NULL;
	}
	if(geo_location->local_coords) {
		relative_cartesian_location_free(geo_location->local_coords);
		geo_location->local_coords = NULL;
	}
	free(geo_location);
}

cJSON *geo_location_convertToJSON(geo_location_t *geo_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(geo_location == NULL) {
		printf("geo_location_convertToJSON() failed [GeoLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(geo_location->point) {
		cJSON *point_local_JSON = point_convertToJSON(
			geo_location->point);
		if(point_local_JSON == NULL) {
			printf("geo_location_convertToJSON() failed [point]");
			goto end;
		}
		cJSON_AddItemToObject(item, "point", point_local_JSON);
		if(item->child == NULL) {
			printf("geo_location_convertToJSON() failed [point]");
			goto end;
		}
	}

	if(geo_location->point_alt) {
		cJSON *point_alt_local_JSON = point_altitude_convertToJSON(
			geo_location->point_alt);
		if(point_alt_local_JSON == NULL) {
			printf("geo_location_convertToJSON() failed [point_alt]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pointAlt", point_alt_local_JSON);
		if(item->child == NULL) {
			printf("geo_location_convertToJSON() failed [point_alt]");
			goto end;
		}
	}

	if(geo_location->ref_point) {
		cJSON *ref_point_local_JSON = local_origin_convertToJSON(
			geo_location->ref_point);
		if(ref_point_local_JSON == NULL) {
			printf("geo_location_convertToJSON() failed [ref_point]");
			goto end;
		}
		cJSON_AddItemToObject(item, "refPoint", ref_point_local_JSON);
		if(item->child == NULL) {
			printf("geo_location_convertToJSON() failed [ref_point]");
			goto end;
		}
	}

	if(geo_location->local_coords) {
		cJSON *local_coords_local_JSON =
			relative_cartesian_location_convertToJSON(
				geo_location->local_coords);
		if(local_coords_local_JSON == NULL) {
			printf(
				"geo_location_convertToJSON() failed [local_coords]");
			goto end;
		}
		cJSON_AddItemToObject(item, "localCoords",
		                      local_coords_local_JSON);
		if(item->child == NULL) {
			printf(
				"geo_location_convertToJSON() failed [local_coords]");
			goto end;
		}
	}

end:
	return item;
}

geo_location_t *geo_location_parseFromJSON(cJSON *geo_locationJSON) {
	geo_location_t *geo_location_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *point = NULL;
	point_t *point_local_nonprim = NULL;
	cJSON *point_alt = NULL;
	point_altitude_t *point_alt_local_nonprim = NULL;
	cJSON *ref_point = NULL;
	local_origin_t *ref_point_local_nonprim = NULL;
	cJSON *local_coords = NULL;
	relative_cartesian_location_t *local_coords_local_nonprim = NULL;
	point = cJSON_GetObjectItemCaseSensitive(geo_locationJSON, "point");
	if(point) {
		point_local_nonprim = point_parseFromJSON(point);
		if(!point_local_nonprim) {
			printf("point_parseFromJSON failed [point]");
			goto end;
		}
	}

	point_alt = cJSON_GetObjectItemCaseSensitive(geo_locationJSON,
	                                             "pointAlt");
	if(point_alt) {
		point_alt_local_nonprim =
			point_altitude_parseFromJSON(point_alt);
		if(!point_alt_local_nonprim) {
			printf("point_altitude_parseFromJSON failed [point_alt]");
			goto end;
		}
	}

	ref_point = cJSON_GetObjectItemCaseSensitive(geo_locationJSON,
	                                             "refPoint");
	if(ref_point) {
		ref_point_local_nonprim = local_origin_parseFromJSON(ref_point);
		if(!ref_point_local_nonprim) {
			printf("local_origin_parseFromJSON failed [ref_point]");
			goto end;
		}
	}

	local_coords = cJSON_GetObjectItemCaseSensitive(geo_locationJSON,
	                                                "localCoords");
	if(local_coords) {
		local_coords_local_nonprim =
			relative_cartesian_location_parseFromJSON(local_coords);
		if(!local_coords_local_nonprim) {
			printf(
				"relative_cartesian_location_parseFromJSON failed [local_coords]");
			goto end;
		}
	}

	geo_location_local_var = geo_location_create(
		point ? point_local_nonprim : NULL,
		point_alt ? point_alt_local_nonprim : NULL,
		ref_point ? ref_point_local_nonprim : NULL,
		local_coords ? local_coords_local_nonprim : NULL
		);

	return geo_location_local_var;
end:
	if(point_local_nonprim) {
		point_free(point_local_nonprim);
		point_local_nonprim = NULL;
	}
	if(point_alt_local_nonprim) {
		point_altitude_free(point_alt_local_nonprim);
		point_alt_local_nonprim = NULL;
	}
	if(ref_point_local_nonprim) {
		local_origin_free(ref_point_local_nonprim);
		ref_point_local_nonprim = NULL;
	}
	if(local_coords_local_nonprim) {
		relative_cartesian_location_free(local_coords_local_nonprim);
		local_coords_local_nonprim = NULL;
	}
	return NULL;
}

geo_location_t *geo_location_copy(geo_location_t *dst, geo_location_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = geo_location_convertToJSON(src);
	if(!item) {
		printf("geo_location_convertToJSON() failed");
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

	geo_location_free(dst);
	dst = geo_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
