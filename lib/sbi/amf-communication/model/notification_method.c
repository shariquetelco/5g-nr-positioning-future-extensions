#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_method.h"

notification_method_t *notification_method_create() {
	notification_method_t *notification_method_local_var =
		malloc(sizeof(notification_method_t));


	return notification_method_local_var;
}

void notification_method_free(notification_method_t *notification_method) {
	lnode_t *node = NULL;

	if(NULL == notification_method) {
		return;
	}
	free(notification_method);
}

cJSON *notification_method_convertToJSON(
	notification_method_t *notification_method) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(notification_method == NULL) {
		printf(
			"notification_method_convertToJSON() failed [NotificationMethod]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

notification_method_t *notification_method_parseFromJSON(
	cJSON *notification_methodJSON) {
	notification_method_t *notification_method_local_var = NULL;
	lnode_t *node = NULL;
	notification_method_local_var = notification_method_create(
		);

	return notification_method_local_var;
end:
	return NULL;
}

notification_method_t *notification_method_copy(notification_method_t	*dst,
                                                notification_method_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = notification_method_convertToJSON(src);
	if(!item) {
		printf("notification_method_convertToJSON() failed");
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

	notification_method_free(dst);
	dst = notification_method_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
