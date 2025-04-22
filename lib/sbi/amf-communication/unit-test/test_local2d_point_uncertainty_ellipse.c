#ifndef local2d_point_uncertainty_ellipse_TEST
#define local2d_point_uncertainty_ellipse_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define local2d_point_uncertainty_ellipse_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/local2d_point_uncertainty_ellipse.h"
local2d_point_uncertainty_ellipse_t *
instantiate_local2d_point_uncertainty_ellipse(int include_optional);

#include "test_supported_gad_shapes.c"
#include "test_local_origin.c"
#include "test_relative_cartesian_location.c"
#include "test_uncertainty_ellipse.c"


local2d_point_uncertainty_ellipse_t *
instantiate_local2d_point_uncertainty_ellipse(int include_optional) {
	local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse =
		NULL;
	if(include_optional) {
		local2d_point_uncertainty_ellipse =
			local2d_point_uncertainty_ellipse_create(
				null,
				// false, not to have infinite recursion
				instantiate_local_origin(0),
				// false, not to have infinite recursion
				instantiate_relative_cartesian_location(0),
				// false, not to have infinite recursion
				instantiate_uncertainty_ellipse(0),
				0
				);
	} else {
		local2d_point_uncertainty_ellipse =
			local2d_point_uncertainty_ellipse_create(
				null,
				NULL,
				NULL,
				NULL,
				0
				);
	}

	return local2d_point_uncertainty_ellipse;
}


#ifdef local2d_point_uncertainty_ellipse_MAIN

void test_local2d_point_uncertainty_ellipse(int include_optional) {
	local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_1
	        = instantiate_local2d_point_uncertainty_ellipse(include_optional);

	cJSON *jsonlocal2d_point_uncertainty_ellipse_1 =
		local2d_point_uncertainty_ellipse_convertToJSON(
			local2d_point_uncertainty_ellipse_1);
	printf("local2d_point_uncertainty_ellipse :\n%s\n",
	       cJSON_Print(jsonlocal2d_point_uncertainty_ellipse_1));
	local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_2
	        = local2d_point_uncertainty_ellipse_parseFromJSON(
			  jsonlocal2d_point_uncertainty_ellipse_1);
	cJSON *jsonlocal2d_point_uncertainty_ellipse_2 =
		local2d_point_uncertainty_ellipse_convertToJSON(
			local2d_point_uncertainty_ellipse_2);
	printf("repeating local2d_point_uncertainty_ellipse:\n%s\n", cJSON_Print(
		       jsonlocal2d_point_uncertainty_ellipse_2));
}

int main() {
	test_local2d_point_uncertainty_ellipse(1);
	test_local2d_point_uncertainty_ellipse(0);

	printf("Hello world \n");
	return 0;
}

#endif // local2d_point_uncertainty_ellipse_MAIN
#endif // local2d_point_uncertainty_ellipse_TEST
