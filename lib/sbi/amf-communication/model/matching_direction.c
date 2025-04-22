#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matching_direction.h"

matching_direction_t *matching_direction_create() {
	matching_direction_t *matching_direction_local_var =
		malloc(sizeof(matching_direction_t));


	return matching_direction_local_var;
}

void matching_direction_free(matching_direction_t *matching_direction) {
	lnode_t *node = NULL;

	if(NULL == matching_direction) {
		return;
	}
	free(matching_direction);
}

cJSON *matching_direction_convertToJSON(
	matching_direction_t *matching_direction) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(matching_direction == NULL) {
		printf(
			"matching_direction_convertToJSON() failed [MatchingDirection]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

matching_direction_t *matching_direction_parseFromJSON(
	cJSON *matching_directionJSON) {
	matching_direction_t *matching_direction_local_var = NULL;
	lnode_t *node = NULL;
	matching_direction_local_var = matching_direction_create(
		);

	return matching_direction_local_var;
end:
	return NULL;
}

matching_direction_t *matching_direction_copy(matching_direction_t	*dst,
                                              matching_direction_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = matching_direction_convertToJSON(src);
	if(!item) {
		printf("matching_direction_convertToJSON() failed");
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

	matching_direction_free(dst);
	dst = matching_direction_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
