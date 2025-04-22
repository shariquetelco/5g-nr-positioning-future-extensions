#ifndef area_of_validity_TEST
#define area_of_validity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define area_of_validity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/area_of_validity.h"
area_of_validity_t *instantiate_area_of_validity(int include_optional);



area_of_validity_t *instantiate_area_of_validity(int include_optional) {
	area_of_validity_t *area_of_validity = NULL;
	if(include_optional) {
		area_of_validity = area_of_validity_create(
			list_createList(),
			list_createList()
			);
	} else {
		area_of_validity = area_of_validity_create(
			list_createList(),
			list_createList()
			);
	}

	return area_of_validity;
}


#ifdef area_of_validity_MAIN

void test_area_of_validity(int include_optional) {
	area_of_validity_t *area_of_validity_1 = instantiate_area_of_validity(
		include_optional);

	cJSON *jsonarea_of_validity_1 = area_of_validity_convertToJSON(
		area_of_validity_1);
	printf("area_of_validity :\n%s\n", cJSON_Print(jsonarea_of_validity_1));
	area_of_validity_t *area_of_validity_2 = area_of_validity_parseFromJSON(
		jsonarea_of_validity_1);
	cJSON *jsonarea_of_validity_2 = area_of_validity_convertToJSON(
		area_of_validity_2);
	printf("repeating area_of_validity:\n%s\n",
	       cJSON_Print(jsonarea_of_validity_2));
}

int main() {
	test_area_of_validity(1);
	test_area_of_validity(0);

	printf("Hello world \n");
	return 0;
}

#endif // area_of_validity_MAIN
#endif // area_of_validity_TEST
