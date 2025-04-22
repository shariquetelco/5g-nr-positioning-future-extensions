#ifndef loc_update_data_TEST
#define loc_update_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_update_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_update_data.h"
loc_update_data_t *instantiate_loc_update_data(int include_optional);

#include "test_geographic_area.c"
#include "test_civic_address.c"


loc_update_data_t *instantiate_loc_update_data(int include_optional) {
	loc_update_data_t *loc_update_data = NULL;
	if(include_optional) {
		loc_update_data = loc_update_data_create(
			"a",
			"a",
			ngmlc_location_loc_update_data__PSEUDONYM_REQUESTED,
			ngmlc_location_loc_update_data__NI_LR,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			ngmlc_location_loc_update_data__REQUESTED_ACCURACY_FULFILLED,
			// false, not to have infinite recursion
			instantiate_civic_address(0),
			ngmlc_location_loc_update_data__BEST_EFFORT,
			"0",
			"0",
			"a",
			0
			);
	} else {
		loc_update_data = loc_update_data_create(
			"a",
			"a",
			ngmlc_location_loc_update_data__PSEUDONYM_REQUESTED,
			ngmlc_location_loc_update_data__NI_LR,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			ngmlc_location_loc_update_data__REQUESTED_ACCURACY_FULFILLED,
			NULL,
			ngmlc_location_loc_update_data__BEST_EFFORT,
			"0",
			"0",
			"a",
			0
			);
	}

	return loc_update_data;
}


#ifdef loc_update_data_MAIN

void test_loc_update_data(int include_optional) {
	loc_update_data_t *loc_update_data_1 = instantiate_loc_update_data(
		include_optional);

	cJSON *jsonloc_update_data_1 = loc_update_data_convertToJSON(
		loc_update_data_1);
	printf("loc_update_data :\n%s\n", cJSON_Print(jsonloc_update_data_1));
	loc_update_data_t *loc_update_data_2 = loc_update_data_parseFromJSON(
		jsonloc_update_data_1);
	cJSON *jsonloc_update_data_2 = loc_update_data_convertToJSON(
		loc_update_data_2);
	printf("repeating loc_update_data:\n%s\n",
	       cJSON_Print(jsonloc_update_data_2));
}

int main() {
	test_loc_update_data(1);
	test_loc_update_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_update_data_MAIN
#endif // loc_update_data_TEST
