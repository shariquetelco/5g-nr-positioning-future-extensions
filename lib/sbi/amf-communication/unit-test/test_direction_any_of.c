#ifndef direction_any_of_TEST
#define direction_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define direction_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/direction_any_of.h"
direction_any_of_t *instantiate_direction_any_of(int include_optional);



direction_any_of_t *instantiate_direction_any_of(int include_optional) {
	direction_any_of_t *direction_any_of = NULL;
	if(include_optional) {
		direction_any_of = direction_any_of_create(
			);
	} else {
		direction_any_of = direction_any_of_create(
			);
	}

	return direction_any_of;
}


#ifdef direction_any_of_MAIN

void test_direction_any_of(int include_optional) {
	direction_any_of_t *direction_any_of_1 = instantiate_direction_any_of(
		include_optional);

	cJSON *jsondirection_any_of_1 = direction_any_of_convertToJSON(
		direction_any_of_1);
	printf("direction_any_of :\n%s\n", cJSON_Print(jsondirection_any_of_1));
	direction_any_of_t *direction_any_of_2 = direction_any_of_parseFromJSON(
		jsondirection_any_of_1);
	cJSON *jsondirection_any_of_2 = direction_any_of_convertToJSON(
		direction_any_of_2);
	printf("repeating direction_any_of:\n%s\n",
	       cJSON_Print(jsondirection_any_of_2));
}

int main() {
	test_direction_any_of(1);
	test_direction_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // direction_any_of_MAIN
#endif // direction_any_of_TEST
