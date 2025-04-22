#ifndef pc5_qos_flow_item_TEST
#define pc5_qos_flow_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pc5_qos_flow_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pc5_qos_flow_item.h"
pc5_qos_flow_item_t *instantiate_pc5_qos_flow_item(int include_optional);

#include "test_pc5_flow_bit_rates.c"


pc5_qos_flow_item_t *instantiate_pc5_qos_flow_item(int include_optional) {
	pc5_qos_flow_item_t *pc5_qos_flow_item = NULL;
	if(include_optional) {
		pc5_qos_flow_item = pc5_qos_flow_item_create(
			0,
			// false, not to have infinite recursion
			instantiate_pc5_flow_bit_rates(0),
			0
			);
	} else {
		pc5_qos_flow_item = pc5_qos_flow_item_create(
			0,
			NULL,
			0
			);
	}

	return pc5_qos_flow_item;
}


#ifdef pc5_qos_flow_item_MAIN

void test_pc5_qos_flow_item(int include_optional) {
	pc5_qos_flow_item_t *pc5_qos_flow_item_1 =
		instantiate_pc5_qos_flow_item(include_optional);

	cJSON *jsonpc5_qos_flow_item_1 = pc5_qos_flow_item_convertToJSON(
		pc5_qos_flow_item_1);
	printf("pc5_qos_flow_item :\n%s\n",
	       cJSON_Print(jsonpc5_qos_flow_item_1));
	pc5_qos_flow_item_t *pc5_qos_flow_item_2 =
		pc5_qos_flow_item_parseFromJSON(jsonpc5_qos_flow_item_1);
	cJSON *jsonpc5_qos_flow_item_2 = pc5_qos_flow_item_convertToJSON(
		pc5_qos_flow_item_2);
	printf("repeating pc5_qos_flow_item:\n%s\n",
	       cJSON_Print(jsonpc5_qos_flow_item_2));
}

int main() {
	test_pc5_qos_flow_item(1);
	test_pc5_qos_flow_item(0);

	printf("Hello world \n");
	return 0;
}

#endif // pc5_qos_flow_item_MAIN
#endif // pc5_qos_flow_item_TEST
