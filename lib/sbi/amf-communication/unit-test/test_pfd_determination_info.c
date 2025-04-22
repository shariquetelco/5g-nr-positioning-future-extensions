#ifndef pfd_determination_info_TEST
#define pfd_determination_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pfd_determination_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pfd_determination_info.h"
pfd_determination_info_t *instantiate_pfd_determination_info(
	int include_optional);

#include "test_snssai.c"


pfd_determination_info_t *instantiate_pfd_determination_info(
	int include_optional) {
	pfd_determination_info_t *pfd_determination_info = NULL;
	if(include_optional) {
		pfd_determination_info = pfd_determination_info_create(
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0",
			list_createList()
			);
	} else {
		pfd_determination_info = pfd_determination_info_create(
			"0",
			NULL,
			"0",
			list_createList()
			);
	}

	return pfd_determination_info;
}


#ifdef pfd_determination_info_MAIN

void test_pfd_determination_info(int include_optional) {
	pfd_determination_info_t *pfd_determination_info_1 =
		instantiate_pfd_determination_info(include_optional);

	cJSON *jsonpfd_determination_info_1 =
		pfd_determination_info_convertToJSON(pfd_determination_info_1);
	printf("pfd_determination_info :\n%s\n",
	       cJSON_Print(jsonpfd_determination_info_1));
	pfd_determination_info_t *pfd_determination_info_2 =
		pfd_determination_info_parseFromJSON(
			jsonpfd_determination_info_1);
	cJSON *jsonpfd_determination_info_2 =
		pfd_determination_info_convertToJSON(pfd_determination_info_2);
	printf("repeating pfd_determination_info:\n%s\n",
	       cJSON_Print(jsonpfd_determination_info_2));
}

int main() {
	test_pfd_determination_info(1);
	test_pfd_determination_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // pfd_determination_info_MAIN
#endif // pfd_determination_info_TEST
