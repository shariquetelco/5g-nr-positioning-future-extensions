#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dn_perf_ordering_criterion.h"

dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_create() {
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_local_var =
		malloc(sizeof(dn_perf_ordering_criterion_t));


	return dn_perf_ordering_criterion_local_var;
}

void dn_perf_ordering_criterion_free(
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion) {
	lnode_t *node = NULL;

	if(NULL == dn_perf_ordering_criterion) {
		return;
	}
	free(dn_perf_ordering_criterion);
}

cJSON *dn_perf_ordering_criterion_convertToJSON(
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dn_perf_ordering_criterion == NULL) {
		printf(
			"dn_perf_ordering_criterion_convertToJSON() failed [DnPerfOrderingCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_parseFromJSON(
	cJSON *dn_perf_ordering_criterionJSON) {
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_local_var =
		NULL;
	lnode_t *node = NULL;
	dn_perf_ordering_criterion_local_var =
		dn_perf_ordering_criterion_create(
			);

	return dn_perf_ordering_criterion_local_var;
end:
	return NULL;
}

dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_copy(
	dn_perf_ordering_criterion_t *dst, dn_perf_ordering_criterion_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dn_perf_ordering_criterion_convertToJSON(src);
	if(!item) {
		printf("dn_perf_ordering_criterion_convertToJSON() failed");
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

	dn_perf_ordering_criterion_free(dst);
	dst = dn_perf_ordering_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
