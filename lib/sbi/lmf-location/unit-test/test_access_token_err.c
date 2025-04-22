#ifndef access_token_err_TEST
#define access_token_err_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define access_token_err_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/access_token_err.h"
access_token_err_t *instantiate_access_token_err(int include_optional);



access_token_err_t *instantiate_access_token_err(int include_optional) {
	access_token_err_t *access_token_err = NULL;
	if(include_optional) {
		access_token_err = access_token_err_create(
			lmf_location_access_token_err_ERROR_invalid_request,
			"0",
			"0"
			);
	} else {
		access_token_err = access_token_err_create(
			lmf_location_access_token_err_ERROR_invalid_request,
			"0",
			"0"
			);
	}

	return access_token_err;
}


#ifdef access_token_err_MAIN

void test_access_token_err(int include_optional) {
	access_token_err_t *access_token_err_1 = instantiate_access_token_err(
		include_optional);

	cJSON *jsonaccess_token_err_1 = access_token_err_convertToJSON(
		access_token_err_1);
	printf("access_token_err :\n%s\n", cJSON_Print(jsonaccess_token_err_1));
	access_token_err_t *access_token_err_2 = access_token_err_parseFromJSON(
		jsonaccess_token_err_1);
	cJSON *jsonaccess_token_err_2 = access_token_err_convertToJSON(
		access_token_err_2);
	printf("repeating access_token_err:\n%s\n",
	       cJSON_Print(jsonaccess_token_err_2));
}

int main() {
	test_access_token_err(1);
	test_access_token_err(0);

	printf("Hello world \n");
	return 0;
}

#endif // access_token_err_MAIN
#endif // access_token_err_TEST
