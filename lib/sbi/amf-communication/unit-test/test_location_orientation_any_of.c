#ifndef location_orientation_any_of_TEST
#define location_orientation_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_orientation_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_orientation_any_of.h"
location_orientation_any_of_t *instantiate_location_orientation_any_of(
	int include_optional);



location_orientation_any_of_t *instantiate_location_orientation_any_of(
	int include_optional) {
	location_orientation_any_of_t *location_orientation_any_of = NULL;
	if(include_optional) {
		location_orientation_any_of =
			location_orientation_any_of_create(
				);
	} else {
		location_orientation_any_of =
			location_orientation_any_of_create(
				);
	}

	return location_orientation_any_of;
}


#ifdef location_orientation_any_of_MAIN

void test_location_orientation_any_of(int include_optional) {
	location_orientation_any_of_t *location_orientation_any_of_1 =
		instantiate_location_orientation_any_of(include_optional);

	cJSON *jsonlocation_orientation_any_of_1 =
		location_orientation_any_of_convertToJSON(
			location_orientation_any_of_1);
	printf("location_orientation_any_of :\n%s\n",
	       cJSON_Print(jsonlocation_orientation_any_of_1));
	location_orientation_any_of_t *location_orientation_any_of_2 =
		location_orientation_any_of_parseFromJSON(
			jsonlocation_orientation_any_of_1);
	cJSON *jsonlocation_orientation_any_of_2 =
		location_orientation_any_of_convertToJSON(
			location_orientation_any_of_2);
	printf("repeating location_orientation_any_of:\n%s\n",
	       cJSON_Print(jsonlocation_orientation_any_of_2));
}

int main() {
	test_location_orientation_any_of(1);
	test_location_orientation_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_orientation_any_of_MAIN
#endif // location_orientation_any_of_TEST
