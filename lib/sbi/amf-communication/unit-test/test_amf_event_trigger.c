#ifndef amf_event_trigger_TEST
#define amf_event_trigger_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_trigger_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_trigger.h"
amf_event_trigger_t *instantiate_amf_event_trigger(int include_optional);



amf_event_trigger_t *instantiate_amf_event_trigger(int include_optional) {
	amf_event_trigger_t *amf_event_trigger = NULL;
	if(include_optional) {
		amf_event_trigger = amf_event_trigger_create(
			);
	} else {
		amf_event_trigger = amf_event_trigger_create(
			);
	}

	return amf_event_trigger;
}


#ifdef amf_event_trigger_MAIN

void test_amf_event_trigger(int include_optional) {
	amf_event_trigger_t *amf_event_trigger_1 =
		instantiate_amf_event_trigger(include_optional);

	cJSON *jsonamf_event_trigger_1 = amf_event_trigger_convertToJSON(
		amf_event_trigger_1);
	printf("amf_event_trigger :\n%s\n",
	       cJSON_Print(jsonamf_event_trigger_1));
	amf_event_trigger_t *amf_event_trigger_2 =
		amf_event_trigger_parseFromJSON(jsonamf_event_trigger_1);
	cJSON *jsonamf_event_trigger_2 = amf_event_trigger_convertToJSON(
		amf_event_trigger_2);
	printf("repeating amf_event_trigger:\n%s\n",
	       cJSON_Print(jsonamf_event_trigger_2));
}

int main() {
	test_amf_event_trigger(1);
	test_amf_event_trigger(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_trigger_MAIN
#endif // amf_event_trigger_TEST
