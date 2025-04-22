#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cm_state.h"

cm_state_t *cm_state_create() {
	cm_state_t *cm_state_local_var = malloc(sizeof(cm_state_t));


	return cm_state_local_var;
}

void cm_state_free(cm_state_t *cm_state) {
	lnode_t *node = NULL;

	if(NULL == cm_state) {
		return;
	}
	free(cm_state);
}

cJSON *cm_state_convertToJSON(cm_state_t *cm_state) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cm_state == NULL) {
		printf("cm_state_convertToJSON() failed [CmState]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

cm_state_t *cm_state_parseFromJSON(cJSON *cm_stateJSON) {
	cm_state_t *cm_state_local_var = NULL;
	lnode_t *node = NULL;
	cm_state_local_var = cm_state_create(
		);

	return cm_state_local_var;
end:
	return NULL;
}

cm_state_t *cm_state_copy(cm_state_t *dst, cm_state_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cm_state_convertToJSON(src);
	if(!item) {
		printf("cm_state_convertToJSON() failed");
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

	cm_state_free(dst);
	dst = cm_state_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
