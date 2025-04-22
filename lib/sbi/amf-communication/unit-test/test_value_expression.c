#ifndef value_expression_TEST
#define value_expression_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define value_expression_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/value_expression.h"
value_expression_t *instantiate_value_expression(int include_optional);



value_expression_t *instantiate_value_expression(int include_optional) {
	value_expression_t *value_expression = NULL;
	if(include_optional) {
		value_expression = value_expression_create(
			);
	} else {
		value_expression = value_expression_create(
			);
	}

	return value_expression;
}


#ifdef value_expression_MAIN

void test_value_expression(int include_optional) {
	value_expression_t *value_expression_1 = instantiate_value_expression(
		include_optional);

	cJSON *jsonvalue_expression_1 = value_expression_convertToJSON(
		value_expression_1);
	printf("value_expression :\n%s\n", cJSON_Print(jsonvalue_expression_1));
	value_expression_t *value_expression_2 = value_expression_parseFromJSON(
		jsonvalue_expression_1);
	cJSON *jsonvalue_expression_2 = value_expression_convertToJSON(
		value_expression_2);
	printf("repeating value_expression:\n%s\n",
	       cJSON_Print(jsonvalue_expression_2));
}

int main() {
	test_value_expression(1);
	test_value_expression(0);

	printf("Hello world \n");
	return 0;
}

#endif // value_expression_MAIN
#endif // value_expression_TEST
