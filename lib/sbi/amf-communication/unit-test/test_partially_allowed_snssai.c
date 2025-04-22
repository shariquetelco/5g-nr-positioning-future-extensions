#ifndef partially_allowed_snssai_TEST
#define partially_allowed_snssai_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partially_allowed_snssai_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partially_allowed_snssai.h"
partially_allowed_snssai_t *instantiate_partially_allowed_snssai(
	int include_optional);

#include "test_snssai.c"


partially_allowed_snssai_t *instantiate_partially_allowed_snssai(
	int include_optional) {
	partially_allowed_snssai_t *partially_allowed_snssai = NULL;
	if(include_optional) {
		partially_allowed_snssai = partially_allowed_snssai_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList()
			);
	} else {
		partially_allowed_snssai = partially_allowed_snssai_create(
			NULL,
			list_createList()
			);
	}

	return partially_allowed_snssai;
}


#ifdef partially_allowed_snssai_MAIN

void test_partially_allowed_snssai(int include_optional) {
	partially_allowed_snssai_t *partially_allowed_snssai_1 =
		instantiate_partially_allowed_snssai(include_optional);

	cJSON *jsonpartially_allowed_snssai_1 =
		partially_allowed_snssai_convertToJSON(
			partially_allowed_snssai_1);
	printf("partially_allowed_snssai :\n%s\n",
	       cJSON_Print(jsonpartially_allowed_snssai_1));
	partially_allowed_snssai_t *partially_allowed_snssai_2 =
		partially_allowed_snssai_parseFromJSON(
			jsonpartially_allowed_snssai_1);
	cJSON *jsonpartially_allowed_snssai_2 =
		partially_allowed_snssai_convertToJSON(
			partially_allowed_snssai_2);
	printf("repeating partially_allowed_snssai:\n%s\n",
	       cJSON_Print(jsonpartially_allowed_snssai_2));
}

int main() {
	test_partially_allowed_snssai(1);
	test_partially_allowed_snssai(0);

	printf("Hello world \n");
	return 0;
}

#endif // partially_allowed_snssai_MAIN
#endif // partially_allowed_snssai_TEST
