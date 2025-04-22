#ifndef ue_differentiation_info_TEST
#define ue_differentiation_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_differentiation_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_differentiation_info.h"
ue_differentiation_info_t *instantiate_ue_differentiation_info(
	int include_optional);

#include "test_scheduled_communication_time.c"
#include "test_stationary_indication.c"
#include "test_traffic_profile.c"
#include "test_battery_indication.c"


ue_differentiation_info_t *instantiate_ue_differentiation_info(
	int include_optional) {
	ue_differentiation_info_t *ue_differentiation_info = NULL;
	if(include_optional) {
		ue_differentiation_info = ue_differentiation_info_create(
			namf_communication_ue_differentiation_info__PIORIODICALLY,
			56,
			// false, not to have infinite recursion
			instantiate_scheduled_communication_time(0),
			null,
			null,
			// false, not to have infinite recursion
			instantiate_battery_indication(0),
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		ue_differentiation_info = ue_differentiation_info_create(
			namf_communication_ue_differentiation_info__PIORIODICALLY,
			56,
			NULL,
			null,
			null,
			NULL,
			"2013-10-20T19:20:30+01:00"
			);
	}

	return ue_differentiation_info;
}


#ifdef ue_differentiation_info_MAIN

void test_ue_differentiation_info(int include_optional) {
	ue_differentiation_info_t *ue_differentiation_info_1 =
		instantiate_ue_differentiation_info(include_optional);

	cJSON *jsonue_differentiation_info_1 =
		ue_differentiation_info_convertToJSON(ue_differentiation_info_1);
	printf("ue_differentiation_info :\n%s\n",
	       cJSON_Print(jsonue_differentiation_info_1));
	ue_differentiation_info_t *ue_differentiation_info_2 =
		ue_differentiation_info_parseFromJSON(
			jsonue_differentiation_info_1);
	cJSON *jsonue_differentiation_info_2 =
		ue_differentiation_info_convertToJSON(ue_differentiation_info_2);
	printf("repeating ue_differentiation_info:\n%s\n",
	       cJSON_Print(jsonue_differentiation_info_2));
}

int main() {
	test_ue_differentiation_info(1);
	test_ue_differentiation_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_differentiation_info_MAIN
#endif // ue_differentiation_info_TEST
