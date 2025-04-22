#ifndef amf_event_mode_muting_exc_instructions_TEST
#define amf_event_mode_muting_exc_instructions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_mode_muting_exc_instructions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_mode_muting_exc_instructions.h"
amf_event_mode_muting_exc_instructions_t *
instantiate_amf_event_mode_muting_exc_instructions(int include_optional);

#include "test_buffered_notifications_action.c"
#include "test_subscription_action.c"


amf_event_mode_muting_exc_instructions_t *
instantiate_amf_event_mode_muting_exc_instructions(int include_optional) {
	amf_event_mode_muting_exc_instructions_t *
	        amf_event_mode_muting_exc_instructions = NULL;
	if(include_optional) {
		amf_event_mode_muting_exc_instructions =
			amf_event_mode_muting_exc_instructions_create(
				null,
				null
				);
	} else {
		amf_event_mode_muting_exc_instructions =
			amf_event_mode_muting_exc_instructions_create(
				null,
				null
				);
	}

	return amf_event_mode_muting_exc_instructions;
}


#ifdef amf_event_mode_muting_exc_instructions_MAIN

void test_amf_event_mode_muting_exc_instructions(int include_optional) {
	amf_event_mode_muting_exc_instructions_t *
	        amf_event_mode_muting_exc_instructions_1 =
		instantiate_amf_event_mode_muting_exc_instructions(
			include_optional);

	cJSON *jsonamf_event_mode_muting_exc_instructions_1 =
		amf_event_mode_muting_exc_instructions_convertToJSON(
			amf_event_mode_muting_exc_instructions_1);
	printf("amf_event_mode_muting_exc_instructions :\n%s\n",
	       cJSON_Print(jsonamf_event_mode_muting_exc_instructions_1));
	amf_event_mode_muting_exc_instructions_t *
	        amf_event_mode_muting_exc_instructions_2 =
		amf_event_mode_muting_exc_instructions_parseFromJSON(
			jsonamf_event_mode_muting_exc_instructions_1);
	cJSON *jsonamf_event_mode_muting_exc_instructions_2 =
		amf_event_mode_muting_exc_instructions_convertToJSON(
			amf_event_mode_muting_exc_instructions_2);
	printf("repeating amf_event_mode_muting_exc_instructions:\n%s\n", cJSON_Print(
		       jsonamf_event_mode_muting_exc_instructions_2));
}

int main() {
	test_amf_event_mode_muting_exc_instructions(1);
	test_amf_event_mode_muting_exc_instructions(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_mode_muting_exc_instructions_MAIN
#endif // amf_event_mode_muting_exc_instructions_TEST
