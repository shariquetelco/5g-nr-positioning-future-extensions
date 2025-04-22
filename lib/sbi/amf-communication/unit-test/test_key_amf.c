#ifndef key_amf_TEST
#define key_amf_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define key_amf_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/key_amf.h"
key_amf_t *instantiate_key_amf(int include_optional);



key_amf_t *instantiate_key_amf(int include_optional) {
	key_amf_t *key_amf = NULL;
	if(include_optional) {
		key_amf = key_amf_create(
			namf_communication_key_amf__KAMF,
			"0"
			);
	} else {
		key_amf = key_amf_create(
			namf_communication_key_amf__KAMF,
			"0"
			);
	}

	return key_amf;
}


#ifdef key_amf_MAIN

void test_key_amf(int include_optional) {
	key_amf_t *key_amf_1 = instantiate_key_amf(include_optional);

	cJSON *jsonkey_amf_1 = key_amf_convertToJSON(key_amf_1);
	printf("key_amf :\n%s\n", cJSON_Print(jsonkey_amf_1));
	key_amf_t *key_amf_2 = key_amf_parseFromJSON(jsonkey_amf_1);
	cJSON *jsonkey_amf_2 = key_amf_convertToJSON(key_amf_2);
	printf("repeating key_amf:\n%s\n", cJSON_Print(jsonkey_amf_2));
}

int main() {
	test_key_amf(1);
	test_key_amf(0);

	printf("Hello world \n");
	return 0;
}

#endif // key_amf_MAIN
#endif // key_amf_TEST
