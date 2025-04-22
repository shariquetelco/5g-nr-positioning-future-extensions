#ifndef amf_event_mode_TEST
#define amf_event_mode_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_mode_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_mode.h"
amf_event_mode_t *instantiate_amf_event_mode(int include_optional);

#include "test_amf_event_trigger.c"
#include "test_notification_flag.c"
#include "test_amf_event_mode_muting_exc_instructions.c"
#include "test_muting_notifications_settings.c"


amf_event_mode_t *instantiate_amf_event_mode(int include_optional) {
	amf_event_mode_t *amf_event_mode = NULL;
	if(include_optional) {
		amf_event_mode = amf_event_mode_create(
			null,
			56,
			"2013-10-20T19:20:30+01:00",
			56,
			1,
			list_createList(),
			null,
			null,
			null,
			list_createList()
			);
	} else {
		amf_event_mode = amf_event_mode_create(
			null,
			56,
			"2013-10-20T19:20:30+01:00",
			56,
			1,
			list_createList(),
			null,
			null,
			null,
			list_createList()
			);
	}

	return amf_event_mode;
}


#ifdef amf_event_mode_MAIN

void test_amf_event_mode(int include_optional) {
	amf_event_mode_t *amf_event_mode_1 = instantiate_amf_event_mode(
		include_optional);

	cJSON *jsonamf_event_mode_1 = amf_event_mode_convertToJSON(
		amf_event_mode_1);
	printf("amf_event_mode :\n%s\n", cJSON_Print(jsonamf_event_mode_1));
	amf_event_mode_t *amf_event_mode_2 = amf_event_mode_parseFromJSON(
		jsonamf_event_mode_1);
	cJSON *jsonamf_event_mode_2 = amf_event_mode_convertToJSON(
		amf_event_mode_2);
	printf("repeating amf_event_mode:\n%s\n",
	       cJSON_Print(jsonamf_event_mode_2));
}

int main() {
	test_amf_event_mode(1);
	test_amf_event_mode(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_mode_MAIN
#endif // amf_event_mode_TEST
