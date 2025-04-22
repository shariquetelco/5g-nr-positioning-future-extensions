#ifndef clock_quality_detail_level_any_of_TEST
#define clock_quality_detail_level_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define clock_quality_detail_level_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/clock_quality_detail_level_any_of.h"
clock_quality_detail_level_any_of_t *
instantiate_clock_quality_detail_level_any_of(int include_optional);



clock_quality_detail_level_any_of_t *
instantiate_clock_quality_detail_level_any_of(int include_optional) {
	clock_quality_detail_level_any_of_t *clock_quality_detail_level_any_of =
		NULL;
	if(include_optional) {
		clock_quality_detail_level_any_of =
			clock_quality_detail_level_any_of_create(
				);
	} else {
		clock_quality_detail_level_any_of =
			clock_quality_detail_level_any_of_create(
				);
	}

	return clock_quality_detail_level_any_of;
}


#ifdef clock_quality_detail_level_any_of_MAIN

void test_clock_quality_detail_level_any_of(int include_optional) {
	clock_quality_detail_level_any_of_t *clock_quality_detail_level_any_of_1
	        = instantiate_clock_quality_detail_level_any_of(include_optional);

	cJSON *jsonclock_quality_detail_level_any_of_1 =
		clock_quality_detail_level_any_of_convertToJSON(
			clock_quality_detail_level_any_of_1);
	printf("clock_quality_detail_level_any_of :\n%s\n",
	       cJSON_Print(jsonclock_quality_detail_level_any_of_1));
	clock_quality_detail_level_any_of_t *clock_quality_detail_level_any_of_2
	        = clock_quality_detail_level_any_of_parseFromJSON(
			  jsonclock_quality_detail_level_any_of_1);
	cJSON *jsonclock_quality_detail_level_any_of_2 =
		clock_quality_detail_level_any_of_convertToJSON(
			clock_quality_detail_level_any_of_2);
	printf("repeating clock_quality_detail_level_any_of:\n%s\n", cJSON_Print(
		       jsonclock_quality_detail_level_any_of_2));
}

int main() {
	test_clock_quality_detail_level_any_of(1);
	test_clock_quality_detail_level_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // clock_quality_detail_level_any_of_MAIN
#endif // clock_quality_detail_level_any_of_TEST
