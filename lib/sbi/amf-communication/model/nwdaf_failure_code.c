#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_failure_code.h"

nwdaf_failure_code_t *nwdaf_failure_code_create() {
	nwdaf_failure_code_t *nwdaf_failure_code_local_var =
		malloc(sizeof(nwdaf_failure_code_t));


	return nwdaf_failure_code_local_var;
}

void nwdaf_failure_code_free(nwdaf_failure_code_t *nwdaf_failure_code) {
	lnode_t *node = NULL;

	if(NULL == nwdaf_failure_code) {
		return;
	}
	free(nwdaf_failure_code);
}

cJSON *nwdaf_failure_code_convertToJSON(
	nwdaf_failure_code_t *nwdaf_failure_code) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nwdaf_failure_code == NULL) {
		printf(
			"nwdaf_failure_code_convertToJSON() failed [NwdafFailureCode]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

nwdaf_failure_code_t *nwdaf_failure_code_parseFromJSON(
	cJSON *nwdaf_failure_codeJSON) {
	nwdaf_failure_code_t *nwdaf_failure_code_local_var = NULL;
	lnode_t *node = NULL;
	nwdaf_failure_code_local_var = nwdaf_failure_code_create(
		);

	return nwdaf_failure_code_local_var;
end:
	return NULL;
}

nwdaf_failure_code_t *nwdaf_failure_code_copy(nwdaf_failure_code_t	*dst,
                                              nwdaf_failure_code_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nwdaf_failure_code_convertToJSON(src);
	if(!item) {
		printf("nwdaf_failure_code_convertToJSON() failed");
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

	nwdaf_failure_code_free(dst);
	dst = nwdaf_failure_code_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
