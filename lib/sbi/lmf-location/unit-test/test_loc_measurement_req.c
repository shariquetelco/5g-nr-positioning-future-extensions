#ifndef loc_measurement_req_TEST
#define loc_measurement_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_measurement_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_measurement_req.h"
loc_measurement_req_t *instantiate_loc_measurement_req(int include_optional);

#include "test_ncgi.c"
#include "test_ecgi.c"
#include "test_geographic_area.c"


loc_measurement_req_t *instantiate_loc_measurement_req(int include_optional) {
	loc_measurement_req_t *loc_measurement_req = NULL;
	if(include_optional) {
		loc_measurement_req = loc_measurement_req_create(
			// false, not to have infinite recursion
			instantiate_ncgi(0),
			// false, not to have infinite recursion
			instantiate_ecgi(0),
			null,
			"2013-10-20T19:20:30+01:00",
			list_createList()
			);
	} else {
		loc_measurement_req = loc_measurement_req_create(
			NULL,
			NULL,
			null,
			"2013-10-20T19:20:30+01:00",
			list_createList()
			);
	}

	return loc_measurement_req;
}


#ifdef loc_measurement_req_MAIN

void test_loc_measurement_req(int include_optional) {
	loc_measurement_req_t *loc_measurement_req_1 =
		instantiate_loc_measurement_req(include_optional);

	cJSON *jsonloc_measurement_req_1 = loc_measurement_req_convertToJSON(
		loc_measurement_req_1);
	printf("loc_measurement_req :\n%s\n",
	       cJSON_Print(jsonloc_measurement_req_1));
	loc_measurement_req_t *loc_measurement_req_2 =
		loc_measurement_req_parseFromJSON(jsonloc_measurement_req_1);
	cJSON *jsonloc_measurement_req_2 = loc_measurement_req_convertToJSON(
		loc_measurement_req_2);
	printf("repeating loc_measurement_req:\n%s\n",
	       cJSON_Print(jsonloc_measurement_req_2));
}

int main() {
	test_loc_measurement_req(1);
	test_loc_measurement_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_measurement_req_MAIN
#endif // loc_measurement_req_TEST
