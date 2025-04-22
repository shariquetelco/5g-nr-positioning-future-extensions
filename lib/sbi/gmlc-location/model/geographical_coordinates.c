#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geographical_coordinates.h"

geographical_coordinates_t *geographical_coordinates_create(double	lon,
                                                            double	lat) {
	geographical_coordinates_t *geographical_coordinates_local_var = malloc(
		sizeof(geographical_coordinates_t));

	geographical_coordinates_local_var->lon = lon;
	geographical_coordinates_local_var->lat = lat;

	return geographical_coordinates_local_var;
}

void geographical_coordinates_free(
	geographical_coordinates_t *geographical_coordinates) {
	lnode_t *node = NULL;

	if(NULL == geographical_coordinates) {
		return;
	}
	free(geographical_coordinates);
}

cJSON *geographical_coordinates_convertToJSON(
	geographical_coordinates_t *geographical_coordinates) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(geographical_coordinates == NULL) {
		printf(
			"geographical_coordinates_convertToJSON() failed [GeographicalCoordinates]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "lon",
	                           geographical_coordinates->lon) == NULL)
	{
		printf("geographical_coordinates_convertToJSON() failed [lon]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "lat",
	                           geographical_coordinates->lat) == NULL)
	{
		printf("geographical_coordinates_convertToJSON() failed [lat]");
		goto end;
	}

end:
	return item;
}

geographical_coordinates_t *geographical_coordinates_parseFromJSON(
	cJSON *geographical_coordinatesJSON) {
	geographical_coordinates_t *geographical_coordinates_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *lon = NULL;
	cJSON *lat = NULL;
	lon = cJSON_GetObjectItemCaseSensitive(geographical_coordinatesJSON,
	                                       "lon");
	if(!lon) {
		printf("geographical_coordinates_parseFromJSON() failed [lon]");
		goto end;
	}
	if(!cJSON_IsNumber(lon)) {
		printf("geographical_coordinates_parseFromJSON() failed [lon]");
		goto end;
	}

	lat = cJSON_GetObjectItemCaseSensitive(geographical_coordinatesJSON,
	                                       "lat");
	if(!lat) {
		printf("geographical_coordinates_parseFromJSON() failed [lat]");
		goto end;
	}
	if(!cJSON_IsNumber(lat)) {
		printf("geographical_coordinates_parseFromJSON() failed [lat]");
		goto end;
	}

	geographical_coordinates_local_var = geographical_coordinates_create(

		lon->valuedouble,

		lat->valuedouble
		);

	return geographical_coordinates_local_var;
end:
	return NULL;
}

geographical_coordinates_t *geographical_coordinates_copy(
	geographical_coordinates_t *dst, geographical_coordinates_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = geographical_coordinates_convertToJSON(src);
	if(!item) {
		printf("geographical_coordinates_convertToJSON() failed");
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

	geographical_coordinates_free(dst);
	dst = geographical_coordinates_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
