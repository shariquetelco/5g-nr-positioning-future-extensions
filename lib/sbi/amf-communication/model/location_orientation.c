#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_orientation.h"

location_orientation_t *location_orientation_create() {
	location_orientation_t *location_orientation_local_var =
		malloc(sizeof(location_orientation_t));


	return location_orientation_local_var;
}

void location_orientation_free(location_orientation_t *location_orientation) {
	lnode_t *node = NULL;

	if(NULL == location_orientation) {
		return;
	}
	free(location_orientation);
}

cJSON *location_orientation_convertToJSON(
	location_orientation_t *location_orientation) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(location_orientation == NULL) {
		printf(
			"location_orientation_convertToJSON() failed [LocationOrientation]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

location_orientation_t *location_orientation_parseFromJSON(
	cJSON *location_orientationJSON) {
	location_orientation_t *location_orientation_local_var = NULL;
	lnode_t *node = NULL;
	location_orientation_local_var = location_orientation_create(
		);

	return location_orientation_local_var;
end:
	return NULL;
}

location_orientation_t *location_orientation_copy(
	location_orientation_t	*dst,
	location_orientation_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = location_orientation_convertToJSON(src);
	if(!item) {
		printf("location_orientation_convertToJSON() failed");
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

	location_orientation_free(dst);
	dst = location_orientation_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
