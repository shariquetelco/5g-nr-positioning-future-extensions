#ifndef key_amf_type_TEST
#define key_amf_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define key_amf_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/key_amf_type.h"
key_amf_type_t *instantiate_key_amf_type(int include_optional);



key_amf_type_t *instantiate_key_amf_type(int include_optional) {
	key_amf_type_t *key_amf_type = NULL;
	if(include_optional) {
		key_amf_type = key_amf_type_create(
			);
	} else {
		key_amf_type = key_amf_type_create(
			);
	}

	return key_amf_type;
}


#ifdef key_amf_type_MAIN

void test_key_amf_type(int include_optional) {
	key_amf_type_t *key_amf_type_1 = instantiate_key_amf_type(
		include_optional);

	cJSON *jsonkey_amf_type_1 = key_amf_type_convertToJSON(key_amf_type_1);
	printf("key_amf_type :\n%s\n", cJSON_Print(jsonkey_amf_type_1));
	key_amf_type_t *key_amf_type_2 = key_amf_type_parseFromJSON(
		jsonkey_amf_type_1);
	cJSON *jsonkey_amf_type_2 = key_amf_type_convertToJSON(key_amf_type_2);
	printf("repeating key_amf_type:\n%s\n",
	       cJSON_Print(jsonkey_amf_type_2));
}

int main() {
	test_key_amf_type(1);
	test_key_amf_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // key_amf_type_MAIN
#endif // key_amf_type_TEST
