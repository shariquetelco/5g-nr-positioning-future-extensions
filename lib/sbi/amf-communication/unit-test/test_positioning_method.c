#ifndef positioning_method_TEST
#define positioning_method_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define positioning_method_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/positioning_method.h"
positioning_method_t *instantiate_positioning_method(int include_optional);



positioning_method_t *instantiate_positioning_method(int include_optional) {
	positioning_method_t *positioning_method = NULL;
	if(include_optional) {
		positioning_method = positioning_method_create(
			);
	} else {
		positioning_method = positioning_method_create(
			);
	}

	return positioning_method;
}


#ifdef positioning_method_MAIN

void test_positioning_method(int include_optional) {
	positioning_method_t *positioning_method_1 =
		instantiate_positioning_method(include_optional);

	cJSON *jsonpositioning_method_1 = positioning_method_convertToJSON(
		positioning_method_1);
	printf("positioning_method :\n%s\n",
	       cJSON_Print(jsonpositioning_method_1));
	positioning_method_t *positioning_method_2 =
		positioning_method_parseFromJSON(jsonpositioning_method_1);
	cJSON *jsonpositioning_method_2 = positioning_method_convertToJSON(
		positioning_method_2);
	printf("repeating positioning_method:\n%s\n",
	       cJSON_Print(jsonpositioning_method_2));
}

int main() {
	test_positioning_method(1);
	test_positioning_method(0);

	printf("Hello world \n");
	return 0;
}

#endif // positioning_method_MAIN
#endif // positioning_method_TEST
