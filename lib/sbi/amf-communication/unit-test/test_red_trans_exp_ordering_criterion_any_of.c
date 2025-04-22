#ifndef red_trans_exp_ordering_criterion_any_of_TEST
#define red_trans_exp_ordering_criterion_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define red_trans_exp_ordering_criterion_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/red_trans_exp_ordering_criterion_any_of.h"
red_trans_exp_ordering_criterion_any_of_t *
instantiate_red_trans_exp_ordering_criterion_any_of(int include_optional);



red_trans_exp_ordering_criterion_any_of_t *
instantiate_red_trans_exp_ordering_criterion_any_of(int include_optional) {
	red_trans_exp_ordering_criterion_any_of_t *
	        red_trans_exp_ordering_criterion_any_of = NULL;
	if(include_optional) {
		red_trans_exp_ordering_criterion_any_of =
			red_trans_exp_ordering_criterion_any_of_create(
				);
	} else {
		red_trans_exp_ordering_criterion_any_of =
			red_trans_exp_ordering_criterion_any_of_create(
				);
	}

	return red_trans_exp_ordering_criterion_any_of;
}


#ifdef red_trans_exp_ordering_criterion_any_of_MAIN

void test_red_trans_exp_ordering_criterion_any_of(int include_optional) {
	red_trans_exp_ordering_criterion_any_of_t *
	        red_trans_exp_ordering_criterion_any_of_1 =
		instantiate_red_trans_exp_ordering_criterion_any_of(
			include_optional);

	cJSON *jsonred_trans_exp_ordering_criterion_any_of_1 =
		red_trans_exp_ordering_criterion_any_of_convertToJSON(
			red_trans_exp_ordering_criterion_any_of_1);
	printf("red_trans_exp_ordering_criterion_any_of :\n%s\n",
	       cJSON_Print(jsonred_trans_exp_ordering_criterion_any_of_1));
	red_trans_exp_ordering_criterion_any_of_t *
	        red_trans_exp_ordering_criterion_any_of_2 =
		red_trans_exp_ordering_criterion_any_of_parseFromJSON(
			jsonred_trans_exp_ordering_criterion_any_of_1);
	cJSON *jsonred_trans_exp_ordering_criterion_any_of_2 =
		red_trans_exp_ordering_criterion_any_of_convertToJSON(
			red_trans_exp_ordering_criterion_any_of_2);
	printf("repeating red_trans_exp_ordering_criterion_any_of:\n%s\n", cJSON_Print(
		       jsonred_trans_exp_ordering_criterion_any_of_2));
}

int main() {
	test_red_trans_exp_ordering_criterion_any_of(1);
	test_red_trans_exp_ordering_criterion_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // red_trans_exp_ordering_criterion_any_of_MAIN
#endif // red_trans_exp_ordering_criterion_any_of_TEST
