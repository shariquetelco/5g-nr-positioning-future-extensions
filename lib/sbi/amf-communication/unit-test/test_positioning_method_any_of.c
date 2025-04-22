#ifndef positioning_method_any_of_TEST
#define positioning_method_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define positioning_method_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/positioning_method_any_of.h"
positioning_method_any_of_t *instantiate_positioning_method_any_of(
	int include_optional);



positioning_method_any_of_t *instantiate_positioning_method_any_of(
	int include_optional) {
	positioning_method_any_of_t *positioning_method_any_of = NULL;
	if(include_optional) {
		positioning_method_any_of = positioning_method_any_of_create(
			);
	} else {
		positioning_method_any_of = positioning_method_any_of_create(
			);
	}

	return positioning_method_any_of;
}


#ifdef positioning_method_any_of_MAIN

void test_positioning_method_any_of(int include_optional) {
	positioning_method_any_of_t *positioning_method_any_of_1 =
		instantiate_positioning_method_any_of(include_optional);

	cJSON *jsonpositioning_method_any_of_1 =
		positioning_method_any_of_convertToJSON(
			positioning_method_any_of_1);
	printf("positioning_method_any_of :\n%s\n",
	       cJSON_Print(jsonpositioning_method_any_of_1));
	positioning_method_any_of_t *positioning_method_any_of_2 =
		positioning_method_any_of_parseFromJSON(
			jsonpositioning_method_any_of_1);
	cJSON *jsonpositioning_method_any_of_2 =
		positioning_method_any_of_convertToJSON(
			positioning_method_any_of_2);
	printf("repeating positioning_method_any_of:\n%s\n",
	       cJSON_Print(jsonpositioning_method_any_of_2));
}

int main() {
	test_positioning_method_any_of(1);
	test_positioning_method_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // positioning_method_any_of_MAIN
#endif // positioning_method_any_of_TEST
