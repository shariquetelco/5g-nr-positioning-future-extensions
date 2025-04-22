#ifndef pc5_flow_bit_rates_TEST
#define pc5_flow_bit_rates_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pc5_flow_bit_rates_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pc5_flow_bit_rates.h"
pc5_flow_bit_rates_t *instantiate_pc5_flow_bit_rates(int include_optional);



pc5_flow_bit_rates_t *instantiate_pc5_flow_bit_rates(int include_optional) {
	pc5_flow_bit_rates_t *pc5_flow_bit_rates = NULL;
	if(include_optional) {
		pc5_flow_bit_rates = pc5_flow_bit_rates_create(
			"a",
			"a"
			);
	} else {
		pc5_flow_bit_rates = pc5_flow_bit_rates_create(
			"a",
			"a"
			);
	}

	return pc5_flow_bit_rates;
}


#ifdef pc5_flow_bit_rates_MAIN

void test_pc5_flow_bit_rates(int include_optional) {
	pc5_flow_bit_rates_t *pc5_flow_bit_rates_1 =
		instantiate_pc5_flow_bit_rates(include_optional);

	cJSON *jsonpc5_flow_bit_rates_1 = pc5_flow_bit_rates_convertToJSON(
		pc5_flow_bit_rates_1);
	printf("pc5_flow_bit_rates :\n%s\n",
	       cJSON_Print(jsonpc5_flow_bit_rates_1));
	pc5_flow_bit_rates_t *pc5_flow_bit_rates_2 =
		pc5_flow_bit_rates_parseFromJSON(jsonpc5_flow_bit_rates_1);
	cJSON *jsonpc5_flow_bit_rates_2 = pc5_flow_bit_rates_convertToJSON(
		pc5_flow_bit_rates_2);
	printf("repeating pc5_flow_bit_rates:\n%s\n",
	       cJSON_Print(jsonpc5_flow_bit_rates_2));
}

int main() {
	test_pc5_flow_bit_rates(1);
	test_pc5_flow_bit_rates(0);

	printf("Hello world \n");
	return 0;
}

#endif // pc5_flow_bit_rates_MAIN
#endif // pc5_flow_bit_rates_TEST
