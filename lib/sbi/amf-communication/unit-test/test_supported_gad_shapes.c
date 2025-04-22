#ifndef supported_gad_shapes_TEST
#define supported_gad_shapes_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define supported_gad_shapes_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/supported_gad_shapes.h"
supported_gad_shapes_t *instantiate_supported_gad_shapes(int include_optional);



supported_gad_shapes_t *instantiate_supported_gad_shapes(int include_optional) {
	supported_gad_shapes_t *supported_gad_shapes = NULL;
	if(include_optional) {
		supported_gad_shapes = supported_gad_shapes_create(
			);
	} else {
		supported_gad_shapes = supported_gad_shapes_create(
			);
	}

	return supported_gad_shapes;
}


#ifdef supported_gad_shapes_MAIN

void test_supported_gad_shapes(int include_optional) {
	supported_gad_shapes_t *supported_gad_shapes_1 =
		instantiate_supported_gad_shapes(include_optional);

	cJSON *jsonsupported_gad_shapes_1 = supported_gad_shapes_convertToJSON(
		supported_gad_shapes_1);
	printf("supported_gad_shapes :\n%s\n",
	       cJSON_Print(jsonsupported_gad_shapes_1));
	supported_gad_shapes_t *supported_gad_shapes_2 =
		supported_gad_shapes_parseFromJSON(jsonsupported_gad_shapes_1);
	cJSON *jsonsupported_gad_shapes_2 = supported_gad_shapes_convertToJSON(
		supported_gad_shapes_2);
	printf("repeating supported_gad_shapes:\n%s\n",
	       cJSON_Print(jsonsupported_gad_shapes_2));
}

int main() {
	test_supported_gad_shapes(1);
	test_supported_gad_shapes(0);

	printf("Hello world \n");
	return 0;
}

#endif // supported_gad_shapes_MAIN
#endif // supported_gad_shapes_TEST
