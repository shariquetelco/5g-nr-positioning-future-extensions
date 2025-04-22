#ifndef ranging_data_TEST
#define ranging_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ranging_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ranging_data.h"
ranging_data_t *instantiate_ranging_data(int include_optional);

#include "test_minor_location_qo_s.c"
#include "test_range_direction.c"
#include "test_model_2_d_relative_location.c"
#include "test_model_3_d_relative_location.c"
#include "test_velocity_estimate.c"


ranging_data_t *instantiate_ranging_data(int include_optional) {
	ranging_data_t *ranging_data = NULL;
	if(include_optional) {
		ranging_data = ranging_data_create(
			"a",
			"a",
			"2013-10-20T19:20:30+01:00",
			// false, not to have infinite recursion
			instantiate_minor_location_qo_s(0),
			list_createList(),
			"0",
			// false, not to have infinite recursion
			instantiate_range_direction(0),
			// false, not to have infinite recursion
			instantiate_model_2_d_relative_location(0),
			// false, not to have infinite recursion
			instantiate_model_3_d_relative_location(0),
			null
			);
	} else {
		ranging_data = ranging_data_create(
			"a",
			"a",
			"2013-10-20T19:20:30+01:00",
			NULL,
			list_createList(),
			"0",
			NULL,
			NULL,
			NULL,
			null
			);
	}

	return ranging_data;
}


#ifdef ranging_data_MAIN

void test_ranging_data(int include_optional) {
	ranging_data_t *ranging_data_1 = instantiate_ranging_data(
		include_optional);

	cJSON *jsonranging_data_1 = ranging_data_convertToJSON(ranging_data_1);
	printf("ranging_data :\n%s\n", cJSON_Print(jsonranging_data_1));
	ranging_data_t *ranging_data_2 = ranging_data_parseFromJSON(
		jsonranging_data_1);
	cJSON *jsonranging_data_2 = ranging_data_convertToJSON(ranging_data_2);
	printf("repeating ranging_data:\n%s\n",
	       cJSON_Print(jsonranging_data_2));
}

int main() {
	test_ranging_data(1);
	test_ranging_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // ranging_data_MAIN
#endif // ranging_data_TEST
