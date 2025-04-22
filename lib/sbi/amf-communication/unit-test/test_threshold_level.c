#ifndef threshold_level_TEST
#define threshold_level_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define threshold_level_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/threshold_level.h"
threshold_level_t *instantiate_threshold_level(int include_optional);



threshold_level_t *instantiate_threshold_level(int include_optional) {
	threshold_level_t *threshold_level = NULL;
	if(include_optional) {
		threshold_level = threshold_level_create(
			56,
			56,
			56,
			56,
			56,
			"a",
			"a",
			"a",
			"a",
			1.337,
			1,
			1,
			1.337,
			0,
			0,
			1.337,
			1.337,
			1.337
			);
	} else {
		threshold_level = threshold_level_create(
			56,
			56,
			56,
			56,
			56,
			"a",
			"a",
			"a",
			"a",
			1.337,
			1,
			1,
			1.337,
			0,
			0,
			1.337,
			1.337,
			1.337
			);
	}

	return threshold_level;
}


#ifdef threshold_level_MAIN

void test_threshold_level(int include_optional) {
	threshold_level_t *threshold_level_1 = instantiate_threshold_level(
		include_optional);

	cJSON *jsonthreshold_level_1 = threshold_level_convertToJSON(
		threshold_level_1);
	printf("threshold_level :\n%s\n", cJSON_Print(jsonthreshold_level_1));
	threshold_level_t *threshold_level_2 = threshold_level_parseFromJSON(
		jsonthreshold_level_1);
	cJSON *jsonthreshold_level_2 = threshold_level_convertToJSON(
		threshold_level_2);
	printf("repeating threshold_level:\n%s\n",
	       cJSON_Print(jsonthreshold_level_2));
}

int main() {
	test_threshold_level(1);
	test_threshold_level(0);

	printf("Hello world \n");
	return 0;
}

#endif // threshold_level_MAIN
#endif // threshold_level_TEST
