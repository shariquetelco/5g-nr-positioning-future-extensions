#ifndef auth_status_TEST
#define auth_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define auth_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/auth_status.h"
auth_status_t *instantiate_auth_status(int include_optional);



auth_status_t *instantiate_auth_status(int include_optional) {
	auth_status_t *auth_status = NULL;
	if(include_optional) {
		auth_status = auth_status_create(
			);
	} else {
		auth_status = auth_status_create(
			);
	}

	return auth_status;
}


#ifdef auth_status_MAIN

void test_auth_status(int include_optional) {
	auth_status_t *auth_status_1 =
		instantiate_auth_status(include_optional);

	cJSON *jsonauth_status_1 = auth_status_convertToJSON(auth_status_1);
	printf("auth_status :\n%s\n", cJSON_Print(jsonauth_status_1));
	auth_status_t *auth_status_2 = auth_status_parseFromJSON(
		jsonauth_status_1);
	cJSON *jsonauth_status_2 = auth_status_convertToJSON(auth_status_2);
	printf("repeating auth_status:\n%s\n", cJSON_Print(jsonauth_status_2));
}

int main() {
	test_auth_status(1);
	test_auth_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // auth_status_MAIN
#endif // auth_status_TEST
