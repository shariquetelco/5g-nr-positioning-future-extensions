#ifndef event_notify_data_type_TEST
#define event_notify_data_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_notify_data_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_notify_data_type.h"
event_notify_data_type_t *instantiate_event_notify_data_type(
	int include_optional);



event_notify_data_type_t *instantiate_event_notify_data_type(
	int include_optional) {
	event_notify_data_type_t *event_notify_data_type = NULL;
	if(include_optional) {
		event_notify_data_type = event_notify_data_type_create(
			);
	} else {
		event_notify_data_type = event_notify_data_type_create(
			);
	}

	return event_notify_data_type;
}


#ifdef event_notify_data_type_MAIN

void test_event_notify_data_type(int include_optional) {
	event_notify_data_type_t *event_notify_data_type_1 =
		instantiate_event_notify_data_type(include_optional);

	cJSON *jsonevent_notify_data_type_1 =
		event_notify_data_type_convertToJSON(event_notify_data_type_1);
	printf("event_notify_data_type :\n%s\n",
	       cJSON_Print(jsonevent_notify_data_type_1));
	event_notify_data_type_t *event_notify_data_type_2 =
		event_notify_data_type_parseFromJSON(
			jsonevent_notify_data_type_1);
	cJSON *jsonevent_notify_data_type_2 =
		event_notify_data_type_convertToJSON(event_notify_data_type_2);
	printf("repeating event_notify_data_type:\n%s\n",
	       cJSON_Print(jsonevent_notify_data_type_2));
}

int main() {
	test_event_notify_data_type(1);
	test_event_notify_data_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_notify_data_type_MAIN
#endif // event_notify_data_type_TEST
