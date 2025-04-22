#ifndef slice_replacement_mapping_TEST
#define slice_replacement_mapping_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define slice_replacement_mapping_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/slice_replacement_mapping.h"
slice_replacement_mapping_t *instantiate_slice_replacement_mapping(
	int include_optional);

#include "test_snssai.c"
#include "test_snssai.c"


slice_replacement_mapping_t *instantiate_slice_replacement_mapping(
	int include_optional) {
	slice_replacement_mapping_t *slice_replacement_mapping = NULL;
	if(include_optional) {
		slice_replacement_mapping = slice_replacement_mapping_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0)
			);
	} else {
		slice_replacement_mapping = slice_replacement_mapping_create(
			NULL,
			NULL
			);
	}

	return slice_replacement_mapping;
}


#ifdef slice_replacement_mapping_MAIN

void test_slice_replacement_mapping(int include_optional) {
	slice_replacement_mapping_t *slice_replacement_mapping_1 =
		instantiate_slice_replacement_mapping(include_optional);

	cJSON *jsonslice_replacement_mapping_1 =
		slice_replacement_mapping_convertToJSON(
			slice_replacement_mapping_1);
	printf("slice_replacement_mapping :\n%s\n",
	       cJSON_Print(jsonslice_replacement_mapping_1));
	slice_replacement_mapping_t *slice_replacement_mapping_2 =
		slice_replacement_mapping_parseFromJSON(
			jsonslice_replacement_mapping_1);
	cJSON *jsonslice_replacement_mapping_2 =
		slice_replacement_mapping_convertToJSON(
			slice_replacement_mapping_2);
	printf("repeating slice_replacement_mapping:\n%s\n",
	       cJSON_Print(jsonslice_replacement_mapping_2));
}

int main() {
	test_slice_replacement_mapping(1);
	test_slice_replacement_mapping(0);

	printf("Hello world \n");
	return 0;
}

#endif // slice_replacement_mapping_MAIN
#endif // slice_replacement_mapping_TEST
