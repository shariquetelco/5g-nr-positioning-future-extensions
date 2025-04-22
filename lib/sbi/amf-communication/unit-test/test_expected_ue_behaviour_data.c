#ifndef expected_ue_behaviour_data_TEST
#define expected_ue_behaviour_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define expected_ue_behaviour_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/expected_ue_behaviour_data.h"
expected_ue_behaviour_data_t *instantiate_expected_ue_behaviour_data(
	int include_optional);

#include "test_stationary_indication.c"
#include "test_scheduled_communication_time.c"
#include "test_scheduled_communication_type.c"
#include "test_traffic_profile.c"
#include "test_battery_indication.c"


expected_ue_behaviour_data_t *instantiate_expected_ue_behaviour_data(
	int include_optional) {
	expected_ue_behaviour_data_t *expected_ue_behaviour_data = NULL;
	if(include_optional) {
		expected_ue_behaviour_data = expected_ue_behaviour_data_create(
			null,
			56,
			56,
			// false, not to have infinite recursion
			instantiate_scheduled_communication_time(0),
			null,
			list_createList(),
			null,
			// false, not to have infinite recursion
			instantiate_battery_indication(0),
			"2013-10-20T19:20:30+01:00",
			"a",
			"a"
			);
	} else {
		expected_ue_behaviour_data = expected_ue_behaviour_data_create(
			null,
			56,
			56,
			NULL,
			null,
			list_createList(),
			null,
			NULL,
			"2013-10-20T19:20:30+01:00",
			"a",
			"a"
			);
	}

	return expected_ue_behaviour_data;
}


#ifdef expected_ue_behaviour_data_MAIN

void test_expected_ue_behaviour_data(int include_optional) {
	expected_ue_behaviour_data_t *expected_ue_behaviour_data_1 =
		instantiate_expected_ue_behaviour_data(include_optional);

	cJSON *jsonexpected_ue_behaviour_data_1 =
		expected_ue_behaviour_data_convertToJSON(
			expected_ue_behaviour_data_1);
	printf("expected_ue_behaviour_data :\n%s\n",
	       cJSON_Print(jsonexpected_ue_behaviour_data_1));
	expected_ue_behaviour_data_t *expected_ue_behaviour_data_2 =
		expected_ue_behaviour_data_parseFromJSON(
			jsonexpected_ue_behaviour_data_1);
	cJSON *jsonexpected_ue_behaviour_data_2 =
		expected_ue_behaviour_data_convertToJSON(
			expected_ue_behaviour_data_2);
	printf("repeating expected_ue_behaviour_data:\n%s\n",
	       cJSON_Print(jsonexpected_ue_behaviour_data_2));
}

int main() {
	test_expected_ue_behaviour_data(1);
	test_expected_ue_behaviour_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // expected_ue_behaviour_data_MAIN
#endif // expected_ue_behaviour_data_TEST
