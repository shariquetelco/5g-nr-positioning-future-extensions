#ifndef loc_accuracy_per_method_TEST
#define loc_accuracy_per_method_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_accuracy_per_method_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_accuracy_per_method.h"
loc_accuracy_per_method_t *instantiate_loc_accuracy_per_method(
	int include_optional);

#include "test_positioning_method.c"


loc_accuracy_per_method_t *instantiate_loc_accuracy_per_method(
	int include_optional) {
	loc_accuracy_per_method_t *loc_accuracy_per_method = NULL;
	if(include_optional) {
		loc_accuracy_per_method = loc_accuracy_per_method_create(
			null,
			0,
			0,
			1
			);
	} else {
		loc_accuracy_per_method = loc_accuracy_per_method_create(
			null,
			0,
			0,
			1
			);
	}

	return loc_accuracy_per_method;
}


#ifdef loc_accuracy_per_method_MAIN

void test_loc_accuracy_per_method(int include_optional) {
	loc_accuracy_per_method_t *loc_accuracy_per_method_1 =
		instantiate_loc_accuracy_per_method(include_optional);

	cJSON *jsonloc_accuracy_per_method_1 =
		loc_accuracy_per_method_convertToJSON(loc_accuracy_per_method_1);
	printf("loc_accuracy_per_method :\n%s\n",
	       cJSON_Print(jsonloc_accuracy_per_method_1));
	loc_accuracy_per_method_t *loc_accuracy_per_method_2 =
		loc_accuracy_per_method_parseFromJSON(
			jsonloc_accuracy_per_method_1);
	cJSON *jsonloc_accuracy_per_method_2 =
		loc_accuracy_per_method_convertToJSON(loc_accuracy_per_method_2);
	printf("repeating loc_accuracy_per_method:\n%s\n",
	       cJSON_Print(jsonloc_accuracy_per_method_2));
}

int main() {
	test_loc_accuracy_per_method(1);
	test_loc_accuracy_per_method(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_accuracy_per_method_MAIN
#endif // loc_accuracy_per_method_TEST
