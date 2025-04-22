#ifndef loc_update_notification_TEST
#define loc_update_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_update_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_update_notification.h"
loc_update_notification_t *instantiate_loc_update_notification(
	int include_optional);

#include "test_geographic_area.c"
#include "test_civic_address.c"


loc_update_notification_t *instantiate_loc_update_notification(
	int include_optional) {
	loc_update_notification_t *loc_update_notification = NULL;
	if(include_optional) {
		loc_update_notification = loc_update_notification_create(
			"a",
			"a",
			ngmlc_location_loc_update_notification__NI_LR,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			ngmlc_location_loc_update_notification__REQUESTED_ACCURACY_FULFILLED,
			// false, not to have infinite recursion
			instantiate_civic_address(0),
			ngmlc_location_loc_update_notification__BEST_EFFORT,
			"0",
			"0"
			);
	} else {
		loc_update_notification = loc_update_notification_create(
			"a",
			"a",
			ngmlc_location_loc_update_notification__NI_LR,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			ngmlc_location_loc_update_notification__REQUESTED_ACCURACY_FULFILLED,
			NULL,
			ngmlc_location_loc_update_notification__BEST_EFFORT,
			"0",
			"0"
			);
	}

	return loc_update_notification;
}


#ifdef loc_update_notification_MAIN

void test_loc_update_notification(int include_optional) {
	loc_update_notification_t *loc_update_notification_1 =
		instantiate_loc_update_notification(include_optional);

	cJSON *jsonloc_update_notification_1 =
		loc_update_notification_convertToJSON(loc_update_notification_1);
	printf("loc_update_notification :\n%s\n",
	       cJSON_Print(jsonloc_update_notification_1));
	loc_update_notification_t *loc_update_notification_2 =
		loc_update_notification_parseFromJSON(
			jsonloc_update_notification_1);
	cJSON *jsonloc_update_notification_2 =
		loc_update_notification_convertToJSON(loc_update_notification_2);
	printf("repeating loc_update_notification:\n%s\n",
	       cJSON_Print(jsonloc_update_notification_2));
}

int main() {
	test_loc_update_notification(1);
	test_loc_update_notification(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_update_notification_MAIN
#endif // loc_update_notification_TEST
