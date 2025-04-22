#ifndef loc_measurements_TEST
#define loc_measurements_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_measurements_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_measurements.h"
loc_measurements_t *instantiate_loc_measurements(int include_optional);



loc_measurements_t *instantiate_loc_measurements(int include_optional) {
	loc_measurements_t *loc_measurements = NULL;
	if(include_optional) {
		loc_measurements = loc_measurements_create(
			56
			);
	} else {
		loc_measurements = loc_measurements_create(
			56
			);
	}

	return loc_measurements;
}


#ifdef loc_measurements_MAIN

void test_loc_measurements(int include_optional) {
	loc_measurements_t *loc_measurements_1 = instantiate_loc_measurements(
		include_optional);

	cJSON *jsonloc_measurements_1 = loc_measurements_convertToJSON(
		loc_measurements_1);
	printf("loc_measurements :\n%s\n", cJSON_Print(jsonloc_measurements_1));
	loc_measurements_t *loc_measurements_2 = loc_measurements_parseFromJSON(
		jsonloc_measurements_1);
	cJSON *jsonloc_measurements_2 = loc_measurements_convertToJSON(
		loc_measurements_2);
	printf("repeating loc_measurements:\n%s\n",
	       cJSON_Print(jsonloc_measurements_2));
}

int main() {
	test_loc_measurements(1);
	test_loc_measurements(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_measurements_MAIN
#endif // loc_measurements_TEST
