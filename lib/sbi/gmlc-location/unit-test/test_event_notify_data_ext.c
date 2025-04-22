#ifndef event_notify_data_ext_TEST
#define event_notify_data_ext_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_notify_data_ext_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_notify_data_ext.h"
event_notify_data_ext_t *instantiate_event_notify_data_ext(
	int include_optional);

#include "test_geographic_area.c"
#include "test_civic_address.c"
#include "test_local_area.c"
#include "test_velocity_estimate.c"
#include "test_minor_location_qo_s.c"
#include "test_high_accuracy_gnss_metrics.c"
#include "test_range_direction.c"
#include "test_model_2_d_relative_location.c"
#include "test_model_3_d_relative_location.c"
#include "test_velocity_estimate.c"


event_notify_data_ext_t *instantiate_event_notify_data_ext(int include_optional)
{
	event_notify_data_ext_t *event_notify_data_ext = NULL;
	if(include_optional) {
		event_notify_data_ext = event_notify_data_ext_create(
			"a",
			"a",
			"01",
			ngmlc_location_event_notify_data_ext__UE_AVAILABLE,
			null,
			// false, not to have infinite recursion
			instantiate_civic_address(0),
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			list_createList(),
			list_createList(),
			"0",
			"a",
			ngmlc_location_event_notify_data_ext__TERMINATION_BY_UE,
			null,
			-32767,
			"0",
			ngmlc_location_event_notify_data_ext__REQUESTED_ACCURACY_FULFILLED,
			ngmlc_location_event_notify_data_ext__POSITIONING_DENIED,
			// false, not to have infinite recursion
			instantiate_minor_location_qo_s(0),
			// false, not to have infinite recursion
			instantiate_high_accuracy_gnss_metrics(0),
			ngmlc_location_event_notify_data_ext__LOS,
			56,
			ngmlc_location_event_notify_data_ext__INDOOR,
			"0",
			// false, not to have infinite recursion
			instantiate_range_direction(0),
			// false, not to have infinite recursion
			instantiate_model_2_d_relative_location(0),
			// false, not to have infinite recursion
			instantiate_model_3_d_relative_location(0),
			null,
			list_createList()
			);
	} else {
		event_notify_data_ext = event_notify_data_ext_create(
			"a",
			"a",
			"01",
			ngmlc_location_event_notify_data_ext__UE_AVAILABLE,
			null,
			NULL,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			list_createList(),
			list_createList(),
			"0",
			"a",
			ngmlc_location_event_notify_data_ext__TERMINATION_BY_UE,
			null,
			-32767,
			"0",
			ngmlc_location_event_notify_data_ext__REQUESTED_ACCURACY_FULFILLED,
			ngmlc_location_event_notify_data_ext__POSITIONING_DENIED,
			NULL,
			NULL,
			ngmlc_location_event_notify_data_ext__LOS,
			56,
			ngmlc_location_event_notify_data_ext__INDOOR,
			"0",
			NULL,
			NULL,
			NULL,
			null,
			list_createList()
			);
	}

	return event_notify_data_ext;
}


#ifdef event_notify_data_ext_MAIN

void test_event_notify_data_ext(int include_optional) {
	event_notify_data_ext_t *event_notify_data_ext_1 =
		instantiate_event_notify_data_ext(include_optional);

	cJSON *jsonevent_notify_data_ext_1 =
		event_notify_data_ext_convertToJSON(event_notify_data_ext_1);
	printf("event_notify_data_ext :\n%s\n",
	       cJSON_Print(jsonevent_notify_data_ext_1));
	event_notify_data_ext_t *event_notify_data_ext_2 =
		event_notify_data_ext_parseFromJSON(jsonevent_notify_data_ext_1);
	cJSON *jsonevent_notify_data_ext_2 =
		event_notify_data_ext_convertToJSON(event_notify_data_ext_2);
	printf("repeating event_notify_data_ext:\n%s\n",
	       cJSON_Print(jsonevent_notify_data_ext_2));
}

int main() {
	test_event_notify_data_ext(1);
	test_event_notify_data_ext(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_notify_data_ext_MAIN
#endif // event_notify_data_ext_TEST
