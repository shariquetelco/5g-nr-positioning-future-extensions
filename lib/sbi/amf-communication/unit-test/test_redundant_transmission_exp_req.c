#ifndef redundant_transmission_exp_req_TEST
#define redundant_transmission_exp_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define redundant_transmission_exp_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/redundant_transmission_exp_req.h"
redundant_transmission_exp_req_t *instantiate_redundant_transmission_exp_req(
	int include_optional);

#include "test_red_trans_exp_ordering_criterion.c"
#include "test_matching_direction.c"


redundant_transmission_exp_req_t *instantiate_redundant_transmission_exp_req(
	int include_optional) {
	redundant_transmission_exp_req_t *redundant_transmission_exp_req = NULL;
	if(include_optional) {
		redundant_transmission_exp_req =
			redundant_transmission_exp_req_create(
				null,
				null
				);
	} else {
		redundant_transmission_exp_req =
			redundant_transmission_exp_req_create(
				null,
				null
				);
	}

	return redundant_transmission_exp_req;
}


#ifdef redundant_transmission_exp_req_MAIN

void test_redundant_transmission_exp_req(int include_optional) {
	redundant_transmission_exp_req_t *redundant_transmission_exp_req_1 =
		instantiate_redundant_transmission_exp_req(include_optional);

	cJSON *jsonredundant_transmission_exp_req_1 =
		redundant_transmission_exp_req_convertToJSON(
			redundant_transmission_exp_req_1);
	printf("redundant_transmission_exp_req :\n%s\n",
	       cJSON_Print(jsonredundant_transmission_exp_req_1));
	redundant_transmission_exp_req_t *redundant_transmission_exp_req_2 =
		redundant_transmission_exp_req_parseFromJSON(
			jsonredundant_transmission_exp_req_1);
	cJSON *jsonredundant_transmission_exp_req_2 =
		redundant_transmission_exp_req_convertToJSON(
			redundant_transmission_exp_req_2);
	printf("repeating redundant_transmission_exp_req:\n%s\n",
	       cJSON_Print(jsonredundant_transmission_exp_req_2));
}

int main() {
	test_redundant_transmission_exp_req(1);
	test_redundant_transmission_exp_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // redundant_transmission_exp_req_MAIN
#endif // redundant_transmission_exp_req_TEST
