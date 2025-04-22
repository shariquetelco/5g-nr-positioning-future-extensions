#ifndef var_rep_period_TEST
#define var_rep_period_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define var_rep_period_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/var_rep_period.h"
var_rep_period_t *instantiate_var_rep_period(int include_optional);

#include "test_int.c"


var_rep_period_t *instantiate_var_rep_period(int include_optional) {
	var_rep_period_t *var_rep_period = NULL;
	if(include_optional) {
		var_rep_period = var_rep_period_create(
			56,
			null
			);
	} else {
		var_rep_period = var_rep_period_create(
			56,
			null
			);
	}

	return var_rep_period;
}


#ifdef var_rep_period_MAIN

void test_var_rep_period(int include_optional) {
	var_rep_period_t *var_rep_period_1 = instantiate_var_rep_period(
		include_optional);

	cJSON *jsonvar_rep_period_1 = var_rep_period_convertToJSON(
		var_rep_period_1);
	printf("var_rep_period :\n%s\n", cJSON_Print(jsonvar_rep_period_1));
	var_rep_period_t *var_rep_period_2 = var_rep_period_parseFromJSON(
		jsonvar_rep_period_1);
	cJSON *jsonvar_rep_period_2 = var_rep_period_convertToJSON(
		var_rep_period_2);
	printf("repeating var_rep_period:\n%s\n",
	       cJSON_Print(jsonvar_rep_period_2));
}

int main() {
	test_var_rep_period(1);
	test_var_rep_period(0);

	printf("Hello world \n");
	return 0;
}

#endif // var_rep_period_MAIN
#endif // var_rep_period_TEST
