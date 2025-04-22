#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_perf_type.h"

network_perf_type_t *network_perf_type_create() {
	network_perf_type_t *network_perf_type_local_var =
		malloc(sizeof(network_perf_type_t));


	return network_perf_type_local_var;
}

void network_perf_type_free(network_perf_type_t *network_perf_type) {
	lnode_t *node = NULL;

	if(NULL == network_perf_type) {
		return;
	}
	free(network_perf_type);
}

cJSON *network_perf_type_convertToJSON(network_perf_type_t *network_perf_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(network_perf_type == NULL) {
		printf(
			"network_perf_type_convertToJSON() failed [NetworkPerfType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

network_perf_type_t *network_perf_type_parseFromJSON(
	cJSON *network_perf_typeJSON) {
	network_perf_type_t *network_perf_type_local_var = NULL;
	lnode_t *node = NULL;
	network_perf_type_local_var = network_perf_type_create(
		);

	return network_perf_type_local_var;
end:
	return NULL;
}

network_perf_type_t *network_perf_type_copy(network_perf_type_t *dst,
                                            network_perf_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = network_perf_type_convertToJSON(src);
	if(!item) {
		printf("network_perf_type_convertToJSON() failed");
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

	network_perf_type_free(dst);
	dst = network_perf_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
