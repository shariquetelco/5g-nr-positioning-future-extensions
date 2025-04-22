#ifndef auth_status_any_of_TEST
#define auth_status_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define auth_status_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/auth_status_any_of.h"
auth_status_any_of_t *instantiate_auth_status_any_of(int include_optional);



auth_status_any_of_t *instantiate_auth_status_any_of(int include_optional) {
	auth_status_any_of_t *auth_status_any_of = NULL;
	if(include_optional) {
		auth_status_any_of = auth_status_any_of_create(
			);
	} else {
		auth_status_any_of = auth_status_any_of_create(
			);
	}

	return auth_status_any_of;
}


#ifdef auth_status_any_of_MAIN

void test_auth_status_any_of(int include_optional) {
	auth_status_any_of_t *auth_status_any_of_1 =
		instantiate_auth_status_any_of(include_optional);

	cJSON *jsonauth_status_any_of_1 = auth_status_any_of_convertToJSON(
		auth_status_any_of_1);
	printf("auth_status_any_of :\n%s\n",
	       cJSON_Print(jsonauth_status_any_of_1));
	auth_status_any_of_t *auth_status_any_of_2 =
		auth_status_any_of_parseFromJSON(jsonauth_status_any_of_1);
	cJSON *jsonauth_status_any_of_2 = auth_status_any_of_convertToJSON(
		auth_status_any_of_2);
	printf("repeating auth_status_any_of:\n%s\n",
	       cJSON_Print(jsonauth_status_any_of_2));
}

int main() {
	test_auth_status_any_of(1);
	test_auth_status_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // auth_status_any_of_MAIN
#endif // auth_status_any_of_TEST
