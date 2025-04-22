#ifndef mbsr_operation_allowed_TEST
#define mbsr_operation_allowed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mbsr_operation_allowed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mbsr_operation_allowed.h"
mbsr_operation_allowed_t *instantiate_mbsr_operation_allowed(
	int include_optional);

#include "test_mbsr_location_info.c"
#include "test_mbsr_time_info.c"


mbsr_operation_allowed_t *instantiate_mbsr_operation_allowed(
	int include_optional) {
	mbsr_operation_allowed_t *mbsr_operation_allowed = NULL;
	if(include_optional) {
		mbsr_operation_allowed = mbsr_operation_allowed_create(
			1,
			// false, not to have infinite recursion
			instantiate_mbsr_location_info(0),
			// false, not to have infinite recursion
			instantiate_mbsr_time_info(0)
			);
	} else {
		mbsr_operation_allowed = mbsr_operation_allowed_create(
			1,
			NULL,
			NULL
			);
	}

	return mbsr_operation_allowed;
}


#ifdef mbsr_operation_allowed_MAIN

void test_mbsr_operation_allowed(int include_optional) {
	mbsr_operation_allowed_t *mbsr_operation_allowed_1 =
		instantiate_mbsr_operation_allowed(include_optional);

	cJSON *jsonmbsr_operation_allowed_1 =
		mbsr_operation_allowed_convertToJSON(mbsr_operation_allowed_1);
	printf("mbsr_operation_allowed :\n%s\n",
	       cJSON_Print(jsonmbsr_operation_allowed_1));
	mbsr_operation_allowed_t *mbsr_operation_allowed_2 =
		mbsr_operation_allowed_parseFromJSON(
			jsonmbsr_operation_allowed_1);
	cJSON *jsonmbsr_operation_allowed_2 =
		mbsr_operation_allowed_convertToJSON(mbsr_operation_allowed_2);
	printf("repeating mbsr_operation_allowed:\n%s\n",
	       cJSON_Print(jsonmbsr_operation_allowed_2));
}

int main() {
	test_mbsr_operation_allowed(1);
	test_mbsr_operation_allowed(0);

	printf("Hello world \n");
	return 0;
}

#endif // mbsr_operation_allowed_MAIN
#endif // mbsr_operation_allowed_TEST
