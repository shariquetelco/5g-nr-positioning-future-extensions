#ifndef dispersion_type_TEST
#define dispersion_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_type.h"
dispersion_type_t *instantiate_dispersion_type(int include_optional);



dispersion_type_t *instantiate_dispersion_type(int include_optional) {
	dispersion_type_t *dispersion_type = NULL;
	if(include_optional) {
		dispersion_type = dispersion_type_create(
			);
	} else {
		dispersion_type = dispersion_type_create(
			);
	}

	return dispersion_type;
}


#ifdef dispersion_type_MAIN

void test_dispersion_type(int include_optional) {
	dispersion_type_t *dispersion_type_1 = instantiate_dispersion_type(
		include_optional);

	cJSON *jsondispersion_type_1 = dispersion_type_convertToJSON(
		dispersion_type_1);
	printf("dispersion_type :\n%s\n", cJSON_Print(jsondispersion_type_1));
	dispersion_type_t *dispersion_type_2 = dispersion_type_parseFromJSON(
		jsondispersion_type_1);
	cJSON *jsondispersion_type_2 = dispersion_type_convertToJSON(
		dispersion_type_2);
	printf("repeating dispersion_type:\n%s\n",
	       cJSON_Print(jsondispersion_type_2));
}

int main() {
	test_dispersion_type(1);
	test_dispersion_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_type_MAIN
#endif // dispersion_type_TEST
