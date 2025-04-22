#ifndef red_trans_exp_ordering_criterion_TEST
#define red_trans_exp_ordering_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define red_trans_exp_ordering_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/red_trans_exp_ordering_criterion.h"
red_trans_exp_ordering_criterion_t *instantiate_red_trans_exp_ordering_criterion(
	int include_optional);



red_trans_exp_ordering_criterion_t *instantiate_red_trans_exp_ordering_criterion(
	int include_optional) {
	red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion =
		NULL;
	if(include_optional) {
		red_trans_exp_ordering_criterion =
			red_trans_exp_ordering_criterion_create(
				);
	} else {
		red_trans_exp_ordering_criterion =
			red_trans_exp_ordering_criterion_create(
				);
	}

	return red_trans_exp_ordering_criterion;
}


#ifdef red_trans_exp_ordering_criterion_MAIN

void test_red_trans_exp_ordering_criterion(int include_optional) {
	red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion_1 =
		instantiate_red_trans_exp_ordering_criterion(include_optional);

	cJSON *jsonred_trans_exp_ordering_criterion_1 =
		red_trans_exp_ordering_criterion_convertToJSON(
			red_trans_exp_ordering_criterion_1);
	printf("red_trans_exp_ordering_criterion :\n%s\n",
	       cJSON_Print(jsonred_trans_exp_ordering_criterion_1));
	red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion_2 =
		red_trans_exp_ordering_criterion_parseFromJSON(
			jsonred_trans_exp_ordering_criterion_1);
	cJSON *jsonred_trans_exp_ordering_criterion_2 =
		red_trans_exp_ordering_criterion_convertToJSON(
			red_trans_exp_ordering_criterion_2);
	printf("repeating red_trans_exp_ordering_criterion:\n%s\n",
	       cJSON_Print(jsonred_trans_exp_ordering_criterion_2));
}

int main() {
	test_red_trans_exp_ordering_criterion(1);
	test_red_trans_exp_ordering_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // red_trans_exp_ordering_criterion_MAIN
#endif // red_trans_exp_ordering_criterion_TEST
