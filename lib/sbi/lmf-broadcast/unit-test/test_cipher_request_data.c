#ifndef cipher_request_data_TEST
#define cipher_request_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cipher_request_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cipher_request_data.h"
cipher_request_data_t *instantiate_cipher_request_data(int include_optional);



cipher_request_data_t *instantiate_cipher_request_data(int include_optional) {
	cipher_request_data_t *cipher_request_data = NULL;
	if(include_optional) {
		cipher_request_data = cipher_request_data_create(
			"0",
			"a"
			);
	} else {
		cipher_request_data = cipher_request_data_create(
			"0",
			"a"
			);
	}

	return cipher_request_data;
}


#ifdef cipher_request_data_MAIN

void test_cipher_request_data(int include_optional) {
	cipher_request_data_t *cipher_request_data_1 =
		instantiate_cipher_request_data(include_optional);

	cJSON *jsoncipher_request_data_1 = cipher_request_data_convertToJSON(
		cipher_request_data_1);
	printf("cipher_request_data :\n%s\n",
	       cJSON_Print(jsoncipher_request_data_1));
	cipher_request_data_t *cipher_request_data_2 =
		cipher_request_data_parseFromJSON(jsoncipher_request_data_1);
	cJSON *jsoncipher_request_data_2 = cipher_request_data_convertToJSON(
		cipher_request_data_2);
	printf("repeating cipher_request_data:\n%s\n",
	       cJSON_Print(jsoncipher_request_data_2));
}

int main() {
	test_cipher_request_data(1);
	test_cipher_request_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // cipher_request_data_MAIN
#endif // cipher_request_data_TEST
