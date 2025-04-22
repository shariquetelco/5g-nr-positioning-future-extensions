#ifndef dispersion_type_one_of_TEST
#define dispersion_type_one_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_type_one_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_type_one_of.h"
dispersion_type_one_of_t *instantiate_dispersion_type_one_of(
	int include_optional);



dispersion_type_one_of_t *instantiate_dispersion_type_one_of(
	int include_optional) {
	dispersion_type_one_of_t *dispersion_type_one_of = NULL;
	if(include_optional) {
		dispersion_type_one_of = dispersion_type_one_of_create(
			);
	} else {
		dispersion_type_one_of = dispersion_type_one_of_create(
			);
	}

	return dispersion_type_one_of;
}


#ifdef dispersion_type_one_of_MAIN

void test_dispersion_type_one_of(int include_optional) {
	dispersion_type_one_of_t *dispersion_type_one_of_1 =
		instantiate_dispersion_type_one_of(include_optional);

	cJSON *jsondispersion_type_one_of_1 =
		dispersion_type_one_of_convertToJSON(dispersion_type_one_of_1);
	printf("dispersion_type_one_of :\n%s\n",
	       cJSON_Print(jsondispersion_type_one_of_1));
	dispersion_type_one_of_t *dispersion_type_one_of_2 =
		dispersion_type_one_of_parseFromJSON(
			jsondispersion_type_one_of_1);
	cJSON *jsondispersion_type_one_of_2 =
		dispersion_type_one_of_convertToJSON(dispersion_type_one_of_2);
	printf("repeating dispersion_type_one_of:\n%s\n",
	       cJSON_Print(jsondispersion_type_one_of_2));
}

int main() {
	test_dispersion_type_one_of(1);
	test_dispersion_type_one_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_type_one_of_MAIN
#endif // dispersion_type_one_of_TEST
