#ifndef event_reporting_status_TEST
#define event_reporting_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_reporting_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_reporting_status.h"
event_reporting_status_t *instantiate_event_reporting_status(
	int include_optional);



event_reporting_status_t *instantiate_event_reporting_status(
	int include_optional) {
	event_reporting_status_t *event_reporting_status = NULL;
	if(include_optional) {
		event_reporting_status = event_reporting_status_create(
			1,
			1
			);
	} else {
		event_reporting_status = event_reporting_status_create(
			1,
			1
			);
	}

	return event_reporting_status;
}


#ifdef event_reporting_status_MAIN

void test_event_reporting_status(int include_optional) {
	event_reporting_status_t *event_reporting_status_1 =
		instantiate_event_reporting_status(include_optional);

	cJSON *jsonevent_reporting_status_1 =
		event_reporting_status_convertToJSON(event_reporting_status_1);
	printf("event_reporting_status :\n%s\n",
	       cJSON_Print(jsonevent_reporting_status_1));
	event_reporting_status_t *event_reporting_status_2 =
		event_reporting_status_parseFromJSON(
			jsonevent_reporting_status_1);
	cJSON *jsonevent_reporting_status_2 =
		event_reporting_status_convertToJSON(event_reporting_status_2);
	printf("repeating event_reporting_status:\n%s\n",
	       cJSON_Print(jsonevent_reporting_status_2));
}

int main() {
	test_event_reporting_status(1);
	test_event_reporting_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_reporting_status_MAIN
#endif // event_reporting_status_TEST
