#ifndef measurement_lte_for_mdt_any_of_TEST
#define measurement_lte_for_mdt_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define measurement_lte_for_mdt_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/measurement_lte_for_mdt_any_of.h"
measurement_lte_for_mdt_any_of_t *instantiate_measurement_lte_for_mdt_any_of(
	int include_optional);



measurement_lte_for_mdt_any_of_t *instantiate_measurement_lte_for_mdt_any_of(
	int include_optional) {
	measurement_lte_for_mdt_any_of_t *measurement_lte_for_mdt_any_of = NULL;
	if(include_optional) {
		measurement_lte_for_mdt_any_of =
			measurement_lte_for_mdt_any_of_create(
				);
	} else {
		measurement_lte_for_mdt_any_of =
			measurement_lte_for_mdt_any_of_create(
				);
	}

	return measurement_lte_for_mdt_any_of;
}


#ifdef measurement_lte_for_mdt_any_of_MAIN

void test_measurement_lte_for_mdt_any_of(int include_optional) {
	measurement_lte_for_mdt_any_of_t *measurement_lte_for_mdt_any_of_1 =
		instantiate_measurement_lte_for_mdt_any_of(include_optional);

	cJSON *jsonmeasurement_lte_for_mdt_any_of_1 =
		measurement_lte_for_mdt_any_of_convertToJSON(
			measurement_lte_for_mdt_any_of_1);
	printf("measurement_lte_for_mdt_any_of :\n%s\n",
	       cJSON_Print(jsonmeasurement_lte_for_mdt_any_of_1));
	measurement_lte_for_mdt_any_of_t *measurement_lte_for_mdt_any_of_2 =
		measurement_lte_for_mdt_any_of_parseFromJSON(
			jsonmeasurement_lte_for_mdt_any_of_1);
	cJSON *jsonmeasurement_lte_for_mdt_any_of_2 =
		measurement_lte_for_mdt_any_of_convertToJSON(
			measurement_lte_for_mdt_any_of_2);
	printf("repeating measurement_lte_for_mdt_any_of:\n%s\n",
	       cJSON_Print(jsonmeasurement_lte_for_mdt_any_of_2));
}

int main() {
	test_measurement_lte_for_mdt_any_of(1);
	test_measurement_lte_for_mdt_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // measurement_lte_for_mdt_any_of_MAIN
#endif // measurement_lte_for_mdt_any_of_TEST
