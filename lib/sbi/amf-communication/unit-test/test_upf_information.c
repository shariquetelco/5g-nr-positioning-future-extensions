#ifndef upf_information_TEST
#define upf_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define upf_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/upf_information.h"
upf_information_t *instantiate_upf_information(int include_optional);

#include "test_addr_fqdn.c"


upf_information_t *instantiate_upf_information(int include_optional) {
	upf_information_t *upf_information = NULL;
	if(include_optional) {
		upf_information = upf_information_create(
			"0",
			// false, not to have infinite recursion
			instantiate_addr_fqdn(0)
			);
	} else {
		upf_information = upf_information_create(
			"0",
			NULL
			);
	}

	return upf_information;
}


#ifdef upf_information_MAIN

void test_upf_information(int include_optional) {
	upf_information_t *upf_information_1 = instantiate_upf_information(
		include_optional);

	cJSON *jsonupf_information_1 = upf_information_convertToJSON(
		upf_information_1);
	printf("upf_information :\n%s\n", cJSON_Print(jsonupf_information_1));
	upf_information_t *upf_information_2 = upf_information_parseFromJSON(
		jsonupf_information_1);
	cJSON *jsonupf_information_2 = upf_information_convertToJSON(
		upf_information_2);
	printf("repeating upf_information:\n%s\n",
	       cJSON_Print(jsonupf_information_2));
}

int main() {
	test_upf_information(1);
	test_upf_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // upf_information_MAIN
#endif // upf_information_TEST
