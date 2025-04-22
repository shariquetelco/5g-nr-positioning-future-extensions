#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_ind.h"

reporting_ind_t *reporting_ind_create() {
	reporting_ind_t *reporting_ind_local_var = malloc(
		sizeof(reporting_ind_t));

	return reporting_ind_local_var;
}

void reporting_ind_free(reporting_ind_t *reporting_ind) {
	lnode_t *node = NULL;

	if(NULL == reporting_ind) {
		return;
	}
	free(reporting_ind);
}

cJSON *reporting_ind_convertToJSON(reporting_ind_t *reporting_ind) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(reporting_ind == NULL) {
		printf("reporting_ind_convertToJSON() failed [ReportingInd]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

reporting_ind_t *reporting_ind_parseFromJSON(cJSON *reporting_indJSON) {
	reporting_ind_t *reporting_ind_local_var = NULL;
	lnode_t *node = NULL;
	reporting_ind_local_var = reporting_ind_create(
		);

	return reporting_ind_local_var;
end:
	return NULL;
}

reporting_ind_t *reporting_ind_copy(reporting_ind_t	*dst,
                                    reporting_ind_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = reporting_ind_convertToJSON(src);
	if(!item) {
		printf("reporting_ind_convertToJSON() failed");
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

	reporting_ind_free(dst);
	dst = reporting_ind_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
