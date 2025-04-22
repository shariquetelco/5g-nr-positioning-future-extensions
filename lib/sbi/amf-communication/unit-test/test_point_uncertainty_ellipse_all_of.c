#ifndef point_uncertainty_ellipse_all_of_TEST
#define point_uncertainty_ellipse_all_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define point_uncertainty_ellipse_all_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/point_uncertainty_ellipse_all_of.h"
point_uncertainty_ellipse_all_of_t *instantiate_point_uncertainty_ellipse_all_of(
	int include_optional);

#include "test_geographical_coordinates.c"
#include "test_uncertainty_ellipse.c"


point_uncertainty_ellipse_all_of_t *instantiate_point_uncertainty_ellipse_all_of(
	int include_optional) {
	point_uncertainty_ellipse_all_of_t *point_uncertainty_ellipse_all_of =
		NULL;
	if(include_optional) {
		point_uncertainty_ellipse_all_of =
			point_uncertainty_ellipse_all_of_create(
				// false, not to have infinite recursion
				instantiate_geographical_coordinates(0),
				// false, not to have infinite recursion
				instantiate_uncertainty_ellipse(0),
				0
				);
	} else {
		point_uncertainty_ellipse_all_of =
			point_uncertainty_ellipse_all_of_create(
				NULL,
				NULL,
				0
				);
	}

	return point_uncertainty_ellipse_all_of;
}


#ifdef point_uncertainty_ellipse_all_of_MAIN

void test_point_uncertainty_ellipse_all_of(int include_optional) {
	point_uncertainty_ellipse_all_of_t *point_uncertainty_ellipse_all_of_1 =
		instantiate_point_uncertainty_ellipse_all_of(include_optional);

	cJSON *jsonpoint_uncertainty_ellipse_all_of_1 =
		point_uncertainty_ellipse_all_of_convertToJSON(
			point_uncertainty_ellipse_all_of_1);
	printf("point_uncertainty_ellipse_all_of :\n%s\n",
	       cJSON_Print(jsonpoint_uncertainty_ellipse_all_of_1));
	point_uncertainty_ellipse_all_of_t *point_uncertainty_ellipse_all_of_2 =
		point_uncertainty_ellipse_all_of_parseFromJSON(
			jsonpoint_uncertainty_ellipse_all_of_1);
	cJSON *jsonpoint_uncertainty_ellipse_all_of_2 =
		point_uncertainty_ellipse_all_of_convertToJSON(
			point_uncertainty_ellipse_all_of_2);
	printf("repeating point_uncertainty_ellipse_all_of:\n%s\n",
	       cJSON_Print(jsonpoint_uncertainty_ellipse_all_of_2));
}

int main() {
	test_point_uncertainty_ellipse_all_of(1);
	test_point_uncertainty_ellipse_all_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // point_uncertainty_ellipse_all_of_MAIN
#endif // point_uncertainty_ellipse_all_of_TEST
