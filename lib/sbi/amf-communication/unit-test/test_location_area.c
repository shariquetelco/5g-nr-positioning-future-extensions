#ifndef location_area_TEST
#define location_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_area.h"
location_area_t *instantiate_location_area(int include_optional);

#include "test_network_area_info_1.c"
#include "test_umt_time.c"


location_area_t *instantiate_location_area(int include_optional) {
	location_area_t *location_area = NULL;
	if(include_optional) {
		location_area = location_area_create(
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_network_area_info_1(0),
			// false, not to have infinite recursion
			instantiate_umt_time(0)
			);
	} else {
		location_area = location_area_create(
			list_createList(),
			list_createList(),
			NULL,
			NULL
			);
	}

	return location_area;
}


#ifdef location_area_MAIN

void test_location_area(int include_optional) {
	location_area_t *location_area_1 = instantiate_location_area(
		include_optional);

	cJSON *jsonlocation_area_1 =
		location_area_convertToJSON(location_area_1);
	printf("location_area :\n%s\n", cJSON_Print(jsonlocation_area_1));
	location_area_t *location_area_2 = location_area_parseFromJSON(
		jsonlocation_area_1);
	cJSON *jsonlocation_area_2 =
		location_area_convertToJSON(location_area_2);
	printf("repeating location_area:\n%s\n", cJSON_Print(
		       jsonlocation_area_2));
}

int main() {
	test_location_area(1);
	test_location_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_area_MAIN
#endif // location_area_TEST
