#ifndef horizontal_velocity_with_uncertainty_TEST
#define horizontal_velocity_with_uncertainty_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define horizontal_velocity_with_uncertainty_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/horizontal_velocity_with_uncertainty.h"
horizontal_velocity_with_uncertainty_t *
instantiate_horizontal_velocity_with_uncertainty(int include_optional);



horizontal_velocity_with_uncertainty_t *
instantiate_horizontal_velocity_with_uncertainty(int include_optional) {
	horizontal_velocity_with_uncertainty_t *
	        horizontal_velocity_with_uncertainty = NULL;
	if(include_optional) {
		horizontal_velocity_with_uncertainty =
			horizontal_velocity_with_uncertainty_create(
				0,
				0,
				0
				);
	} else {
		horizontal_velocity_with_uncertainty =
			horizontal_velocity_with_uncertainty_create(
				0,
				0,
				0
				);
	}

	return horizontal_velocity_with_uncertainty;
}


#ifdef horizontal_velocity_with_uncertainty_MAIN

void test_horizontal_velocity_with_uncertainty(int include_optional) {
	horizontal_velocity_with_uncertainty_t *
	        horizontal_velocity_with_uncertainty_1 =
		instantiate_horizontal_velocity_with_uncertainty(
			include_optional);

	cJSON *jsonhorizontal_velocity_with_uncertainty_1 =
		horizontal_velocity_with_uncertainty_convertToJSON(
			horizontal_velocity_with_uncertainty_1);
	printf("horizontal_velocity_with_uncertainty :\n%s\n",
	       cJSON_Print(jsonhorizontal_velocity_with_uncertainty_1));
	horizontal_velocity_with_uncertainty_t *
	        horizontal_velocity_with_uncertainty_2 =
		horizontal_velocity_with_uncertainty_parseFromJSON(
			jsonhorizontal_velocity_with_uncertainty_1);
	cJSON *jsonhorizontal_velocity_with_uncertainty_2 =
		horizontal_velocity_with_uncertainty_convertToJSON(
			horizontal_velocity_with_uncertainty_2);
	printf("repeating horizontal_velocity_with_uncertainty:\n%s\n", cJSON_Print(
		       jsonhorizontal_velocity_with_uncertainty_2));
}

int main() {
	test_horizontal_velocity_with_uncertainty(1);
	test_horizontal_velocity_with_uncertainty(0);

	printf("Hello world \n");
	return 0;
}

#endif // horizontal_velocity_with_uncertainty_MAIN
#endif // horizontal_velocity_with_uncertainty_TEST
