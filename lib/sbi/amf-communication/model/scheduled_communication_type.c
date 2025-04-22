#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "scheduled_communication_type.h"

scheduled_communication_type_t *scheduled_communication_type_create() {
	scheduled_communication_type_t *scheduled_communication_type_local_var =
		malloc(sizeof(scheduled_communication_type_t));


	return scheduled_communication_type_local_var;
}

void scheduled_communication_type_free(
	scheduled_communication_type_t *scheduled_communication_type) {
	lnode_t *node = NULL;

	if(NULL == scheduled_communication_type) {
		return;
	}
	free(scheduled_communication_type);
}

cJSON *scheduled_communication_type_convertToJSON(
	scheduled_communication_type_t *scheduled_communication_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(scheduled_communication_type == NULL) {
		printf(
			"scheduled_communication_type_convertToJSON() failed [ScheduledCommunicationType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

scheduled_communication_type_t *scheduled_communication_type_parseFromJSON(
	cJSON *scheduled_communication_typeJSON) {
	scheduled_communication_type_t *scheduled_communication_type_local_var =
		NULL;
	lnode_t *node = NULL;
	scheduled_communication_type_local_var =
		scheduled_communication_type_create(
			);

	return scheduled_communication_type_local_var;
end:
	return NULL;
}

scheduled_communication_type_t *scheduled_communication_type_copy(
	scheduled_communication_type_t	*dst,
	scheduled_communication_type_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = scheduled_communication_type_convertToJSON(src);
	if(!item) {
		printf("scheduled_communication_type_convertToJSON() failed");
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

	scheduled_communication_type_free(dst);
	dst = scheduled_communication_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
