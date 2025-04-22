#ifndef ciphering_key_response_TEST
#define ciphering_key_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ciphering_key_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ciphering_key_response.h"
ciphering_key_response_t *instantiate_ciphering_key_response(
	int include_optional);



ciphering_key_response_t *instantiate_ciphering_key_response(
	int include_optional) {
	ciphering_key_response_t *ciphering_key_response = NULL;
	if(include_optional) {
		ciphering_key_response = ciphering_key_response_create(
			list_createList()
			);
	} else {
		ciphering_key_response = ciphering_key_response_create(
			list_createList()
			);
	}

	return ciphering_key_response;
}


#ifdef ciphering_key_response_MAIN

void test_ciphering_key_response(int include_optional) {
	ciphering_key_response_t *ciphering_key_response_1 =
		instantiate_ciphering_key_response(include_optional);

	cJSON *jsonciphering_key_response_1 =
		ciphering_key_response_convertToJSON(ciphering_key_response_1);
	printf("ciphering_key_response :\n%s\n",
	       cJSON_Print(jsonciphering_key_response_1));
	ciphering_key_response_t *ciphering_key_response_2 =
		ciphering_key_response_parseFromJSON(
			jsonciphering_key_response_1);
	cJSON *jsonciphering_key_response_2 =
		ciphering_key_response_convertToJSON(ciphering_key_response_2);
	printf("repeating ciphering_key_response:\n%s\n",
	       cJSON_Print(jsonciphering_key_response_2));
}

int main() {
	test_ciphering_key_response(1);
	test_ciphering_key_response(0);

	printf("Hello world \n");
	return 0;
}

#endif // ciphering_key_response_MAIN
#endif // ciphering_key_response_TEST
