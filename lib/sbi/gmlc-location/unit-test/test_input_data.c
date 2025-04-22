#ifndef input_data_TEST
#define input_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_data.h"
input_data_t *instantiate_input_data(int include_optional);

#include "test_location_qo_s.c"
#include "test_periodic_event_info.c"
#include "test_area_event_info_ext.c"
#include "test_motion_event_info.c"
#include "test_ue_privacy_requirements.c"
#include "test_lp_hap_type.c"
#include "test_geographic_area.c"
#include "test_input_data_reporting_ind.c"
#include "test_integrity_requirements.c"
#include "test_up_loc_rep_info_af.c"
#include "test_mapped_location_qo_s_eps.c"


input_data_t *instantiate_input_data(int include_optional) {
	input_data_t *input_data = NULL;
	if(include_optional) {
		input_data = input_data_create(
			"a",
			"a",
			"0",
			"a",
			"a",
			ngmlc_location_input_data__EMERGENCY_SERVICES,
			// false, not to have infinite recursion
			instantiate_location_qo_s(0),
			list_createList(),
			"0",
			list_createList(),
			ngmlc_location_input_data__UE_AVAILABLE,
			// false, not to have infinite recursion
			instantiate_periodic_event_info(0),
			null,
			// false, not to have infinite recursion
			instantiate_motion_event_info(0),
			"01",
			"0",
			"0",
			"0",
			"0",
			// false, not to have infinite recursion
			instantiate_ue_privacy_requirements(0),
			0,
			ngmlc_location_input_data__VELOCITY_IS_NOT_REQUESTED,
			ngmlc_location_input_data__HIGHEST_PRIORITY,
			ngmlc_location_input_data__CURRENT_LOCATION,
			0,
			"a",
			"0",
			"2013-10-20T19:20:30+01:00",
			1,
			"0",
			null,
			null,
			null,
			// false, not to have infinite recursion
			instantiate_integrity_requirements(0),
			// false, not to have infinite recursion
			instantiate_up_loc_rep_info_af(0),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_mapped_location_qo_s_eps(0),
			56
			);
	} else {
		input_data = input_data_create(
			"a",
			"a",
			"0",
			"a",
			"a",
			ngmlc_location_input_data__EMERGENCY_SERVICES,
			NULL,
			list_createList(),
			"0",
			list_createList(),
			ngmlc_location_input_data__UE_AVAILABLE,
			NULL,
			null,
			NULL,
			"01",
			"0",
			"0",
			"0",
			"0",
			NULL,
			0,
			ngmlc_location_input_data__VELOCITY_IS_NOT_REQUESTED,
			ngmlc_location_input_data__HIGHEST_PRIORITY,
			ngmlc_location_input_data__CURRENT_LOCATION,
			0,
			"a",
			"0",
			"2013-10-20T19:20:30+01:00",
			1,
			"0",
			null,
			null,
			null,
			NULL,
			NULL,
			list_createList(),
			list_createList(),
			NULL,
			56
			);
	}

	return input_data;
}


#ifdef input_data_MAIN

void test_input_data(int include_optional) {
	input_data_t *input_data_1 = instantiate_input_data(include_optional);

	cJSON *jsoninput_data_1 = input_data_convertToJSON(input_data_1);
	printf("input_data :\n%s\n", cJSON_Print(jsoninput_data_1));
	input_data_t *input_data_2 = input_data_parseFromJSON(jsoninput_data_1);
	cJSON *jsoninput_data_2 = input_data_convertToJSON(input_data_2);
	printf("repeating input_data:\n%s\n", cJSON_Print(jsoninput_data_2));
}

int main() {
	test_input_data(1);
	test_input_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // input_data_MAIN
#endif // input_data_TEST
