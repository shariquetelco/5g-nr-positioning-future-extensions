#ifndef redundant_transmission_exp_info_TEST
#define redundant_transmission_exp_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define redundant_transmission_exp_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/redundant_transmission_exp_info.h"
redundant_transmission_exp_info_t *instantiate_redundant_transmission_exp_info(
	int include_optional);

#include "test_network_area_info.c"


redundant_transmission_exp_info_t *instantiate_redundant_transmission_exp_info(
	int include_optional) {
	redundant_transmission_exp_info_t *redundant_transmission_exp_info =
		NULL;
	if(include_optional) {
		redundant_transmission_exp_info =
			redundant_transmission_exp_info_create(
				// false, not to have infinite recursion
				instantiate_network_area_info(0),
				"0",
				list_createList()
				);
	} else {
		redundant_transmission_exp_info =
			redundant_transmission_exp_info_create(
				NULL,
				"0",
				list_createList()
				);
	}

	return redundant_transmission_exp_info;
}


#ifdef redundant_transmission_exp_info_MAIN

void test_redundant_transmission_exp_info(int include_optional) {
	redundant_transmission_exp_info_t *redundant_transmission_exp_info_1 =
		instantiate_redundant_transmission_exp_info(include_optional);

	cJSON *jsonredundant_transmission_exp_info_1 =
		redundant_transmission_exp_info_convertToJSON(
			redundant_transmission_exp_info_1);
	printf("redundant_transmission_exp_info :\n%s\n",
	       cJSON_Print(jsonredundant_transmission_exp_info_1));
	redundant_transmission_exp_info_t *redundant_transmission_exp_info_2 =
		redundant_transmission_exp_info_parseFromJSON(
			jsonredundant_transmission_exp_info_1);
	cJSON *jsonredundant_transmission_exp_info_2 =
		redundant_transmission_exp_info_convertToJSON(
			redundant_transmission_exp_info_2);
	printf("repeating redundant_transmission_exp_info:\n%s\n",
	       cJSON_Print(jsonredundant_transmission_exp_info_2));
}

int main() {
	test_redundant_transmission_exp_info(1);
	test_redundant_transmission_exp_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // redundant_transmission_exp_info_MAIN
#endif // redundant_transmission_exp_info_TEST
