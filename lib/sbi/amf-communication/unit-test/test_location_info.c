#ifndef location_info_TEST
#define location_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_info.h"
location_info_t *instantiate_location_info(int include_optional);

#include "test_user_location.c"
#include "test_geographical_area.c"


location_info_t *instantiate_location_info(int include_optional) {
	location_info_t *location_info = NULL;
	if(include_optional) {
		location_info = location_info_create(
			// false, not to have infinite recursion
			instantiate_user_location(0),
			// false, not to have infinite recursion
			instantiate_geographical_area(0),
			1,
			0,
			list_createList(),
			0
			);
	} else {
		location_info = location_info_create(
			NULL,
			NULL,
			1,
			0,
			list_createList(),
			0
			);
	}

	return location_info;
}


#ifdef location_info_MAIN

void test_location_info(int include_optional) {
	location_info_t *location_info_1 = instantiate_location_info(
		include_optional);

	cJSON *jsonlocation_info_1 =
		location_info_convertToJSON(location_info_1);
	printf("location_info :\n%s\n", cJSON_Print(jsonlocation_info_1));
	location_info_t *location_info_2 = location_info_parseFromJSON(
		jsonlocation_info_1);
	cJSON *jsonlocation_info_2 =
		location_info_convertToJSON(location_info_2);
	printf("repeating location_info:\n%s\n", cJSON_Print(
		       jsonlocation_info_2));
}

int main() {
	test_location_info(1);
	test_location_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_info_MAIN
#endif // location_info_TEST
