#ifndef ciphering_data_set_TEST
#define ciphering_data_set_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ciphering_data_set_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ciphering_data_set.h"
ciphering_data_set_t *instantiate_ciphering_data_set(int include_optional);



ciphering_data_set_t *instantiate_ciphering_data_set(int include_optional) {
	ciphering_data_set_t *ciphering_data_set = NULL;
	if(include_optional) {
		ciphering_data_set = ciphering_data_set_create(
			0,
			"YQ==",
			"YQ==",
			"YQ==",
			"YQ==",
			"2013-10-20T19:20:30+01:00",
			1,
			"YQ=="
			);
	} else {
		ciphering_data_set = ciphering_data_set_create(
			0,
			"YQ==",
			"YQ==",
			"YQ==",
			"YQ==",
			"2013-10-20T19:20:30+01:00",
			1,
			"YQ=="
			);
	}

	return ciphering_data_set;
}


#ifdef ciphering_data_set_MAIN

void test_ciphering_data_set(int include_optional) {
	ciphering_data_set_t *ciphering_data_set_1 =
		instantiate_ciphering_data_set(include_optional);

	cJSON *jsonciphering_data_set_1 = ciphering_data_set_convertToJSON(
		ciphering_data_set_1);
	printf("ciphering_data_set :\n%s\n",
	       cJSON_Print(jsonciphering_data_set_1));
	ciphering_data_set_t *ciphering_data_set_2 =
		ciphering_data_set_parseFromJSON(jsonciphering_data_set_1);
	cJSON *jsonciphering_data_set_2 = ciphering_data_set_convertToJSON(
		ciphering_data_set_2);
	printf("repeating ciphering_data_set:\n%s\n",
	       cJSON_Print(jsonciphering_data_set_2));
}

int main() {
	test_ciphering_data_set(1);
	test_ciphering_data_set(0);

	printf("Hello world \n");
	return 0;
}

#endif // ciphering_data_set_MAIN
#endif // ciphering_data_set_TEST
