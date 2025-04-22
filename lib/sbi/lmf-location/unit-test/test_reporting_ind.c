#ifndef reporting_ind_TEST
#define reporting_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reporting_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reporting_ind.h"
reporting_ind_t *instantiate_reporting_ind(int include_optional);



reporting_ind_t *instantiate_reporting_ind(int include_optional) {
	reporting_ind_t *reporting_ind = NULL;
	if(include_optional) {
		reporting_ind = reporting_ind_create(
			);
	} else {
		reporting_ind = reporting_ind_create(
			);
	}

	return reporting_ind;
}


#ifdef reporting_ind_MAIN

void test_reporting_ind(int include_optional) {
	reporting_ind_t *reporting_ind_1 = instantiate_reporting_ind(
		include_optional);

	cJSON *jsonreporting_ind_1 =
		reporting_ind_convertToJSON(reporting_ind_1);
	printf("reporting_ind :\n%s\n", cJSON_Print(jsonreporting_ind_1));
	reporting_ind_t *reporting_ind_2 = reporting_ind_parseFromJSON(
		jsonreporting_ind_1);
	cJSON *jsonreporting_ind_2 =
		reporting_ind_convertToJSON(reporting_ind_2);
	printf("repeating reporting_ind:\n%s\n", cJSON_Print(
		       jsonreporting_ind_2));
}

int main() {
	test_reporting_ind(1);
	test_reporting_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // reporting_ind_MAIN
#endif // reporting_ind_TEST
