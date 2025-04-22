#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_perf_order_criterion.h"

network_perf_order_criterion_t *network_perf_order_criterion_create() {
	network_perf_order_criterion_t *network_perf_order_criterion_local_var =
		malloc(sizeof(network_perf_order_criterion_t));


	return network_perf_order_criterion_local_var;
}

void network_perf_order_criterion_free(
	network_perf_order_criterion_t *network_perf_order_criterion) {
	lnode_t *node = NULL;

	if(NULL == network_perf_order_criterion) {
		return;
	}
	free(network_perf_order_criterion);
}

cJSON *network_perf_order_criterion_convertToJSON(
	network_perf_order_criterion_t *network_perf_order_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(network_perf_order_criterion == NULL) {
		printf(
			"network_perf_order_criterion_convertToJSON() failed [NetworkPerfOrderCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

network_perf_order_criterion_t *network_perf_order_criterion_parseFromJSON(
	cJSON *network_perf_order_criterionJSON) {
	network_perf_order_criterion_t *network_perf_order_criterion_local_var =
		NULL;
	lnode_t *node = NULL;
	network_perf_order_criterion_local_var =
		network_perf_order_criterion_create(
			);

	return network_perf_order_criterion_local_var;
end:
	return NULL;
}

network_perf_order_criterion_t *network_perf_order_criterion_copy(
	network_perf_order_criterion_t	*dst,
	network_perf_order_criterion_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = network_perf_order_criterion_convertToJSON(src);
	if(!item) {
		printf("network_perf_order_criterion_convertToJSON() failed");
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

	network_perf_order_criterion_free(dst);
	dst = network_perf_order_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
