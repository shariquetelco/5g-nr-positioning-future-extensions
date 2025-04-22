#ifndef ebi_arp_mapping_TEST
#define ebi_arp_mapping_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ebi_arp_mapping_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ebi_arp_mapping.h"
ebi_arp_mapping_t *instantiate_ebi_arp_mapping(int include_optional);

#include "test_arp.c"


ebi_arp_mapping_t *instantiate_ebi_arp_mapping(int include_optional) {
	ebi_arp_mapping_t *ebi_arp_mapping = NULL;
	if(include_optional) {
		ebi_arp_mapping = ebi_arp_mapping_create(
			0,
			// false, not to have infinite recursion
			instantiate_arp(0)
			);
	} else {
		ebi_arp_mapping = ebi_arp_mapping_create(
			0,
			NULL
			);
	}

	return ebi_arp_mapping;
}


#ifdef ebi_arp_mapping_MAIN

void test_ebi_arp_mapping(int include_optional) {
	ebi_arp_mapping_t *ebi_arp_mapping_1 = instantiate_ebi_arp_mapping(
		include_optional);

	cJSON *jsonebi_arp_mapping_1 = ebi_arp_mapping_convertToJSON(
		ebi_arp_mapping_1);
	printf("ebi_arp_mapping :\n%s\n", cJSON_Print(jsonebi_arp_mapping_1));
	ebi_arp_mapping_t *ebi_arp_mapping_2 = ebi_arp_mapping_parseFromJSON(
		jsonebi_arp_mapping_1);
	cJSON *jsonebi_arp_mapping_2 = ebi_arp_mapping_convertToJSON(
		ebi_arp_mapping_2);
	printf("repeating ebi_arp_mapping:\n%s\n",
	       cJSON_Print(jsonebi_arp_mapping_2));
}

int main() {
	test_ebi_arp_mapping(1);
	test_ebi_arp_mapping(0);

	printf("Hello world \n");
	return 0;
}

#endif // ebi_arp_mapping_MAIN
#endif // ebi_arp_mapping_TEST
