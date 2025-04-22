#ifndef allowed_snssai_TEST
#define allowed_snssai_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define allowed_snssai_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/allowed_snssai.h"
allowed_snssai_t *instantiate_allowed_snssai(int include_optional);

#include "test_snssai.c"
#include "test_snssai.c"


allowed_snssai_t *instantiate_allowed_snssai(int include_optional) {
	allowed_snssai_t *allowed_snssai = NULL;
	if(include_optional) {
		allowed_snssai = allowed_snssai_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_snssai(0)
			);
	} else {
		allowed_snssai = allowed_snssai_create(
			NULL,
			list_createList(),
			NULL
			);
	}

	return allowed_snssai;
}


#ifdef allowed_snssai_MAIN

void test_allowed_snssai(int include_optional) {
	allowed_snssai_t *allowed_snssai_1 = instantiate_allowed_snssai(
		include_optional);

	cJSON *jsonallowed_snssai_1 = allowed_snssai_convertToJSON(
		allowed_snssai_1);
	printf("allowed_snssai :\n%s\n", cJSON_Print(jsonallowed_snssai_1));
	allowed_snssai_t *allowed_snssai_2 = allowed_snssai_parseFromJSON(
		jsonallowed_snssai_1);
	cJSON *jsonallowed_snssai_2 = allowed_snssai_convertToJSON(
		allowed_snssai_2);
	printf("repeating allowed_snssai:\n%s\n",
	       cJSON_Print(jsonallowed_snssai_2));
}

int main() {
	test_allowed_snssai(1);
	test_allowed_snssai(0);

	printf("Hello world \n");
	return 0;
}

#endif // allowed_snssai_MAIN
#endif // allowed_snssai_TEST
