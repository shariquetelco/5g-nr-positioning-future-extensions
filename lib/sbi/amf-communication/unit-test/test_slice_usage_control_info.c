#ifndef slice_usage_control_info_TEST
#define slice_usage_control_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define slice_usage_control_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/slice_usage_control_info.h"
slice_usage_control_info_t *instantiate_slice_usage_control_info(
	int include_optional);

#include "test_snssai.c"


slice_usage_control_info_t *instantiate_slice_usage_control_info(
	int include_optional) {
	slice_usage_control_info_t *slice_usage_control_info = NULL;
	if(include_optional) {
		slice_usage_control_info = slice_usage_control_info_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			56,
			56
			);
	} else {
		slice_usage_control_info = slice_usage_control_info_create(
			NULL,
			56,
			56
			);
	}

	return slice_usage_control_info;
}


#ifdef slice_usage_control_info_MAIN

void test_slice_usage_control_info(int include_optional) {
	slice_usage_control_info_t *slice_usage_control_info_1 =
		instantiate_slice_usage_control_info(include_optional);

	cJSON *jsonslice_usage_control_info_1 =
		slice_usage_control_info_convertToJSON(
			slice_usage_control_info_1);
	printf("slice_usage_control_info :\n%s\n",
	       cJSON_Print(jsonslice_usage_control_info_1));
	slice_usage_control_info_t *slice_usage_control_info_2 =
		slice_usage_control_info_parseFromJSON(
			jsonslice_usage_control_info_1);
	cJSON *jsonslice_usage_control_info_2 =
		slice_usage_control_info_convertToJSON(
			slice_usage_control_info_2);
	printf("repeating slice_usage_control_info:\n%s\n",
	       cJSON_Print(jsonslice_usage_control_info_2));
}

int main() {
	test_slice_usage_control_info(1);
	test_slice_usage_control_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // slice_usage_control_info_MAIN
#endif // slice_usage_control_info_TEST
