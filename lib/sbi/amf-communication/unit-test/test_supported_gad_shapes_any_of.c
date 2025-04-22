#ifndef supported_gad_shapes_any_of_TEST
#define supported_gad_shapes_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define supported_gad_shapes_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/supported_gad_shapes_any_of.h"
supported_gad_shapes_any_of_t *instantiate_supported_gad_shapes_any_of(
	int include_optional);



supported_gad_shapes_any_of_t *instantiate_supported_gad_shapes_any_of(
	int include_optional) {
	supported_gad_shapes_any_of_t *supported_gad_shapes_any_of = NULL;
	if(include_optional) {
		supported_gad_shapes_any_of =
			supported_gad_shapes_any_of_create(
				);
	} else {
		supported_gad_shapes_any_of =
			supported_gad_shapes_any_of_create(
				);
	}

	return supported_gad_shapes_any_of;
}


#ifdef supported_gad_shapes_any_of_MAIN

void test_supported_gad_shapes_any_of(int include_optional) {
	supported_gad_shapes_any_of_t *supported_gad_shapes_any_of_1 =
		instantiate_supported_gad_shapes_any_of(include_optional);

	cJSON *jsonsupported_gad_shapes_any_of_1 =
		supported_gad_shapes_any_of_convertToJSON(
			supported_gad_shapes_any_of_1);
	printf("supported_gad_shapes_any_of :\n%s\n",
	       cJSON_Print(jsonsupported_gad_shapes_any_of_1));
	supported_gad_shapes_any_of_t *supported_gad_shapes_any_of_2 =
		supported_gad_shapes_any_of_parseFromJSON(
			jsonsupported_gad_shapes_any_of_1);
	cJSON *jsonsupported_gad_shapes_any_of_2 =
		supported_gad_shapes_any_of_convertToJSON(
			supported_gad_shapes_any_of_2);
	printf("repeating supported_gad_shapes_any_of:\n%s\n",
	       cJSON_Print(jsonsupported_gad_shapes_any_of_2));
}

int main() {
	test_supported_gad_shapes_any_of(1);
	test_supported_gad_shapes_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // supported_gad_shapes_any_of_MAIN
#endif // supported_gad_shapes_any_of_TEST
