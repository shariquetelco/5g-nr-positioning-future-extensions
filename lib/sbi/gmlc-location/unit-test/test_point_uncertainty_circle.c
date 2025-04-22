#ifndef point_uncertainty_circle_TEST
#define point_uncertainty_circle_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define point_uncertainty_circle_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/point_uncertainty_circle.h"
point_uncertainty_circle_t *instantiate_point_uncertainty_circle(
	int include_optional);

#include "test_geographical_coordinates.c"


point_uncertainty_circle_t *instantiate_point_uncertainty_circle(
	int include_optional) {
	point_uncertainty_circle_t *point_uncertainty_circle = NULL;
	if(include_optional) {
		point_uncertainty_circle = point_uncertainty_circle_create(
			ngmlc_location_point_uncertainty_circle__POINT,
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			0
			);
	} else {
		point_uncertainty_circle = point_uncertainty_circle_create(
			ngmlc_location_point_uncertainty_circle__POINT,
			NULL,
			0
			);
	}

	return point_uncertainty_circle;
}


#ifdef point_uncertainty_circle_MAIN

void test_point_uncertainty_circle(int include_optional) {
	point_uncertainty_circle_t *point_uncertainty_circle_1 =
		instantiate_point_uncertainty_circle(include_optional);

	cJSON *jsonpoint_uncertainty_circle_1 =
		point_uncertainty_circle_convertToJSON(
			point_uncertainty_circle_1);
	printf("point_uncertainty_circle :\n%s\n",
	       cJSON_Print(jsonpoint_uncertainty_circle_1));
	point_uncertainty_circle_t *point_uncertainty_circle_2 =
		point_uncertainty_circle_parseFromJSON(
			jsonpoint_uncertainty_circle_1);
	cJSON *jsonpoint_uncertainty_circle_2 =
		point_uncertainty_circle_convertToJSON(
			point_uncertainty_circle_2);
	printf("repeating point_uncertainty_circle:\n%s\n",
	       cJSON_Print(jsonpoint_uncertainty_circle_2));
}

int main() {
	test_point_uncertainty_circle(1);
	test_point_uncertainty_circle(0);

	printf("Hello world \n");
	return 0;
}

#endif // point_uncertainty_circle_MAIN
#endif // point_uncertainty_circle_TEST
