#ifndef event_reporting_requirement_TEST
#define event_reporting_requirement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_reporting_requirement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_reporting_requirement.h"
event_reporting_requirement_t *instantiate_event_reporting_requirement(
	int include_optional);

#include "test_accuracy.c"
#include "test_analytics_metadata_indication.c"
#include "test_time_window.c"


event_reporting_requirement_t *instantiate_event_reporting_requirement(
	int include_optional) {
	event_reporting_requirement_t *event_reporting_requirement = NULL;
	if(include_optional) {
		event_reporting_requirement =
			event_reporting_requirement_create(
				null,
				list_createList(),
				"2013-10-20T19:20:30+01:00",
				"2013-10-20T19:20:30+01:00",
				56,
				1,
				0,
				0,
				"2013-10-20T19:20:30+01:00",
				list_createList(),
				// false, not to have infinite recursion
				instantiate_analytics_metadata_indication(0),
				// false, not to have infinite recursion
				instantiate_time_window(0)
				);
	} else {
		event_reporting_requirement =
			event_reporting_requirement_create(
				null,
				list_createList(),
				"2013-10-20T19:20:30+01:00",
				"2013-10-20T19:20:30+01:00",
				56,
				1,
				0,
				0,
				"2013-10-20T19:20:30+01:00",
				list_createList(),
				NULL,
				NULL
				);
	}

	return event_reporting_requirement;
}


#ifdef event_reporting_requirement_MAIN

void test_event_reporting_requirement(int include_optional) {
	event_reporting_requirement_t *event_reporting_requirement_1 =
		instantiate_event_reporting_requirement(include_optional);

	cJSON *jsonevent_reporting_requirement_1 =
		event_reporting_requirement_convertToJSON(
			event_reporting_requirement_1);
	printf("event_reporting_requirement :\n%s\n",
	       cJSON_Print(jsonevent_reporting_requirement_1));
	event_reporting_requirement_t *event_reporting_requirement_2 =
		event_reporting_requirement_parseFromJSON(
			jsonevent_reporting_requirement_1);
	cJSON *jsonevent_reporting_requirement_2 =
		event_reporting_requirement_convertToJSON(
			event_reporting_requirement_2);
	printf("repeating event_reporting_requirement:\n%s\n",
	       cJSON_Print(jsonevent_reporting_requirement_2));
}

int main() {
	test_event_reporting_requirement(1);
	test_event_reporting_requirement(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_reporting_requirement_MAIN
#endif // event_reporting_requirement_TEST
