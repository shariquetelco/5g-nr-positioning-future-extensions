#ifndef speed_threshold_info_TEST
#define speed_threshold_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define speed_threshold_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/speed_threshold_info.h"
speed_threshold_info_t *instantiate_speed_threshold_info(int include_optional);



speed_threshold_info_t *instantiate_speed_threshold_info(int include_optional) {
	speed_threshold_info_t *speed_threshold_info = NULL;
	if(include_optional) {
		speed_threshold_info = speed_threshold_info_create(
			0,
			1
			);
	} else {
		speed_threshold_info = speed_threshold_info_create(
			0,
			1
			);
	}

	return speed_threshold_info;
}


#ifdef speed_threshold_info_MAIN

void test_speed_threshold_info(int include_optional) {
	speed_threshold_info_t *speed_threshold_info_1 =
		instantiate_speed_threshold_info(include_optional);

	cJSON *jsonspeed_threshold_info_1 = speed_threshold_info_convertToJSON(
		speed_threshold_info_1);
	printf("speed_threshold_info :\n%s\n",
	       cJSON_Print(jsonspeed_threshold_info_1));
	speed_threshold_info_t *speed_threshold_info_2 =
		speed_threshold_info_parseFromJSON(jsonspeed_threshold_info_1);
	cJSON *jsonspeed_threshold_info_2 = speed_threshold_info_convertToJSON(
		speed_threshold_info_2);
	printf("repeating speed_threshold_info:\n%s\n",
	       cJSON_Print(jsonspeed_threshold_info_2));
}

int main() {
	test_speed_threshold_info(1);
	test_speed_threshold_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // speed_threshold_info_MAIN
#endif // speed_threshold_info_TEST
