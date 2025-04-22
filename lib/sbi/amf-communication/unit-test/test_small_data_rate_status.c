#ifndef small_data_rate_status_TEST
#define small_data_rate_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define small_data_rate_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/small_data_rate_status.h"
small_data_rate_status_t *instantiate_small_data_rate_status(
	int include_optional);



small_data_rate_status_t *instantiate_small_data_rate_status(
	int include_optional) {
	small_data_rate_status_t *small_data_rate_status = NULL;
	if(include_optional) {
		small_data_rate_status = small_data_rate_status_create(
			0,
			0,
			"2013-10-20T19:20:30+01:00",
			0,
			0
			);
	} else {
		small_data_rate_status = small_data_rate_status_create(
			0,
			0,
			"2013-10-20T19:20:30+01:00",
			0,
			0
			);
	}

	return small_data_rate_status;
}


#ifdef small_data_rate_status_MAIN

void test_small_data_rate_status(int include_optional) {
	small_data_rate_status_t *small_data_rate_status_1 =
		instantiate_small_data_rate_status(include_optional);

	cJSON *jsonsmall_data_rate_status_1 =
		small_data_rate_status_convertToJSON(small_data_rate_status_1);
	printf("small_data_rate_status :\n%s\n",
	       cJSON_Print(jsonsmall_data_rate_status_1));
	small_data_rate_status_t *small_data_rate_status_2 =
		small_data_rate_status_parseFromJSON(
			jsonsmall_data_rate_status_1);
	cJSON *jsonsmall_data_rate_status_2 =
		small_data_rate_status_convertToJSON(small_data_rate_status_2);
	printf("repeating small_data_rate_status:\n%s\n",
	       cJSON_Print(jsonsmall_data_rate_status_2));
}

int main() {
	test_small_data_rate_status(1);
	test_small_data_rate_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // small_data_rate_status_MAIN
#endif // small_data_rate_status_TEST
