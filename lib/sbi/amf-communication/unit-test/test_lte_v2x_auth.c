#ifndef lte_v2x_auth_TEST
#define lte_v2x_auth_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lte_v2x_auth_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lte_v2x_auth.h"
lte_v2x_auth_t *instantiate_lte_v2x_auth(int include_optional);

#include "test_ue_auth.c"
#include "test_ue_auth.c"


lte_v2x_auth_t *instantiate_lte_v2x_auth(int include_optional) {
	lte_v2x_auth_t *lte_v2x_auth = NULL;
	if(include_optional) {
		lte_v2x_auth = lte_v2x_auth_create(
			null,
			null
			);
	} else {
		lte_v2x_auth = lte_v2x_auth_create(
			null,
			null
			);
	}

	return lte_v2x_auth;
}


#ifdef lte_v2x_auth_MAIN

void test_lte_v2x_auth(int include_optional) {
	lte_v2x_auth_t *lte_v2x_auth_1 = instantiate_lte_v2x_auth(
		include_optional);

	cJSON *jsonlte_v2x_auth_1 = lte_v2x_auth_convertToJSON(lte_v2x_auth_1);
	printf("lte_v2x_auth :\n%s\n", cJSON_Print(jsonlte_v2x_auth_1));
	lte_v2x_auth_t *lte_v2x_auth_2 = lte_v2x_auth_parseFromJSON(
		jsonlte_v2x_auth_1);
	cJSON *jsonlte_v2x_auth_2 = lte_v2x_auth_convertToJSON(lte_v2x_auth_2);
	printf("repeating lte_v2x_auth:\n%s\n",
	       cJSON_Print(jsonlte_v2x_auth_2));
}

int main() {
	test_lte_v2x_auth(1);
	test_lte_v2x_auth(0);

	printf("Hello world \n");
	return 0;
}

#endif // lte_v2x_auth_MAIN
#endif // lte_v2x_auth_TEST
