#ifndef expected_analytics_type_TEST
#define expected_analytics_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define expected_analytics_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/expected_analytics_type.h"
expected_analytics_type_t *instantiate_expected_analytics_type(
	int include_optional);



expected_analytics_type_t *instantiate_expected_analytics_type(
	int include_optional) {
	expected_analytics_type_t *expected_analytics_type = NULL;
	if(include_optional) {
		expected_analytics_type = expected_analytics_type_create(
			);
	} else {
		expected_analytics_type = expected_analytics_type_create(
			);
	}

	return expected_analytics_type;
}


#ifdef expected_analytics_type_MAIN

void test_expected_analytics_type(int include_optional) {
	expected_analytics_type_t *expected_analytics_type_1 =
		instantiate_expected_analytics_type(include_optional);

	cJSON *jsonexpected_analytics_type_1 =
		expected_analytics_type_convertToJSON(expected_analytics_type_1);
	printf("expected_analytics_type :\n%s\n",
	       cJSON_Print(jsonexpected_analytics_type_1));
	expected_analytics_type_t *expected_analytics_type_2 =
		expected_analytics_type_parseFromJSON(
			jsonexpected_analytics_type_1);
	cJSON *jsonexpected_analytics_type_2 =
		expected_analytics_type_convertToJSON(expected_analytics_type_2);
	printf("repeating expected_analytics_type:\n%s\n",
	       cJSON_Print(jsonexpected_analytics_type_2));
}

int main() {
	test_expected_analytics_type(1);
	test_expected_analytics_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // expected_analytics_type_MAIN
#endif // expected_analytics_type_TEST
