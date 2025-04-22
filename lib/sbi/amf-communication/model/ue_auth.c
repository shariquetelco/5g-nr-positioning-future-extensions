#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_auth.h"

ue_auth_t *ue_auth_create() {
	ue_auth_t *ue_auth_local_var = malloc(sizeof(ue_auth_t));


	return ue_auth_local_var;
}

void ue_auth_free(ue_auth_t *ue_auth) {
	lnode_t *node = NULL;

	if(NULL == ue_auth) {
		return;
	}
	free(ue_auth);
}

cJSON *ue_auth_convertToJSON(ue_auth_t *ue_auth) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_auth == NULL) {
		printf("ue_auth_convertToJSON() failed [UeAuth]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

ue_auth_t *ue_auth_parseFromJSON(cJSON *ue_authJSON) {
	ue_auth_t *ue_auth_local_var = NULL;
	lnode_t *node = NULL;
	ue_auth_local_var = ue_auth_create(
		);

	return ue_auth_local_var;
end:
	return NULL;
}

ue_auth_t *ue_auth_copy(ue_auth_t *dst, ue_auth_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_auth_convertToJSON(src);
	if(!item) {
		printf("ue_auth_convertToJSON() failed");
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

	ue_auth_free(dst);
	dst = ue_auth_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
