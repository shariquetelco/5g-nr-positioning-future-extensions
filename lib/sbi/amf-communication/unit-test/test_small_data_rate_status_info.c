#ifndef small_data_rate_status_info_TEST
#define small_data_rate_status_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define small_data_rate_status_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/small_data_rate_status_info.h"
small_data_rate_status_info_t *instantiate_small_data_rate_status_info(
	int include_optional);

#include "test_snssai.c"
#include "test_small_data_rate_status.c"


small_data_rate_status_info_t *instantiate_small_data_rate_status_info(
	int include_optional) {
	small_data_rate_status_info_t *small_data_rate_status_info = NULL;
	if(include_optional) {
		small_data_rate_status_info =
			small_data_rate_status_info_create(
				// false, not to have infinite recursion
				instantiate_snssai(0),
				"0",
				// false, not to have infinite recursion
				instantiate_small_data_rate_status(0)
				);
	} else {
		small_data_rate_status_info =
			small_data_rate_status_info_create(
				NULL,
				"0",
				NULL
				);
	}

	return small_data_rate_status_info;
}


#ifdef small_data_rate_status_info_MAIN

void test_small_data_rate_status_info(int include_optional) {
	small_data_rate_status_info_t *small_data_rate_status_info_1 =
		instantiate_small_data_rate_status_info(include_optional);

	cJSON *jsonsmall_data_rate_status_info_1 =
		small_data_rate_status_info_convertToJSON(
			small_data_rate_status_info_1);
	printf("small_data_rate_status_info :\n%s\n",
	       cJSON_Print(jsonsmall_data_rate_status_info_1));
	small_data_rate_status_info_t *small_data_rate_status_info_2 =
		small_data_rate_status_info_parseFromJSON(
			jsonsmall_data_rate_status_info_1);
	cJSON *jsonsmall_data_rate_status_info_2 =
		small_data_rate_status_info_convertToJSON(
			small_data_rate_status_info_2);
	printf("repeating small_data_rate_status_info:\n%s\n",
	       cJSON_Print(jsonsmall_data_rate_status_info_2));
}

int main() {
	test_small_data_rate_status_info(1);
	test_small_data_rate_status_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // small_data_rate_status_info_MAIN
#endif // small_data_rate_status_info_TEST
