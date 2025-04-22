#ifndef address_list_TEST
#define address_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define address_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/address_list.h"
address_list_t *instantiate_address_list(int include_optional);



address_list_t *instantiate_address_list(int include_optional) {
	address_list_t *address_list = NULL;
	if(include_optional) {
		address_list = address_list_create(
			list_createList(),
			list_createList()
			);
	} else {
		address_list = address_list_create(
			list_createList(),
			list_createList()
			);
	}

	return address_list;
}


#ifdef address_list_MAIN

void test_address_list(int include_optional) {
	address_list_t *address_list_1 = instantiate_address_list(
		include_optional);

	cJSON *jsonaddress_list_1 = address_list_convertToJSON(address_list_1);
	printf("address_list :\n%s\n", cJSON_Print(jsonaddress_list_1));
	address_list_t *address_list_2 = address_list_parseFromJSON(
		jsonaddress_list_1);
	cJSON *jsonaddress_list_2 = address_list_convertToJSON(address_list_2);
	printf("repeating address_list:\n%s\n",
	       cJSON_Print(jsonaddress_list_2));
}

int main() {
	test_address_list(1);
	test_address_list(0);

	printf("Hello world \n");
	return 0;
}

#endif // address_list_MAIN
#endif // address_list_TEST
