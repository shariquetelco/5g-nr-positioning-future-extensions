#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "range_direction.h"

range_direction_t *range_direction_create(bool is_distance, double distance,
                                          bool is_azimuth_direction,
                                          int azimuth_direction,
                                          bool is_elevation_direction,
                                          int elevation_direction) {
	range_direction_t *range_direction_local_var =
		malloc(sizeof(range_direction_t));

	range_direction_local_var->is_distance = is_distance;
	range_direction_local_var->distance = distance;
	range_direction_local_var->is_azimuth_direction = is_azimuth_direction;
	range_direction_local_var->azimuth_direction = azimuth_direction;
	range_direction_local_var->is_elevation_direction =
		is_elevation_direction;
	range_direction_local_var->elevation_direction = elevation_direction;

	return range_direction_local_var;
}

void range_direction_free(range_direction_t *range_direction) {
	lnode_t *node = NULL;

	if(NULL == range_direction) {
		return;
	}
	free(range_direction);
}

cJSON *range_direction_convertToJSON(range_direction_t *range_direction) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(range_direction == NULL) {
		printf("range_direction_convertToJSON() failed [RangeDirection]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(range_direction->is_distance) {
		if(cJSON_AddNumberToObject(item, "distance",
		                           range_direction->distance) == NULL)
		{
			printf(
				"range_direction_convertToJSON() failed [distance]");
			goto end;
		}
	}

	if(range_direction->is_azimuth_direction) {
		if(cJSON_AddNumberToObject(item, "azimuthDirection",
		                           range_direction->azimuth_direction)
		   == NULL)
		{
			printf(
				"range_direction_convertToJSON() failed [azimuth_direction]");
			goto end;
		}
	}

	if(range_direction->is_elevation_direction) {
		if(cJSON_AddNumberToObject(item, "elevationDirection",
		                           range_direction->elevation_direction)
		   == NULL)
		{
			printf(
				"range_direction_convertToJSON() failed [elevation_direction]");
			goto end;
		}
	}

end:
	return item;
}

range_direction_t *range_direction_parseFromJSON(cJSON *range_directionJSON) {
	range_direction_t *range_direction_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *distance = NULL;
	cJSON *azimuth_direction = NULL;
	cJSON *elevation_direction = NULL;
	distance = cJSON_GetObjectItemCaseSensitive(range_directionJSON,
	                                            "distance");
	if(distance) {
		if(!cJSON_IsNumber(distance)) {
			printf(
				"range_direction_parseFromJSON() failed [distance]");
			goto end;
		}
	}

	azimuth_direction = cJSON_GetObjectItemCaseSensitive(
		range_directionJSON, "azimuthDirection");
	if(azimuth_direction) {
		if(!cJSON_IsNumber(azimuth_direction)) {
			printf(
				"range_direction_parseFromJSON() failed [azimuth_direction]");
			goto end;
		}
	}

	elevation_direction = cJSON_GetObjectItemCaseSensitive(
		range_directionJSON, "elevationDirection");
	if(elevation_direction) {
		if(!cJSON_IsNumber(elevation_direction)) {
			printf(
				"range_direction_parseFromJSON() failed [elevation_direction]");
			goto end;
		}
	}

	range_direction_local_var = range_direction_create(
		distance ? true : false,
		distance ? distance->valuedouble : 0,
		azimuth_direction ? true : false,
		azimuth_direction ? azimuth_direction->valuedouble : 0,
		elevation_direction ? true : false,
		elevation_direction ? elevation_direction->valuedouble : 0
		);

	return range_direction_local_var;
end:
	return NULL;
}

range_direction_t *range_direction_copy(range_direction_t	*dst,
                                        range_direction_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = range_direction_convertToJSON(src);
	if(!item) {
		printf("range_direction_convertToJSON() failed");
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

	range_direction_free(dst);
	dst = range_direction_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
