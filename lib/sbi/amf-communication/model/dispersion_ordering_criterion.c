#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dispersion_ordering_criterion.h"

dispersion_ordering_criterion_t *dispersion_ordering_criterion_create() {
	dispersion_ordering_criterion_t *dispersion_ordering_criterion_local_var
	        = malloc(sizeof(dispersion_ordering_criterion_t));


	return dispersion_ordering_criterion_local_var;
}

void dispersion_ordering_criterion_free(
	dispersion_ordering_criterion_t *dispersion_ordering_criterion) {
	lnode_t *node = NULL;

	if(NULL == dispersion_ordering_criterion) {
		return;
	}
	free(dispersion_ordering_criterion);
}

cJSON *dispersion_ordering_criterion_convertToJSON(
	dispersion_ordering_criterion_t *dispersion_ordering_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dispersion_ordering_criterion == NULL) {
		printf(
			"dispersion_ordering_criterion_convertToJSON() failed [DispersionOrderingCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

dispersion_ordering_criterion_t *dispersion_ordering_criterion_parseFromJSON(
	cJSON *dispersion_ordering_criterionJSON) {
	dispersion_ordering_criterion_t *dispersion_ordering_criterion_local_var
	        = NULL;
	lnode_t *node = NULL;
	dispersion_ordering_criterion_local_var =
		dispersion_ordering_criterion_create(
			);

	return dispersion_ordering_criterion_local_var;
end:
	return NULL;
}

dispersion_ordering_criterion_t *dispersion_ordering_criterion_copy(
	dispersion_ordering_criterion_t *dst,
	dispersion_ordering_criterion_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dispersion_ordering_criterion_convertToJSON(src);
	if(!item) {
		printf("dispersion_ordering_criterion_convertToJSON() failed");
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

	dispersion_ordering_criterion_free(dst);
	dst = dispersion_ordering_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
