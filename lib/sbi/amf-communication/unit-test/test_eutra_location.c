#ifndef eutra_location_TEST
#define eutra_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eutra_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eutra_location.h"
eutra_location_t *instantiate_eutra_location(int include_optional);

#include "test_tai.c"
#include "test_ecgi.c"
#include "test_global_ran_node_id.c"
#include "test_global_ran_node_id.c"


eutra_location_t *instantiate_eutra_location(int include_optional) {
	eutra_location_t *eutra_location = NULL;
	if(include_optional) {
		eutra_location = eutra_location_create(
			// false, not to have infinite recursion
			instantiate_tai(0),
			1,
			// false, not to have infinite recursion
			instantiate_ecgi(0),
			1,
			0,
			"2013-10-20T19:20:30+01:00",
			"a",
			"a",
			// false, not to have infinite recursion
			instantiate_global_ran_node_id(0),
			// false, not to have infinite recursion
			instantiate_global_ran_node_id(0)
			);
	} else {
		eutra_location = eutra_location_create(
			NULL,
			1,
			NULL,
			1,
			0,
			"2013-10-20T19:20:30+01:00",
			"a",
			"a",
			NULL,
			NULL
			);
	}

	return eutra_location;
}


#ifdef eutra_location_MAIN

void test_eutra_location(int include_optional) {
	eutra_location_t *eutra_location_1 = instantiate_eutra_location(
		include_optional);

	cJSON *jsoneutra_location_1 = eutra_location_convertToJSON(
		eutra_location_1);
	printf("eutra_location :\n%s\n", cJSON_Print(jsoneutra_location_1));
	eutra_location_t *eutra_location_2 = eutra_location_parseFromJSON(
		jsoneutra_location_1);
	cJSON *jsoneutra_location_2 = eutra_location_convertToJSON(
		eutra_location_2);
	printf("repeating eutra_location:\n%s\n",
	       cJSON_Print(jsoneutra_location_2));
}

int main() {
	test_eutra_location(1);
	test_eutra_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // eutra_location_MAIN
#endif // eutra_location_TEST
