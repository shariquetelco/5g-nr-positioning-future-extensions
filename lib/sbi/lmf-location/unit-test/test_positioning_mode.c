#ifndef positioning_mode_TEST
#define positioning_mode_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define positioning_mode_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/positioning_mode.h"
positioning_mode_t *instantiate_positioning_mode(int include_optional);



positioning_mode_t *instantiate_positioning_mode(int include_optional) {
	positioning_mode_t *positioning_mode = NULL;
	if(include_optional) {
		positioning_mode = positioning_mode_create(
			);
	} else {
		positioning_mode = positioning_mode_create(
			);
	}

	return positioning_mode;
}


#ifdef positioning_mode_MAIN

void test_positioning_mode(int include_optional) {
	positioning_mode_t *positioning_mode_1 = instantiate_positioning_mode(
		include_optional);

	cJSON *jsonpositioning_mode_1 = positioning_mode_convertToJSON(
		positioning_mode_1);
	printf("positioning_mode :\n%s\n", cJSON_Print(jsonpositioning_mode_1));
	positioning_mode_t *positioning_mode_2 = positioning_mode_parseFromJSON(
		jsonpositioning_mode_1);
	cJSON *jsonpositioning_mode_2 = positioning_mode_convertToJSON(
		positioning_mode_2);
	printf("repeating positioning_mode:\n%s\n",
	       cJSON_Print(jsonpositioning_mode_2));
}

int main() {
	test_positioning_mode(1);
	test_positioning_mode(0);

	printf("Hello world \n");
	return 0;
}

#endif // positioning_mode_MAIN
#endif // positioning_mode_TEST
