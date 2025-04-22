#ifndef polygon_all_of_TEST
#define polygon_all_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define polygon_all_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/polygon_all_of.h"
polygon_all_of_t *instantiate_polygon_all_of(int include_optional);



polygon_all_of_t *instantiate_polygon_all_of(int include_optional) {
	polygon_all_of_t *polygon_all_of = NULL;
	if(include_optional) {
		polygon_all_of = polygon_all_of_create(
			list_createList()
			);
	} else {
		polygon_all_of = polygon_all_of_create(
			list_createList()
			);
	}

	return polygon_all_of;
}


#ifdef polygon_all_of_MAIN

void test_polygon_all_of(int include_optional) {
	polygon_all_of_t *polygon_all_of_1 = instantiate_polygon_all_of(
		include_optional);

	cJSON *jsonpolygon_all_of_1 = polygon_all_of_convertToJSON(
		polygon_all_of_1);
	printf("polygon_all_of :\n%s\n", cJSON_Print(jsonpolygon_all_of_1));
	polygon_all_of_t *polygon_all_of_2 = polygon_all_of_parseFromJSON(
		jsonpolygon_all_of_1);
	cJSON *jsonpolygon_all_of_2 = polygon_all_of_convertToJSON(
		polygon_all_of_2);
	printf("repeating polygon_all_of:\n%s\n",
	       cJSON_Print(jsonpolygon_all_of_2));
}

int main() {
	test_polygon_all_of(1);
	test_polygon_all_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // polygon_all_of_MAIN
#endif // polygon_all_of_TEST
