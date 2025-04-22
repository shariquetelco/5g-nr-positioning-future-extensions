#ifndef scheduled_communication_type_any_of_TEST
#define scheduled_communication_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define scheduled_communication_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/scheduled_communication_type_any_of.h"
scheduled_communication_type_any_of_t *
instantiate_scheduled_communication_type_any_of(int include_optional);



scheduled_communication_type_any_of_t *
instantiate_scheduled_communication_type_any_of(int include_optional) {
	scheduled_communication_type_any_of_t *
	        scheduled_communication_type_any_of = NULL;
	if(include_optional) {
		scheduled_communication_type_any_of =
			scheduled_communication_type_any_of_create(
				);
	} else {
		scheduled_communication_type_any_of =
			scheduled_communication_type_any_of_create(
				);
	}

	return scheduled_communication_type_any_of;
}


#ifdef scheduled_communication_type_any_of_MAIN

void test_scheduled_communication_type_any_of(int include_optional) {
	scheduled_communication_type_any_of_t *
	        scheduled_communication_type_any_of_1 =
		instantiate_scheduled_communication_type_any_of(include_optional);

	cJSON *jsonscheduled_communication_type_any_of_1 =
		scheduled_communication_type_any_of_convertToJSON(
			scheduled_communication_type_any_of_1);
	printf("scheduled_communication_type_any_of :\n%s\n",
	       cJSON_Print(jsonscheduled_communication_type_any_of_1));
	scheduled_communication_type_any_of_t *
	        scheduled_communication_type_any_of_2 =
		scheduled_communication_type_any_of_parseFromJSON(
			jsonscheduled_communication_type_any_of_1);
	cJSON *jsonscheduled_communication_type_any_of_2 =
		scheduled_communication_type_any_of_convertToJSON(
			scheduled_communication_type_any_of_2);
	printf("repeating scheduled_communication_type_any_of:\n%s\n", cJSON_Print(
		       jsonscheduled_communication_type_any_of_2));
}

int main() {
	test_scheduled_communication_type_any_of(1);
	test_scheduled_communication_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // scheduled_communication_type_any_of_MAIN
#endif // scheduled_communication_type_any_of_TEST
