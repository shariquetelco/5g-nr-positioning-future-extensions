#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "measurement_nr_for_mdt.h"

measurement_nr_for_mdt_t *measurement_nr_for_mdt_create() {
	measurement_nr_for_mdt_t *measurement_nr_for_mdt_local_var = malloc(
		sizeof(measurement_nr_for_mdt_t));


	return measurement_nr_for_mdt_local_var;
}

void measurement_nr_for_mdt_free(
	measurement_nr_for_mdt_t *measurement_nr_for_mdt) {
	lnode_t *node = NULL;

	if(NULL == measurement_nr_for_mdt) {
		return;
	}
	free(measurement_nr_for_mdt);
}

cJSON *measurement_nr_for_mdt_convertToJSON(
	measurement_nr_for_mdt_t *measurement_nr_for_mdt) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(measurement_nr_for_mdt == NULL) {
		printf(
			"measurement_nr_for_mdt_convertToJSON() failed [MeasurementNrForMdt]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

measurement_nr_for_mdt_t *measurement_nr_for_mdt_parseFromJSON(
	cJSON *measurement_nr_for_mdtJSON) {
	measurement_nr_for_mdt_t *measurement_nr_for_mdt_local_var = NULL;
	lnode_t *node = NULL;
	measurement_nr_for_mdt_local_var = measurement_nr_for_mdt_create(
		);

	return measurement_nr_for_mdt_local_var;
end:
	return NULL;
}

measurement_nr_for_mdt_t *measurement_nr_for_mdt_copy(
	measurement_nr_for_mdt_t *dst, measurement_nr_for_mdt_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = measurement_nr_for_mdt_convertToJSON(src);
	if(!item) {
		printf("measurement_nr_for_mdt_convertToJSON() failed");
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

	measurement_nr_for_mdt_free(dst);
	dst = measurement_nr_for_mdt_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
