#ifndef matching_direction_any_of_TEST
#define matching_direction_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define matching_direction_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/matching_direction_any_of.h"
matching_direction_any_of_t *instantiate_matching_direction_any_of(
	int include_optional);



matching_direction_any_of_t *instantiate_matching_direction_any_of(
	int include_optional) {
	matching_direction_any_of_t *matching_direction_any_of = NULL;
	if(include_optional) {
		matching_direction_any_of = matching_direction_any_of_create(
			);
	} else {
		matching_direction_any_of = matching_direction_any_of_create(
			);
	}

	return matching_direction_any_of;
}


#ifdef matching_direction_any_of_MAIN

void test_matching_direction_any_of(int include_optional) {
	matching_direction_any_of_t *matching_direction_any_of_1 =
		instantiate_matching_direction_any_of(include_optional);

	cJSON *jsonmatching_direction_any_of_1 =
		matching_direction_any_of_convertToJSON(
			matching_direction_any_of_1);
	printf("matching_direction_any_of :\n%s\n",
	       cJSON_Print(jsonmatching_direction_any_of_1));
	matching_direction_any_of_t *matching_direction_any_of_2 =
		matching_direction_any_of_parseFromJSON(
			jsonmatching_direction_any_of_1);
	cJSON *jsonmatching_direction_any_of_2 =
		matching_direction_any_of_convertToJSON(
			matching_direction_any_of_2);
	printf("repeating matching_direction_any_of:\n%s\n",
	       cJSON_Print(jsonmatching_direction_any_of_2));
}

int main() {
	test_matching_direction_any_of(1);
	test_matching_direction_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // matching_direction_any_of_MAIN
#endif // matching_direction_any_of_TEST
