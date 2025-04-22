#ifndef reporting_ind_any_of_TEST
#define reporting_ind_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reporting_ind_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reporting_ind_any_of.h"
reporting_ind_any_of_t *instantiate_reporting_ind_any_of(int include_optional);



reporting_ind_any_of_t *instantiate_reporting_ind_any_of(int include_optional) {
	reporting_ind_any_of_t *reporting_ind_any_of = NULL;
	if(include_optional) {
		reporting_ind_any_of = reporting_ind_any_of_create(
			);
	} else {
		reporting_ind_any_of = reporting_ind_any_of_create(
			);
	}

	return reporting_ind_any_of;
}


#ifdef reporting_ind_any_of_MAIN

void test_reporting_ind_any_of(int include_optional) {
	reporting_ind_any_of_t *reporting_ind_any_of_1 =
		instantiate_reporting_ind_any_of(include_optional);

	cJSON *jsonreporting_ind_any_of_1 = reporting_ind_any_of_convertToJSON(
		reporting_ind_any_of_1);
	printf("reporting_ind_any_of :\n%s\n",
	       cJSON_Print(jsonreporting_ind_any_of_1));
	reporting_ind_any_of_t *reporting_ind_any_of_2 =
		reporting_ind_any_of_parseFromJSON(jsonreporting_ind_any_of_1);
	cJSON *jsonreporting_ind_any_of_2 = reporting_ind_any_of_convertToJSON(
		reporting_ind_any_of_2);
	printf("repeating reporting_ind_any_of:\n%s\n",
	       cJSON_Print(jsonreporting_ind_any_of_2));
}

int main() {
	test_reporting_ind_any_of(1);
	test_reporting_ind_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // reporting_ind_any_of_MAIN
#endif // reporting_ind_any_of_TEST
