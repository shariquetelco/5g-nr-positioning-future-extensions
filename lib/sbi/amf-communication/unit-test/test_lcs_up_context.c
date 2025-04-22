#ifndef lcs_up_context_TEST
#define lcs_up_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lcs_up_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lcs_up_context.h"
lcs_up_context_t *instantiate_lcs_up_context(int include_optional);

#include "test_up_connection_status.c"


lcs_up_context_t *instantiate_lcs_up_context(int include_optional) {
	lcs_up_context_t *lcs_up_context = NULL;
	if(include_optional) {
		lcs_up_context = lcs_up_context_create(
			null,
			"0"
			);
	} else {
		lcs_up_context = lcs_up_context_create(
			null,
			"0"
			);
	}

	return lcs_up_context;
}


#ifdef lcs_up_context_MAIN

void test_lcs_up_context(int include_optional) {
	lcs_up_context_t *lcs_up_context_1 = instantiate_lcs_up_context(
		include_optional);

	cJSON *jsonlcs_up_context_1 = lcs_up_context_convertToJSON(
		lcs_up_context_1);
	printf("lcs_up_context :\n%s\n", cJSON_Print(jsonlcs_up_context_1));
	lcs_up_context_t *lcs_up_context_2 = lcs_up_context_parseFromJSON(
		jsonlcs_up_context_1);
	cJSON *jsonlcs_up_context_2 = lcs_up_context_convertToJSON(
		lcs_up_context_2);
	printf("repeating lcs_up_context:\n%s\n",
	       cJSON_Print(jsonlcs_up_context_2));
}

int main() {
	test_lcs_up_context(1);
	test_lcs_up_context(0);

	printf("Hello world \n");
	return 0;
}

#endif // lcs_up_context_MAIN
#endif // lcs_up_context_TEST
