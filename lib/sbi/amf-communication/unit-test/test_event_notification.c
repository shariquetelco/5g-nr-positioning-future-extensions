#ifndef event_notification_TEST
#define event_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_notification.h"
event_notification_t *instantiate_event_notification(int include_optional);

#include "test_nwdaf_event.c"
#include "test_nwdaf_failure_code.c"
#include "test_analytics_metadata_info.c"
#include "test_slice_load_level_information.c"
#include "test_accuracy_info.c"


event_notification_t *instantiate_event_notification(int include_optional) {
	event_notification_t *event_notification = NULL;
	if(include_optional) {
		event_notification = event_notification_create(
			null,
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00",
			null,
			56,
			// false, not to have infinite recursion
			instantiate_analytics_metadata_info(0),
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_slice_load_level_information(0),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_accuracy_info(0),
			1,
			1,
			1,
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		event_notification = event_notification_create(
			null,
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00",
			null,
			56,
			NULL,
			list_createList(),
			list_createList(),
			list_createList(),
			NULL,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			NULL,
			1,
			1,
			1,
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return event_notification;
}


#ifdef event_notification_MAIN

void test_event_notification(int include_optional) {
	event_notification_t *event_notification_1 =
		instantiate_event_notification(include_optional);

	cJSON *jsonevent_notification_1 = event_notification_convertToJSON(
		event_notification_1);
	printf("event_notification :\n%s\n",
	       cJSON_Print(jsonevent_notification_1));
	event_notification_t *event_notification_2 =
		event_notification_parseFromJSON(jsonevent_notification_1);
	cJSON *jsonevent_notification_2 = event_notification_convertToJSON(
		event_notification_2);
	printf("repeating event_notification:\n%s\n",
	       cJSON_Print(jsonevent_notification_2));
}

int main() {
	test_event_notification(1);
	test_event_notification(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_notification_MAIN
#endif // event_notification_TEST
