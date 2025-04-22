#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job_type.h"

job_type_t *job_type_create() {
	job_type_t *job_type_local_var = malloc(sizeof(job_type_t));


	return job_type_local_var;
}

void job_type_free(job_type_t *job_type) {
	lnode_t *node = NULL;

	if(NULL == job_type) {
		return;
	}
	free(job_type);
}

cJSON *job_type_convertToJSON(job_type_t *job_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(job_type == NULL) {
		printf("job_type_convertToJSON() failed [JobType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

job_type_t *job_type_parseFromJSON(cJSON *job_typeJSON) {
	job_type_t *job_type_local_var = NULL;
	lnode_t *node = NULL;
	job_type_local_var = job_type_create(
		);

	return job_type_local_var;
end:
	return NULL;
}

job_type_t *job_type_copy(job_type_t *dst, job_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = job_type_convertToJSON(src);
	if(!item) {
		printf("job_type_convertToJSON() failed");
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

	job_type_free(dst);
	dst = job_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
