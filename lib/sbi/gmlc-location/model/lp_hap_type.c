#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lp_hap_type.h"

lp_hap_type_t *lp_hap_type_create() {
	lp_hap_type_t *lp_hap_type_local_var = malloc(sizeof(lp_hap_type_t));


	return lp_hap_type_local_var;
}

void lp_hap_type_free(lp_hap_type_t *lp_hap_type) {
	lnode_t *node = NULL;

	if(NULL == lp_hap_type) {
		return;
	}
	free(lp_hap_type);
}

cJSON *lp_hap_type_convertToJSON(lp_hap_type_t *lp_hap_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(lp_hap_type == NULL) {
		printf("lp_hap_type_convertToJSON() failed [LpHapType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

lp_hap_type_t *lp_hap_type_parseFromJSON(cJSON *lp_hap_typeJSON) {
	lp_hap_type_t *lp_hap_type_local_var = NULL;
	lnode_t *node = NULL;
	lp_hap_type_local_var = lp_hap_type_create(
		);

	return lp_hap_type_local_var;
end:
	return NULL;
}

lp_hap_type_t *lp_hap_type_copy(lp_hap_type_t *dst, lp_hap_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = lp_hap_type_convertToJSON(src);
	if(!item) {
		printf("lp_hap_type_convertToJSON() failed");
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

	lp_hap_type_free(dst);
	dst = lp_hap_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
