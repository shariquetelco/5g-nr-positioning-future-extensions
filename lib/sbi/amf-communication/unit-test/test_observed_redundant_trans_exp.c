#ifndef observed_redundant_trans_exp_TEST
#define observed_redundant_trans_exp_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define observed_redundant_trans_exp_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/observed_redundant_trans_exp.h"
observed_redundant_trans_exp_t *instantiate_observed_redundant_trans_exp(
	int include_optional);



observed_redundant_trans_exp_t *instantiate_observed_redundant_trans_exp(
	int include_optional) {
	observed_redundant_trans_exp_t *observed_redundant_trans_exp = NULL;
	if(include_optional) {
		observed_redundant_trans_exp =
			observed_redundant_trans_exp_create(
				0,
				1.337,
				0,
				1.337,
				1,
				1.337,
				1,
				1.337,
				1,
				1.337,
				1,
				1.337,
				0,
				1.337,
				0,
				1.337
				);
	} else {
		observed_redundant_trans_exp =
			observed_redundant_trans_exp_create(
				0,
				1.337,
				0,
				1.337,
				1,
				1.337,
				1,
				1.337,
				1,
				1.337,
				1,
				1.337,
				0,
				1.337,
				0,
				1.337
				);
	}

	return observed_redundant_trans_exp;
}


#ifdef observed_redundant_trans_exp_MAIN

void test_observed_redundant_trans_exp(int include_optional) {
	observed_redundant_trans_exp_t *observed_redundant_trans_exp_1 =
		instantiate_observed_redundant_trans_exp(include_optional);

	cJSON *jsonobserved_redundant_trans_exp_1 =
		observed_redundant_trans_exp_convertToJSON(
			observed_redundant_trans_exp_1);
	printf("observed_redundant_trans_exp :\n%s\n",
	       cJSON_Print(jsonobserved_redundant_trans_exp_1));
	observed_redundant_trans_exp_t *observed_redundant_trans_exp_2 =
		observed_redundant_trans_exp_parseFromJSON(
			jsonobserved_redundant_trans_exp_1);
	cJSON *jsonobserved_redundant_trans_exp_2 =
		observed_redundant_trans_exp_convertToJSON(
			observed_redundant_trans_exp_2);
	printf("repeating observed_redundant_trans_exp:\n%s\n",
	       cJSON_Print(jsonobserved_redundant_trans_exp_2));
}

int main() {
	test_observed_redundant_trans_exp(1);
	test_observed_redundant_trans_exp(0);

	printf("Hello world \n");
	return 0;
}

#endif // observed_redundant_trans_exp_MAIN
#endif // observed_redundant_trans_exp_TEST
