#ifndef horizontal_velocity_TEST
#define horizontal_velocity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define horizontal_velocity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/horizontal_velocity.h"
horizontal_velocity_t *instantiate_horizontal_velocity(int include_optional);



horizontal_velocity_t *instantiate_horizontal_velocity(int include_optional) {
	horizontal_velocity_t *horizontal_velocity = NULL;
	if(include_optional) {
		horizontal_velocity = horizontal_velocity_create(
			0,
			0
			);
	} else {
		horizontal_velocity = horizontal_velocity_create(
			0,
			0
			);
	}

	return horizontal_velocity;
}


#ifdef horizontal_velocity_MAIN

void test_horizontal_velocity(int include_optional) {
	horizontal_velocity_t *horizontal_velocity_1 =
		instantiate_horizontal_velocity(include_optional);

	cJSON *jsonhorizontal_velocity_1 = horizontal_velocity_convertToJSON(
		horizontal_velocity_1);
	printf("horizontal_velocity :\n%s\n",
	       cJSON_Print(jsonhorizontal_velocity_1));
	horizontal_velocity_t *horizontal_velocity_2 =
		horizontal_velocity_parseFromJSON(jsonhorizontal_velocity_1);
	cJSON *jsonhorizontal_velocity_2 = horizontal_velocity_convertToJSON(
		horizontal_velocity_2);
	printf("repeating horizontal_velocity:\n%s\n",
	       cJSON_Print(jsonhorizontal_velocity_2));
}

int main() {
	test_horizontal_velocity(1);
	test_horizontal_velocity(0);

	printf("Hello world \n");
	return 0;
}

#endif // horizontal_velocity_MAIN
#endif // horizontal_velocity_TEST
