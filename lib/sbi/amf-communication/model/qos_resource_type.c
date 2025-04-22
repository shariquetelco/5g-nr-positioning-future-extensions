#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "qos_resource_type.h"

qos_resource_type_t *qos_resource_type_create() {
	qos_resource_type_t *qos_resource_type_local_var =
		malloc(sizeof(qos_resource_type_t));


	return qos_resource_type_local_var;
}

void qos_resource_type_free(qos_resource_type_t *qos_resource_type) {
	lnode_t *node = NULL;

	if(NULL == qos_resource_type) {
		return;
	}
	free(qos_resource_type);
}

cJSON *qos_resource_type_convertToJSON(qos_resource_type_t *qos_resource_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(qos_resource_type == NULL) {
		printf(
			"qos_resource_type_convertToJSON() failed [QosResourceType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

qos_resource_type_t *qos_resource_type_parseFromJSON(
	cJSON *qos_resource_typeJSON) {
	qos_resource_type_t *qos_resource_type_local_var = NULL;
	lnode_t *node = NULL;
	qos_resource_type_local_var = qos_resource_type_create(
		);

	return qos_resource_type_local_var;
end:
	return NULL;
}

qos_resource_type_t *qos_resource_type_copy(qos_resource_type_t *dst,
                                            qos_resource_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = qos_resource_type_convertToJSON(src);
	if(!item) {
		printf("qos_resource_type_convertToJSON() failed");
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

	qos_resource_type_free(dst);
	dst = qos_resource_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
