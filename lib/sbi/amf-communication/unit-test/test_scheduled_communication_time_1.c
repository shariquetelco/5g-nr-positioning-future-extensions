#ifndef scheduled_communication_time_1_TEST
#define scheduled_communication_time_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define scheduled_communication_time_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/scheduled_communication_time_1.h"
scheduled_communication_time_1_t *instantiate_scheduled_communication_time_1(
	int include_optional);



scheduled_communication_time_1_t *instantiate_scheduled_communication_time_1(
	int include_optional) {
	scheduled_communication_time_1_t *scheduled_communication_time_1 = NULL;
	if(include_optional) {
		scheduled_communication_time_1 =
			scheduled_communication_time_1_create(
				list_createList(),
				"0",
				"0"
				);
	} else {
		scheduled_communication_time_1 =
			scheduled_communication_time_1_create(
				list_createList(),
				"0",
				"0"
				);
	}

	return scheduled_communication_time_1;
}


#ifdef scheduled_communication_time_1_MAIN

void test_scheduled_communication_time_1(int include_optional) {
	scheduled_communication_time_1_t *scheduled_communication_time_1_1 =
		instantiate_scheduled_communication_time_1(include_optional);

	cJSON *jsonscheduled_communication_time_1_1 =
		scheduled_communication_time_1_convertToJSON(
			scheduled_communication_time_1_1);
	printf("scheduled_communication_time_1 :\n%s\n",
	       cJSON_Print(jsonscheduled_communication_time_1_1));
	scheduled_communication_time_1_t *scheduled_communication_time_1_2 =
		scheduled_communication_time_1_parseFromJSON(
			jsonscheduled_communication_time_1_1);
	cJSON *jsonscheduled_communication_time_1_2 =
		scheduled_communication_time_1_convertToJSON(
			scheduled_communication_time_1_2);
	printf("repeating scheduled_communication_time_1:\n%s\n",
	       cJSON_Print(jsonscheduled_communication_time_1_2));
}

int main() {
	test_scheduled_communication_time_1(1);
	test_scheduled_communication_time_1(0);

	printf("Hello world \n");
	return 0;
}

#endif // scheduled_communication_time_1_MAIN
#endif // scheduled_communication_time_1_TEST
