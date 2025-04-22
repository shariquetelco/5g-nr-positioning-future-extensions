#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partitioning_criteria.h"

partitioning_criteria_t *partitioning_criteria_create() {
	partitioning_criteria_t *partitioning_criteria_local_var = malloc(
		sizeof(partitioning_criteria_t));


	return partitioning_criteria_local_var;
}

void partitioning_criteria_free(partitioning_criteria_t *partitioning_criteria)
{
	lnode_t *node = NULL;

	if(NULL == partitioning_criteria) {
		return;
	}
	free(partitioning_criteria);
}

cJSON *partitioning_criteria_convertToJSON(
	partitioning_criteria_t *partitioning_criteria) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(partitioning_criteria == NULL) {
		printf(
			"partitioning_criteria_convertToJSON() failed [PartitioningCriteria]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

partitioning_criteria_t *partitioning_criteria_parseFromJSON(
	cJSON *partitioning_criteriaJSON) {
	partitioning_criteria_t *partitioning_criteria_local_var = NULL;
	lnode_t *node = NULL;
	partitioning_criteria_local_var = partitioning_criteria_create(
		);

	return partitioning_criteria_local_var;
end:
	return NULL;
}

partitioning_criteria_t *partitioning_criteria_copy(
	partitioning_criteria_t *dst, partitioning_criteria_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = partitioning_criteria_convertToJSON(src);
	if(!item) {
		printf("partitioning_criteria_convertToJSON() failed");
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

	partitioning_criteria_free(dst);
	dst = partitioning_criteria_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
