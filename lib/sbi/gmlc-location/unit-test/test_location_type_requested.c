#ifndef location_type_requested_TEST
#define location_type_requested_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_type_requested_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_type_requested.h"
location_type_requested_t *instantiate_location_type_requested(
	int include_optional);



location_type_requested_t *instantiate_location_type_requested(
	int include_optional) {
	location_type_requested_t *location_type_requested = NULL;
	if(include_optional) {
		location_type_requested = location_type_requested_create(
			);
	} else {
		location_type_requested = location_type_requested_create(
			);
	}

	return location_type_requested;
}


#ifdef location_type_requested_MAIN

void test_location_type_requested(int include_optional) {
	location_type_requested_t *location_type_requested_1 =
		instantiate_location_type_requested(include_optional);

	cJSON *jsonlocation_type_requested_1 =
		location_type_requested_convertToJSON(location_type_requested_1);
	printf("location_type_requested :\n%s\n",
	       cJSON_Print(jsonlocation_type_requested_1));
	location_type_requested_t *location_type_requested_2 =
		location_type_requested_parseFromJSON(
			jsonlocation_type_requested_1);
	cJSON *jsonlocation_type_requested_2 =
		location_type_requested_convertToJSON(location_type_requested_2);
	printf("repeating location_type_requested:\n%s\n",
	       cJSON_Print(jsonlocation_type_requested_2));
}

int main() {
	test_location_type_requested(1);
	test_location_type_requested(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_type_requested_MAIN
#endif // location_type_requested_TEST
