#ifndef velocity_estimate_TEST
#define velocity_estimate_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define velocity_estimate_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/velocity_estimate.h"
velocity_estimate_t *instantiate_velocity_estimate(int include_optional);



velocity_estimate_t *instantiate_velocity_estimate(int include_optional) {
	velocity_estimate_t *velocity_estimate = NULL;
	if(include_optional) {
		velocity_estimate = velocity_estimate_create(
			0,
			0,
			0,
			lmf_location_velocity_estimate__UPWARD,
			0,
			0
			);
	} else {
		velocity_estimate = velocity_estimate_create(
			0,
			0,
			0,
			lmf_location_velocity_estimate__UPWARD,
			0,
			0
			);
	}

	return velocity_estimate;
}


#ifdef velocity_estimate_MAIN

void test_velocity_estimate(int include_optional) {
	velocity_estimate_t *velocity_estimate_1 =
		instantiate_velocity_estimate(include_optional);

	cJSON *jsonvelocity_estimate_1 = velocity_estimate_convertToJSON(
		velocity_estimate_1);
	printf("velocity_estimate :\n%s\n",
	       cJSON_Print(jsonvelocity_estimate_1));
	velocity_estimate_t *velocity_estimate_2 =
		velocity_estimate_parseFromJSON(jsonvelocity_estimate_1);
	cJSON *jsonvelocity_estimate_2 = velocity_estimate_convertToJSON(
		velocity_estimate_2);
	printf("repeating velocity_estimate:\n%s\n",
	       cJSON_Print(jsonvelocity_estimate_2));
}

int main() {
	test_velocity_estimate(1);
	test_velocity_estimate(0);

	printf("Hello world \n");
	return 0;
}

#endif // velocity_estimate_MAIN
#endif // velocity_estimate_TEST
