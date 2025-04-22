#ifndef value_expression_any_of_TEST
#define value_expression_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define value_expression_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/value_expression_any_of.h"
value_expression_any_of_t *instantiate_value_expression_any_of(
	int include_optional);



value_expression_any_of_t *instantiate_value_expression_any_of(
	int include_optional) {
	value_expression_any_of_t *value_expression_any_of = NULL;
	if(include_optional) {
		value_expression_any_of = value_expression_any_of_create(
			);
	} else {
		value_expression_any_of = value_expression_any_of_create(
			);
	}

	return value_expression_any_of;
}


#ifdef value_expression_any_of_MAIN

void test_value_expression_any_of(int include_optional) {
	value_expression_any_of_t *value_expression_any_of_1 =
		instantiate_value_expression_any_of(include_optional);

	cJSON *jsonvalue_expression_any_of_1 =
		value_expression_any_of_convertToJSON(value_expression_any_of_1);
	printf("value_expression_any_of :\n%s\n",
	       cJSON_Print(jsonvalue_expression_any_of_1));
	value_expression_any_of_t *value_expression_any_of_2 =
		value_expression_any_of_parseFromJSON(
			jsonvalue_expression_any_of_1);
	cJSON *jsonvalue_expression_any_of_2 =
		value_expression_any_of_convertToJSON(value_expression_any_of_2);
	printf("repeating value_expression_any_of:\n%s\n",
	       cJSON_Print(jsonvalue_expression_any_of_2));
}

int main() {
	test_value_expression_any_of(1);
	test_value_expression_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // value_expression_any_of_MAIN
#endif // value_expression_any_of_TEST
