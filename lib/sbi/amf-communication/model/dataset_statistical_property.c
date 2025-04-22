#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dataset_statistical_property.h"

dataset_statistical_property_t *dataset_statistical_property_create() {
	dataset_statistical_property_t *dataset_statistical_property_local_var =
		malloc(sizeof(dataset_statistical_property_t));


	return dataset_statistical_property_local_var;
}

void dataset_statistical_property_free(
	dataset_statistical_property_t *dataset_statistical_property) {
	lnode_t *node = NULL;

	if(NULL == dataset_statistical_property) {
		return;
	}
	free(dataset_statistical_property);
}

cJSON *dataset_statistical_property_convertToJSON(
	dataset_statistical_property_t *dataset_statistical_property) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dataset_statistical_property == NULL) {
		printf(
			"dataset_statistical_property_convertToJSON() failed [DatasetStatisticalProperty]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

dataset_statistical_property_t *dataset_statistical_property_parseFromJSON(
	cJSON *dataset_statistical_propertyJSON) {
	dataset_statistical_property_t *dataset_statistical_property_local_var =
		NULL;
	lnode_t *node = NULL;
	dataset_statistical_property_local_var =
		dataset_statistical_property_create(
			);

	return dataset_statistical_property_local_var;
end:
	return NULL;
}

dataset_statistical_property_t *dataset_statistical_property_copy(
	dataset_statistical_property_t	*dst,
	dataset_statistical_property_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dataset_statistical_property_convertToJSON(src);
	if(!item) {
		printf("dataset_statistical_property_convertToJSON() failed");
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

	dataset_statistical_property_free(dst);
	dst = dataset_statistical_property_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
