#ifndef polygon_TEST
#define polygon_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define polygon_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/polygon.h"
polygon_t *instantiate_polygon(int include_optional);



polygon_t *instantiate_polygon(int include_optional) {
	polygon_t *polygon = NULL;
	if(include_optional) {
		polygon = polygon_create(
			ngmlc_location_polygon__POINT,
			list_createList()
			);
	} else {
		polygon = polygon_create(
			ngmlc_location_polygon__POINT,
			list_createList()
			);
	}

	return polygon;
}


#ifdef polygon_MAIN

void test_polygon(int include_optional) {
	polygon_t *polygon_1 = instantiate_polygon(include_optional);

	cJSON *jsonpolygon_1 = polygon_convertToJSON(polygon_1);
	printf("polygon :\n%s\n", cJSON_Print(jsonpolygon_1));
	polygon_t *polygon_2 = polygon_parseFromJSON(jsonpolygon_1);
	cJSON *jsonpolygon_2 = polygon_convertToJSON(polygon_2);
	printf("repeating polygon:\n%s\n", cJSON_Print(jsonpolygon_2));
}

int main() {
	test_polygon(1);
	test_polygon(0);

	printf("Hello world \n");
	return 0;
}

#endif // polygon_MAIN
#endif // polygon_TEST
