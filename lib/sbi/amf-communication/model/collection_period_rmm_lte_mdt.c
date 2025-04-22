#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "collection_period_rmm_lte_mdt.h"

collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_create() {
	collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_local_var
	        = malloc(sizeof(collection_period_rmm_lte_mdt_t));


	return collection_period_rmm_lte_mdt_local_var;
}

void collection_period_rmm_lte_mdt_free(
	collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt) {
	lnode_t *node = NULL;

	if(NULL == collection_period_rmm_lte_mdt) {
		return;
	}
	free(collection_period_rmm_lte_mdt);
}

cJSON *collection_period_rmm_lte_mdt_convertToJSON(
	collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(collection_period_rmm_lte_mdt == NULL) {
		printf(
			"collection_period_rmm_lte_mdt_convertToJSON() failed [CollectionPeriodRmmLteMdt]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_parseFromJSON(
	cJSON *collection_period_rmm_lte_mdtJSON) {
	collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_local_var
	        = NULL;
	lnode_t *node = NULL;
	collection_period_rmm_lte_mdt_local_var =
		collection_period_rmm_lte_mdt_create(
			);

	return collection_period_rmm_lte_mdt_local_var;
end:
	return NULL;
}

collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_mdt_copy(
	collection_period_rmm_lte_mdt_t *dst,
	collection_period_rmm_lte_mdt_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = collection_period_rmm_lte_mdt_convertToJSON(src);
	if(!item) {
		printf("collection_period_rmm_lte_mdt_convertToJSON() failed");
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

	collection_period_rmm_lte_mdt_free(dst);
	dst = collection_period_rmm_lte_mdt_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
