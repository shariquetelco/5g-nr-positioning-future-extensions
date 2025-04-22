#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "measurement_lte_for_mdt.h"

measurement_lte_for_mdt_t *measurement_lte_for_mdt_create() {
	measurement_lte_for_mdt_t *measurement_lte_for_mdt_local_var = malloc(
		sizeof(measurement_lte_for_mdt_t));


	return measurement_lte_for_mdt_local_var;
}

void measurement_lte_for_mdt_free(
	measurement_lte_for_mdt_t *measurement_lte_for_mdt) {
	lnode_t *node = NULL;

	if(NULL == measurement_lte_for_mdt) {
		return;
	}
	free(measurement_lte_for_mdt);
}

cJSON *measurement_lte_for_mdt_convertToJSON(
	measurement_lte_for_mdt_t *measurement_lte_for_mdt) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(measurement_lte_for_mdt == NULL) {
		printf(
			"measurement_lte_for_mdt_convertToJSON() failed [MeasurementLteForMdt]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

measurement_lte_for_mdt_t *measurement_lte_for_mdt_parseFromJSON(
	cJSON *measurement_lte_for_mdtJSON) {
	measurement_lte_for_mdt_t *measurement_lte_for_mdt_local_var = NULL;
	lnode_t *node = NULL;
	measurement_lte_for_mdt_local_var = measurement_lte_for_mdt_create(
		);

	return measurement_lte_for_mdt_local_var;
end:
	return NULL;
}

measurement_lte_for_mdt_t *measurement_lte_for_mdt_copy(
	measurement_lte_for_mdt_t *dst, measurement_lte_for_mdt_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = measurement_lte_for_mdt_convertToJSON(src);
	if(!item) {
		printf("measurement_lte_for_mdt_convertToJSON() failed");
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

	measurement_lte_for_mdt_free(dst);
	dst = measurement_lte_for_mdt_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
