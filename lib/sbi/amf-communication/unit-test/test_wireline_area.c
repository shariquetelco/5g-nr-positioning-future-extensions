#ifndef wireline_area_TEST
#define wireline_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wireline_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wireline_area.h"
wireline_area_t *instantiate_wireline_area(int include_optional);



wireline_area_t *instantiate_wireline_area(int include_optional) {
	wireline_area_t *wireline_area = NULL;
	if(include_optional) {
		wireline_area = wireline_area_create(
			list_createList(),
			list_createList(),
			"0",
			"0",
			list_createList()
			);
	} else {
		wireline_area = wireline_area_create(
			list_createList(),
			list_createList(),
			"0",
			"0",
			list_createList()
			);
	}

	return wireline_area;
}


#ifdef wireline_area_MAIN

void test_wireline_area(int include_optional) {
	wireline_area_t *wireline_area_1 = instantiate_wireline_area(
		include_optional);

	cJSON *jsonwireline_area_1 =
		wireline_area_convertToJSON(wireline_area_1);
	printf("wireline_area :\n%s\n", cJSON_Print(jsonwireline_area_1));
	wireline_area_t *wireline_area_2 = wireline_area_parseFromJSON(
		jsonwireline_area_1);
	cJSON *jsonwireline_area_2 =
		wireline_area_convertToJSON(wireline_area_2);
	printf("repeating wireline_area:\n%s\n", cJSON_Print(
		       jsonwireline_area_2));
}

int main() {
	test_wireline_area(1);
	test_wireline_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // wireline_area_MAIN
#endif // wireline_area_TEST
