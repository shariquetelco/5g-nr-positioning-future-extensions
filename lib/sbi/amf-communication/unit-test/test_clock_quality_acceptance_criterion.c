#ifndef clock_quality_acceptance_criterion_TEST
#define clock_quality_acceptance_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define clock_quality_acceptance_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/clock_quality_acceptance_criterion.h"
clock_quality_acceptance_criterion_t *
instantiate_clock_quality_acceptance_criterion(int include_optional);

#include "test_clock_quality.c"


clock_quality_acceptance_criterion_t *
instantiate_clock_quality_acceptance_criterion(int include_optional) {
	clock_quality_acceptance_criterion_t *clock_quality_acceptance_criterion
	        = NULL;
	if(include_optional) {
		clock_quality_acceptance_criterion =
			clock_quality_acceptance_criterion_create(
				list_createList(),
				// false, not to have infinite recursion
				instantiate_clock_quality(0),
				list_createList()
				);
	} else {
		clock_quality_acceptance_criterion =
			clock_quality_acceptance_criterion_create(
				list_createList(),
				NULL,
				list_createList()
				);
	}

	return clock_quality_acceptance_criterion;
}


#ifdef clock_quality_acceptance_criterion_MAIN

void test_clock_quality_acceptance_criterion(int include_optional) {
	clock_quality_acceptance_criterion_t *
	        clock_quality_acceptance_criterion_1 =
		instantiate_clock_quality_acceptance_criterion(include_optional);

	cJSON *jsonclock_quality_acceptance_criterion_1 =
		clock_quality_acceptance_criterion_convertToJSON(
			clock_quality_acceptance_criterion_1);
	printf("clock_quality_acceptance_criterion :\n%s\n",
	       cJSON_Print(jsonclock_quality_acceptance_criterion_1));
	clock_quality_acceptance_criterion_t *
	        clock_quality_acceptance_criterion_2 =
		clock_quality_acceptance_criterion_parseFromJSON(
			jsonclock_quality_acceptance_criterion_1);
	cJSON *jsonclock_quality_acceptance_criterion_2 =
		clock_quality_acceptance_criterion_convertToJSON(
			clock_quality_acceptance_criterion_2);
	printf("repeating clock_quality_acceptance_criterion:\n%s\n", cJSON_Print(
		       jsonclock_quality_acceptance_criterion_2));
}

int main() {
	test_clock_quality_acceptance_criterion(1);
	test_clock_quality_acceptance_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // clock_quality_acceptance_criterion_MAIN
#endif // clock_quality_acceptance_criterion_TEST
