#ifndef area_scope_TEST
#define area_scope_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define area_scope_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/area_scope.h"
area_scope_t *instantiate_area_scope(int include_optional);



area_scope_t *instantiate_area_scope(int include_optional) {
	area_scope_t *area_scope = NULL;
	if(include_optional) {
		area_scope = area_scope_create(
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		area_scope = area_scope_create(
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return area_scope;
}


#ifdef area_scope_MAIN

void test_area_scope(int include_optional) {
	area_scope_t *area_scope_1 = instantiate_area_scope(include_optional);

	cJSON *jsonarea_scope_1 = area_scope_convertToJSON(area_scope_1);
	printf("area_scope :\n%s\n", cJSON_Print(jsonarea_scope_1));
	area_scope_t *area_scope_2 = area_scope_parseFromJSON(jsonarea_scope_1);
	cJSON *jsonarea_scope_2 = area_scope_convertToJSON(area_scope_2);
	printf("repeating area_scope:\n%s\n", cJSON_Print(jsonarea_scope_2));
}

int main() {
	test_area_scope(1);
	test_area_scope(0);

	printf("Hello world \n");
	return 0;
}

#endif // area_scope_MAIN
#endif // area_scope_TEST
