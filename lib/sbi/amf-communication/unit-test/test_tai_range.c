#ifndef tai_range_TEST
#define tai_range_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tai_range_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tai_range.h"
tai_range_t *instantiate_tai_range(int include_optional);

#include "test_plmn_id.c"


tai_range_t *instantiate_tai_range(int include_optional) {
	tai_range_t *tai_range = NULL;
	if(include_optional) {
		tai_range = tai_range_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			list_createList(),
			"a"
			);
	} else {
		tai_range = tai_range_create(
			NULL,
			list_createList(),
			"a"
			);
	}

	return tai_range;
}


#ifdef tai_range_MAIN

void test_tai_range(int include_optional) {
	tai_range_t *tai_range_1 = instantiate_tai_range(include_optional);

	cJSON *jsontai_range_1 = tai_range_convertToJSON(tai_range_1);
	printf("tai_range :\n%s\n", cJSON_Print(jsontai_range_1));
	tai_range_t *tai_range_2 = tai_range_parseFromJSON(jsontai_range_1);
	cJSON *jsontai_range_2 = tai_range_convertToJSON(tai_range_2);
	printf("repeating tai_range:\n%s\n", cJSON_Print(jsontai_range_2));
}

int main() {
	test_tai_range(1);
	test_tai_range(0);

	printf("Hello world \n");
	return 0;
}

#endif // tai_range_MAIN
#endif // tai_range_TEST
