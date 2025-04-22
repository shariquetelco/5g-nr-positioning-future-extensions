#ifndef time_to_collision_info_TEST
#define time_to_collision_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_to_collision_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_to_collision_info.h"
time_to_collision_info_t *instantiate_time_to_collision_info(
	int include_optional);



time_to_collision_info_t *instantiate_time_to_collision_info(
	int include_optional) {
	time_to_collision_info_t *time_to_collision_info = NULL;
	if(include_optional) {
		time_to_collision_info = time_to_collision_info_create(
			"2013-10-20T19:20:30+01:00",
			0,
			0
			);
	} else {
		time_to_collision_info = time_to_collision_info_create(
			"2013-10-20T19:20:30+01:00",
			0,
			0
			);
	}

	return time_to_collision_info;
}


#ifdef time_to_collision_info_MAIN

void test_time_to_collision_info(int include_optional) {
	time_to_collision_info_t *time_to_collision_info_1 =
		instantiate_time_to_collision_info(include_optional);

	cJSON *jsontime_to_collision_info_1 =
		time_to_collision_info_convertToJSON(time_to_collision_info_1);
	printf("time_to_collision_info :\n%s\n",
	       cJSON_Print(jsontime_to_collision_info_1));
	time_to_collision_info_t *time_to_collision_info_2 =
		time_to_collision_info_parseFromJSON(
			jsontime_to_collision_info_1);
	cJSON *jsontime_to_collision_info_2 =
		time_to_collision_info_convertToJSON(time_to_collision_info_2);
	printf("repeating time_to_collision_info:\n%s\n",
	       cJSON_Print(jsontime_to_collision_info_2));
}

int main() {
	test_time_to_collision_info(1);
	test_time_to_collision_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // time_to_collision_info_MAIN
#endif // time_to_collision_info_TEST
