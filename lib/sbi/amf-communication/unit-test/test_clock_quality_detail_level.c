#ifndef clock_quality_detail_level_TEST
#define clock_quality_detail_level_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define clock_quality_detail_level_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/clock_quality_detail_level.h"
clock_quality_detail_level_t *instantiate_clock_quality_detail_level(
	int include_optional);



clock_quality_detail_level_t *instantiate_clock_quality_detail_level(
	int include_optional) {
	clock_quality_detail_level_t *clock_quality_detail_level = NULL;
	if(include_optional) {
		clock_quality_detail_level = clock_quality_detail_level_create(
			);
	} else {
		clock_quality_detail_level = clock_quality_detail_level_create(
			);
	}

	return clock_quality_detail_level;
}


#ifdef clock_quality_detail_level_MAIN

void test_clock_quality_detail_level(int include_optional) {
	clock_quality_detail_level_t *clock_quality_detail_level_1 =
		instantiate_clock_quality_detail_level(include_optional);

	cJSON *jsonclock_quality_detail_level_1 =
		clock_quality_detail_level_convertToJSON(
			clock_quality_detail_level_1);
	printf("clock_quality_detail_level :\n%s\n",
	       cJSON_Print(jsonclock_quality_detail_level_1));
	clock_quality_detail_level_t *clock_quality_detail_level_2 =
		clock_quality_detail_level_parseFromJSON(
			jsonclock_quality_detail_level_1);
	cJSON *jsonclock_quality_detail_level_2 =
		clock_quality_detail_level_convertToJSON(
			clock_quality_detail_level_2);
	printf("repeating clock_quality_detail_level:\n%s\n",
	       cJSON_Print(jsonclock_quality_detail_level_2));
}

int main() {
	test_clock_quality_detail_level(1);
	test_clock_quality_detail_level(0);

	printf("Hello world \n");
	return 0;
}

#endif // clock_quality_detail_level_MAIN
#endif // clock_quality_detail_level_TEST
