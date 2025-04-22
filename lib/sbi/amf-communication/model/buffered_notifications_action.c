#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "buffered_notifications_action.h"

buffered_notifications_action_t *buffered_notifications_action_create() {
	buffered_notifications_action_t *buffered_notifications_action_local_var
	        = malloc(sizeof(buffered_notifications_action_t));


	return buffered_notifications_action_local_var;
}

void buffered_notifications_action_free(
	buffered_notifications_action_t *buffered_notifications_action) {
	lnode_t *node = NULL;

	if(NULL == buffered_notifications_action) {
		return;
	}
	free(buffered_notifications_action);
}

cJSON *buffered_notifications_action_convertToJSON(
	buffered_notifications_action_t *buffered_notifications_action) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(buffered_notifications_action == NULL) {
		printf(
			"buffered_notifications_action_convertToJSON() failed [BufferedNotificationsAction]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

buffered_notifications_action_t *buffered_notifications_action_parseFromJSON(
	cJSON *buffered_notifications_actionJSON) {
	buffered_notifications_action_t *buffered_notifications_action_local_var
	        = NULL;
	lnode_t *node = NULL;
	buffered_notifications_action_local_var =
		buffered_notifications_action_create(
			);

	return buffered_notifications_action_local_var;
end:
	return NULL;
}

buffered_notifications_action_t *buffered_notifications_action_copy(
	buffered_notifications_action_t *dst,
	buffered_notifications_action_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = buffered_notifications_action_convertToJSON(src);
	if(!item) {
		printf("buffered_notifications_action_convertToJSON() failed");
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

	buffered_notifications_action_free(dst);
	dst = buffered_notifications_action_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
