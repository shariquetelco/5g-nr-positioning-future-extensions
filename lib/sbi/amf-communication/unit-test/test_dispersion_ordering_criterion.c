#ifndef dispersion_ordering_criterion_TEST
#define dispersion_ordering_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_ordering_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_ordering_criterion.h"
dispersion_ordering_criterion_t *instantiate_dispersion_ordering_criterion(
	int include_optional);



dispersion_ordering_criterion_t *instantiate_dispersion_ordering_criterion(
	int include_optional) {
	dispersion_ordering_criterion_t *dispersion_ordering_criterion = NULL;
	if(include_optional) {
		dispersion_ordering_criterion =
			dispersion_ordering_criterion_create(
				);
	} else {
		dispersion_ordering_criterion =
			dispersion_ordering_criterion_create(
				);
	}

	return dispersion_ordering_criterion;
}


#ifdef dispersion_ordering_criterion_MAIN

void test_dispersion_ordering_criterion(int include_optional) {
	dispersion_ordering_criterion_t *dispersion_ordering_criterion_1 =
		instantiate_dispersion_ordering_criterion(include_optional);

	cJSON *jsondispersion_ordering_criterion_1 =
		dispersion_ordering_criterion_convertToJSON(
			dispersion_ordering_criterion_1);
	printf("dispersion_ordering_criterion :\n%s\n",
	       cJSON_Print(jsondispersion_ordering_criterion_1));
	dispersion_ordering_criterion_t *dispersion_ordering_criterion_2 =
		dispersion_ordering_criterion_parseFromJSON(
			jsondispersion_ordering_criterion_1);
	cJSON *jsondispersion_ordering_criterion_2 =
		dispersion_ordering_criterion_convertToJSON(
			dispersion_ordering_criterion_2);
	printf("repeating dispersion_ordering_criterion:\n%s\n",
	       cJSON_Print(jsondispersion_ordering_criterion_2));
}

int main() {
	test_dispersion_ordering_criterion(1);
	test_dispersion_ordering_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_ordering_criterion_MAIN
#endif // dispersion_ordering_criterion_TEST
