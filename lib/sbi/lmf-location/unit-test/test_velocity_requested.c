#ifndef velocity_requested_TEST
#define velocity_requested_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define velocity_requested_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/velocity_requested.h"
velocity_requested_t *instantiate_velocity_requested(int include_optional);



velocity_requested_t *instantiate_velocity_requested(int include_optional) {
	velocity_requested_t *velocity_requested = NULL;
	if(include_optional) {
		velocity_requested = velocity_requested_create(
			);
	} else {
		velocity_requested = velocity_requested_create(
			);
	}

	return velocity_requested;
}


#ifdef velocity_requested_MAIN

void test_velocity_requested(int include_optional) {
	velocity_requested_t *velocity_requested_1 =
		instantiate_velocity_requested(include_optional);

	cJSON *jsonvelocity_requested_1 = velocity_requested_convertToJSON(
		velocity_requested_1);
	printf("velocity_requested :\n%s\n",
	       cJSON_Print(jsonvelocity_requested_1));
	velocity_requested_t *velocity_requested_2 =
		velocity_requested_parseFromJSON(jsonvelocity_requested_1);
	cJSON *jsonvelocity_requested_2 = velocity_requested_convertToJSON(
		velocity_requested_2);
	printf("repeating velocity_requested:\n%s\n",
	       cJSON_Print(jsonvelocity_requested_2));
}

int main() {
	test_velocity_requested(1);
	test_velocity_requested(0);

	printf("Hello world \n");
	return 0;
}

#endif // velocity_requested_MAIN
#endif // velocity_requested_TEST
