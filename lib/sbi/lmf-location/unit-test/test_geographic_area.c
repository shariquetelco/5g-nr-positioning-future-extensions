#ifndef geographic_area_TEST
#define geographic_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define geographic_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/geographic_area.h"
geographic_area_t *instantiate_geographic_area(int include_optional);

#include "test_geographical_coordinates.c"
#include "test_uncertainty_ellipse.c"


geographic_area_t *instantiate_geographic_area(int include_optional) {
	geographic_area_t *geographic_area = NULL;
	if(include_optional) {
		geographic_area = geographic_area_create(
			lmf_location_geographic_area__POINT,
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			0,
			// false, not to have infinite recursion
			instantiate_uncertainty_ellipse(0),
			0,
			list_createList(),
			-32767,
			0,
			0,
			0,
			0,
			0,
			0
			);
	} else {
		geographic_area = geographic_area_create(
			lmf_location_geographic_area__POINT,
			NULL,
			0,
			NULL,
			0,
			list_createList(),
			-32767,
			0,
			0,
			0,
			0,
			0,
			0
			);
	}

	return geographic_area;
}


#ifdef geographic_area_MAIN

void test_geographic_area(int include_optional) {
	geographic_area_t *geographic_area_1 = instantiate_geographic_area(
		include_optional);

	cJSON *jsongeographic_area_1 = geographic_area_convertToJSON(
		geographic_area_1);
	printf("geographic_area :\n%s\n", cJSON_Print(jsongeographic_area_1));
	geographic_area_t *geographic_area_2 = geographic_area_parseFromJSON(
		jsongeographic_area_1);
	cJSON *jsongeographic_area_2 = geographic_area_convertToJSON(
		geographic_area_2);
	printf("repeating geographic_area:\n%s\n",
	       cJSON_Print(jsongeographic_area_2));
}

int main() {
	test_geographic_area(1);
	test_geographic_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // geographic_area_MAIN
#endif // geographic_area_TEST
