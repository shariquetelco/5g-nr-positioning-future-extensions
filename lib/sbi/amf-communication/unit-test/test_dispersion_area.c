#ifndef dispersion_area_TEST
#define dispersion_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_area.h"
dispersion_area_t *instantiate_dispersion_area(int include_optional);



dispersion_area_t *instantiate_dispersion_area(int include_optional) {
	dispersion_area_t *dispersion_area = NULL;
	if(include_optional) {
		dispersion_area = dispersion_area_create(
			list_createList(),
			list_createList(),
			list_createList(),
			1
			);
	} else {
		dispersion_area = dispersion_area_create(
			list_createList(),
			list_createList(),
			list_createList(),
			1
			);
	}

	return dispersion_area;
}


#ifdef dispersion_area_MAIN

void test_dispersion_area(int include_optional) {
	dispersion_area_t *dispersion_area_1 = instantiate_dispersion_area(
		include_optional);

	cJSON *jsondispersion_area_1 = dispersion_area_convertToJSON(
		dispersion_area_1);
	printf("dispersion_area :\n%s\n", cJSON_Print(jsondispersion_area_1));
	dispersion_area_t *dispersion_area_2 = dispersion_area_parseFromJSON(
		jsondispersion_area_1);
	cJSON *jsondispersion_area_2 = dispersion_area_convertToJSON(
		dispersion_area_2);
	printf("repeating dispersion_area:\n%s\n",
	       cJSON_Print(jsondispersion_area_2));
}

int main() {
	test_dispersion_area(1);
	test_dispersion_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_area_MAIN
#endif // dispersion_area_TEST
