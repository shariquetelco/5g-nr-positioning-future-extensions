#ifndef additional_measurement_TEST
#define additional_measurement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define additional_measurement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/additional_measurement.h"
additional_measurement_t *instantiate_additional_measurement(
	int include_optional);

#include "test_network_area_info.c"
#include "test_address_list.c"
#include "test_address_list.c"


additional_measurement_t *instantiate_additional_measurement(
	int include_optional) {
	additional_measurement_t *additional_measurement = NULL;
	if(include_optional) {
		additional_measurement = additional_measurement_create(
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_address_list(0),
			// false, not to have infinite recursion
			instantiate_address_list(0),
			list_createList()
			);
	} else {
		additional_measurement = additional_measurement_create(
			NULL,
			list_createList(),
			list_createList(),
			NULL,
			NULL,
			list_createList()
			);
	}

	return additional_measurement;
}


#ifdef additional_measurement_MAIN

void test_additional_measurement(int include_optional) {
	additional_measurement_t *additional_measurement_1 =
		instantiate_additional_measurement(include_optional);

	cJSON *jsonadditional_measurement_1 =
		additional_measurement_convertToJSON(additional_measurement_1);
	printf("additional_measurement :\n%s\n",
	       cJSON_Print(jsonadditional_measurement_1));
	additional_measurement_t *additional_measurement_2 =
		additional_measurement_parseFromJSON(
			jsonadditional_measurement_1);
	cJSON *jsonadditional_measurement_2 =
		additional_measurement_convertToJSON(additional_measurement_2);
	printf("repeating additional_measurement:\n%s\n",
	       cJSON_Print(jsonadditional_measurement_2));
}

int main() {
	test_additional_measurement(1);
	test_additional_measurement(0);

	printf("Hello world \n");
	return 0;
}

#endif // additional_measurement_MAIN
#endif // additional_measurement_TEST
