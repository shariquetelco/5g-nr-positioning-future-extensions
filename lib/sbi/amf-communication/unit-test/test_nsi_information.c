#ifndef nsi_information_TEST
#define nsi_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nsi_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nsi_information.h"
nsi_information_t *instantiate_nsi_information(int include_optional);



nsi_information_t *instantiate_nsi_information(int include_optional) {
	nsi_information_t *nsi_information = NULL;
	if(include_optional) {
		nsi_information = nsi_information_create(
			"0",
			"0",
			"0",
			"0",
			list_createList()
			);
	} else {
		nsi_information = nsi_information_create(
			"0",
			"0",
			"0",
			"0",
			list_createList()
			);
	}

	return nsi_information;
}


#ifdef nsi_information_MAIN

void test_nsi_information(int include_optional) {
	nsi_information_t *nsi_information_1 = instantiate_nsi_information(
		include_optional);

	cJSON *jsonnsi_information_1 = nsi_information_convertToJSON(
		nsi_information_1);
	printf("nsi_information :\n%s\n", cJSON_Print(jsonnsi_information_1));
	nsi_information_t *nsi_information_2 = nsi_information_parseFromJSON(
		jsonnsi_information_1);
	cJSON *jsonnsi_information_2 = nsi_information_convertToJSON(
		nsi_information_2);
	printf("repeating nsi_information:\n%s\n",
	       cJSON_Print(jsonnsi_information_2));
}

int main() {
	test_nsi_information(1);
	test_nsi_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // nsi_information_MAIN
#endif // nsi_information_TEST
