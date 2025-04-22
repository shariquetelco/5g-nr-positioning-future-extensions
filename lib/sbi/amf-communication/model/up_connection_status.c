#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_connection_status.h"

up_connection_status_t *up_connection_status_create() {
	up_connection_status_t *up_connection_status_local_var =
		malloc(sizeof(up_connection_status_t));


	return up_connection_status_local_var;
}

void up_connection_status_free(up_connection_status_t *up_connection_status) {
	lnode_t *node = NULL;

	if(NULL == up_connection_status) {
		return;
	}
	free(up_connection_status);
}

cJSON *up_connection_status_convertToJSON(
	up_connection_status_t *up_connection_status) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(up_connection_status == NULL) {
		printf(
			"up_connection_status_convertToJSON() failed [UpConnectionStatus]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

up_connection_status_t *up_connection_status_parseFromJSON(
	cJSON *up_connection_statusJSON) {
	up_connection_status_t *up_connection_status_local_var = NULL;
	lnode_t *node = NULL;
	up_connection_status_local_var = up_connection_status_create(
		);

	return up_connection_status_local_var;
end:
	return NULL;
}

up_connection_status_t *up_connection_status_copy(
	up_connection_status_t	*dst,
	up_connection_status_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = up_connection_status_convertToJSON(src);
	if(!item) {
		printf("up_connection_status_convertToJSON() failed");
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

	up_connection_status_free(dst);
	dst = up_connection_status_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
