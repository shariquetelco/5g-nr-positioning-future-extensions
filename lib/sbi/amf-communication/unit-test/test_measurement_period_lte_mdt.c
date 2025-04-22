#ifndef measurement_period_lte_mdt_TEST
#define measurement_period_lte_mdt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define measurement_period_lte_mdt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/measurement_period_lte_mdt.h"
measurement_period_lte_mdt_t *instantiate_measurement_period_lte_mdt(
	int include_optional);



measurement_period_lte_mdt_t *instantiate_measurement_period_lte_mdt(
	int include_optional) {
	measurement_period_lte_mdt_t *measurement_period_lte_mdt = NULL;
	if(include_optional) {
		measurement_period_lte_mdt = measurement_period_lte_mdt_create(
			);
	} else {
		measurement_period_lte_mdt = measurement_period_lte_mdt_create(
			);
	}

	return measurement_period_lte_mdt;
}


#ifdef measurement_period_lte_mdt_MAIN

void test_measurement_period_lte_mdt(int include_optional) {
	measurement_period_lte_mdt_t *measurement_period_lte_mdt_1 =
		instantiate_measurement_period_lte_mdt(include_optional);

	cJSON *jsonmeasurement_period_lte_mdt_1 =
		measurement_period_lte_mdt_convertToJSON(
			measurement_period_lte_mdt_1);
	printf("measurement_period_lte_mdt :\n%s\n",
	       cJSON_Print(jsonmeasurement_period_lte_mdt_1));
	measurement_period_lte_mdt_t *measurement_period_lte_mdt_2 =
		measurement_period_lte_mdt_parseFromJSON(
			jsonmeasurement_period_lte_mdt_1);
	cJSON *jsonmeasurement_period_lte_mdt_2 =
		measurement_period_lte_mdt_convertToJSON(
			measurement_period_lte_mdt_2);
	printf("repeating measurement_period_lte_mdt:\n%s\n",
	       cJSON_Print(jsonmeasurement_period_lte_mdt_2));
}

int main() {
	test_measurement_period_lte_mdt(1);
	test_measurement_period_lte_mdt(0);

	printf("Hello world \n");
	return 0;
}

#endif // measurement_period_lte_mdt_MAIN
#endif // measurement_period_lte_mdt_TEST
