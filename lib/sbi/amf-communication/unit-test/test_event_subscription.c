#ifndef event_subscription_TEST
#define event_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_subscription.h"
event_subscription_t *instantiate_event_subscription(int include_optional);

#include "test_nwdaf_event.c"
#include "test_event_reporting_requirement.c"
#include "test_notification_method.c"
#include "test_matching_direction.c"
#include "test_network_area_info.c"
#include "test_geo_location.c"
#include "test_qos_requirement.c"
#include "test_target_ue_information.c"
#include "test_roaming_info.c"
#include "test_user_data_con_order_crit.c"
#include "test_expected_analytics_type.c"
#include "test_expected_ue_behaviour_data.c"
#include "test_upf_information.c"
#include "test_loc_info_granularity.c"
#include "test_location_orientation.c"
#include "test_accuracy_req.c"
#include "test_analytics_feedback_info.c"


event_subscription_t *instantiate_event_subscription(int include_optional) {
	event_subscription_t *event_subscription = NULL;
	if(include_optional) {
		event_subscription = event_subscription_create(
			1,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			// false, not to have infinite recursion
			instantiate_event_reporting_requirement(0),
			list_createList(),
			56,
			null,
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			// false, not to have infinite recursion
			instantiate_geo_location(0),
			56,
			0,
			0,
			list_createList(),
			list_createList(),
			0,
			0,
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_qos_requirement(0),
			list_createList(),
			list_createList(),
			56,
			list_createList(),
			// false, not to have infinite recursion
			instantiate_target_ue_information(0),
			// false, not to have infinite recursion
			instantiate_roaming_info(0),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			list_createList(),
			list_createList(),
			null,
			// false, not to have infinite recursion
			instantiate_expected_ue_behaviour_data(0),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_upf_information(0),
			list_createList(),
			list_createList(),
			list_createList(),
			"0",
			list_createList(),
			list_createList(),
			null,
			null,
			list_createList(),
			// false, not to have infinite recursion
			instantiate_accuracy_req(0),
			1,
			1,
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_analytics_feedback_info(0)
			);
	} else {
		event_subscription = event_subscription_create(
			1,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			NULL,
			list_createList(),
			56,
			null,
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			NULL,
			NULL,
			56,
			0,
			0,
			list_createList(),
			list_createList(),
			0,
			0,
			list_createList(),
			list_createList(),
			NULL,
			list_createList(),
			list_createList(),
			56,
			list_createList(),
			NULL,
			NULL,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			list_createList(),
			list_createList(),
			null,
			NULL,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			NULL,
			list_createList(),
			list_createList(),
			list_createList(),
			"0",
			list_createList(),
			list_createList(),
			null,
			null,
			list_createList(),
			NULL,
			1,
			1,
			list_createList(),
			list_createList(),
			NULL
			);
	}

	return event_subscription;
}


#ifdef event_subscription_MAIN

void test_event_subscription(int include_optional) {
	event_subscription_t *event_subscription_1 =
		instantiate_event_subscription(include_optional);

	cJSON *jsonevent_subscription_1 = event_subscription_convertToJSON(
		event_subscription_1);
	printf("event_subscription :\n%s\n",
	       cJSON_Print(jsonevent_subscription_1));
	event_subscription_t *event_subscription_2 =
		event_subscription_parseFromJSON(jsonevent_subscription_1);
	cJSON *jsonevent_subscription_2 = event_subscription_convertToJSON(
		event_subscription_2);
	printf("repeating event_subscription:\n%s\n",
	       cJSON_Print(jsonevent_subscription_2));
}

int main() {
	test_event_subscription(1);
	test_event_subscription(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_subscription_MAIN
#endif // event_subscription_TEST
