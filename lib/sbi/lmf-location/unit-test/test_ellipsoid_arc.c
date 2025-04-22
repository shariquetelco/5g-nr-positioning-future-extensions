#ifndef ellipsoid_arc_TEST
#define ellipsoid_arc_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ellipsoid_arc_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ellipsoid_arc.h"
ellipsoid_arc_t *instantiate_ellipsoid_arc(int include_optional);

#include "test_geographical_coordinates.c"


ellipsoid_arc_t *instantiate_ellipsoid_arc(int include_optional) {
	ellipsoid_arc_t *ellipsoid_arc = NULL;
	if(include_optional) {
		ellipsoid_arc = ellipsoid_arc_create(
			lmf_location_ellipsoid_arc__POINT,
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			0,
			0,
			0,
			0,
			0
			);
	} else {
		ellipsoid_arc = ellipsoid_arc_create(
			lmf_location_ellipsoid_arc__POINT,
			NULL,
			0,
			0,
			0,
			0,
			0
			);
	}

	return ellipsoid_arc;
}


#ifdef ellipsoid_arc_MAIN

void test_ellipsoid_arc(int include_optional) {
	ellipsoid_arc_t *ellipsoid_arc_1 = instantiate_ellipsoid_arc(
		include_optional);

	cJSON *jsonellipsoid_arc_1 =
		ellipsoid_arc_convertToJSON(ellipsoid_arc_1);
	printf("ellipsoid_arc :\n%s\n", cJSON_Print(jsonellipsoid_arc_1));
	ellipsoid_arc_t *ellipsoid_arc_2 = ellipsoid_arc_parseFromJSON(
		jsonellipsoid_arc_1);
	cJSON *jsonellipsoid_arc_2 =
		ellipsoid_arc_convertToJSON(ellipsoid_arc_2);
	printf("repeating ellipsoid_arc:\n%s\n", cJSON_Print(
		       jsonellipsoid_arc_2));
}

int main() {
	test_ellipsoid_arc(1);
	test_ellipsoid_arc(0);

	printf("Hello world \n");
	return 0;
}

#endif // ellipsoid_arc_MAIN
#endif // ellipsoid_arc_TEST
