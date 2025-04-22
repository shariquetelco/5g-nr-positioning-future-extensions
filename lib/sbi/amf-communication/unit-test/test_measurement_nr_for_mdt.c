#ifndef measurement_nr_for_mdt_TEST
#define measurement_nr_for_mdt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define measurement_nr_for_mdt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/measurement_nr_for_mdt.h"
measurement_nr_for_mdt_t *instantiate_measurement_nr_for_mdt(
	int include_optional);



measurement_nr_for_mdt_t *instantiate_measurement_nr_for_mdt(
	int include_optional) {
	measurement_nr_for_mdt_t *measurement_nr_for_mdt = NULL;
	if(include_optional) {
		measurement_nr_for_mdt = measurement_nr_for_mdt_create(
			);
	} else {
		measurement_nr_for_mdt = measurement_nr_for_mdt_create(
			);
	}

	return measurement_nr_for_mdt;
}


#ifdef measurement_nr_for_mdt_MAIN

void test_measurement_nr_for_mdt(int include_optional) {
	measurement_nr_for_mdt_t *measurement_nr_for_mdt_1 =
		instantiate_measurement_nr_for_mdt(include_optional);

	cJSON *jsonmeasurement_nr_for_mdt_1 =
		measurement_nr_for_mdt_convertToJSON(measurement_nr_for_mdt_1);
	printf("measurement_nr_for_mdt :\n%s\n",
	       cJSON_Print(jsonmeasurement_nr_for_mdt_1));
	measurement_nr_for_mdt_t *measurement_nr_for_mdt_2 =
		measurement_nr_for_mdt_parseFromJSON(
			jsonmeasurement_nr_for_mdt_1);
	cJSON *jsonmeasurement_nr_for_mdt_2 =
		measurement_nr_for_mdt_convertToJSON(measurement_nr_for_mdt_2);
	printf("repeating measurement_nr_for_mdt:\n%s\n",
	       cJSON_Print(jsonmeasurement_nr_for_mdt_2));
}

int main() {
	test_measurement_nr_for_mdt(1);
	test_measurement_nr_for_mdt(0);

	printf("Hello world \n");
	return 0;
}

#endif // measurement_nr_for_mdt_MAIN
#endif // measurement_nr_for_mdt_TEST
