#ifndef time_source_TEST
#define time_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_source.h"
time_source_t *instantiate_time_source(int include_optional);



time_source_t *instantiate_time_source(int include_optional) {
	time_source_t *time_source = NULL;
	if(include_optional) {
		time_source = time_source_create(
			);
	} else {
		time_source = time_source_create(
			);
	}

	return time_source;
}


#ifdef time_source_MAIN

void test_time_source(int include_optional) {
	time_source_t *time_source_1 =
		instantiate_time_source(include_optional);

	cJSON *jsontime_source_1 = time_source_convertToJSON(time_source_1);
	printf("time_source :\n%s\n", cJSON_Print(jsontime_source_1));
	time_source_t *time_source_2 = time_source_parseFromJSON(
		jsontime_source_1);
	cJSON *jsontime_source_2 = time_source_convertToJSON(time_source_2);
	printf("repeating time_source:\n%s\n", cJSON_Print(jsontime_source_2));
}

int main() {
	test_time_source(1);
	test_time_source(0);

	printf("Hello world \n");
	return 0;
}

#endif // time_source_MAIN
#endif // time_source_TEST
