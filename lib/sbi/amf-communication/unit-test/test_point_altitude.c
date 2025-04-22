#ifndef point_altitude_TEST
#define point_altitude_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define point_altitude_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/point_altitude.h"
point_altitude_t *instantiate_point_altitude(int include_optional);

#include "test_supported_gad_shapes.c"
#include "test_geographical_coordinates.c"


point_altitude_t *instantiate_point_altitude(int include_optional) {
	point_altitude_t *point_altitude = NULL;
	if(include_optional) {
		point_altitude = point_altitude_create(
			null,
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			-32767
			);
	} else {
		point_altitude = point_altitude_create(
			null,
			NULL,
			-32767
			);
	}

	return point_altitude;
}


#ifdef point_altitude_MAIN

void test_point_altitude(int include_optional) {
	point_altitude_t *point_altitude_1 = instantiate_point_altitude(
		include_optional);

	cJSON *jsonpoint_altitude_1 = point_altitude_convertToJSON(
		point_altitude_1);
	printf("point_altitude :\n%s\n", cJSON_Print(jsonpoint_altitude_1));
	point_altitude_t *point_altitude_2 = point_altitude_parseFromJSON(
		jsonpoint_altitude_1);
	cJSON *jsonpoint_altitude_2 = point_altitude_convertToJSON(
		point_altitude_2);
	printf("repeating point_altitude:\n%s\n",
	       cJSON_Print(jsonpoint_altitude_2));
}

int main() {
	test_point_altitude(1);
	test_point_altitude(0);

	printf("Hello world \n");
	return 0;
}

#endif // point_altitude_MAIN
#endif // point_altitude_TEST
