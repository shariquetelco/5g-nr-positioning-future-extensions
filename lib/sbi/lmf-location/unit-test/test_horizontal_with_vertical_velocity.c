#ifndef horizontal_with_vertical_velocity_TEST
#define horizontal_with_vertical_velocity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define horizontal_with_vertical_velocity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/horizontal_with_vertical_velocity.h"
horizontal_with_vertical_velocity_t *
instantiate_horizontal_with_vertical_velocity(int include_optional);



horizontal_with_vertical_velocity_t *
instantiate_horizontal_with_vertical_velocity(int include_optional) {
	horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity =
		NULL;
	if(include_optional) {
		horizontal_with_vertical_velocity =
			horizontal_with_vertical_velocity_create(
				0,
				0,
				0,
				lmf_location_horizontal_with_vertical_velocity__UPWARD
				);
	} else {
		horizontal_with_vertical_velocity =
			horizontal_with_vertical_velocity_create(
				0,
				0,
				0,
				lmf_location_horizontal_with_vertical_velocity__UPWARD
				);
	}

	return horizontal_with_vertical_velocity;
}


#ifdef horizontal_with_vertical_velocity_MAIN

void test_horizontal_with_vertical_velocity(int include_optional) {
	horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_1
	        = instantiate_horizontal_with_vertical_velocity(include_optional);

	cJSON *jsonhorizontal_with_vertical_velocity_1 =
		horizontal_with_vertical_velocity_convertToJSON(
			horizontal_with_vertical_velocity_1);
	printf("horizontal_with_vertical_velocity :\n%s\n",
	       cJSON_Print(jsonhorizontal_with_vertical_velocity_1));
	horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_2
	        = horizontal_with_vertical_velocity_parseFromJSON(
			  jsonhorizontal_with_vertical_velocity_1);
	cJSON *jsonhorizontal_with_vertical_velocity_2 =
		horizontal_with_vertical_velocity_convertToJSON(
			horizontal_with_vertical_velocity_2);
	printf("repeating horizontal_with_vertical_velocity:\n%s\n", cJSON_Print(
		       jsonhorizontal_with_vertical_velocity_2));
}

int main() {
	test_horizontal_with_vertical_velocity(1);
	test_horizontal_with_vertical_velocity(0);

	printf("Hello world \n");
	return 0;
}

#endif // horizontal_with_vertical_velocity_MAIN
#endif // horizontal_with_vertical_velocity_TEST
