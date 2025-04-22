#ifndef vertical_direction_TEST
#define vertical_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vertical_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vertical_direction.h"
vertical_direction_t *instantiate_vertical_direction(int include_optional);



vertical_direction_t *instantiate_vertical_direction(int include_optional) {
	vertical_direction_t *vertical_direction = NULL;
	if(include_optional) {
		vertical_direction = vertical_direction_create(
			);
	} else {
		vertical_direction = vertical_direction_create(
			);
	}

	return vertical_direction;
}


#ifdef vertical_direction_MAIN

void test_vertical_direction(int include_optional) {
	vertical_direction_t *vertical_direction_1 =
		instantiate_vertical_direction(include_optional);

	cJSON *jsonvertical_direction_1 = vertical_direction_convertToJSON(
		vertical_direction_1);
	printf("vertical_direction :\n%s\n",
	       cJSON_Print(jsonvertical_direction_1));
	vertical_direction_t *vertical_direction_2 =
		vertical_direction_parseFromJSON(jsonvertical_direction_1);
	cJSON *jsonvertical_direction_2 = vertical_direction_convertToJSON(
		vertical_direction_2);
	printf("repeating vertical_direction:\n%s\n",
	       cJSON_Print(jsonvertical_direction_2));
}

int main() {
	test_vertical_direction(1);
	test_vertical_direction(0);

	printf("Hello world \n");
	return 0;
}

#endif // vertical_direction_MAIN
#endif // vertical_direction_TEST
