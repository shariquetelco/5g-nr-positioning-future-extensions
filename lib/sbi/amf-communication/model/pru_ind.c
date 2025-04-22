#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pru_ind.h"

pru_ind_t *pru_ind_create() {
	pru_ind_t *pru_ind_local_var = malloc(sizeof(pru_ind_t));


	return pru_ind_local_var;
}

void pru_ind_free(pru_ind_t *pru_ind) {
	lnode_t *node = NULL;

	if(NULL == pru_ind) {
		return;
	}
	free(pru_ind);
}

cJSON *pru_ind_convertToJSON(pru_ind_t *pru_ind) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pru_ind == NULL) {
		printf("pru_ind_convertToJSON() failed [PruInd]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

pru_ind_t *pru_ind_parseFromJSON(cJSON *pru_indJSON) {
	pru_ind_t *pru_ind_local_var = NULL;
	lnode_t *node = NULL;
	pru_ind_local_var = pru_ind_create(
		);

	return pru_ind_local_var;
end:
	return NULL;
}

pru_ind_t *pru_ind_copy(pru_ind_t *dst, pru_ind_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pru_ind_convertToJSON(src);
	if(!item) {
		printf("pru_ind_convertToJSON() failed");
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

	pru_ind_free(dst);
	dst = pru_ind_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
