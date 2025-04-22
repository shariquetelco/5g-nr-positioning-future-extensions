#ifndef local3d_point_uncertainty_ellipsoid_TEST
#define local3d_point_uncertainty_ellipsoid_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define local3d_point_uncertainty_ellipsoid_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/local3d_point_uncertainty_ellipsoid.h"
local3d_point_uncertainty_ellipsoid_t *
instantiate_local3d_point_uncertainty_ellipsoid(int include_optional);

#include "test_supported_gad_shapes.c"
#include "test_local_origin.c"
#include "test_relative_cartesian_location.c"
#include "test_uncertainty_ellipsoid.c"


local3d_point_uncertainty_ellipsoid_t *
instantiate_local3d_point_uncertainty_ellipsoid(int include_optional) {
	local3d_point_uncertainty_ellipsoid_t *
	        local3d_point_uncertainty_ellipsoid = NULL;
	if(include_optional) {
		local3d_point_uncertainty_ellipsoid =
			local3d_point_uncertainty_ellipsoid_create(
				null,
				// false, not to have infinite recursion
				instantiate_local_origin(0),
				// false, not to have infinite recursion
				instantiate_relative_cartesian_location(0),
				// false, not to have infinite recursion
				instantiate_uncertainty_ellipsoid(0),
				0
				);
	} else {
		local3d_point_uncertainty_ellipsoid =
			local3d_point_uncertainty_ellipsoid_create(
				null,
				NULL,
				NULL,
				NULL,
				0
				);
	}

	return local3d_point_uncertainty_ellipsoid;
}


#ifdef local3d_point_uncertainty_ellipsoid_MAIN

void test_local3d_point_uncertainty_ellipsoid(int include_optional) {
	local3d_point_uncertainty_ellipsoid_t *
	        local3d_point_uncertainty_ellipsoid_1 =
		instantiate_local3d_point_uncertainty_ellipsoid(include_optional);

	cJSON *jsonlocal3d_point_uncertainty_ellipsoid_1 =
		local3d_point_uncertainty_ellipsoid_convertToJSON(
			local3d_point_uncertainty_ellipsoid_1);
	printf("local3d_point_uncertainty_ellipsoid :\n%s\n",
	       cJSON_Print(jsonlocal3d_point_uncertainty_ellipsoid_1));
	local3d_point_uncertainty_ellipsoid_t *
	        local3d_point_uncertainty_ellipsoid_2 =
		local3d_point_uncertainty_ellipsoid_parseFromJSON(
			jsonlocal3d_point_uncertainty_ellipsoid_1);
	cJSON *jsonlocal3d_point_uncertainty_ellipsoid_2 =
		local3d_point_uncertainty_ellipsoid_convertToJSON(
			local3d_point_uncertainty_ellipsoid_2);
	printf("repeating local3d_point_uncertainty_ellipsoid:\n%s\n", cJSON_Print(
		       jsonlocal3d_point_uncertainty_ellipsoid_2));
}

int main() {
	test_local3d_point_uncertainty_ellipsoid(1);
	test_local3d_point_uncertainty_ellipsoid(0);

	printf("Hello world \n");
	return 0;
}

#endif // local3d_point_uncertainty_ellipsoid_MAIN
#endif // local3d_point_uncertainty_ellipsoid_TEST
