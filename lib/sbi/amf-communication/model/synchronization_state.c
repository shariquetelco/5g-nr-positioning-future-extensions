#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "synchronization_state.h"

synchronization_state_t *synchronization_state_create() {
	synchronization_state_t *synchronization_state_local_var = malloc(
		sizeof(synchronization_state_t));


	return synchronization_state_local_var;
}

void synchronization_state_free(synchronization_state_t *synchronization_state)
{
	lnode_t *node = NULL;

	if(NULL == synchronization_state) {
		return;
	}
	free(synchronization_state);
}

cJSON *synchronization_state_convertToJSON(
	synchronization_state_t *synchronization_state) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(synchronization_state == NULL) {
		printf(
			"synchronization_state_convertToJSON() failed [SynchronizationState]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

synchronization_state_t *synchronization_state_parseFromJSON(
	cJSON *synchronization_stateJSON) {
	synchronization_state_t *synchronization_state_local_var = NULL;
	lnode_t *node = NULL;
	synchronization_state_local_var = synchronization_state_create(
		);

	return synchronization_state_local_var;
end:
	return NULL;
}

synchronization_state_t *synchronization_state_copy(
	synchronization_state_t *dst, synchronization_state_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = synchronization_state_convertToJSON(src);
	if(!item) {
		printf("synchronization_state_convertToJSON() failed");
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

	synchronization_state_free(dst);
	dst = synchronization_state_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
