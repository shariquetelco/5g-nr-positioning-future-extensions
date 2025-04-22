#ifndef point_TEST
#define point_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define point_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/point.h"
point_t *instantiate_point(int include_optional);

#include "test_geographical_coordinates.c"


point_t *instantiate_point(int include_optional) {
	point_t *point = NULL;
	if(include_optional) {
		point = point_create(
			ngmlc_location_point__POINT,
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0)
			);
	} else {
		point = point_create(
			ngmlc_location_point__POINT,
			NULL
			);
	}

	return point;
}


#ifdef point_MAIN

void test_point(int include_optional) {
	point_t *point_1 = instantiate_point(include_optional);

	cJSON *jsonpoint_1 = point_convertToJSON(point_1);
	printf("point :\n%s\n", cJSON_Print(jsonpoint_1));
	point_t *point_2 = point_parseFromJSON(jsonpoint_1);
	cJSON *jsonpoint_2 = point_convertToJSON(point_2);
	printf("repeating point:\n%s\n", cJSON_Print(jsonpoint_2));
}

int main() {
	test_point(1);
	test_point(0);

	printf("Hello world \n");
	return 0;
}

#endif // point_MAIN
#endif // point_TEST
