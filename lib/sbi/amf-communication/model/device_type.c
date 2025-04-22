#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "device_type.h"

device_type_t *device_type_create() {
	device_type_t *device_type_local_var = malloc(sizeof(device_type_t));


	return device_type_local_var;
}

void device_type_free(device_type_t *device_type) {
	lnode_t *node = NULL;

	if(NULL == device_type) {
		return;
	}
	free(device_type);
}

cJSON *device_type_convertToJSON(device_type_t *device_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(device_type == NULL) {
		printf("device_type_convertToJSON() failed [DeviceType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

device_type_t *device_type_parseFromJSON(cJSON *device_typeJSON) {
	device_type_t *device_type_local_var = NULL;
	lnode_t *node = NULL;
	device_type_local_var = device_type_create(
		);

	return device_type_local_var;
end:
	return NULL;
}

device_type_t *device_type_copy(device_type_t *dst, device_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = device_type_convertToJSON(src);
	if(!item) {
		printf("device_type_convertToJSON() failed");
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

	device_type_free(dst);
	dst = device_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
