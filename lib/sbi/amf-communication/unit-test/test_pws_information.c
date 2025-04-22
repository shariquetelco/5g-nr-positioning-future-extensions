#ifndef pws_information_TEST
#define pws_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pws_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pws_information.h"
pws_information_t *instantiate_pws_information(int include_optional);

#include "test_n2_info_content.c"


pws_information_t *instantiate_pws_information(int include_optional) {
	pws_information_t *pws_information = NULL;
	if(include_optional) {
		pws_information = pws_information_create(
			0,
			0,
			// false, not to have infinite recursion
			instantiate_n2_info_content(0),
			list_createList(),
			1,
			"0",
			"0"
			);
	} else {
		pws_information = pws_information_create(
			0,
			0,
			NULL,
			list_createList(),
			1,
			"0",
			"0"
			);
	}

	return pws_information;
}


#ifdef pws_information_MAIN

void test_pws_information(int include_optional) {
	pws_information_t *pws_information_1 = instantiate_pws_information(
		include_optional);

	cJSON *jsonpws_information_1 = pws_information_convertToJSON(
		pws_information_1);
	printf("pws_information :\n%s\n", cJSON_Print(jsonpws_information_1));
	pws_information_t *pws_information_2 = pws_information_parseFromJSON(
		jsonpws_information_1);
	cJSON *jsonpws_information_2 = pws_information_convertToJSON(
		pws_information_2);
	printf("repeating pws_information:\n%s\n",
	       cJSON_Print(jsonpws_information_2));
}

int main() {
	test_pws_information(1);
	test_pws_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // pws_information_MAIN
#endif // pws_information_TEST
