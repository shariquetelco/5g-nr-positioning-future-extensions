#ifndef input_ranging_data_TEST
#define input_ranging_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_ranging_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_ranging_data.h"
input_ranging_data_t *instantiate_input_ranging_data(int include_optional);

#include "test_location_qo_s.c"


input_ranging_data_t *instantiate_input_ranging_data(int include_optional) {
	input_ranging_data_t *input_ranging_data = NULL;
	if(include_optional) {
		input_ranging_data = input_ranging_data_create(
			"a",
			"a",
			// false, not to have infinite recursion
			instantiate_location_qo_s(0),
			ngmlc_location_input_ranging_data__EMERGENCY_SERVICES,
			"0",
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		input_ranging_data = input_ranging_data_create(
			"a",
			"a",
			NULL,
			ngmlc_location_input_ranging_data__EMERGENCY_SERVICES,
			"0",
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	}

	return input_ranging_data;
}


#ifdef input_ranging_data_MAIN

void test_input_ranging_data(int include_optional) {
	input_ranging_data_t *input_ranging_data_1 =
		instantiate_input_ranging_data(include_optional);

	cJSON *jsoninput_ranging_data_1 = input_ranging_data_convertToJSON(
		input_ranging_data_1);
	printf("input_ranging_data :\n%s\n",
	       cJSON_Print(jsoninput_ranging_data_1));
	input_ranging_data_t *input_ranging_data_2 =
		input_ranging_data_parseFromJSON(jsoninput_ranging_data_1);
	cJSON *jsoninput_ranging_data_2 = input_ranging_data_convertToJSON(
		input_ranging_data_2);
	printf("repeating input_ranging_data:\n%s\n",
	       cJSON_Print(jsoninput_ranging_data_2));
}

int main() {
	test_input_ranging_data(1);
	test_input_ranging_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // input_ranging_data_MAIN
#endif // input_ranging_data_TEST
