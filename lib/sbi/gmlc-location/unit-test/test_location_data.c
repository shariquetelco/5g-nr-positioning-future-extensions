#ifndef location_data_TEST
#define location_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_data.h"
location_data_t *instantiate_location_data(int include_optional);

#include "test_geographic_area.c"
#include "test_civic_address.c"
#include "test_local_area.c"
#include "test_velocity_estimate.c"
#include "test_location_privacy_ver_result.c"
#include "test_minor_location_qo_s.c"
#include "test_periodic_event_info.c"
#include "test_high_accuracy_gnss_metrics.c"
#include "test_range_direction.c"
#include "test_model_2_d_relative_location.c"
#include "test_model_3_d_relative_location.c"
#include "test_velocity_estimate.c"


location_data_t *instantiate_location_data(int include_optional) {
	location_data_t *location_data = NULL;
	if(include_optional) {
		location_data = location_data_create(
			"a",
			"a",
			null,
			// false, not to have infinite recursion
			instantiate_civic_address(0),
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			list_createList(),
			list_createList(),
			ngmlc_location_location_data__REQUESTED_ACCURACY_FULFILLED,
			null,
			"01",
			-32767,
			"0",
			null,
			ngmlc_location_location_data__SUCCESS_COMPLETELY,
			// false, not to have infinite recursion
			instantiate_minor_location_qo_s(0),
			1,
			// false, not to have infinite recursion
			instantiate_periodic_event_info(0),
			// false, not to have infinite recursion
			instantiate_high_accuracy_gnss_metrics(0),
			ngmlc_location_location_data__LOS,
			ngmlc_location_location_data__INDOOR,
			"0",
			// false, not to have infinite recursion
			instantiate_range_direction(0),
			// false, not to have infinite recursion
			instantiate_model_2_d_relative_location(0),
			// false, not to have infinite recursion
			instantiate_model_3_d_relative_location(0),
			null
			);
	} else {
		location_data = location_data_create(
			"a",
			"a",
			null,
			NULL,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			list_createList(),
			list_createList(),
			ngmlc_location_location_data__REQUESTED_ACCURACY_FULFILLED,
			null,
			"01",
			-32767,
			"0",
			null,
			ngmlc_location_location_data__SUCCESS_COMPLETELY,
			NULL,
			1,
			NULL,
			NULL,
			ngmlc_location_location_data__LOS,
			ngmlc_location_location_data__INDOOR,
			"0",
			NULL,
			NULL,
			NULL,
			null
			);
	}

	return location_data;
}


#ifdef location_data_MAIN

void test_location_data(int include_optional) {
	location_data_t *location_data_1 = instantiate_location_data(
		include_optional);

	cJSON *jsonlocation_data_1 =
		location_data_convertToJSON(location_data_1);
	printf("location_data :\n%s\n", cJSON_Print(jsonlocation_data_1));
	location_data_t *location_data_2 = location_data_parseFromJSON(
		jsonlocation_data_1);
	cJSON *jsonlocation_data_2 =
		location_data_convertToJSON(location_data_2);
	printf("repeating location_data:\n%s\n", cJSON_Print(
		       jsonlocation_data_2));
}

int main() {
	test_location_data(1);
	test_location_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_data_MAIN
#endif // location_data_TEST
