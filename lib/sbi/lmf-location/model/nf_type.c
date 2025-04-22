#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type.h"

nf_type_t *nf_type_create() {
	nf_type_t *nf_type_local_var = malloc(sizeof(nf_type_t));


	return nf_type_local_var;
}

void nf_type_free(nf_type_t *nf_type) {
	lnode_t *node = NULL;

	if(NULL == nf_type) {
		return;
	}
	free(nf_type);
}

cJSON *nf_type_convertToJSON(nf_type_t *nf_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nf_type == NULL) {
		printf("nf_type_convertToJSON() failed [NFType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

nf_type_t *nf_type_parseFromJSON(cJSON *nf_typeJSON) {
	nf_type_t *nf_type_local_var = NULL;
	lnode_t *node = NULL;
	nf_type_local_var = nf_type_create(
		);

	return nf_type_local_var;
end:
	return NULL;
}

nf_type_t *nf_type_copy(nf_type_t *dst, nf_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nf_type_convertToJSON(src);
	if(!item) {
		printf("nf_type_convertToJSON() failed");
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

	nf_type_free(dst);
	dst = nf_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
