#ifndef tai_TEST
#define tai_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tai_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tai.h"
tai_t *instantiate_tai(int include_optional);

#include "test_plmn_id.c"


tai_t *instantiate_tai(int include_optional) {
	tai_t *tai = NULL;
	if(include_optional) {
		tai = tai_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			"a"
			);
	} else {
		tai = tai_create(
			NULL,
			"a",
			"a"
			);
	}

	return tai;
}


#ifdef tai_MAIN

void test_tai(int include_optional) {
	tai_t *tai_1 = instantiate_tai(include_optional);

	cJSON *jsontai_1 = tai_convertToJSON(tai_1);
	printf("tai :\n%s\n", cJSON_Print(jsontai_1));
	tai_t *tai_2 = tai_parseFromJSON(jsontai_1);
	cJSON *jsontai_2 = tai_convertToJSON(tai_2);
	printf("repeating tai:\n%s\n", cJSON_Print(jsontai_2));
}

int main() {
	test_tai(1);
	test_tai(0);

	printf("Hello world \n");
	return 0;
}

#endif // tai_MAIN
#endif // tai_TEST
