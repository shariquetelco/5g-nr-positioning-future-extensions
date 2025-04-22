#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_service_auth.h"

lcs_service_auth_t *lcs_service_auth_create() {
	lcs_service_auth_t *lcs_service_auth_local_var =
		malloc(sizeof(lcs_service_auth_t));


	return lcs_service_auth_local_var;
}

void lcs_service_auth_free(lcs_service_auth_t *lcs_service_auth) {
	lnode_t *node = NULL;

	if(NULL == lcs_service_auth) {
		return;
	}
	free(lcs_service_auth);
}

cJSON *lcs_service_auth_convertToJSON(lcs_service_auth_t *lcs_service_auth) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(lcs_service_auth == NULL) {
		printf(
			"lcs_service_auth_convertToJSON() failed [LcsServiceAuth]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

lcs_service_auth_t *lcs_service_auth_parseFromJSON(cJSON *lcs_service_authJSON)
{
	lcs_service_auth_t *lcs_service_auth_local_var = NULL;
	lnode_t *node = NULL;
	lcs_service_auth_local_var = lcs_service_auth_create(
		);

	return lcs_service_auth_local_var;
end:
	return NULL;
}

lcs_service_auth_t *lcs_service_auth_copy(lcs_service_auth_t	*dst,
                                          lcs_service_auth_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = lcs_service_auth_convertToJSON(src);
	if(!item) {
		printf("lcs_service_auth_convertToJSON() failed");
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

	lcs_service_auth_free(dst);
	dst = lcs_service_auth_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
