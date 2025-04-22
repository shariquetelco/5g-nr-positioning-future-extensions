#ifndef time_window_TEST
#define time_window_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_window_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_window.h"
time_window_t *instantiate_time_window(int include_optional);



time_window_t *instantiate_time_window(int include_optional) {
	time_window_t *time_window = NULL;
	if(include_optional) {
		time_window = time_window_create(
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		time_window = time_window_create(
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00"
			);
	}

	return time_window;
}


#ifdef time_window_MAIN

void test_time_window(int include_optional) {
	time_window_t *time_window_1 =
		instantiate_time_window(include_optional);

	cJSON *jsontime_window_1 = time_window_convertToJSON(time_window_1);
	printf("time_window :\n%s\n", cJSON_Print(jsontime_window_1));
	time_window_t *time_window_2 = time_window_parseFromJSON(
		jsontime_window_1);
	cJSON *jsontime_window_2 = time_window_convertToJSON(time_window_2);
	printf("repeating time_window:\n%s\n", cJSON_Print(jsontime_window_2));
}

int main() {
	test_time_window(1);
	test_time_window(0);

	printf("Hello world \n");
	return 0;
}

#endif // time_window_MAIN
#endif // time_window_TEST
