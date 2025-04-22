#ifndef expected_ue_behavior_TEST
#define expected_ue_behavior_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define expected_ue_behavior_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/expected_ue_behavior.h"
expected_ue_behavior_t *instantiate_expected_ue_behavior(int include_optional);



expected_ue_behavior_t *instantiate_expected_ue_behavior(int include_optional) {
	expected_ue_behavior_t *expected_ue_behavior = NULL;
	if(include_optional) {
		expected_ue_behavior = expected_ue_behavior_create(
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		expected_ue_behavior = expected_ue_behavior_create(
			list_createList(),
			"2013-10-20T19:20:30+01:00"
			);
	}

	return expected_ue_behavior;
}


#ifdef expected_ue_behavior_MAIN

void test_expected_ue_behavior(int include_optional) {
	expected_ue_behavior_t *expected_ue_behavior_1 =
		instantiate_expected_ue_behavior(include_optional);

	cJSON *jsonexpected_ue_behavior_1 = expected_ue_behavior_convertToJSON(
		expected_ue_behavior_1);
	printf("expected_ue_behavior :\n%s\n",
	       cJSON_Print(jsonexpected_ue_behavior_1));
	expected_ue_behavior_t *expected_ue_behavior_2 =
		expected_ue_behavior_parseFromJSON(jsonexpected_ue_behavior_1);
	cJSON *jsonexpected_ue_behavior_2 = expected_ue_behavior_convertToJSON(
		expected_ue_behavior_2);
	printf("repeating expected_ue_behavior:\n%s\n",
	       cJSON_Print(jsonexpected_ue_behavior_2));
}

int main() {
	test_expected_ue_behavior(1);
	test_expected_ue_behavior(0);

	printf("Hello world \n");
	return 0;
}

#endif // expected_ue_behavior_MAIN
#endif // expected_ue_behavior_TEST
