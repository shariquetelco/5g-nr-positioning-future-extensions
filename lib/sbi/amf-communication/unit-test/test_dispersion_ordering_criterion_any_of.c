#ifndef dispersion_ordering_criterion_any_of_TEST
#define dispersion_ordering_criterion_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_ordering_criterion_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_ordering_criterion_any_of.h"
dispersion_ordering_criterion_any_of_t *
instantiate_dispersion_ordering_criterion_any_of(int include_optional);



dispersion_ordering_criterion_any_of_t *
instantiate_dispersion_ordering_criterion_any_of(int include_optional) {
	dispersion_ordering_criterion_any_of_t *
	        dispersion_ordering_criterion_any_of = NULL;
	if(include_optional) {
		dispersion_ordering_criterion_any_of =
			dispersion_ordering_criterion_any_of_create(
				);
	} else {
		dispersion_ordering_criterion_any_of =
			dispersion_ordering_criterion_any_of_create(
				);
	}

	return dispersion_ordering_criterion_any_of;
}


#ifdef dispersion_ordering_criterion_any_of_MAIN

void test_dispersion_ordering_criterion_any_of(int include_optional) {
	dispersion_ordering_criterion_any_of_t *
	        dispersion_ordering_criterion_any_of_1 =
		instantiate_dispersion_ordering_criterion_any_of(
			include_optional);

	cJSON *jsondispersion_ordering_criterion_any_of_1 =
		dispersion_ordering_criterion_any_of_convertToJSON(
			dispersion_ordering_criterion_any_of_1);
	printf("dispersion_ordering_criterion_any_of :\n%s\n",
	       cJSON_Print(jsondispersion_ordering_criterion_any_of_1));
	dispersion_ordering_criterion_any_of_t *
	        dispersion_ordering_criterion_any_of_2 =
		dispersion_ordering_criterion_any_of_parseFromJSON(
			jsondispersion_ordering_criterion_any_of_1);
	cJSON *jsondispersion_ordering_criterion_any_of_2 =
		dispersion_ordering_criterion_any_of_convertToJSON(
			dispersion_ordering_criterion_any_of_2);
	printf("repeating dispersion_ordering_criterion_any_of:\n%s\n", cJSON_Print(
		       jsondispersion_ordering_criterion_any_of_2));
}

int main() {
	test_dispersion_ordering_criterion_any_of(1);
	test_dispersion_ordering_criterion_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_ordering_criterion_any_of_MAIN
#endif // dispersion_ordering_criterion_any_of_TEST
