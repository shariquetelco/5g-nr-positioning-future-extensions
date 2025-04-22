#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "measurement_period_lte_mdt.h"

measurement_period_lte_mdt_t *measurement_period_lte_mdt_create() {
	measurement_period_lte_mdt_t *measurement_period_lte_mdt_local_var =
		malloc(sizeof(measurement_period_lte_mdt_t));


	return measurement_period_lte_mdt_local_var;
}

void measurement_period_lte_mdt_free(
	measurement_period_lte_mdt_t *measurement_period_lte_mdt) {
	lnode_t *node = NULL;

	if(NULL == measurement_period_lte_mdt) {
		return;
	}
	free(measurement_period_lte_mdt);
}

cJSON *measurement_period_lte_mdt_convertToJSON(
	measurement_period_lte_mdt_t *measurement_period_lte_mdt) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(measurement_period_lte_mdt == NULL) {
		printf(
			"measurement_period_lte_mdt_convertToJSON() failed [MeasurementPeriodLteMdt]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

measurement_period_lte_mdt_t *measurement_period_lte_mdt_parseFromJSON(
	cJSON *measurement_period_lte_mdtJSON) {
	measurement_period_lte_mdt_t *measurement_period_lte_mdt_local_var =
		NULL;
	lnode_t *node = NULL;
	measurement_period_lte_mdt_local_var =
		measurement_period_lte_mdt_create(
			);

	return measurement_period_lte_mdt_local_var;
end:
	return NULL;
}

measurement_period_lte_mdt_t *measurement_period_lte_mdt_copy(
	measurement_period_lte_mdt_t *dst, measurement_period_lte_mdt_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = measurement_period_lte_mdt_convertToJSON(src);
	if(!item) {
		printf("measurement_period_lte_mdt_convertToJSON() failed");
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

	measurement_period_lte_mdt_free(dst);
	dst = measurement_period_lte_mdt_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
