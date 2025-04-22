#ifndef amf_event_TEST
#define amf_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event.h"
amf_event_t *instantiate_amf_event(int include_optional);

#include "test_amf_event_type.c"
#include "test_reachability_filter.c"
#include "test_target_area.c"
#include "test_ue_in_area_filter.c"
#include "test_dispersion_area.c"


amf_event_t *instantiate_amf_event(int include_optional) {
	amf_event_t *amf_event = NULL;
	if(include_optional) {
		amf_event = amf_event_create(
			null,
			1,
			list_createList(),
			list_createList(),
			0,
			list_createList(),
			1,
			null,
			1,
			56,
			list_createList(),
			56,
			// false, not to have infinite recursion
			instantiate_target_area(0),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_ue_in_area_filter(0),
			56,
			"2013-10-20T19:20:30+01:00",
			1,
			// false, not to have infinite recursion
			instantiate_dispersion_area(0),
			"2013-10-20T19:20:30+01:00",
			1,
			1,
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		amf_event = amf_event_create(
			null,
			1,
			list_createList(),
			list_createList(),
			0,
			list_createList(),
			1,
			null,
			1,
			56,
			list_createList(),
			56,
			NULL,
			list_createList(),
			NULL,
			56,
			"2013-10-20T19:20:30+01:00",
			1,
			NULL,
			"2013-10-20T19:20:30+01:00",
			1,
			1,
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return amf_event;
}


#ifdef amf_event_MAIN

void test_amf_event(int include_optional) {
	amf_event_t *amf_event_1 = instantiate_amf_event(include_optional);

	cJSON *jsonamf_event_1 = amf_event_convertToJSON(amf_event_1);
	printf("amf_event :\n%s\n", cJSON_Print(jsonamf_event_1));
	amf_event_t *amf_event_2 = amf_event_parseFromJSON(jsonamf_event_1);
	cJSON *jsonamf_event_2 = amf_event_convertToJSON(amf_event_2);
	printf("repeating amf_event:\n%s\n", cJSON_Print(jsonamf_event_2));
}

int main() {
	test_amf_event(1);
	test_amf_event(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_MAIN
#endif // amf_event_TEST
