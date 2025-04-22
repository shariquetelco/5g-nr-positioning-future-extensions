#ifndef gera_location_TEST
#define gera_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gera_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gera_location.h"
gera_location_t *instantiate_gera_location(int include_optional);

#include "test_cell_global_id.c"
#include "test_service_area_id.c"
#include "test_location_area_id.c"
#include "test_routing_area_id.c"


gera_location_t *instantiate_gera_location(int include_optional) {
	gera_location_t *gera_location = NULL;
	if(include_optional) {
		gera_location = gera_location_create(
			"0",
			// false, not to have infinite recursion
			instantiate_cell_global_id(0),
			// false, not to have infinite recursion
			instantiate_service_area_id(0),
			// false, not to have infinite recursion
			instantiate_location_area_id(0),
			// false, not to have infinite recursion
			instantiate_routing_area_id(0),
			"0",
			"0",
			0,
			"2013-10-20T19:20:30+01:00",
			"a",
			"a"
			);
	} else {
		gera_location = gera_location_create(
			"0",
			NULL,
			NULL,
			NULL,
			NULL,
			"0",
			"0",
			0,
			"2013-10-20T19:20:30+01:00",
			"a",
			"a"
			);
	}

	return gera_location;
}


#ifdef gera_location_MAIN

void test_gera_location(int include_optional) {
	gera_location_t *gera_location_1 = instantiate_gera_location(
		include_optional);

	cJSON *jsongera_location_1 =
		gera_location_convertToJSON(gera_location_1);
	printf("gera_location :\n%s\n", cJSON_Print(jsongera_location_1));
	gera_location_t *gera_location_2 = gera_location_parseFromJSON(
		jsongera_location_1);
	cJSON *jsongera_location_2 =
		gera_location_convertToJSON(gera_location_2);
	printf("repeating gera_location:\n%s\n", cJSON_Print(
		       jsongera_location_2));
}

int main() {
	test_gera_location(1);
	test_gera_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // gera_location_MAIN
#endif // gera_location_TEST
