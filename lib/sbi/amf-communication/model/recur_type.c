#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recur_type.h"

recur_type_t *recur_type_create() {
	recur_type_t *recur_type_local_var = malloc(sizeof(recur_type_t));


	return recur_type_local_var;
}

void recur_type_free(recur_type_t *recur_type) {
	lnode_t *node = NULL;

	if(NULL == recur_type) {
		return;
	}
	free(recur_type);
}

cJSON *recur_type_convertToJSON(recur_type_t *recur_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(recur_type == NULL) {
		printf("recur_type_convertToJSON() failed [RecurType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

recur_type_t *recur_type_parseFromJSON(cJSON *recur_typeJSON) {
	recur_type_t *recur_type_local_var = NULL;
	lnode_t *node = NULL;
	recur_type_local_var = recur_type_create(
		);

	return recur_type_local_var;
end:
	return NULL;
}

recur_type_t *recur_type_copy(recur_type_t *dst, recur_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = recur_type_convertToJSON(src);
	if(!item) {
		printf("recur_type_convertToJSON() failed");
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

	recur_type_free(dst);
	dst = recur_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
