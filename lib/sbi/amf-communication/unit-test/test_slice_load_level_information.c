#ifndef slice_load_level_information_TEST
#define slice_load_level_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define slice_load_level_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/slice_load_level_information.h"
slice_load_level_information_t *instantiate_slice_load_level_information(
	int include_optional);



slice_load_level_information_t *instantiate_slice_load_level_information(
	int include_optional) {
	slice_load_level_information_t *slice_load_level_information = NULL;
	if(include_optional) {
		slice_load_level_information =
			slice_load_level_information_create(
				56,
				list_createList()
				);
	} else {
		slice_load_level_information =
			slice_load_level_information_create(
				56,
				list_createList()
				);
	}

	return slice_load_level_information;
}


#ifdef slice_load_level_information_MAIN

void test_slice_load_level_information(int include_optional) {
	slice_load_level_information_t *slice_load_level_information_1 =
		instantiate_slice_load_level_information(include_optional);

	cJSON *jsonslice_load_level_information_1 =
		slice_load_level_information_convertToJSON(
			slice_load_level_information_1);
	printf("slice_load_level_information :\n%s\n",
	       cJSON_Print(jsonslice_load_level_information_1));
	slice_load_level_information_t *slice_load_level_information_2 =
		slice_load_level_information_parseFromJSON(
			jsonslice_load_level_information_1);
	cJSON *jsonslice_load_level_information_2 =
		slice_load_level_information_convertToJSON(
			slice_load_level_information_2);
	printf("repeating slice_load_level_information:\n%s\n",
	       cJSON_Print(jsonslice_load_level_information_2));
}

int main() {
	test_slice_load_level_information(1);
	test_slice_load_level_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // slice_load_level_information_MAIN
#endif // slice_load_level_information_TEST
