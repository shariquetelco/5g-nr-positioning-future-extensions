#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "exception_id.h"

exception_id_t *exception_id_create() {
	exception_id_t *exception_id_local_var = malloc(sizeof(exception_id_t));


	return exception_id_local_var;
}

void exception_id_free(exception_id_t *exception_id) {
	lnode_t *node = NULL;

	if(NULL == exception_id) {
		return;
	}
	free(exception_id);
}

cJSON *exception_id_convertToJSON(exception_id_t *exception_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(exception_id == NULL) {
		printf("exception_id_convertToJSON() failed [ExceptionId]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

exception_id_t *exception_id_parseFromJSON(cJSON *exception_idJSON) {
	exception_id_t *exception_id_local_var = NULL;
	lnode_t *node = NULL;
	exception_id_local_var = exception_id_create(
		);

	return exception_id_local_var;
end:
	return NULL;
}

exception_id_t *exception_id_copy(exception_id_t *dst, exception_id_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = exception_id_convertToJSON(src);
	if(!item) {
		printf("exception_id_convertToJSON() failed");
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

	exception_id_free(dst);
	dst = exception_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
