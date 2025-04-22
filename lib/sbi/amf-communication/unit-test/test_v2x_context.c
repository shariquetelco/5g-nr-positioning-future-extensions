#ifndef v2x_context_TEST
#define v2x_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2x_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2x_context.h"
v2x_context_t *instantiate_v2x_context(int include_optional);

#include "test_nr_v2x_auth.c"
#include "test_lte_v2x_auth.c"
#include "test_pc5_qo_s_para.c"


v2x_context_t *instantiate_v2x_context(int include_optional) {
	v2x_context_t *v2x_context = NULL;
	if(include_optional) {
		v2x_context = v2x_context_create(
			// false, not to have infinite recursion
			instantiate_nr_v2x_auth(0),
			// false, not to have infinite recursion
			instantiate_lte_v2x_auth(0),
			"a",
			"a",
			// false, not to have infinite recursion
			instantiate_pc5_qo_s_para(0)
			);
	} else {
		v2x_context = v2x_context_create(
			NULL,
			NULL,
			"a",
			"a",
			NULL
			);
	}

	return v2x_context;
}


#ifdef v2x_context_MAIN

void test_v2x_context(int include_optional) {
	v2x_context_t *v2x_context_1 =
		instantiate_v2x_context(include_optional);

	cJSON *jsonv2x_context_1 = v2x_context_convertToJSON(v2x_context_1);
	printf("v2x_context :\n%s\n", cJSON_Print(jsonv2x_context_1));
	v2x_context_t *v2x_context_2 = v2x_context_parseFromJSON(
		jsonv2x_context_1);
	cJSON *jsonv2x_context_2 = v2x_context_convertToJSON(v2x_context_2);
	printf("repeating v2x_context:\n%s\n", cJSON_Print(jsonv2x_context_2));
}

int main() {
	test_v2x_context(1);
	test_v2x_context(0);

	printf("Hello world \n");
	return 0;
}

#endif // v2x_context_MAIN
#endif // v2x_context_TEST
