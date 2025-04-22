#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flow_direction.h"

flow_direction_t *flow_direction_create() {
	flow_direction_t *flow_direction_local_var =
		malloc(sizeof(flow_direction_t));


	return flow_direction_local_var;
}

void flow_direction_free(flow_direction_t *flow_direction) {
	lnode_t *node = NULL;

	if(NULL == flow_direction) {
		return;
	}
	free(flow_direction);
}

cJSON *flow_direction_convertToJSON(flow_direction_t *flow_direction) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(flow_direction == NULL) {
		printf("flow_direction_convertToJSON() failed [FlowDirection]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

flow_direction_t *flow_direction_parseFromJSON(cJSON *flow_directionJSON) {
	flow_direction_t *flow_direction_local_var = NULL;
	lnode_t *node = NULL;
	flow_direction_local_var = flow_direction_create(
		);

	return flow_direction_local_var;
end:
	return NULL;
}

flow_direction_t *flow_direction_copy(flow_direction_t	*dst,
                                      flow_direction_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = flow_direction_convertToJSON(src);
	if(!item) {
		printf("flow_direction_convertToJSON() failed");
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

	flow_direction_free(dst);
	dst = flow_direction_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
