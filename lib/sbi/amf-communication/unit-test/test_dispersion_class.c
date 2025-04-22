#ifndef dispersion_class_TEST
#define dispersion_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_class.h"
dispersion_class_t *instantiate_dispersion_class(int include_optional);



dispersion_class_t *instantiate_dispersion_class(int include_optional) {
	dispersion_class_t *dispersion_class = NULL;
	if(include_optional) {
		dispersion_class = dispersion_class_create(
			);
	} else {
		dispersion_class = dispersion_class_create(
			);
	}

	return dispersion_class;
}


#ifdef dispersion_class_MAIN

void test_dispersion_class(int include_optional) {
	dispersion_class_t *dispersion_class_1 = instantiate_dispersion_class(
		include_optional);

	cJSON *jsondispersion_class_1 = dispersion_class_convertToJSON(
		dispersion_class_1);
	printf("dispersion_class :\n%s\n", cJSON_Print(jsondispersion_class_1));
	dispersion_class_t *dispersion_class_2 = dispersion_class_parseFromJSON(
		jsondispersion_class_1);
	cJSON *jsondispersion_class_2 = dispersion_class_convertToJSON(
		dispersion_class_2);
	printf("repeating dispersion_class:\n%s\n",
	       cJSON_Print(jsondispersion_class_2));
}

int main() {
	test_dispersion_class(1);
	test_dispersion_class(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_class_MAIN
#endif // dispersion_class_TEST
