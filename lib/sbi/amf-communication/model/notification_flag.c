#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_flag.h"

notification_flag_t *notification_flag_create() {
	notification_flag_t *notification_flag_local_var =
		malloc(sizeof(notification_flag_t));


	return notification_flag_local_var;
}

void notification_flag_free(notification_flag_t *notification_flag) {
	lnode_t *node = NULL;

	if(NULL == notification_flag) {
		return;
	}
	free(notification_flag);
}

cJSON *notification_flag_convertToJSON(notification_flag_t *notification_flag) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(notification_flag == NULL) {
		printf(
			"notification_flag_convertToJSON() failed [NotificationFlag]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

notification_flag_t *notification_flag_parseFromJSON(
	cJSON *notification_flagJSON) {
	notification_flag_t *notification_flag_local_var = NULL;
	lnode_t *node = NULL;
	notification_flag_local_var = notification_flag_create(
		);

	return notification_flag_local_var;
end:
	return NULL;
}

notification_flag_t *notification_flag_copy(notification_flag_t *dst,
                                            notification_flag_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = notification_flag_convertToJSON(src);
	if(!item) {
		printf("notification_flag_convertToJSON() failed");
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

	notification_flag_free(dst);
	dst = notification_flag_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
