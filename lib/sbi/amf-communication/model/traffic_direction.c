#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "traffic_direction.h"

traffic_direction_t *traffic_direction_create() {
	traffic_direction_t *traffic_direction_local_var =
		malloc(sizeof(traffic_direction_t));


	return traffic_direction_local_var;
}

void traffic_direction_free(traffic_direction_t *traffic_direction) {
	lnode_t *node = NULL;

	if(NULL == traffic_direction) {
		return;
	}
	free(traffic_direction);
}

cJSON *traffic_direction_convertToJSON(traffic_direction_t *traffic_direction) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(traffic_direction == NULL) {
		printf(
			"traffic_direction_convertToJSON() failed [TrafficDirection]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

traffic_direction_t *traffic_direction_parseFromJSON(
	cJSON *traffic_directionJSON) {
	traffic_direction_t *traffic_direction_local_var = NULL;
	lnode_t *node = NULL;
	traffic_direction_local_var = traffic_direction_create(
		);

	return traffic_direction_local_var;
end:
	return NULL;
}

traffic_direction_t *traffic_direction_copy(traffic_direction_t *dst,
                                            traffic_direction_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = traffic_direction_convertToJSON(src);
	if(!item) {
		printf("traffic_direction_convertToJSON() failed");
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

	traffic_direction_free(dst);
	dst = traffic_direction_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
