#ifndef dispersion_class_one_of_TEST
#define dispersion_class_one_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_class_one_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_class_one_of.h"
dispersion_class_one_of_t *instantiate_dispersion_class_one_of(
	int include_optional);



dispersion_class_one_of_t *instantiate_dispersion_class_one_of(
	int include_optional) {
	dispersion_class_one_of_t *dispersion_class_one_of = NULL;
	if(include_optional) {
		dispersion_class_one_of = dispersion_class_one_of_create(
			);
	} else {
		dispersion_class_one_of = dispersion_class_one_of_create(
			);
	}

	return dispersion_class_one_of;
}


#ifdef dispersion_class_one_of_MAIN

void test_dispersion_class_one_of(int include_optional) {
	dispersion_class_one_of_t *dispersion_class_one_of_1 =
		instantiate_dispersion_class_one_of(include_optional);

	cJSON *jsondispersion_class_one_of_1 =
		dispersion_class_one_of_convertToJSON(dispersion_class_one_of_1);
	printf("dispersion_class_one_of :\n%s\n",
	       cJSON_Print(jsondispersion_class_one_of_1));
	dispersion_class_one_of_t *dispersion_class_one_of_2 =
		dispersion_class_one_of_parseFromJSON(
			jsondispersion_class_one_of_1);
	cJSON *jsondispersion_class_one_of_2 =
		dispersion_class_one_of_convertToJSON(dispersion_class_one_of_2);
	printf("repeating dispersion_class_one_of:\n%s\n",
	       cJSON_Print(jsondispersion_class_one_of_2));
}

int main() {
	test_dispersion_class_one_of(1);
	test_dispersion_class_one_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_class_one_of_MAIN
#endif // dispersion_class_one_of_TEST
