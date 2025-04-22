#ifndef geographical_area_TEST
#define geographical_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define geographical_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/geographical_area.h"
geographical_area_t *instantiate_geographical_area(int include_optional);

#include "test_civic_address.c"
#include "test_geographic_area.c"


geographical_area_t *instantiate_geographical_area(int include_optional) {
	geographical_area_t *geographical_area = NULL;
	if(include_optional) {
		geographical_area = geographical_area_create(
			// false, not to have infinite recursion
			instantiate_civic_address(0),
			null
			);
	} else {
		geographical_area = geographical_area_create(
			NULL,
			null
			);
	}

	return geographical_area;
}


#ifdef geographical_area_MAIN

void test_geographical_area(int include_optional) {
	geographical_area_t *geographical_area_1 =
		instantiate_geographical_area(include_optional);

	cJSON *jsongeographical_area_1 = geographical_area_convertToJSON(
		geographical_area_1);
	printf("geographical_area :\n%s\n",
	       cJSON_Print(jsongeographical_area_1));
	geographical_area_t *geographical_area_2 =
		geographical_area_parseFromJSON(jsongeographical_area_1);
	cJSON *jsongeographical_area_2 = geographical_area_convertToJSON(
		geographical_area_2);
	printf("repeating geographical_area:\n%s\n",
	       cJSON_Print(jsongeographical_area_2));
}

int main() {
	test_geographical_area(1);
	test_geographical_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // geographical_area_MAIN
#endif // geographical_area_TEST
