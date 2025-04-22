#ifndef lcs_service_auth_TEST
#define lcs_service_auth_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lcs_service_auth_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lcs_service_auth.h"
lcs_service_auth_t *instantiate_lcs_service_auth(int include_optional);



lcs_service_auth_t *instantiate_lcs_service_auth(int include_optional) {
	lcs_service_auth_t *lcs_service_auth = NULL;
	if(include_optional) {
		lcs_service_auth = lcs_service_auth_create(
			);
	} else {
		lcs_service_auth = lcs_service_auth_create(
			);
	}

	return lcs_service_auth;
}


#ifdef lcs_service_auth_MAIN

void test_lcs_service_auth(int include_optional) {
	lcs_service_auth_t *lcs_service_auth_1 = instantiate_lcs_service_auth(
		include_optional);

	cJSON *jsonlcs_service_auth_1 = lcs_service_auth_convertToJSON(
		lcs_service_auth_1);
	printf("lcs_service_auth :\n%s\n", cJSON_Print(jsonlcs_service_auth_1));
	lcs_service_auth_t *lcs_service_auth_2 = lcs_service_auth_parseFromJSON(
		jsonlcs_service_auth_1);
	cJSON *jsonlcs_service_auth_2 = lcs_service_auth_convertToJSON(
		lcs_service_auth_2);
	printf("repeating lcs_service_auth:\n%s\n",
	       cJSON_Print(jsonlcs_service_auth_2));
}

int main() {
	test_lcs_service_auth(1);
	test_lcs_service_auth(0);

	printf("Hello world \n");
	return 0;
}

#endif // lcs_service_auth_MAIN
#endif // lcs_service_auth_TEST
