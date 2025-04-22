#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reachability_filter.h"

reachability_filter_t *reachability_filter_create() {
	reachability_filter_t *reachability_filter_local_var =
		malloc(sizeof(reachability_filter_t));


	return reachability_filter_local_var;
}

void reachability_filter_free(reachability_filter_t *reachability_filter) {
	lnode_t *node = NULL;

	if(NULL == reachability_filter) {
		return;
	}
	free(reachability_filter);
}

cJSON *reachability_filter_convertToJSON(
	reachability_filter_t *reachability_filter) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(reachability_filter == NULL) {
		printf(
			"reachability_filter_convertToJSON() failed [ReachabilityFilter]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

reachability_filter_t *reachability_filter_parseFromJSON(
	cJSON *reachability_filterJSON) {
	reachability_filter_t *reachability_filter_local_var = NULL;
	lnode_t *node = NULL;
	reachability_filter_local_var = reachability_filter_create(
		);

	return reachability_filter_local_var;
end:
	return NULL;
}

reachability_filter_t *reachability_filter_copy(reachability_filter_t	*dst,
                                                reachability_filter_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = reachability_filter_convertToJSON(src);
	if(!item) {
		printf("reachability_filter_convertToJSON() failed");
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

	reachability_filter_free(dst);
	dst = reachability_filter_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
