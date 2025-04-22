#ifndef sensor_measurement_any_of_TEST
#define sensor_measurement_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sensor_measurement_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sensor_measurement_any_of.h"
sensor_measurement_any_of_t *instantiate_sensor_measurement_any_of(
	int include_optional);



sensor_measurement_any_of_t *instantiate_sensor_measurement_any_of(
	int include_optional) {
	sensor_measurement_any_of_t *sensor_measurement_any_of = NULL;
	if(include_optional) {
		sensor_measurement_any_of = sensor_measurement_any_of_create(
			);
	} else {
		sensor_measurement_any_of = sensor_measurement_any_of_create(
			);
	}

	return sensor_measurement_any_of;
}


#ifdef sensor_measurement_any_of_MAIN

void test_sensor_measurement_any_of(int include_optional) {
	sensor_measurement_any_of_t *sensor_measurement_any_of_1 =
		instantiate_sensor_measurement_any_of(include_optional);

	cJSON *jsonsensor_measurement_any_of_1 =
		sensor_measurement_any_of_convertToJSON(
			sensor_measurement_any_of_1);
	printf("sensor_measurement_any_of :\n%s\n",
	       cJSON_Print(jsonsensor_measurement_any_of_1));
	sensor_measurement_any_of_t *sensor_measurement_any_of_2 =
		sensor_measurement_any_of_parseFromJSON(
			jsonsensor_measurement_any_of_1);
	cJSON *jsonsensor_measurement_any_of_2 =
		sensor_measurement_any_of_convertToJSON(
			sensor_measurement_any_of_2);
	printf("repeating sensor_measurement_any_of:\n%s\n",
	       cJSON_Print(jsonsensor_measurement_any_of_2));
}

int main() {
	test_sensor_measurement_any_of(1);
	test_sensor_measurement_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // sensor_measurement_any_of_MAIN
#endif // sensor_measurement_any_of_TEST
