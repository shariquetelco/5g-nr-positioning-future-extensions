#ifndef amf_event_trigger_any_of_TEST
#define amf_event_trigger_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_trigger_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_trigger_any_of.h"
amf_event_trigger_any_of_t *instantiate_amf_event_trigger_any_of(
	int include_optional);



amf_event_trigger_any_of_t *instantiate_amf_event_trigger_any_of(
	int include_optional) {
	amf_event_trigger_any_of_t *amf_event_trigger_any_of = NULL;
	if(include_optional) {
		amf_event_trigger_any_of = amf_event_trigger_any_of_create(
			);
	} else {
		amf_event_trigger_any_of = amf_event_trigger_any_of_create(
			);
	}

	return amf_event_trigger_any_of;
}


#ifdef amf_event_trigger_any_of_MAIN

void test_amf_event_trigger_any_of(int include_optional) {
	amf_event_trigger_any_of_t *amf_event_trigger_any_of_1 =
		instantiate_amf_event_trigger_any_of(include_optional);

	cJSON *jsonamf_event_trigger_any_of_1 =
		amf_event_trigger_any_of_convertToJSON(
			amf_event_trigger_any_of_1);
	printf("amf_event_trigger_any_of :\n%s\n",
	       cJSON_Print(jsonamf_event_trigger_any_of_1));
	amf_event_trigger_any_of_t *amf_event_trigger_any_of_2 =
		amf_event_trigger_any_of_parseFromJSON(
			jsonamf_event_trigger_any_of_1);
	cJSON *jsonamf_event_trigger_any_of_2 =
		amf_event_trigger_any_of_convertToJSON(
			amf_event_trigger_any_of_2);
	printf("repeating amf_event_trigger_any_of:\n%s\n",
	       cJSON_Print(jsonamf_event_trigger_any_of_2));
}

int main() {
	test_amf_event_trigger_any_of(1);
	test_amf_event_trigger_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_trigger_any_of_MAIN
#endif // amf_event_trigger_any_of_TEST
