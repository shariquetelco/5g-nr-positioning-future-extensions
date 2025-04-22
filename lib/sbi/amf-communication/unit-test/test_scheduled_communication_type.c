#ifndef scheduled_communication_type_TEST
#define scheduled_communication_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define scheduled_communication_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/scheduled_communication_type.h"
scheduled_communication_type_t *instantiate_scheduled_communication_type(
	int include_optional);



scheduled_communication_type_t *instantiate_scheduled_communication_type(
	int include_optional) {
	scheduled_communication_type_t *scheduled_communication_type = NULL;
	if(include_optional) {
		scheduled_communication_type =
			scheduled_communication_type_create(
				);
	} else {
		scheduled_communication_type =
			scheduled_communication_type_create(
				);
	}

	return scheduled_communication_type;
}


#ifdef scheduled_communication_type_MAIN

void test_scheduled_communication_type(int include_optional) {
	scheduled_communication_type_t *scheduled_communication_type_1 =
		instantiate_scheduled_communication_type(include_optional);

	cJSON *jsonscheduled_communication_type_1 =
		scheduled_communication_type_convertToJSON(
			scheduled_communication_type_1);
	printf("scheduled_communication_type :\n%s\n",
	       cJSON_Print(jsonscheduled_communication_type_1));
	scheduled_communication_type_t *scheduled_communication_type_2 =
		scheduled_communication_type_parseFromJSON(
			jsonscheduled_communication_type_1);
	cJSON *jsonscheduled_communication_type_2 =
		scheduled_communication_type_convertToJSON(
			scheduled_communication_type_2);
	printf("repeating scheduled_communication_type:\n%s\n",
	       cJSON_Print(jsonscheduled_communication_type_2));
}

int main() {
	test_scheduled_communication_type(1);
	test_scheduled_communication_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // scheduled_communication_type_MAIN
#endif // scheduled_communication_type_TEST
