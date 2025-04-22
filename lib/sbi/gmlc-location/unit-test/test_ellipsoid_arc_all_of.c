#ifndef ellipsoid_arc_all_of_TEST
#define ellipsoid_arc_all_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ellipsoid_arc_all_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ellipsoid_arc_all_of.h"
ellipsoid_arc_all_of_t *instantiate_ellipsoid_arc_all_of(int include_optional);

#include "test_geographical_coordinates.c"


ellipsoid_arc_all_of_t *instantiate_ellipsoid_arc_all_of(int include_optional) {
	ellipsoid_arc_all_of_t *ellipsoid_arc_all_of = NULL;
	if(include_optional) {
		ellipsoid_arc_all_of = ellipsoid_arc_all_of_create(
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			0,
			0,
			0,
			0,
			0
			);
	} else {
		ellipsoid_arc_all_of = ellipsoid_arc_all_of_create(
			NULL,
			0,
			0,
			0,
			0,
			0
			);
	}

	return ellipsoid_arc_all_of;
}


#ifdef ellipsoid_arc_all_of_MAIN

void test_ellipsoid_arc_all_of(int include_optional) {
	ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_1 =
		instantiate_ellipsoid_arc_all_of(include_optional);

	cJSON *jsonellipsoid_arc_all_of_1 = ellipsoid_arc_all_of_convertToJSON(
		ellipsoid_arc_all_of_1);
	printf("ellipsoid_arc_all_of :\n%s\n",
	       cJSON_Print(jsonellipsoid_arc_all_of_1));
	ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_2 =
		ellipsoid_arc_all_of_parseFromJSON(jsonellipsoid_arc_all_of_1);
	cJSON *jsonellipsoid_arc_all_of_2 = ellipsoid_arc_all_of_convertToJSON(
		ellipsoid_arc_all_of_2);
	printf("repeating ellipsoid_arc_all_of:\n%s\n",
	       cJSON_Print(jsonellipsoid_arc_all_of_2));
}

int main() {
	test_ellipsoid_arc_all_of(1);
	test_ellipsoid_arc_all_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // ellipsoid_arc_all_of_MAIN
#endif // ellipsoid_arc_all_of_TEST
