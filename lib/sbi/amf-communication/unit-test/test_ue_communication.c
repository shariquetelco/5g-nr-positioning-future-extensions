#ifndef ue_communication_TEST
#define ue_communication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_communication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_communication.h"
ue_communication_t *instantiate_ue_communication(int include_optional);

#include "test_scheduled_communication_time_1.c"
#include "test_traffic_characterization.c"
#include "test_app_list_for_ue_comm.c"
#include "test_sess_inact_timer_for_ue_comm.c"


ue_communication_t *instantiate_ue_communication(int include_optional) {
	ue_communication_t *ue_communication = NULL;
	if(include_optional) {
		ue_communication = ue_communication_create(
			56,
			1.337,
			56,
			1.337,
			"2013-10-20T19:20:30+01:00",
			1.337,
			// false, not to have infinite recursion
			instantiate_scheduled_communication_time_1(0),
			// false, not to have infinite recursion
			instantiate_traffic_characterization(0),
			1,
			1,
			0,
			// false, not to have infinite recursion
			instantiate_app_list_for_ue_comm(0),
			// false, not to have infinite recursion
			instantiate_sess_inact_timer_for_ue_comm(0)
			);
	} else {
		ue_communication = ue_communication_create(
			56,
			1.337,
			56,
			1.337,
			"2013-10-20T19:20:30+01:00",
			1.337,
			NULL,
			NULL,
			1,
			1,
			0,
			NULL,
			NULL
			);
	}

	return ue_communication;
}


#ifdef ue_communication_MAIN

void test_ue_communication(int include_optional) {
	ue_communication_t *ue_communication_1 = instantiate_ue_communication(
		include_optional);

	cJSON *jsonue_communication_1 = ue_communication_convertToJSON(
		ue_communication_1);
	printf("ue_communication :\n%s\n", cJSON_Print(jsonue_communication_1));
	ue_communication_t *ue_communication_2 = ue_communication_parseFromJSON(
		jsonue_communication_1);
	cJSON *jsonue_communication_2 = ue_communication_convertToJSON(
		ue_communication_2);
	printf("repeating ue_communication:\n%s\n",
	       cJSON_Print(jsonue_communication_2));
}

int main() {
	test_ue_communication(1);
	test_ue_communication(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_communication_MAIN
#endif // ue_communication_TEST
