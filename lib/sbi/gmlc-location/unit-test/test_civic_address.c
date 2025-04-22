#ifndef civic_address_TEST
#define civic_address_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define civic_address_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/civic_address.h"
civic_address_t *instantiate_civic_address(int include_optional);



civic_address_t *instantiate_civic_address(int include_optional) {
	civic_address_t *civic_address = NULL;
	if(include_optional) {
		civic_address = civic_address_create(
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0"
			);
	} else {
		civic_address = civic_address_create(
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0",
			"0"
			);
	}

	return civic_address;
}


#ifdef civic_address_MAIN

void test_civic_address(int include_optional) {
	civic_address_t *civic_address_1 = instantiate_civic_address(
		include_optional);

	cJSON *jsoncivic_address_1 =
		civic_address_convertToJSON(civic_address_1);
	printf("civic_address :\n%s\n", cJSON_Print(jsoncivic_address_1));
	civic_address_t *civic_address_2 = civic_address_parseFromJSON(
		jsoncivic_address_1);
	cJSON *jsoncivic_address_2 =
		civic_address_convertToJSON(civic_address_2);
	printf("repeating civic_address:\n%s\n", cJSON_Print(
		       jsoncivic_address_2));
}

int main() {
	test_civic_address(1);
	test_civic_address(0);

	printf("Hello world \n");
	return 0;
}

#endif // civic_address_MAIN
#endif // civic_address_TEST
