#ifndef redundant_transmission_exp_per_ts_TEST
#define redundant_transmission_exp_per_ts_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define redundant_transmission_exp_per_ts_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/redundant_transmission_exp_per_ts.h"
redundant_transmission_exp_per_ts_t *
instantiate_redundant_transmission_exp_per_ts(int include_optional);

#include "test_observed_redundant_trans_exp.c"


redundant_transmission_exp_per_ts_t *
instantiate_redundant_transmission_exp_per_ts(int include_optional) {
	redundant_transmission_exp_per_ts_t *redundant_transmission_exp_per_ts =
		NULL;
	if(include_optional) {
		redundant_transmission_exp_per_ts =
			redundant_transmission_exp_per_ts_create(
				"2013-10-20T19:20:30+01:00",
				56,
				// false, not to have infinite recursion
				instantiate_observed_redundant_trans_exp(0),
				1,
				1,
				0
				);
	} else {
		redundant_transmission_exp_per_ts =
			redundant_transmission_exp_per_ts_create(
				"2013-10-20T19:20:30+01:00",
				56,
				NULL,
				1,
				1,
				0
				);
	}

	return redundant_transmission_exp_per_ts;
}


#ifdef redundant_transmission_exp_per_ts_MAIN

void test_redundant_transmission_exp_per_ts(int include_optional) {
	redundant_transmission_exp_per_ts_t *redundant_transmission_exp_per_ts_1
	        = instantiate_redundant_transmission_exp_per_ts(include_optional);

	cJSON *jsonredundant_transmission_exp_per_ts_1 =
		redundant_transmission_exp_per_ts_convertToJSON(
			redundant_transmission_exp_per_ts_1);
	printf("redundant_transmission_exp_per_ts :\n%s\n",
	       cJSON_Print(jsonredundant_transmission_exp_per_ts_1));
	redundant_transmission_exp_per_ts_t *redundant_transmission_exp_per_ts_2
	        = redundant_transmission_exp_per_ts_parseFromJSON(
			  jsonredundant_transmission_exp_per_ts_1);
	cJSON *jsonredundant_transmission_exp_per_ts_2 =
		redundant_transmission_exp_per_ts_convertToJSON(
			redundant_transmission_exp_per_ts_2);
	printf("repeating redundant_transmission_exp_per_ts:\n%s\n", cJSON_Print(
		       jsonredundant_transmission_exp_per_ts_2));
}

int main() {
	test_redundant_transmission_exp_per_ts(1);
	test_redundant_transmission_exp_per_ts(0);

	printf("Hello world \n");
	return 0;
}

#endif // redundant_transmission_exp_per_ts_MAIN
#endif // redundant_transmission_exp_per_ts_TEST
