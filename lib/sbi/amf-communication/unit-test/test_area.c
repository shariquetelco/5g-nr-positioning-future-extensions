#ifndef area_TEST
#define area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/area.h"
area_t *instantiate_area(int include_optional);



area_t *instantiate_area(int include_optional) {
	area_t *area = NULL;
	if(include_optional) {
		area = area_create(
			list_createList(),
			"0"
			);
	} else {
		area = area_create(
			list_createList(),
			"0"
			);
	}

	return area;
}


#ifdef area_MAIN

void test_area(int include_optional) {
	area_t *area_1 = instantiate_area(include_optional);

	cJSON *jsonarea_1 = area_convertToJSON(area_1);
	printf("area :\n%s\n", cJSON_Print(jsonarea_1));
	area_t *area_2 = area_parseFromJSON(jsonarea_1);
	cJSON *jsonarea_2 = area_convertToJSON(area_2);
	printf("repeating area:\n%s\n", cJSON_Print(jsonarea_2));
}

int main() {
	test_area(1);
	test_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // area_MAIN
#endif // area_TEST
