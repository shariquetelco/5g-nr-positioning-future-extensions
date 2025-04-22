#ifndef geographical_coordinates_TEST
#define geographical_coordinates_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define geographical_coordinates_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/geographical_coordinates.h"
geographical_coordinates_t *instantiate_geographical_coordinates(
	int include_optional);



geographical_coordinates_t *instantiate_geographical_coordinates(
	int include_optional) {
	geographical_coordinates_t *geographical_coordinates = NULL;
	if(include_optional) {
		geographical_coordinates = geographical_coordinates_create(
			-180,
			-90
			);
	} else {
		geographical_coordinates = geographical_coordinates_create(
			-180,
			-90
			);
	}

	return geographical_coordinates;
}


#ifdef geographical_coordinates_MAIN

void test_geographical_coordinates(int include_optional) {
	geographical_coordinates_t *geographical_coordinates_1 =
		instantiate_geographical_coordinates(include_optional);

	cJSON *jsongeographical_coordinates_1 =
		geographical_coordinates_convertToJSON(
			geographical_coordinates_1);
	printf("geographical_coordinates :\n%s\n",
	       cJSON_Print(jsongeographical_coordinates_1));
	geographical_coordinates_t *geographical_coordinates_2 =
		geographical_coordinates_parseFromJSON(
			jsongeographical_coordinates_1);
	cJSON *jsongeographical_coordinates_2 =
		geographical_coordinates_convertToJSON(
			geographical_coordinates_2);
	printf("repeating geographical_coordinates:\n%s\n",
	       cJSON_Print(jsongeographical_coordinates_2));
}

int main() {
	test_geographical_coordinates(1);
	test_geographical_coordinates(0);

	printf("Hello world \n");
	return 0;
}

#endif // geographical_coordinates_MAIN
#endif // geographical_coordinates_TEST
