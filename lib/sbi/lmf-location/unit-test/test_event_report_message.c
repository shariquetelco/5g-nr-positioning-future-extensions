#ifndef event_report_message_TEST
#define event_report_message_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_report_message_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_report_message.h"
event_report_message_t *instantiate_event_report_message(int include_optional);

#include "test_ref_to_binary_data.c"


event_report_message_t *instantiate_event_report_message(int include_optional) {
	event_report_message_t *event_report_message = NULL;
	if(include_optional) {
		event_report_message = event_report_message_create(
			lmf_location_event_report_message__SUPPLEMENTARY_SERVICES,
			// false, not to have infinite recursion
			instantiate_ref_to_binary_data(0)
			);
	} else {
		event_report_message = event_report_message_create(
			lmf_location_event_report_message__SUPPLEMENTARY_SERVICES,
			NULL
			);
	}

	return event_report_message;
}


#ifdef event_report_message_MAIN

void test_event_report_message(int include_optional) {
	event_report_message_t *event_report_message_1 =
		instantiate_event_report_message(include_optional);

	cJSON *jsonevent_report_message_1 = event_report_message_convertToJSON(
		event_report_message_1);
	printf("event_report_message :\n%s\n",
	       cJSON_Print(jsonevent_report_message_1));
	event_report_message_t *event_report_message_2 =
		event_report_message_parseFromJSON(jsonevent_report_message_1);
	cJSON *jsonevent_report_message_2 = event_report_message_convertToJSON(
		event_report_message_2);
	printf("repeating event_report_message:\n%s\n",
	       cJSON_Print(jsonevent_report_message_2));
}

int main() {
	test_event_report_message(1);
	test_event_report_message(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_report_message_MAIN
#endif // event_report_message_TEST
