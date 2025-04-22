#ifndef gad_shape_TEST
#define gad_shape_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gad_shape_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gad_shape.h"
gad_shape_t *instantiate_gad_shape(int include_optional);



gad_shape_t *instantiate_gad_shape(int include_optional) {
	gad_shape_t *gad_shape = NULL;
	if(include_optional) {
		gad_shape = gad_shape_create(
			ngmlc_location_gad_shape__POINT
			);
	} else {
		gad_shape = gad_shape_create(
			ngmlc_location_gad_shape__POINT
			);
	}

	return gad_shape;
}


#ifdef gad_shape_MAIN

void test_gad_shape(int include_optional) {
	gad_shape_t *gad_shape_1 = instantiate_gad_shape(include_optional);

	cJSON *jsongad_shape_1 = gad_shape_convertToJSON(gad_shape_1);
	printf("gad_shape :\n%s\n", cJSON_Print(jsongad_shape_1));
	gad_shape_t *gad_shape_2 = gad_shape_parseFromJSON(jsongad_shape_1);
	cJSON *jsongad_shape_2 = gad_shape_convertToJSON(gad_shape_2);
	printf("repeating gad_shape:\n%s\n", cJSON_Print(jsongad_shape_2));
}

int main() {
	test_gad_shape(1);
	test_gad_shape(0);

	printf("Hello world \n");
	return 0;
}

#endif // gad_shape_MAIN
#endif // gad_shape_TEST
