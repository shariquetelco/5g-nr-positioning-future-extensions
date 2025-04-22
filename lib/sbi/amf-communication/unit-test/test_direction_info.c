#ifndef direction_info_TEST
#define direction_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define direction_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/direction_info.h"
direction_info_t *instantiate_direction_info(int include_optional);

#include "test_direction.c"


direction_info_t *instantiate_direction_info(int include_optional) {
	direction_info_t *direction_info = NULL;
	if(include_optional) {
		direction_info = direction_info_create(
			"a",
			"a",
			0,
			1.337,
			1,
			null
			);
	} else {
		direction_info = direction_info_create(
			"a",
			"a",
			0,
			1.337,
			1,
			null
			);
	}

	return direction_info;
}


#ifdef direction_info_MAIN

void test_direction_info(int include_optional) {
	direction_info_t *direction_info_1 = instantiate_direction_info(
		include_optional);

	cJSON *jsondirection_info_1 = direction_info_convertToJSON(
		direction_info_1);
	printf("direction_info :\n%s\n", cJSON_Print(jsondirection_info_1));
	direction_info_t *direction_info_2 = direction_info_parseFromJSON(
		jsondirection_info_1);
	cJSON *jsondirection_info_2 = direction_info_convertToJSON(
		direction_info_2);
	printf("repeating direction_info:\n%s\n",
	       cJSON_Print(jsondirection_info_2));
}

int main() {
	test_direction_info(1);
	test_direction_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // direction_info_MAIN
#endif // direction_info_TEST
