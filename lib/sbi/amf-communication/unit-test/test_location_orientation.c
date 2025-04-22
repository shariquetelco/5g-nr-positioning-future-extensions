#ifndef location_orientation_TEST
#define location_orientation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_orientation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_orientation.h"
location_orientation_t *instantiate_location_orientation(int include_optional);



location_orientation_t *instantiate_location_orientation(int include_optional) {
	location_orientation_t *location_orientation = NULL;
	if(include_optional) {
		location_orientation = location_orientation_create(
			);
	} else {
		location_orientation = location_orientation_create(
			);
	}

	return location_orientation;
}


#ifdef location_orientation_MAIN

void test_location_orientation(int include_optional) {
	location_orientation_t *location_orientation_1 =
		instantiate_location_orientation(include_optional);

	cJSON *jsonlocation_orientation_1 = location_orientation_convertToJSON(
		location_orientation_1);
	printf("location_orientation :\n%s\n",
	       cJSON_Print(jsonlocation_orientation_1));
	location_orientation_t *location_orientation_2 =
		location_orientation_parseFromJSON(jsonlocation_orientation_1);
	cJSON *jsonlocation_orientation_2 = location_orientation_convertToJSON(
		location_orientation_2);
	printf("repeating location_orientation:\n%s\n",
	       cJSON_Print(jsonlocation_orientation_2));
}

int main() {
	test_location_orientation(1);
	test_location_orientation(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_orientation_MAIN
#endif // location_orientation_TEST
