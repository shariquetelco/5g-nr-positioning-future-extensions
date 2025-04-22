#ifndef point_altitude_uncertainty_TEST
#define point_altitude_uncertainty_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define point_altitude_uncertainty_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/point_altitude_uncertainty.h"
point_altitude_uncertainty_t *instantiate_point_altitude_uncertainty(
	int include_optional);

#include "test_geographical_coordinates.c"
#include "test_uncertainty_ellipse.c"


point_altitude_uncertainty_t *instantiate_point_altitude_uncertainty(
	int include_optional) {
	point_altitude_uncertainty_t *point_altitude_uncertainty = NULL;
	if(include_optional) {
		point_altitude_uncertainty = point_altitude_uncertainty_create(
			ngmlc_location_point_altitude_uncertainty__POINT,
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			-32767,
			// false, not to have infinite recursion
			instantiate_uncertainty_ellipse(0),
			0,
			0,
			0
			);
	} else {
		point_altitude_uncertainty = point_altitude_uncertainty_create(
			ngmlc_location_point_altitude_uncertainty__POINT,
			NULL,
			-32767,
			NULL,
			0,
			0,
			0
			);
	}

	return point_altitude_uncertainty;
}


#ifdef point_altitude_uncertainty_MAIN

void test_point_altitude_uncertainty(int include_optional) {
	point_altitude_uncertainty_t *point_altitude_uncertainty_1 =
		instantiate_point_altitude_uncertainty(include_optional);

	cJSON *jsonpoint_altitude_uncertainty_1 =
		point_altitude_uncertainty_convertToJSON(
			point_altitude_uncertainty_1);
	printf("point_altitude_uncertainty :\n%s\n",
	       cJSON_Print(jsonpoint_altitude_uncertainty_1));
	point_altitude_uncertainty_t *point_altitude_uncertainty_2 =
		point_altitude_uncertainty_parseFromJSON(
			jsonpoint_altitude_uncertainty_1);
	cJSON *jsonpoint_altitude_uncertainty_2 =
		point_altitude_uncertainty_convertToJSON(
			point_altitude_uncertainty_2);
	printf("repeating point_altitude_uncertainty:\n%s\n",
	       cJSON_Print(jsonpoint_altitude_uncertainty_2));
}

int main() {
	test_point_altitude_uncertainty(1);
	test_point_altitude_uncertainty(0);

	printf("Hello world \n");
	return 0;
}

#endif // point_altitude_uncertainty_MAIN
#endif // point_altitude_uncertainty_TEST
