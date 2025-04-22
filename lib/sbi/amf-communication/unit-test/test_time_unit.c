#ifndef time_unit_TEST
#define time_unit_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_unit_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_unit.h"
time_unit_t *instantiate_time_unit(int include_optional);



time_unit_t *instantiate_time_unit(int include_optional) {
	time_unit_t *time_unit = NULL;
	if(include_optional) {
		time_unit = time_unit_create(
			);
	} else {
		time_unit = time_unit_create(
			);
	}

	return time_unit;
}


#ifdef time_unit_MAIN

void test_time_unit(int include_optional) {
	time_unit_t *time_unit_1 = instantiate_time_unit(include_optional);

	cJSON *jsontime_unit_1 = time_unit_convertToJSON(time_unit_1);
	printf("time_unit :\n%s\n", cJSON_Print(jsontime_unit_1));
	time_unit_t *time_unit_2 = time_unit_parseFromJSON(jsontime_unit_1);
	cJSON *jsontime_unit_2 = time_unit_convertToJSON(time_unit_2);
	printf("repeating time_unit:\n%s\n", cJSON_Print(jsontime_unit_2));
}

int main() {
	test_time_unit(1);
	test_time_unit(0);

	printf("Hello world \n");
	return 0;
}

#endif // time_unit_MAIN
#endif // time_unit_TEST
