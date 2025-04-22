#ifndef point_uncertainty_ellipse_TEST
#define point_uncertainty_ellipse_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define point_uncertainty_ellipse_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/point_uncertainty_ellipse.h"
point_uncertainty_ellipse_t *instantiate_point_uncertainty_ellipse(
	int include_optional);

#include "test_supported_gad_shapes.c"
#include "test_geographical_coordinates.c"
#include "test_uncertainty_ellipse.c"


point_uncertainty_ellipse_t *instantiate_point_uncertainty_ellipse(
	int include_optional) {
	point_uncertainty_ellipse_t *point_uncertainty_ellipse = NULL;
	if(include_optional) {
		point_uncertainty_ellipse = point_uncertainty_ellipse_create(
			null,
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			// false, not to have infinite recursion
			instantiate_uncertainty_ellipse(0),
			0
			);
	} else {
		point_uncertainty_ellipse = point_uncertainty_ellipse_create(
			null,
			NULL,
			NULL,
			0
			);
	}

	return point_uncertainty_ellipse;
}


#ifdef point_uncertainty_ellipse_MAIN

void test_point_uncertainty_ellipse(int include_optional) {
	point_uncertainty_ellipse_t *point_uncertainty_ellipse_1 =
		instantiate_point_uncertainty_ellipse(include_optional);

	cJSON *jsonpoint_uncertainty_ellipse_1 =
		point_uncertainty_ellipse_convertToJSON(
			point_uncertainty_ellipse_1);
	printf("point_uncertainty_ellipse :\n%s\n",
	       cJSON_Print(jsonpoint_uncertainty_ellipse_1));
	point_uncertainty_ellipse_t *point_uncertainty_ellipse_2 =
		point_uncertainty_ellipse_parseFromJSON(
			jsonpoint_uncertainty_ellipse_1);
	cJSON *jsonpoint_uncertainty_ellipse_2 =
		point_uncertainty_ellipse_convertToJSON(
			point_uncertainty_ellipse_2);
	printf("repeating point_uncertainty_ellipse:\n%s\n",
	       cJSON_Print(jsonpoint_uncertainty_ellipse_2));
}

int main() {
	test_point_uncertainty_ellipse(1);
	test_point_uncertainty_ellipse(0);

	printf("Hello world \n");
	return 0;
}

#endif // point_uncertainty_ellipse_MAIN
#endif // point_uncertainty_ellipse_TEST
