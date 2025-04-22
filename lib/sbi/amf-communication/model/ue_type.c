#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_type.h"

ue_type_t *ue_type_create() {
	ue_type_t *ue_type_local_var = malloc(sizeof(ue_type_t));


	return ue_type_local_var;
}

void ue_type_free(ue_type_t *ue_type) {
	lnode_t *node = NULL;

	if(NULL == ue_type) {
		return;
	}
	free(ue_type);
}

cJSON *ue_type_convertToJSON(ue_type_t *ue_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_type == NULL) {
		printf("ue_type_convertToJSON() failed [UeType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

ue_type_t *ue_type_parseFromJSON(cJSON *ue_typeJSON) {
	ue_type_t *ue_type_local_var = NULL;
	lnode_t *node = NULL;
	ue_type_local_var = ue_type_create(
		);

	return ue_type_local_var;
end:
	return NULL;
}

ue_type_t *ue_type_copy(ue_type_t *dst, ue_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_type_convertToJSON(src);
	if(!item) {
		printf("ue_type_convertToJSON() failed");
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

	ue_type_free(dst);
	dst = ue_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
