#ifndef loc_measurement_resp_TEST
#define loc_measurement_resp_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_measurement_resp_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_measurement_resp.h"
loc_measurement_resp_t *instantiate_loc_measurement_resp(int include_optional);

#include "test_loc_measurements.c"
#include "test_geographic_area.c"
#include "test_velocity_estimate.c"
#include "test_local_area.c"


loc_measurement_resp_t *instantiate_loc_measurement_resp(int include_optional) {
	loc_measurement_resp_t *loc_measurement_resp = NULL;
	if(include_optional) {
		loc_measurement_resp = loc_measurement_resp_create(
			// false, not to have infinite recursion
			instantiate_loc_measurements(0),
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			null,
			null
			);
	} else {
		loc_measurement_resp = loc_measurement_resp_create(
			NULL,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			null,
			null
			);
	}

	return loc_measurement_resp;
}


#ifdef loc_measurement_resp_MAIN

void test_loc_measurement_resp(int include_optional) {
	loc_measurement_resp_t *loc_measurement_resp_1 =
		instantiate_loc_measurement_resp(include_optional);

	cJSON *jsonloc_measurement_resp_1 = loc_measurement_resp_convertToJSON(
		loc_measurement_resp_1);
	printf("loc_measurement_resp :\n%s\n",
	       cJSON_Print(jsonloc_measurement_resp_1));
	loc_measurement_resp_t *loc_measurement_resp_2 =
		loc_measurement_resp_parseFromJSON(jsonloc_measurement_resp_1);
	cJSON *jsonloc_measurement_resp_2 = loc_measurement_resp_convertToJSON(
		loc_measurement_resp_2);
	printf("repeating loc_measurement_resp:\n%s\n",
	       cJSON_Print(jsonloc_measurement_resp_2));
}

int main() {
	test_loc_measurement_resp(1);
	test_loc_measurement_resp(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_measurement_resp_MAIN
#endif // loc_measurement_resp_TEST
