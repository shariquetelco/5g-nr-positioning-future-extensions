#ifndef output_strategy_TEST
#define output_strategy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_strategy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_strategy.h"
output_strategy_t *instantiate_output_strategy(int include_optional);



output_strategy_t *instantiate_output_strategy(int include_optional) {
	output_strategy_t *output_strategy = NULL;
	if(include_optional) {
		output_strategy = output_strategy_create(
			);
	} else {
		output_strategy = output_strategy_create(
			);
	}

	return output_strategy;
}


#ifdef output_strategy_MAIN

void test_output_strategy(int include_optional) {
	output_strategy_t *output_strategy_1 = instantiate_output_strategy(
		include_optional);

	cJSON *jsonoutput_strategy_1 = output_strategy_convertToJSON(
		output_strategy_1);
	printf("output_strategy :\n%s\n", cJSON_Print(jsonoutput_strategy_1));
	output_strategy_t *output_strategy_2 = output_strategy_parseFromJSON(
		jsonoutput_strategy_1);
	cJSON *jsonoutput_strategy_2 = output_strategy_convertToJSON(
		output_strategy_2);
	printf("repeating output_strategy:\n%s\n",
	       cJSON_Print(jsonoutput_strategy_2));
}

int main() {
	test_output_strategy(1);
	test_output_strategy(0);

	printf("Hello world \n");
	return 0;
}

#endif // output_strategy_MAIN
#endif // output_strategy_TEST
