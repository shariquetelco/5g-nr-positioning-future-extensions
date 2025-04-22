#ifndef rslp_information_TEST
#define rslp_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rslp_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rslp_information.h"
rslp_information_t *instantiate_rslp_information(int include_optional);

#include "test_n2_info_content.c"


rslp_information_t *instantiate_rslp_information(int include_optional) {
	rslp_information_t *rslp_information = NULL;
	if(include_optional) {
		rslp_information = rslp_information_create(
			// false, not to have infinite recursion
			instantiate_n2_info_content(0)
			);
	} else {
		rslp_information = rslp_information_create(
			NULL
			);
	}

	return rslp_information;
}


#ifdef rslp_information_MAIN

void test_rslp_information(int include_optional) {
	rslp_information_t *rslp_information_1 = instantiate_rslp_information(
		include_optional);

	cJSON *jsonrslp_information_1 = rslp_information_convertToJSON(
		rslp_information_1);
	printf("rslp_information :\n%s\n", cJSON_Print(jsonrslp_information_1));
	rslp_information_t *rslp_information_2 = rslp_information_parseFromJSON(
		jsonrslp_information_1);
	cJSON *jsonrslp_information_2 = rslp_information_convertToJSON(
		rslp_information_2);
	printf("repeating rslp_information:\n%s\n",
	       cJSON_Print(jsonrslp_information_2));
}

int main() {
	test_rslp_information(1);
	test_rslp_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // rslp_information_MAIN
#endif // rslp_information_TEST
