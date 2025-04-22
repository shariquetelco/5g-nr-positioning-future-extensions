#ifndef ciphering_key_info_TEST
#define ciphering_key_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ciphering_key_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ciphering_key_info.h"
ciphering_key_info_t *instantiate_ciphering_key_info(int include_optional);



ciphering_key_info_t *instantiate_ciphering_key_info(int include_optional) {
	ciphering_key_info_t *ciphering_key_info = NULL;
	if(include_optional) {
		ciphering_key_info = ciphering_key_info_create(
			list_createList(),
			"a"
			);
	} else {
		ciphering_key_info = ciphering_key_info_create(
			list_createList(),
			"a"
			);
	}

	return ciphering_key_info;
}


#ifdef ciphering_key_info_MAIN

void test_ciphering_key_info(int include_optional) {
	ciphering_key_info_t *ciphering_key_info_1 =
		instantiate_ciphering_key_info(include_optional);

	cJSON *jsonciphering_key_info_1 = ciphering_key_info_convertToJSON(
		ciphering_key_info_1);
	printf("ciphering_key_info :\n%s\n",
	       cJSON_Print(jsonciphering_key_info_1));
	ciphering_key_info_t *ciphering_key_info_2 =
		ciphering_key_info_parseFromJSON(jsonciphering_key_info_1);
	cJSON *jsonciphering_key_info_2 = ciphering_key_info_convertToJSON(
		ciphering_key_info_2);
	printf("repeating ciphering_key_info:\n%s\n",
	       cJSON_Print(jsonciphering_key_info_2));
}

int main() {
	test_ciphering_key_info(1);
	test_ciphering_key_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // ciphering_key_info_MAIN
#endif // ciphering_key_info_TEST
