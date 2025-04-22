#ifndef as_time_distribution_param_TEST
#define as_time_distribution_param_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define as_time_distribution_param_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/as_time_distribution_param.h"
as_time_distribution_param_t *instantiate_as_time_distribution_param(
	int include_optional);

#include "test_clock_quality_detail_level.c"
#include "test_clock_quality_acceptance_criterion.c"


as_time_distribution_param_t *instantiate_as_time_distribution_param(
	int include_optional) {
	as_time_distribution_param_t *as_time_distribution_param = NULL;
	if(include_optional) {
		as_time_distribution_param = as_time_distribution_param_create(
			1,
			0,
			null,
			// false, not to have infinite recursion
			instantiate_clock_quality_acceptance_criterion(0)
			);
	} else {
		as_time_distribution_param = as_time_distribution_param_create(
			1,
			0,
			null,
			NULL
			);
	}

	return as_time_distribution_param;
}


#ifdef as_time_distribution_param_MAIN

void test_as_time_distribution_param(int include_optional) {
	as_time_distribution_param_t *as_time_distribution_param_1 =
		instantiate_as_time_distribution_param(include_optional);

	cJSON *jsonas_time_distribution_param_1 =
		as_time_distribution_param_convertToJSON(
			as_time_distribution_param_1);
	printf("as_time_distribution_param :\n%s\n",
	       cJSON_Print(jsonas_time_distribution_param_1));
	as_time_distribution_param_t *as_time_distribution_param_2 =
		as_time_distribution_param_parseFromJSON(
			jsonas_time_distribution_param_1);
	cJSON *jsonas_time_distribution_param_2 =
		as_time_distribution_param_convertToJSON(
			as_time_distribution_param_2);
	printf("repeating as_time_distribution_param:\n%s\n",
	       cJSON_Print(jsonas_time_distribution_param_2));
}

int main() {
	test_as_time_distribution_param(1);
	test_as_time_distribution_param(0);

	printf("Hello world \n");
	return 0;
}

#endif // as_time_distribution_param_MAIN
#endif // as_time_distribution_param_TEST
