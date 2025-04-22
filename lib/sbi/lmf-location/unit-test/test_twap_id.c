#ifndef twap_id_TEST
#define twap_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define twap_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/twap_id.h"
twap_id_t *instantiate_twap_id(int include_optional);



twap_id_t *instantiate_twap_id(int include_optional) {
	twap_id_t *twap_id = NULL;
	if(include_optional) {
		twap_id = twap_id_create(
			"0",
			"0",
			"YQ=="
			);
	} else {
		twap_id = twap_id_create(
			"0",
			"0",
			"YQ=="
			);
	}

	return twap_id;
}


#ifdef twap_id_MAIN

void test_twap_id(int include_optional) {
	twap_id_t *twap_id_1 = instantiate_twap_id(include_optional);

	cJSON *jsontwap_id_1 = twap_id_convertToJSON(twap_id_1);
	printf("twap_id :\n%s\n", cJSON_Print(jsontwap_id_1));
	twap_id_t *twap_id_2 = twap_id_parseFromJSON(jsontwap_id_1);
	cJSON *jsontwap_id_2 = twap_id_convertToJSON(twap_id_2);
	printf("repeating twap_id:\n%s\n", cJSON_Print(jsontwap_id_2));
}

int main() {
	test_twap_id(1);
	test_twap_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // twap_id_MAIN
#endif // twap_id_TEST
