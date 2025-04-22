#ifndef time_source_any_of_TEST
#define time_source_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_source_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_source_any_of.h"
time_source_any_of_t *instantiate_time_source_any_of(int include_optional);



time_source_any_of_t *instantiate_time_source_any_of(int include_optional) {
	time_source_any_of_t *time_source_any_of = NULL;
	if(include_optional) {
		time_source_any_of = time_source_any_of_create(
			);
	} else {
		time_source_any_of = time_source_any_of_create(
			);
	}

	return time_source_any_of;
}


#ifdef time_source_any_of_MAIN

void test_time_source_any_of(int include_optional) {
	time_source_any_of_t *time_source_any_of_1 =
		instantiate_time_source_any_of(include_optional);

	cJSON *jsontime_source_any_of_1 = time_source_any_of_convertToJSON(
		time_source_any_of_1);
	printf("time_source_any_of :\n%s\n",
	       cJSON_Print(jsontime_source_any_of_1));
	time_source_any_of_t *time_source_any_of_2 =
		time_source_any_of_parseFromJSON(jsontime_source_any_of_1);
	cJSON *jsontime_source_any_of_2 = time_source_any_of_convertToJSON(
		time_source_any_of_2);
	printf("repeating time_source_any_of:\n%s\n",
	       cJSON_Print(jsontime_source_any_of_2));
}

int main() {
	test_time_source_any_of(1);
	test_time_source_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // time_source_any_of_MAIN
#endif // time_source_any_of_TEST
