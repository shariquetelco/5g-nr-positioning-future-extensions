#ifndef motion_event_info_TEST
#define motion_event_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define motion_event_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/motion_event_info.h"
motion_event_info_t *instantiate_motion_event_info(int include_optional);



motion_event_info_t *instantiate_motion_event_info(int include_optional) {
	motion_event_info_t *motion_event_info = NULL;
	if(include_optional) {
		motion_event_info = motion_event_info_create(
			1,
			lmf_location_motion_event_info__ONE_TIME_EVENT,
			1,
			1,
			1,
			1,
			1
			);
	} else {
		motion_event_info = motion_event_info_create(
			1,
			lmf_location_motion_event_info__ONE_TIME_EVENT,
			1,
			1,
			1,
			1,
			1
			);
	}

	return motion_event_info;
}


#ifdef motion_event_info_MAIN

void test_motion_event_info(int include_optional) {
	motion_event_info_t *motion_event_info_1 =
		instantiate_motion_event_info(include_optional);

	cJSON *jsonmotion_event_info_1 = motion_event_info_convertToJSON(
		motion_event_info_1);
	printf("motion_event_info :\n%s\n",
	       cJSON_Print(jsonmotion_event_info_1));
	motion_event_info_t *motion_event_info_2 =
		motion_event_info_parseFromJSON(jsonmotion_event_info_1);
	cJSON *jsonmotion_event_info_2 = motion_event_info_convertToJSON(
		motion_event_info_2);
	printf("repeating motion_event_info:\n%s\n",
	       cJSON_Print(jsonmotion_event_info_2));
}

int main() {
	test_motion_event_info(1);
	test_motion_event_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // motion_event_info_MAIN
#endif // motion_event_info_TEST
