#ifndef horizontal_with_vertical_velocity_and_uncertainty_TEST
#define horizontal_with_vertical_velocity_and_uncertainty_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define horizontal_with_vertical_velocity_and_uncertainty_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/horizontal_with_vertical_velocity_and_uncertainty.h"
horizontal_with_vertical_velocity_and_uncertainty_t *
instantiate_horizontal_with_vertical_velocity_and_uncertainty(
	int include_optional);



horizontal_with_vertical_velocity_and_uncertainty_t *
instantiate_horizontal_with_vertical_velocity_and_uncertainty(
	int include_optional) {
	horizontal_with_vertical_velocity_and_uncertainty_t *
	        horizontal_with_vertical_velocity_and_uncertainty = NULL;
	if(include_optional) {
		horizontal_with_vertical_velocity_and_uncertainty =
			horizontal_with_vertical_velocity_and_uncertainty_create(
				0,
				0,
				0,
				lmf_location_horizontal_with_vertical_velocity_and_uncertainty__UPWARD,
				0,
				0
				);
	} else {
		horizontal_with_vertical_velocity_and_uncertainty =
			horizontal_with_vertical_velocity_and_uncertainty_create(
				0,
				0,
				0,
				lmf_location_horizontal_with_vertical_velocity_and_uncertainty__UPWARD,
				0,
				0
				);
	}

	return horizontal_with_vertical_velocity_and_uncertainty;
}


#ifdef horizontal_with_vertical_velocity_and_uncertainty_MAIN

void test_horizontal_with_vertical_velocity_and_uncertainty(
	int include_optional) {
	horizontal_with_vertical_velocity_and_uncertainty_t *
	        horizontal_with_vertical_velocity_and_uncertainty_1 =
		instantiate_horizontal_with_vertical_velocity_and_uncertainty(
			include_optional);

	cJSON *jsonhorizontal_with_vertical_velocity_and_uncertainty_1 =
		horizontal_with_vertical_velocity_and_uncertainty_convertToJSON(
			horizontal_with_vertical_velocity_and_uncertainty_1);
	printf("horizontal_with_vertical_velocity_and_uncertainty :\n%s\n", cJSON_Print(
		       jsonhorizontal_with_vertical_velocity_and_uncertainty_1));
	horizontal_with_vertical_velocity_and_uncertainty_t *
	        horizontal_with_vertical_velocity_and_uncertainty_2 =
		horizontal_with_vertical_velocity_and_uncertainty_parseFromJSON(
			jsonhorizontal_with_vertical_velocity_and_uncertainty_1);
	cJSON *jsonhorizontal_with_vertical_velocity_and_uncertainty_2 =
		horizontal_with_vertical_velocity_and_uncertainty_convertToJSON(
			horizontal_with_vertical_velocity_and_uncertainty_2);
	printf(
		"repeating horizontal_with_vertical_velocity_and_uncertainty:\n%s\n", cJSON_Print(
			jsonhorizontal_with_vertical_velocity_and_uncertainty_2));
}

int main() {
	test_horizontal_with_vertical_velocity_and_uncertainty(1);
	test_horizontal_with_vertical_velocity_and_uncertainty(0);

	printf("Hello world \n");
	return 0;
}

#endif // horizontal_with_vertical_velocity_and_uncertainty_MAIN
#endif // horizontal_with_vertical_velocity_and_uncertainty_TEST
