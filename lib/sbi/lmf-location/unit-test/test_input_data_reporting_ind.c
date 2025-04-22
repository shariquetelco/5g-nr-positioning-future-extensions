#ifndef input_data_reporting_ind_TEST
#define input_data_reporting_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_data_reporting_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_data_reporting_ind.h"
input_data_reporting_ind_t *instantiate_input_data_reporting_ind(
	int include_optional);



input_data_reporting_ind_t *instantiate_input_data_reporting_ind(
	int include_optional) {
	input_data_reporting_ind_t *input_data_reporting_ind = NULL;
	if(include_optional) {
		input_data_reporting_ind = input_data_reporting_ind_create(
			);
	} else {
		input_data_reporting_ind = input_data_reporting_ind_create(
			);
	}

	return input_data_reporting_ind;
}


#ifdef input_data_reporting_ind_MAIN

void test_input_data_reporting_ind(int include_optional) {
	input_data_reporting_ind_t *input_data_reporting_ind_1 =
		instantiate_input_data_reporting_ind(include_optional);

	cJSON *jsoninput_data_reporting_ind_1 =
		input_data_reporting_ind_convertToJSON(
			input_data_reporting_ind_1);
	printf("input_data_reporting_ind :\n%s\n",
	       cJSON_Print(jsoninput_data_reporting_ind_1));
	input_data_reporting_ind_t *input_data_reporting_ind_2 =
		input_data_reporting_ind_parseFromJSON(
			jsoninput_data_reporting_ind_1);
	cJSON *jsoninput_data_reporting_ind_2 =
		input_data_reporting_ind_convertToJSON(
			input_data_reporting_ind_2);
	printf("repeating input_data_reporting_ind:\n%s\n",
	       cJSON_Print(jsoninput_data_reporting_ind_2));
}

int main() {
	test_input_data_reporting_ind(1);
	test_input_data_reporting_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // input_data_reporting_ind_MAIN
#endif // input_data_reporting_ind_TEST
