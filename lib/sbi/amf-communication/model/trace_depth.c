#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trace_depth.h"

trace_depth_t *trace_depth_create() {
	trace_depth_t *trace_depth_local_var = malloc(sizeof(trace_depth_t));


	return trace_depth_local_var;
}

void trace_depth_free(trace_depth_t *trace_depth) {
	lnode_t *node = NULL;

	if(NULL == trace_depth) {
		return;
	}
	free(trace_depth);
}

cJSON *trace_depth_convertToJSON(trace_depth_t *trace_depth) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(trace_depth == NULL) {
		printf("trace_depth_convertToJSON() failed [TraceDepth]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

trace_depth_t *trace_depth_parseFromJSON(cJSON *trace_depthJSON) {
	trace_depth_t *trace_depth_local_var = NULL;
	lnode_t *node = NULL;
	trace_depth_local_var = trace_depth_create(
		);

	return trace_depth_local_var;
end:
	return NULL;
}

trace_depth_t *trace_depth_copy(trace_depth_t *dst, trace_depth_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = trace_depth_convertToJSON(src);
	if(!item) {
		printf("trace_depth_convertToJSON() failed");
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

	trace_depth_free(dst);
	dst = trace_depth_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
