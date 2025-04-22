#ifndef nf_load_level_information_TEST
#define nf_load_level_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nf_load_level_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nf_load_level_information.h"
nf_load_level_information_t *instantiate_nf_load_level_information(
	int include_optional);

#include "test_nf_type.c"
#include "test_nf_status.c"
#include "test_snssai.c"


nf_load_level_information_t *instantiate_nf_load_level_information(
	int include_optional) {
	nf_load_level_information_t *nf_load_level_information = NULL;
	if(include_optional) {
		nf_load_level_information = nf_load_level_information_create(
			null,
			"0",
			"0",
			// false, not to have infinite recursion
			instantiate_nf_status(0),
			56,
			56,
			56,
			56,
			56,
			56,
			// false, not to have infinite recursion
			instantiate_snssai(0),
			0
			);
	} else {
		nf_load_level_information = nf_load_level_information_create(
			null,
			"0",
			"0",
			NULL,
			56,
			56,
			56,
			56,
			56,
			56,
			NULL,
			0
			);
	}

	return nf_load_level_information;
}


#ifdef nf_load_level_information_MAIN

void test_nf_load_level_information(int include_optional) {
	nf_load_level_information_t *nf_load_level_information_1 =
		instantiate_nf_load_level_information(include_optional);

	cJSON *jsonnf_load_level_information_1 =
		nf_load_level_information_convertToJSON(
			nf_load_level_information_1);
	printf("nf_load_level_information :\n%s\n",
	       cJSON_Print(jsonnf_load_level_information_1));
	nf_load_level_information_t *nf_load_level_information_2 =
		nf_load_level_information_parseFromJSON(
			jsonnf_load_level_information_1);
	cJSON *jsonnf_load_level_information_2 =
		nf_load_level_information_convertToJSON(
			nf_load_level_information_2);
	printf("repeating nf_load_level_information:\n%s\n",
	       cJSON_Print(jsonnf_load_level_information_2));
}

int main() {
	test_nf_load_level_information(1);
	test_nf_load_level_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // nf_load_level_information_MAIN
#endif // nf_load_level_information_TEST
