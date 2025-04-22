#ifndef nrppa_information_TEST
#define nrppa_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nrppa_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nrppa_information.h"
nrppa_information_t *instantiate_nrppa_information(int include_optional);

#include "test_n2_info_content.c"


nrppa_information_t *instantiate_nrppa_information(int include_optional) {
	nrppa_information_t *nrppa_information = NULL;
	if(include_optional) {
		nrppa_information = nrppa_information_create(
			"0",
			// false, not to have infinite recursion
			instantiate_n2_info_content(0),
			"0"
			);
	} else {
		nrppa_information = nrppa_information_create(
			"0",
			NULL,
			"0"
			);
	}

	return nrppa_information;
}


#ifdef nrppa_information_MAIN

void test_nrppa_information(int include_optional) {
	nrppa_information_t *nrppa_information_1 =
		instantiate_nrppa_information(include_optional);

	cJSON *jsonnrppa_information_1 = nrppa_information_convertToJSON(
		nrppa_information_1);
	printf("nrppa_information :\n%s\n",
	       cJSON_Print(jsonnrppa_information_1));
	nrppa_information_t *nrppa_information_2 =
		nrppa_information_parseFromJSON(jsonnrppa_information_1);
	cJSON *jsonnrppa_information_2 = nrppa_information_convertToJSON(
		nrppa_information_2);
	printf("repeating nrppa_information:\n%s\n",
	       cJSON_Print(jsonnrppa_information_2));
}

int main() {
	test_nrppa_information(1);
	test_nrppa_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // nrppa_information_MAIN
#endif // nrppa_information_TEST
