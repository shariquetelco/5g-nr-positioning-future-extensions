#ifndef nssai_mapping_TEST
#define nssai_mapping_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nssai_mapping_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nssai_mapping.h"
nssai_mapping_t *instantiate_nssai_mapping(int include_optional);

#include "test_snssai.c"
#include "test_snssai.c"


nssai_mapping_t *instantiate_nssai_mapping(int include_optional) {
	nssai_mapping_t *nssai_mapping = NULL;
	if(include_optional) {
		nssai_mapping = nssai_mapping_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0)
			);
	} else {
		nssai_mapping = nssai_mapping_create(
			NULL,
			NULL
			);
	}

	return nssai_mapping;
}


#ifdef nssai_mapping_MAIN

void test_nssai_mapping(int include_optional) {
	nssai_mapping_t *nssai_mapping_1 = instantiate_nssai_mapping(
		include_optional);

	cJSON *jsonnssai_mapping_1 =
		nssai_mapping_convertToJSON(nssai_mapping_1);
	printf("nssai_mapping :\n%s\n", cJSON_Print(jsonnssai_mapping_1));
	nssai_mapping_t *nssai_mapping_2 = nssai_mapping_parseFromJSON(
		jsonnssai_mapping_1);
	cJSON *jsonnssai_mapping_2 =
		nssai_mapping_convertToJSON(nssai_mapping_2);
	printf("repeating nssai_mapping:\n%s\n", cJSON_Print(
		       jsonnssai_mapping_2));
}

int main() {
	test_nssai_mapping(1);
	test_nssai_mapping(0);

	printf("Hello world \n");
	return 0;
}

#endif // nssai_mapping_MAIN
#endif // nssai_mapping_TEST
