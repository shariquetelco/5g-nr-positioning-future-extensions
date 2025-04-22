#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "presence_state.h"

presence_state_t *presence_state_create() {
	presence_state_t *presence_state_local_var =
		malloc(sizeof(presence_state_t));


	return presence_state_local_var;
}

void presence_state_free(presence_state_t *presence_state) {
	lnode_t *node = NULL;

	if(NULL == presence_state) {
		return;
	}
	free(presence_state);
}

cJSON *presence_state_convertToJSON(presence_state_t *presence_state) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(presence_state == NULL) {
		printf("presence_state_convertToJSON() failed [PresenceState]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

presence_state_t *presence_state_parseFromJSON(cJSON *presence_stateJSON) {
	presence_state_t *presence_state_local_var = NULL;
	lnode_t *node = NULL;
	presence_state_local_var = presence_state_create(
		);

	return presence_state_local_var;
end:
	return NULL;
}

presence_state_t *presence_state_copy(presence_state_t	*dst,
                                      presence_state_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = presence_state_convertToJSON(src);
	if(!item) {
		printf("presence_state_convertToJSON() failed");
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

	presence_state_free(dst);
	dst = presence_state_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
