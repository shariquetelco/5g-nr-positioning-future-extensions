#ifndef relative_cartesian_location_TEST
#define relative_cartesian_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define relative_cartesian_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/relative_cartesian_location.h"
relative_cartesian_location_t *instantiate_relative_cartesian_location(
	int include_optional);



relative_cartesian_location_t *instantiate_relative_cartesian_location(
	int include_optional) {
	relative_cartesian_location_t *relative_cartesian_location = NULL;
	if(include_optional) {
		relative_cartesian_location =
			relative_cartesian_location_create(
				1.337,
				1.337,
				1.337
				);
	} else {
		relative_cartesian_location =
			relative_cartesian_location_create(
				1.337,
				1.337,
				1.337
				);
	}

	return relative_cartesian_location;
}


#ifdef relative_cartesian_location_MAIN

void test_relative_cartesian_location(int include_optional) {
	relative_cartesian_location_t *relative_cartesian_location_1 =
		instantiate_relative_cartesian_location(include_optional);

	cJSON *jsonrelative_cartesian_location_1 =
		relative_cartesian_location_convertToJSON(
			relative_cartesian_location_1);
	printf("relative_cartesian_location :\n%s\n",
	       cJSON_Print(jsonrelative_cartesian_location_1));
	relative_cartesian_location_t *relative_cartesian_location_2 =
		relative_cartesian_location_parseFromJSON(
			jsonrelative_cartesian_location_1);
	cJSON *jsonrelative_cartesian_location_2 =
		relative_cartesian_location_convertToJSON(
			relative_cartesian_location_2);
	printf("repeating relative_cartesian_location:\n%s\n",
	       cJSON_Print(jsonrelative_cartesian_location_2));
}

int main() {
	test_relative_cartesian_location(1);
	test_relative_cartesian_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // relative_cartesian_location_MAIN
#endif // relative_cartesian_location_TEST
