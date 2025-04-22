#ifndef point_altitude_all_of_TEST
#define point_altitude_all_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define point_altitude_all_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/point_altitude_all_of.h"
point_altitude_all_of_t *instantiate_point_altitude_all_of(
	int include_optional);

#include "test_geographical_coordinates.c"


point_altitude_all_of_t *instantiate_point_altitude_all_of(int include_optional)
{
	point_altitude_all_of_t *point_altitude_all_of = NULL;
	if(include_optional) {
		point_altitude_all_of = point_altitude_all_of_create(
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			-32767
			);
	} else {
		point_altitude_all_of = point_altitude_all_of_create(
			NULL,
			-32767
			);
	}

	return point_altitude_all_of;
}


#ifdef point_altitude_all_of_MAIN

void test_point_altitude_all_of(int include_optional) {
	point_altitude_all_of_t *point_altitude_all_of_1 =
		instantiate_point_altitude_all_of(include_optional);

	cJSON *jsonpoint_altitude_all_of_1 =
		point_altitude_all_of_convertToJSON(point_altitude_all_of_1);
	printf("point_altitude_all_of :\n%s\n",
	       cJSON_Print(jsonpoint_altitude_all_of_1));
	point_altitude_all_of_t *point_altitude_all_of_2 =
		point_altitude_all_of_parseFromJSON(jsonpoint_altitude_all_of_1);
	cJSON *jsonpoint_altitude_all_of_2 =
		point_altitude_all_of_convertToJSON(point_altitude_all_of_2);
	printf("repeating point_altitude_all_of:\n%s\n",
	       cJSON_Print(jsonpoint_altitude_all_of_2));
}

int main() {
	test_point_altitude_all_of(1);
	test_point_altitude_all_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // point_altitude_all_of_MAIN
#endif // point_altitude_all_of_TEST
