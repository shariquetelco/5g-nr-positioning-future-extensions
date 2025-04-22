#ifndef a2x_context_TEST
#define a2x_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define a2x_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/a2x_context.h"
a2x_context_t *instantiate_a2x_context(int include_optional);

#include "test_nr_a2x_auth.c"
#include "test_lte_a2x_auth.c"
#include "test_pc5_qo_s_para.c"


a2x_context_t *instantiate_a2x_context(int include_optional) {
	a2x_context_t *a2x_context = NULL;
	if(include_optional) {
		a2x_context = a2x_context_create(
			// false, not to have infinite recursion
			instantiate_nr_a2x_auth(0),
			// false, not to have infinite recursion
			instantiate_lte_a2x_auth(0),
			"a",
			"a",
			// false, not to have infinite recursion
			instantiate_pc5_qo_s_para(0)
			);
	} else {
		a2x_context = a2x_context_create(
			NULL,
			NULL,
			"a",
			"a",
			NULL
			);
	}

	return a2x_context;
}


#ifdef a2x_context_MAIN

void test_a2x_context(int include_optional) {
	a2x_context_t *a2x_context_1 =
		instantiate_a2x_context(include_optional);

	cJSON *jsona2x_context_1 = a2x_context_convertToJSON(a2x_context_1);
	printf("a2x_context :\n%s\n", cJSON_Print(jsona2x_context_1));
	a2x_context_t *a2x_context_2 = a2x_context_parseFromJSON(
		jsona2x_context_1);
	cJSON *jsona2x_context_2 = a2x_context_convertToJSON(a2x_context_2);
	printf("repeating a2x_context:\n%s\n", cJSON_Print(jsona2x_context_2));
}

int main() {
	test_a2x_context(1);
	test_a2x_context(0);

	printf("Hello world \n");
	return 0;
}

#endif // a2x_context_MAIN
#endif // a2x_context_TEST
