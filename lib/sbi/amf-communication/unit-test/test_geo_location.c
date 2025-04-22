#ifndef geo_location_TEST
#define geo_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define geo_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/geo_location.h"
geo_location_t *instantiate_geo_location(int include_optional);

#include "test_point.c"
#include "test_point_altitude.c"
#include "test_local_origin.c"
#include "test_relative_cartesian_location.c"


geo_location_t *instantiate_geo_location(int include_optional) {
	geo_location_t *geo_location = NULL;
	if(include_optional) {
		geo_location = geo_location_create(
			null,
			null,
			// false, not to have infinite recursion
			instantiate_local_origin(0),
			// false, not to have infinite recursion
			instantiate_relative_cartesian_location(0)
			);
	} else {
		geo_location = geo_location_create(
			null,
			null,
			NULL,
			NULL
			);
	}

	return geo_location;
}


#ifdef geo_location_MAIN

void test_geo_location(int include_optional) {
	geo_location_t *geo_location_1 = instantiate_geo_location(
		include_optional);

	cJSON *jsongeo_location_1 = geo_location_convertToJSON(geo_location_1);
	printf("geo_location :\n%s\n", cJSON_Print(jsongeo_location_1));
	geo_location_t *geo_location_2 = geo_location_parseFromJSON(
		jsongeo_location_1);
	cJSON *jsongeo_location_2 = geo_location_convertToJSON(geo_location_2);
	printf("repeating geo_location:\n%s\n",
	       cJSON_Print(jsongeo_location_2));
}

int main() {
	test_geo_location(1);
	test_geo_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // geo_location_MAIN
#endif // geo_location_TEST
