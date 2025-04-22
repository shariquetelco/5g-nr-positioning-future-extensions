#ifndef expected_analytics_type_any_of_TEST
#define expected_analytics_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define expected_analytics_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/expected_analytics_type_any_of.h"
expected_analytics_type_any_of_t *instantiate_expected_analytics_type_any_of(
	int include_optional);



expected_analytics_type_any_of_t *instantiate_expected_analytics_type_any_of(
	int include_optional) {
	expected_analytics_type_any_of_t *expected_analytics_type_any_of = NULL;
	if(include_optional) {
		expected_analytics_type_any_of =
			expected_analytics_type_any_of_create(
				);
	} else {
		expected_analytics_type_any_of =
			expected_analytics_type_any_of_create(
				);
	}

	return expected_analytics_type_any_of;
}


#ifdef expected_analytics_type_any_of_MAIN

void test_expected_analytics_type_any_of(int include_optional) {
	expected_analytics_type_any_of_t *expected_analytics_type_any_of_1 =
		instantiate_expected_analytics_type_any_of(include_optional);

	cJSON *jsonexpected_analytics_type_any_of_1 =
		expected_analytics_type_any_of_convertToJSON(
			expected_analytics_type_any_of_1);
	printf("expected_analytics_type_any_of :\n%s\n",
	       cJSON_Print(jsonexpected_analytics_type_any_of_1));
	expected_analytics_type_any_of_t *expected_analytics_type_any_of_2 =
		expected_analytics_type_any_of_parseFromJSON(
			jsonexpected_analytics_type_any_of_1);
	cJSON *jsonexpected_analytics_type_any_of_2 =
		expected_analytics_type_any_of_convertToJSON(
			expected_analytics_type_any_of_2);
	printf("repeating expected_analytics_type_any_of:\n%s\n",
	       cJSON_Print(jsonexpected_analytics_type_any_of_2));
}

int main() {
	test_expected_analytics_type_any_of(1);
	test_expected_analytics_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // expected_analytics_type_any_of_MAIN
#endif // expected_analytics_type_any_of_TEST
