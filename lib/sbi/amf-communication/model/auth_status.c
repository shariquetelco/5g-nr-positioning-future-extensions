#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "auth_status.h"

auth_status_t *auth_status_create() {
	auth_status_t *auth_status_local_var = malloc(sizeof(auth_status_t));


	return auth_status_local_var;
}

void auth_status_free(auth_status_t *auth_status) {
	lnode_t *node = NULL;

	if(NULL == auth_status) {
		return;
	}
	free(auth_status);
}

cJSON *auth_status_convertToJSON(auth_status_t *auth_status) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(auth_status == NULL) {
		printf("auth_status_convertToJSON() failed [AuthStatus]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

auth_status_t *auth_status_parseFromJSON(cJSON *auth_statusJSON) {
	auth_status_t *auth_status_local_var = NULL;
	lnode_t *node = NULL;
	auth_status_local_var = auth_status_create(
		);

	return auth_status_local_var;
end:
	return NULL;
}

auth_status_t *auth_status_copy(auth_status_t *dst, auth_status_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = auth_status_convertToJSON(src);
	if(!item) {
		printf("auth_status_convertToJSON() failed");
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

	auth_status_free(dst);
	dst = auth_status_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
