#ifndef sensor_measurement_TEST
#define sensor_measurement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sensor_measurement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sensor_measurement.h"
sensor_measurement_t *instantiate_sensor_measurement(int include_optional);



sensor_measurement_t *instantiate_sensor_measurement(int include_optional) {
	sensor_measurement_t *sensor_measurement = NULL;
	if(include_optional) {
		sensor_measurement = sensor_measurement_create(
			);
	} else {
		sensor_measurement = sensor_measurement_create(
			);
	}

	return sensor_measurement;
}


#ifdef sensor_measurement_MAIN

void test_sensor_measurement(int include_optional) {
	sensor_measurement_t *sensor_measurement_1 =
		instantiate_sensor_measurement(include_optional);

	cJSON *jsonsensor_measurement_1 = sensor_measurement_convertToJSON(
		sensor_measurement_1);
	printf("sensor_measurement :\n%s\n",
	       cJSON_Print(jsonsensor_measurement_1));
	sensor_measurement_t *sensor_measurement_2 =
		sensor_measurement_parseFromJSON(jsonsensor_measurement_1);
	cJSON *jsonsensor_measurement_2 = sensor_measurement_convertToJSON(
		sensor_measurement_2);
	printf("repeating sensor_measurement:\n%s\n",
	       cJSON_Print(jsonsensor_measurement_2));
}

int main() {
	test_sensor_measurement(1);
	test_sensor_measurement(0);

	printf("Hello world \n");
	return 0;
}

#endif // sensor_measurement_MAIN
#endif // sensor_measurement_TEST
