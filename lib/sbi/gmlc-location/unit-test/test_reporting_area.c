#ifndef reporting_area_TEST
#define reporting_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reporting_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reporting_area.h"
reporting_area_t *instantiate_reporting_area(int include_optional);

#include "test_tai.c"
#include "test_ecgi.c"
#include "test_ncgi.c"


reporting_area_t *instantiate_reporting_area(int include_optional) {
	reporting_area_t *reporting_area = NULL;
	if(include_optional) {
		reporting_area = reporting_area_create(
			ngmlc_location_reporting_area__EPS_TRACKING_AREA_IDENTITY,
			// false, not to have infinite recursion
			instantiate_tai(0),
			// false, not to have infinite recursion
			instantiate_ecgi(0),
			// false, not to have infinite recursion
			instantiate_ncgi(0)
			);
	} else {
		reporting_area = reporting_area_create(
			ngmlc_location_reporting_area__EPS_TRACKING_AREA_IDENTITY,
			NULL,
			NULL,
			NULL
			);
	}

	return reporting_area;
}


#ifdef reporting_area_MAIN

void test_reporting_area(int include_optional) {
	reporting_area_t *reporting_area_1 = instantiate_reporting_area(
		include_optional);

	cJSON *jsonreporting_area_1 = reporting_area_convertToJSON(
		reporting_area_1);
	printf("reporting_area :\n%s\n", cJSON_Print(jsonreporting_area_1));
	reporting_area_t *reporting_area_2 = reporting_area_parseFromJSON(
		jsonreporting_area_1);
	cJSON *jsonreporting_area_2 = reporting_area_convertToJSON(
		reporting_area_2);
	printf("repeating reporting_area:\n%s\n",
	       cJSON_Print(jsonreporting_area_2));
}

int main() {
	test_reporting_area(1);
	test_reporting_area(0);

	printf("Hello world \n");
	return 0;
}

#endif // reporting_area_MAIN
#endif // reporting_area_TEST
