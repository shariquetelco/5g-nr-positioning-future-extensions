#ifndef comb_gci_and_hfc_n_ids_TEST
#define comb_gci_and_hfc_n_ids_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define comb_gci_and_hfc_n_ids_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/comb_gci_and_hfc_n_ids.h"
comb_gci_and_hfc_n_ids_t *instantiate_comb_gci_and_hfc_n_ids(
	int include_optional);



comb_gci_and_hfc_n_ids_t *instantiate_comb_gci_and_hfc_n_ids(
	int include_optional) {
	comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids = NULL;
	if(include_optional) {
		comb_gci_and_hfc_n_ids = comb_gci_and_hfc_n_ids_create(
			"0",
			"0"
			);
	} else {
		comb_gci_and_hfc_n_ids = comb_gci_and_hfc_n_ids_create(
			"0",
			"0"
			);
	}

	return comb_gci_and_hfc_n_ids;
}


#ifdef comb_gci_and_hfc_n_ids_MAIN

void test_comb_gci_and_hfc_n_ids(int include_optional) {
	comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids_1 =
		instantiate_comb_gci_and_hfc_n_ids(include_optional);

	cJSON *jsoncomb_gci_and_hfc_n_ids_1 =
		comb_gci_and_hfc_n_ids_convertToJSON(comb_gci_and_hfc_n_ids_1);
	printf("comb_gci_and_hfc_n_ids :\n%s\n",
	       cJSON_Print(jsoncomb_gci_and_hfc_n_ids_1));
	comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_ids_2 =
		comb_gci_and_hfc_n_ids_parseFromJSON(
			jsoncomb_gci_and_hfc_n_ids_1);
	cJSON *jsoncomb_gci_and_hfc_n_ids_2 =
		comb_gci_and_hfc_n_ids_convertToJSON(comb_gci_and_hfc_n_ids_2);
	printf("repeating comb_gci_and_hfc_n_ids:\n%s\n",
	       cJSON_Print(jsoncomb_gci_and_hfc_n_ids_2));
}

int main() {
	test_comb_gci_and_hfc_n_ids(1);
	test_comb_gci_and_hfc_n_ids(0);

	printf("Hello world \n");
	return 0;
}

#endif // comb_gci_and_hfc_n_ids_MAIN
#endif // comb_gci_and_hfc_n_ids_TEST
