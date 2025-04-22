#ifndef utra_location_TEST
#define utra_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define utra_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/utra_location.h"
utra_location_t *instantiate_utra_location(int include_optional);

#include "test_cell_global_id.c"
#include "test_service_area_id.c"
#include "test_location_area_id.c"
#include "test_routing_area_id.c"


utra_location_t *instantiate_utra_location(int include_optional) {
	utra_location_t *utra_location = NULL;
	if(include_optional) {
		utra_location = utra_location_create(
			// false, not to have infinite recursion
			instantiate_cell_global_id(0),
			// false, not to have infinite recursion
			instantiate_service_area_id(0),
			// false, not to have infinite recursion
			instantiate_location_area_id(0),
			// false, not to have infinite recursion
			instantiate_routing_area_id(0),
			0,
			"2013-10-20T19:20:30+01:00",
			"a",
			"a"
			);
	} else {
		utra_location = utra_location_create(
			NULL,
			NULL,
			NULL,
			NULL,
			0,
			"2013-10-20T19:20:30+01:00",
			"a",
			"a"
			);
	}

	return utra_location;
}


#ifdef utra_location_MAIN

void test_utra_location(int include_optional) {
	utra_location_t *utra_location_1 = instantiate_utra_location(
		include_optional);

	cJSON *jsonutra_location_1 =
		utra_location_convertToJSON(utra_location_1);
	printf("utra_location :\n%s\n", cJSON_Print(jsonutra_location_1));
	utra_location_t *utra_location_2 = utra_location_parseFromJSON(
		jsonutra_location_1);
	cJSON *jsonutra_location_2 =
		utra_location_convertToJSON(utra_location_2);
	printf("repeating utra_location:\n%s\n", cJSON_Print(
		       jsonutra_location_2));
}

int main() {
	test_utra_location(1);
	test_utra_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // utra_location_MAIN
#endif // utra_location_TEST
