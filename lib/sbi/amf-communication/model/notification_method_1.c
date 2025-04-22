#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_method_1.h"

notification_method_1_t *notification_method_1_create() {
	notification_method_1_t *notification_method_1_local_var = malloc(
		sizeof(notification_method_1_t));


	return notification_method_1_local_var;
}

void notification_method_1_free(notification_method_1_t *notification_method_1)
{
	lnode_t *node = NULL;

	if(NULL == notification_method_1) {
		return;
	}
	free(notification_method_1);
}

cJSON *notification_method_1_convertToJSON(
	notification_method_1_t *notification_method_1) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(notification_method_1 == NULL) {
		printf(
			"notification_method_1_convertToJSON() failed [NotificationMethod_1]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

notification_method_1_t *notification_method_1_parseFromJSON(
	cJSON *notification_method_1JSON) {
	notification_method_1_t *notification_method_1_local_var = NULL;
	lnode_t *node = NULL;
	notification_method_1_local_var = notification_method_1_create(
		);

	return notification_method_1_local_var;
end:
	return NULL;
}

notification_method_1_t *notification_method_1_copy(
	notification_method_1_t *dst, notification_method_1_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = notification_method_1_convertToJSON(src);
	if(!item) {
		printf("notification_method_1_convertToJSON() failed");
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

	notification_method_1_free(dst);
	dst = notification_method_1_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
