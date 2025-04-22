#ifndef scheduled_communication_time_TEST
#define scheduled_communication_time_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define scheduled_communication_time_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/scheduled_communication_time.h"
scheduled_communication_time_t *instantiate_scheduled_communication_time(
	int include_optional);



scheduled_communication_time_t *instantiate_scheduled_communication_time(
	int include_optional) {
	scheduled_communication_time_t *scheduled_communication_time = NULL;
	if(include_optional) {
		scheduled_communication_time =
			scheduled_communication_time_create(
				list_createList(),
				"0",
				"0"
				);
	} else {
		scheduled_communication_time =
			scheduled_communication_time_create(
				list_createList(),
				"0",
				"0"
				);
	}

	return scheduled_communication_time;
}


#ifdef scheduled_communication_time_MAIN

void test_scheduled_communication_time(int include_optional) {
	scheduled_communication_time_t *scheduled_communication_time_1 =
		instantiate_scheduled_communication_time(include_optional);

	cJSON *jsonscheduled_communication_time_1 =
		scheduled_communication_time_convertToJSON(
			scheduled_communication_time_1);
	printf("scheduled_communication_time :\n%s\n",
	       cJSON_Print(jsonscheduled_communication_time_1));
	scheduled_communication_time_t *scheduled_communication_time_2 =
		scheduled_communication_time_parseFromJSON(
			jsonscheduled_communication_time_1);
	cJSON *jsonscheduled_communication_time_2 =
		scheduled_communication_time_convertToJSON(
			scheduled_communication_time_2);
	printf("repeating scheduled_communication_time:\n%s\n",
	       cJSON_Print(jsonscheduled_communication_time_2));
}

int main() {
	test_scheduled_communication_time(1);
	test_scheduled_communication_time(0);

	printf("Hello world \n");
	return 0;
}

#endif // scheduled_communication_time_MAIN
#endif // scheduled_communication_time_TEST
