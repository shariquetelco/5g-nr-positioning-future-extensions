#ifndef ue_location_info_TEST
#define ue_location_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_location_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_location_info.h"
ue_location_info_t *instantiate_ue_location_info(int include_optional);

#include "test_geographic_area.c"
#include "test_velocity_estimate.c"


ue_location_info_t *instantiate_ue_location_info(int include_optional) {
	ue_location_info_t *ue_location_info = NULL;
	if(include_optional) {
		ue_location_info = ue_location_info_create(
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			null,
			0,
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		ue_location_info = ue_location_info_create(
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			null,
			0,
			"2013-10-20T19:20:30+01:00"
			);
	}

	return ue_location_info;
}


#ifdef ue_location_info_MAIN

void test_ue_location_info(int include_optional) {
	ue_location_info_t *ue_location_info_1 = instantiate_ue_location_info(
		include_optional);

	cJSON *jsonue_location_info_1 = ue_location_info_convertToJSON(
		ue_location_info_1);
	printf("ue_location_info :\n%s\n", cJSON_Print(jsonue_location_info_1));
	ue_location_info_t *ue_location_info_2 = ue_location_info_parseFromJSON(
		jsonue_location_info_1);
	cJSON *jsonue_location_info_2 = ue_location_info_convertToJSON(
		ue_location_info_2);
	printf("repeating ue_location_info:\n%s\n",
	       cJSON_Print(jsonue_location_info_2));
}

int main() {
	test_ue_location_info(1);
	test_ue_location_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_location_info_MAIN
#endif // ue_location_info_TEST
