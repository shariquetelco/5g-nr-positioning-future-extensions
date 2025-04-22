#ifndef output_strategy_any_of_TEST
#define output_strategy_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define output_strategy_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/output_strategy_any_of.h"
output_strategy_any_of_t *instantiate_output_strategy_any_of(
	int include_optional);



output_strategy_any_of_t *instantiate_output_strategy_any_of(
	int include_optional) {
	output_strategy_any_of_t *output_strategy_any_of = NULL;
	if(include_optional) {
		output_strategy_any_of = output_strategy_any_of_create(
			);
	} else {
		output_strategy_any_of = output_strategy_any_of_create(
			);
	}

	return output_strategy_any_of;
}


#ifdef output_strategy_any_of_MAIN

void test_output_strategy_any_of(int include_optional) {
	output_strategy_any_of_t *output_strategy_any_of_1 =
		instantiate_output_strategy_any_of(include_optional);

	cJSON *jsonoutput_strategy_any_of_1 =
		output_strategy_any_of_convertToJSON(output_strategy_any_of_1);
	printf("output_strategy_any_of :\n%s\n",
	       cJSON_Print(jsonoutput_strategy_any_of_1));
	output_strategy_any_of_t *output_strategy_any_of_2 =
		output_strategy_any_of_parseFromJSON(
			jsonoutput_strategy_any_of_1);
	cJSON *jsonoutput_strategy_any_of_2 =
		output_strategy_any_of_convertToJSON(output_strategy_any_of_2);
	printf("repeating output_strategy_any_of:\n%s\n",
	       cJSON_Print(jsonoutput_strategy_any_of_2));
}

int main() {
	test_output_strategy_any_of(1);
	test_output_strategy_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // output_strategy_any_of_MAIN
#endif // output_strategy_any_of_TEST
