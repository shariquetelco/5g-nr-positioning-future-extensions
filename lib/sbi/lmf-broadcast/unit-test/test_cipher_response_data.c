#ifndef cipher_response_data_TEST
#define cipher_response_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cipher_response_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cipher_response_data.h"
cipher_response_data_t *instantiate_cipher_response_data(int include_optional);



cipher_response_data_t *instantiate_cipher_response_data(int include_optional) {
	cipher_response_data_t *cipher_response_data = NULL;
	if(include_optional) {
		cipher_response_data = cipher_response_data_create(
			lmf_broadcast_cipher_response_data__CIPHERING_KEY_DATA_AVAILABLE
			);
	} else {
		cipher_response_data = cipher_response_data_create(
			lmf_broadcast_cipher_response_data__CIPHERING_KEY_DATA_AVAILABLE
			);
	}

	return cipher_response_data;
}


#ifdef cipher_response_data_MAIN

void test_cipher_response_data(int include_optional) {
	cipher_response_data_t *cipher_response_data_1 =
		instantiate_cipher_response_data(include_optional);

	cJSON *jsoncipher_response_data_1 = cipher_response_data_convertToJSON(
		cipher_response_data_1);
	printf("cipher_response_data :\n%s\n",
	       cJSON_Print(jsoncipher_response_data_1));
	cipher_response_data_t *cipher_response_data_2 =
		cipher_response_data_parseFromJSON(jsoncipher_response_data_1);
	cJSON *jsoncipher_response_data_2 = cipher_response_data_convertToJSON(
		cipher_response_data_2);
	printf("repeating cipher_response_data:\n%s\n",
	       cJSON_Print(jsoncipher_response_data_2));
}

int main() {
	test_cipher_response_data(1);
	test_cipher_response_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // cipher_response_data_MAIN
#endif // cipher_response_data_TEST
