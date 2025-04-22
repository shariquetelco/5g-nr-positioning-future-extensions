#ifndef dispersion_requirement_TEST
#define dispersion_requirement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_requirement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_requirement.h"
dispersion_requirement_t *instantiate_dispersion_requirement(
	int include_optional);

#include "test_dispersion_type.c"
#include "test_dispersion_ordering_criterion.c"
#include "test_matching_direction.c"


dispersion_requirement_t *instantiate_dispersion_requirement(
	int include_optional) {
	dispersion_requirement_t *dispersion_requirement = NULL;
	if(include_optional) {
		dispersion_requirement = dispersion_requirement_create(
			null,
			list_createList(),
			list_createList(),
			null,
			null
			);
	} else {
		dispersion_requirement = dispersion_requirement_create(
			null,
			list_createList(),
			list_createList(),
			null,
			null
			);
	}

	return dispersion_requirement;
}


#ifdef dispersion_requirement_MAIN

void test_dispersion_requirement(int include_optional) {
	dispersion_requirement_t *dispersion_requirement_1 =
		instantiate_dispersion_requirement(include_optional);

	cJSON *jsondispersion_requirement_1 =
		dispersion_requirement_convertToJSON(dispersion_requirement_1);
	printf("dispersion_requirement :\n%s\n",
	       cJSON_Print(jsondispersion_requirement_1));
	dispersion_requirement_t *dispersion_requirement_2 =
		dispersion_requirement_parseFromJSON(
			jsondispersion_requirement_1);
	cJSON *jsondispersion_requirement_2 =
		dispersion_requirement_convertToJSON(dispersion_requirement_2);
	printf("repeating dispersion_requirement:\n%s\n",
	       cJSON_Print(jsondispersion_requirement_2));
}

int main() {
	test_dispersion_requirement(1);
	test_dispersion_requirement(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_requirement_MAIN
#endif // dispersion_requirement_TEST
