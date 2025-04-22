#ifndef direction_TEST
#define direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/direction.h"
direction_t *instantiate_direction(int include_optional);



direction_t *instantiate_direction(int include_optional) {
	direction_t *direction = NULL;
	if(include_optional) {
		direction = direction_create(
			);
	} else {
		direction = direction_create(
			);
	}

	return direction;
}


#ifdef direction_MAIN

void test_direction(int include_optional) {
	direction_t *direction_1 = instantiate_direction(include_optional);

	cJSON *jsondirection_1 = direction_convertToJSON(direction_1);
	printf("direction :\n%s\n", cJSON_Print(jsondirection_1));
	direction_t *direction_2 = direction_parseFromJSON(jsondirection_1);
	cJSON *jsondirection_2 = direction_convertToJSON(direction_2);
	printf("repeating direction:\n%s\n", cJSON_Print(jsondirection_2));
}

int main() {
	test_direction(1);
	test_direction(0);

	printf("Hello world \n");
	return 0;
}

#endif // direction_MAIN
#endif // direction_TEST
