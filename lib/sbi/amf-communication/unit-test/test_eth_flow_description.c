#ifndef eth_flow_description_TEST
#define eth_flow_description_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eth_flow_description_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eth_flow_description.h"
eth_flow_description_t *instantiate_eth_flow_description(int include_optional);

#include "test_flow_direction.c"


eth_flow_description_t *instantiate_eth_flow_description(int include_optional) {
	eth_flow_description_t *eth_flow_description = NULL;
	if(include_optional) {
		eth_flow_description = eth_flow_description_create(
			"a",
			"0",
			"0",
			null,
			"a",
			list_createList(),
			"a",
			"a"
			);
	} else {
		eth_flow_description = eth_flow_description_create(
			"a",
			"0",
			"0",
			null,
			"a",
			list_createList(),
			"a",
			"a"
			);
	}

	return eth_flow_description;
}


#ifdef eth_flow_description_MAIN

void test_eth_flow_description(int include_optional) {
	eth_flow_description_t *eth_flow_description_1 =
		instantiate_eth_flow_description(include_optional);

	cJSON *jsoneth_flow_description_1 = eth_flow_description_convertToJSON(
		eth_flow_description_1);
	printf("eth_flow_description :\n%s\n",
	       cJSON_Print(jsoneth_flow_description_1));
	eth_flow_description_t *eth_flow_description_2 =
		eth_flow_description_parseFromJSON(jsoneth_flow_description_1);
	cJSON *jsoneth_flow_description_2 = eth_flow_description_convertToJSON(
		eth_flow_description_2);
	printf("repeating eth_flow_description:\n%s\n",
	       cJSON_Print(jsoneth_flow_description_2));
}

int main() {
	test_eth_flow_description(1);
	test_eth_flow_description(0);

	printf("Hello world \n");
	return 0;
}

#endif // eth_flow_description_MAIN
#endif // eth_flow_description_TEST
