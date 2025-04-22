#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "direction.h"

direction_t *direction_create() {
	direction_t *direction_local_var = malloc(sizeof(direction_t));


	return direction_local_var;
}

void direction_free(direction_t *direction) {
	lnode_t *node = NULL;

	if(NULL == direction) {
		return;
	}
	free(direction);
}

cJSON *direction_convertToJSON(direction_t *direction) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(direction == NULL) {
		printf("direction_convertToJSON() failed [Direction]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

direction_t *direction_parseFromJSON(cJSON *directionJSON) {
	direction_t *direction_local_var = NULL;
	lnode_t *node = NULL;
	direction_local_var = direction_create(
		);

	return direction_local_var;
end:
	return NULL;
}

direction_t *direction_copy(direction_t *dst, direction_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = direction_convertToJSON(src);
	if(!item) {
		printf("direction_convertToJSON() failed");
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

	direction_free(dst);
	dst = direction_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
