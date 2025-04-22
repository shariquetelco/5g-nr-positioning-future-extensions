#ifndef slice_mbr_TEST
#define slice_mbr_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define slice_mbr_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/slice_mbr.h"
slice_mbr_t *instantiate_slice_mbr(int include_optional);



slice_mbr_t *instantiate_slice_mbr(int include_optional) {
	slice_mbr_t *slice_mbr = NULL;
	if(include_optional) {
		slice_mbr = slice_mbr_create(
			"a",
			"a"
			);
	} else {
		slice_mbr = slice_mbr_create(
			"a",
			"a"
			);
	}

	return slice_mbr;
}


#ifdef slice_mbr_MAIN

void test_slice_mbr(int include_optional) {
	slice_mbr_t *slice_mbr_1 = instantiate_slice_mbr(include_optional);

	cJSON *jsonslice_mbr_1 = slice_mbr_convertToJSON(slice_mbr_1);
	printf("slice_mbr :\n%s\n", cJSON_Print(jsonslice_mbr_1));
	slice_mbr_t *slice_mbr_2 = slice_mbr_parseFromJSON(jsonslice_mbr_1);
	cJSON *jsonslice_mbr_2 = slice_mbr_convertToJSON(slice_mbr_2);
	printf("repeating slice_mbr:\n%s\n", cJSON_Print(jsonslice_mbr_2));
}

int main() {
	test_slice_mbr(1);
	test_slice_mbr(0);

	printf("Hello world \n");
	return 0;
}

#endif // slice_mbr_MAIN
#endif // slice_mbr_TEST
