#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "preemption_capability.h"

preemption_capability_t *preemption_capability_create() {
	preemption_capability_t *preemption_capability_local_var = malloc(
		sizeof(preemption_capability_t));


	return preemption_capability_local_var;
}

void preemption_capability_free(preemption_capability_t *preemption_capability)
{
	lnode_t *node = NULL;

	if(NULL == preemption_capability) {
		return;
	}
	free(preemption_capability);
}

cJSON *preemption_capability_convertToJSON(
	preemption_capability_t *preemption_capability) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(preemption_capability == NULL) {
		printf(
			"preemption_capability_convertToJSON() failed [PreemptionCapability]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

preemption_capability_t *preemption_capability_parseFromJSON(
	cJSON *preemption_capabilityJSON) {
	preemption_capability_t *preemption_capability_local_var = NULL;
	lnode_t *node = NULL;
	preemption_capability_local_var = preemption_capability_create(
		);

	return preemption_capability_local_var;
end:
	return NULL;
}

preemption_capability_t *preemption_capability_copy(
	preemption_capability_t *dst, preemption_capability_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = preemption_capability_convertToJSON(src);
	if(!item) {
		printf("preemption_capability_convertToJSON() failed");
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

	preemption_capability_free(dst);
	dst = preemption_capability_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
