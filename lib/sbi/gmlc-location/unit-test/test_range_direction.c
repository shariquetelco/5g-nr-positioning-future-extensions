#ifndef range_direction_TEST
#define range_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define range_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/range_direction.h"
range_direction_t *instantiate_range_direction(int include_optional);



range_direction_t *instantiate_range_direction(int include_optional) {
	range_direction_t *range_direction = NULL;
	if(include_optional) {
		range_direction = range_direction_create(
			1.337,
			0,
			0
			);
	} else {
		range_direction = range_direction_create(
			1.337,
			0,
			0
			);
	}

	return range_direction;
}


#ifdef range_direction_MAIN

void test_range_direction(int include_optional) {
	range_direction_t *range_direction_1 = instantiate_range_direction(
		include_optional);

	cJSON *jsonrange_direction_1 = range_direction_convertToJSON(
		range_direction_1);
	printf("range_direction :\n%s\n", cJSON_Print(jsonrange_direction_1));
	range_direction_t *range_direction_2 = range_direction_parseFromJSON(
		jsonrange_direction_1);
	cJSON *jsonrange_direction_2 = range_direction_convertToJSON(
		range_direction_2);
	printf("repeating range_direction:\n%s\n",
	       cJSON_Print(jsonrange_direction_2));
}

int main() {
	test_range_direction(1);
	test_range_direction(0);

	printf("Hello world \n");
	return 0;
}

#endif // range_direction_MAIN
#endif // range_direction_TEST
