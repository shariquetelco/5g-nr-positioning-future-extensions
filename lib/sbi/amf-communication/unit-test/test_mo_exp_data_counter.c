#ifndef mo_exp_data_counter_TEST
#define mo_exp_data_counter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mo_exp_data_counter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mo_exp_data_counter.h"
mo_exp_data_counter_t *instantiate_mo_exp_data_counter(int include_optional);



mo_exp_data_counter_t *instantiate_mo_exp_data_counter(int include_optional) {
	mo_exp_data_counter_t *mo_exp_data_counter = NULL;
	if(include_optional) {
		mo_exp_data_counter = mo_exp_data_counter_create(
			56,
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		mo_exp_data_counter = mo_exp_data_counter_create(
			56,
			"2013-10-20T19:20:30+01:00"
			);
	}

	return mo_exp_data_counter;
}


#ifdef mo_exp_data_counter_MAIN

void test_mo_exp_data_counter(int include_optional) {
	mo_exp_data_counter_t *mo_exp_data_counter_1 =
		instantiate_mo_exp_data_counter(include_optional);

	cJSON *jsonmo_exp_data_counter_1 = mo_exp_data_counter_convertToJSON(
		mo_exp_data_counter_1);
	printf("mo_exp_data_counter :\n%s\n",
	       cJSON_Print(jsonmo_exp_data_counter_1));
	mo_exp_data_counter_t *mo_exp_data_counter_2 =
		mo_exp_data_counter_parseFromJSON(jsonmo_exp_data_counter_1);
	cJSON *jsonmo_exp_data_counter_2 = mo_exp_data_counter_convertToJSON(
		mo_exp_data_counter_2);
	printf("repeating mo_exp_data_counter:\n%s\n",
	       cJSON_Print(jsonmo_exp_data_counter_2));
}

int main() {
	test_mo_exp_data_counter(1);
	test_mo_exp_data_counter(0);

	printf("Hello world \n");
	return 0;
}

#endif // mo_exp_data_counter_MAIN
#endif // mo_exp_data_counter_TEST
