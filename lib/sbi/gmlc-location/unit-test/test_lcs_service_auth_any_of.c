#ifndef lcs_service_auth_any_of_TEST
#define lcs_service_auth_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lcs_service_auth_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lcs_service_auth_any_of.h"
lcs_service_auth_any_of_t *instantiate_lcs_service_auth_any_of(
	int include_optional);



lcs_service_auth_any_of_t *instantiate_lcs_service_auth_any_of(
	int include_optional) {
	lcs_service_auth_any_of_t *lcs_service_auth_any_of = NULL;
	if(include_optional) {
		lcs_service_auth_any_of = lcs_service_auth_any_of_create(
			);
	} else {
		lcs_service_auth_any_of = lcs_service_auth_any_of_create(
			);
	}

	return lcs_service_auth_any_of;
}


#ifdef lcs_service_auth_any_of_MAIN

void test_lcs_service_auth_any_of(int include_optional) {
	lcs_service_auth_any_of_t *lcs_service_auth_any_of_1 =
		instantiate_lcs_service_auth_any_of(include_optional);

	cJSON *jsonlcs_service_auth_any_of_1 =
		lcs_service_auth_any_of_convertToJSON(lcs_service_auth_any_of_1);
	printf("lcs_service_auth_any_of :\n%s\n",
	       cJSON_Print(jsonlcs_service_auth_any_of_1));
	lcs_service_auth_any_of_t *lcs_service_auth_any_of_2 =
		lcs_service_auth_any_of_parseFromJSON(
			jsonlcs_service_auth_any_of_1);
	cJSON *jsonlcs_service_auth_any_of_2 =
		lcs_service_auth_any_of_convertToJSON(lcs_service_auth_any_of_2);
	printf("repeating lcs_service_auth_any_of:\n%s\n",
	       cJSON_Print(jsonlcs_service_auth_any_of_2));
}

int main() {
	test_lcs_service_auth_any_of(1);
	test_lcs_service_auth_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // lcs_service_auth_any_of_MAIN
#endif // lcs_service_auth_any_of_TEST
