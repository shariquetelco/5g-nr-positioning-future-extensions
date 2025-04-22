#ifndef loc_context_data_TEST
#define loc_context_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_context_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_context_data.h"
loc_context_data_t *instantiate_loc_context_data(int include_optional);

#include "test_location_qo_s.c"
#include "test_periodic_event_info.c"
#include "test_area_event_info.c"
#include "test_motion_event_info.c"
#include "test_event_report_message.c"
#include "test_event_reporting_status.c"
#include "test_ue_location_info.c"
#include "test_ecgi.c"
#include "test_ncgi.c"
#include "test_guami.c"
#include "test_up_cum_evt_rpt_criteria.c"


loc_context_data_t *instantiate_loc_context_data(int include_optional) {
	loc_context_data_t *loc_context_data = NULL;
	if(include_optional) {
		loc_context_data = loc_context_data_create(
			"0",
			// false, not to have infinite recursion
			instantiate_location_qo_s(0),
			list_createList(),
			"a",
			"a",
			lmf_location_loc_context_data__UE_AVAILABLE,
			"0",
			"01",
			// false, not to have infinite recursion
			instantiate_periodic_event_info(0),
			// false, not to have infinite recursion
			instantiate_area_event_info(0),
			// false, not to have infinite recursion
			instantiate_motion_event_info(0),
			// false, not to have infinite recursion
			instantiate_event_report_message(0),
			// false, not to have infinite recursion
			instantiate_event_reporting_status(0),
			// false, not to have infinite recursion
			instantiate_ue_location_info(0),
			1,
			// false, not to have infinite recursion
			instantiate_ecgi(0),
			// false, not to have infinite recursion
			instantiate_ncgi(0),
			// false, not to have infinite recursion
			instantiate_guami(0),
			"a",
			"YQ==",
			"2013-10-20T19:20:30+01:00",
			lmf_location_loc_context_data__INDOOR,
			lmf_location_loc_context_data__LOS,
			// false, not to have infinite recursion
			instantiate_up_cum_evt_rpt_criteria(0)
			);
	} else {
		loc_context_data = loc_context_data_create(
			"0",
			NULL,
			list_createList(),
			"a",
			"a",
			lmf_location_loc_context_data__UE_AVAILABLE,
			"0",
			"01",
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			1,
			NULL,
			NULL,
			NULL,
			"a",
			"YQ==",
			"2013-10-20T19:20:30+01:00",
			lmf_location_loc_context_data__INDOOR,
			lmf_location_loc_context_data__LOS,
			NULL
			);
	}

	return loc_context_data;
}


#ifdef loc_context_data_MAIN

void test_loc_context_data(int include_optional) {
	loc_context_data_t *loc_context_data_1 = instantiate_loc_context_data(
		include_optional);

	cJSON *jsonloc_context_data_1 = loc_context_data_convertToJSON(
		loc_context_data_1);
	printf("loc_context_data :\n%s\n", cJSON_Print(jsonloc_context_data_1));
	loc_context_data_t *loc_context_data_2 = loc_context_data_parseFromJSON(
		jsonloc_context_data_1);
	cJSON *jsonloc_context_data_2 = loc_context_data_convertToJSON(
		loc_context_data_2);
	printf("repeating loc_context_data:\n%s\n",
	       cJSON_Print(jsonloc_context_data_2));
}

int main() {
	test_loc_context_data(1);
	test_loc_context_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_context_data_MAIN
#endif // loc_context_data_TEST
