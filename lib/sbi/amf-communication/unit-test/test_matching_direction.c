#ifndef matching_direction_TEST
#define matching_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define matching_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/matching_direction.h"
matching_direction_t *instantiate_matching_direction(int include_optional);



matching_direction_t *instantiate_matching_direction(int include_optional) {
	matching_direction_t *matching_direction = NULL;
	if(include_optional) {
		matching_direction = matching_direction_create(
			);
	} else {
		matching_direction = matching_direction_create(
			);
	}

	return matching_direction;
}


#ifdef matching_direction_MAIN

void test_matching_direction(int include_optional) {
	matching_direction_t *matching_direction_1 =
		instantiate_matching_direction(include_optional);

	cJSON *jsonmatching_direction_1 = matching_direction_convertToJSON(
		matching_direction_1);
	printf("matching_direction :\n%s\n",
	       cJSON_Print(jsonmatching_direction_1));
	matching_direction_t *matching_direction_2 =
		matching_direction_parseFromJSON(jsonmatching_direction_1);
	cJSON *jsonmatching_direction_2 = matching_direction_convertToJSON(
		matching_direction_2);
	printf("repeating matching_direction:\n%s\n",
	       cJSON_Print(jsonmatching_direction_2));
}

int main() {
	test_matching_direction(1);
	test_matching_direction(0);

	printf("Hello world \n");
	return 0;
}

#endif // matching_direction_MAIN
#endif // matching_direction_TEST
