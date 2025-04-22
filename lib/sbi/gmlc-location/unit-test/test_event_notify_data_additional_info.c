#ifndef event_notify_data_additional_info_TEST
#define event_notify_data_additional_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_notify_data_additional_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_notify_data_additional_info.h"
event_notify_data_additional_info_t *
instantiate_event_notify_data_additional_info(int include_optional);



event_notify_data_additional_info_t *
instantiate_event_notify_data_additional_info(int include_optional) {
	event_notify_data_additional_info_t *event_notify_data_additional_info =
		NULL;
	if(include_optional) {
		event_notify_data_additional_info =
			event_notify_data_additional_info_create(
				list_createList()
				);
	} else {
		event_notify_data_additional_info =
			event_notify_data_additional_info_create(
				list_createList()
				);
	}

	return event_notify_data_additional_info;
}


#ifdef event_notify_data_additional_info_MAIN

void test_event_notify_data_additional_info(int include_optional) {
	event_notify_data_additional_info_t *event_notify_data_additional_info_1
	        = instantiate_event_notify_data_additional_info(include_optional);

	cJSON *jsonevent_notify_data_additional_info_1 =
		event_notify_data_additional_info_convertToJSON(
			event_notify_data_additional_info_1);
	printf("event_notify_data_additional_info :\n%s\n",
	       cJSON_Print(jsonevent_notify_data_additional_info_1));
	event_notify_data_additional_info_t *event_notify_data_additional_info_2
	        = event_notify_data_additional_info_parseFromJSON(
			  jsonevent_notify_data_additional_info_1);
	cJSON *jsonevent_notify_data_additional_info_2 =
		event_notify_data_additional_info_convertToJSON(
			event_notify_data_additional_info_2);
	printf("repeating event_notify_data_additional_info:\n%s\n", cJSON_Print(
		       jsonevent_notify_data_additional_info_2));
}

int main() {
	test_event_notify_data_additional_info(1);
	test_event_notify_data_additional_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_notify_data_additional_info_MAIN
#endif // event_notify_data_additional_info_TEST
