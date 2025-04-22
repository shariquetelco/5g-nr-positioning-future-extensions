#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sensor_measurement.h"

sensor_measurement_t *sensor_measurement_create() {
	sensor_measurement_t *sensor_measurement_local_var =
		malloc(sizeof(sensor_measurement_t));


	return sensor_measurement_local_var;
}

void sensor_measurement_free(sensor_measurement_t *sensor_measurement) {
	lnode_t *node = NULL;

	if(NULL == sensor_measurement) {
		return;
	}
	free(sensor_measurement);
}

cJSON *sensor_measurement_convertToJSON(
	sensor_measurement_t *sensor_measurement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(sensor_measurement == NULL) {
		printf(
			"sensor_measurement_convertToJSON() failed [SensorMeasurement]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

sensor_measurement_t *sensor_measurement_parseFromJSON(
	cJSON *sensor_measurementJSON) {
	sensor_measurement_t *sensor_measurement_local_var = NULL;
	lnode_t *node = NULL;
	sensor_measurement_local_var = sensor_measurement_create(
		);

	return sensor_measurement_local_var;
end:
	return NULL;
}

sensor_measurement_t *sensor_measurement_copy(sensor_measurement_t	*dst,
                                              sensor_measurement_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = sensor_measurement_convertToJSON(src);
	if(!item) {
		printf("sensor_measurement_convertToJSON() failed");
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

	sensor_measurement_free(dst);
	dst = sensor_measurement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
