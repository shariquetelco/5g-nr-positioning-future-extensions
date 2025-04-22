#ifndef local_area_TEST
#define local_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define local_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/local_area.h"
local_area_t *instantiate_local_area(int include_optional);

#include "test_local_origin.c"
#include "test_relative_cartesian_location.c"
#include "test_uncertainty_ellipse.c"
#include "test_uncertainty_ellipsoid.c"


local_area_t *instantiate_local_area(int include_optional) {
	local_area_t *local_area = NULL;
	if(include_optional) {
		local_area = local_area_create(
			ngmlc_location_local_area__POINT,
			// false, not to have infinite recursion
			instantiate_local_origin(0),
			// false, not to have infinite recursion
			instantiate_relative_cartesian_location(0),
			// false, not to have infinite recursion
			instantiate_uncertainty_ellipse(0),
			0,
			// false, not to have infinite recursion
			instantiate_uncertainty_ellipsoid(0)
			);
	} else {
		local_area = local_area_create(
			ngmlc_location_local_area__POINT,
			NULL,
			NULL,
			NULL,
			0,
			NULL
			);
	}

	return local_area;
}


#ifdef local_area_MAIN

void test_local_area(int include_optional) {
	local_area_t *local_area_1 = instantiate_local_area(include_optional);

	cJSON *jsonlocal_area_1 = local_area_convertToJSON(local_area_1);
	printf("local_area :\n%s\n", cJSON_Print(jsonlocal_area_1));
	local_area_t *local_area_2 = local_area_parseFromJSON(jsonlocal_area_1);
	cJSON *jsonlocal_area_2 = local_area_convertToJSON(local_area_2);
	printf("repeating local_area:\n%s\n", cJSON_Print(jsonlocal_area_2));
}

int main() {
	test_local_area(1);
	test_local_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // local_area_MAIN
#endif // local_area_TEST
