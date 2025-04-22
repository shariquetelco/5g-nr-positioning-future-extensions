#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_experience_type.h"

service_experience_type_t *service_experience_type_create() {
	service_experience_type_t *service_experience_type_local_var = malloc(
		sizeof(service_experience_type_t));


	return service_experience_type_local_var;
}

void service_experience_type_free(
	service_experience_type_t *service_experience_type) {
	lnode_t *node = NULL;

	if(NULL == service_experience_type) {
		return;
	}
	free(service_experience_type);
}

cJSON *service_experience_type_convertToJSON(
	service_experience_type_t *service_experience_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(service_experience_type == NULL) {
		printf(
			"service_experience_type_convertToJSON() failed [ServiceExperienceType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

service_experience_type_t *service_experience_type_parseFromJSON(
	cJSON *service_experience_typeJSON) {
	service_experience_type_t *service_experience_type_local_var = NULL;
	lnode_t *node = NULL;
	service_experience_type_local_var = service_experience_type_create(
		);

	return service_experience_type_local_var;
end:
	return NULL;
}

service_experience_type_t *service_experience_type_copy(
	service_experience_type_t *dst, service_experience_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = service_experience_type_convertToJSON(src);
	if(!item) {
		printf("service_experience_type_convertToJSON() failed");
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

	service_experience_type_free(dst);
	dst = service_experience_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
