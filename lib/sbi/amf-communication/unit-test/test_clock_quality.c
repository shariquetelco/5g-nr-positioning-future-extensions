#ifndef clock_quality_TEST
#define clock_quality_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define clock_quality_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/clock_quality.h"
clock_quality_t *instantiate_clock_quality(int include_optional);



clock_quality_t *instantiate_clock_quality(int include_optional) {
	clock_quality_t *clock_quality = NULL;
	if(include_optional) {
		clock_quality = clock_quality_create(
			1,
			1,
			0,
			"a",
			1
			);
	} else {
		clock_quality = clock_quality_create(
			1,
			1,
			0,
			"a",
			1
			);
	}

	return clock_quality;
}


#ifdef clock_quality_MAIN

void test_clock_quality(int include_optional) {
	clock_quality_t *clock_quality_1 = instantiate_clock_quality(
		include_optional);

	cJSON *jsonclock_quality_1 =
		clock_quality_convertToJSON(clock_quality_1);
	printf("clock_quality :\n%s\n", cJSON_Print(jsonclock_quality_1));
	clock_quality_t *clock_quality_2 = clock_quality_parseFromJSON(
		jsonclock_quality_1);
	cJSON *jsonclock_quality_2 =
		clock_quality_convertToJSON(clock_quality_2);
	printf("repeating clock_quality:\n%s\n", cJSON_Print(
		       jsonclock_quality_2));
}

int main() {
	test_clock_quality(1);
	test_clock_quality(0);

	printf("Hello world \n");
	return 0;
}

#endif // clock_quality_MAIN
#endif // clock_quality_TEST
