#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_network_type.h"

core_network_type_t *core_network_type_create() {
	core_network_type_t *core_network_type_local_var =
		malloc(sizeof(core_network_type_t));


	return core_network_type_local_var;
}

void core_network_type_free(core_network_type_t *core_network_type) {
	lnode_t *node = NULL;

	if(NULL == core_network_type) {
		return;
	}
	free(core_network_type);
}

cJSON *core_network_type_convertToJSON(core_network_type_t *core_network_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(core_network_type == NULL) {
		printf(
			"core_network_type_convertToJSON() failed [CoreNetworkType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

core_network_type_t *core_network_type_parseFromJSON(
	cJSON *core_network_typeJSON) {
	core_network_type_t *core_network_type_local_var = NULL;
	lnode_t *node = NULL;
	core_network_type_local_var = core_network_type_create(
		);

	return core_network_type_local_var;
end:
	return NULL;
}

core_network_type_t *core_network_type_copy(core_network_type_t *dst,
                                            core_network_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = core_network_type_convertToJSON(src);
	if(!item) {
		printf("core_network_type_convertToJSON() failed");
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

	core_network_type_free(dst);
	dst = core_network_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
