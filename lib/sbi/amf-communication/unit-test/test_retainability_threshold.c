#ifndef retainability_threshold_TEST
#define retainability_threshold_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define retainability_threshold_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/retainability_threshold.h"
retainability_threshold_t *instantiate_retainability_threshold(
	int include_optional);

#include "test_time_unit.c"


retainability_threshold_t *instantiate_retainability_threshold(
	int include_optional) {
	retainability_threshold_t *retainability_threshold = NULL;
	if(include_optional) {
		retainability_threshold = retainability_threshold_create(
			0,
			null,
			1
			);
	} else {
		retainability_threshold = retainability_threshold_create(
			0,
			null,
			1
			);
	}

	return retainability_threshold;
}


#ifdef retainability_threshold_MAIN

void test_retainability_threshold(int include_optional) {
	retainability_threshold_t *retainability_threshold_1 =
		instantiate_retainability_threshold(include_optional);

	cJSON *jsonretainability_threshold_1 =
		retainability_threshold_convertToJSON(retainability_threshold_1);
	printf("retainability_threshold :\n%s\n",
	       cJSON_Print(jsonretainability_threshold_1));
	retainability_threshold_t *retainability_threshold_2 =
		retainability_threshold_parseFromJSON(
			jsonretainability_threshold_1);
	cJSON *jsonretainability_threshold_2 =
		retainability_threshold_convertToJSON(retainability_threshold_2);
	printf("repeating retainability_threshold:\n%s\n",
	       cJSON_Print(jsonretainability_threshold_2));
}

int main() {
	test_retainability_threshold(1);
	test_retainability_threshold(0);

	printf("Hello world \n");
	return 0;
}

#endif // retainability_threshold_MAIN
#endif // retainability_threshold_TEST
