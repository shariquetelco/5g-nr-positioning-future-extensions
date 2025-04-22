#ifndef reporting_area_type_TEST
#define reporting_area_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reporting_area_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reporting_area_type.h"
reporting_area_type_t *instantiate_reporting_area_type(int include_optional);



reporting_area_type_t *instantiate_reporting_area_type(int include_optional) {
	reporting_area_type_t *reporting_area_type = NULL;
	if(include_optional) {
		reporting_area_type = reporting_area_type_create(
			);
	} else {
		reporting_area_type = reporting_area_type_create(
			);
	}

	return reporting_area_type;
}


#ifdef reporting_area_type_MAIN

void test_reporting_area_type(int include_optional) {
	reporting_area_type_t *reporting_area_type_1 =
		instantiate_reporting_area_type(include_optional);

	cJSON *jsonreporting_area_type_1 = reporting_area_type_convertToJSON(
		reporting_area_type_1);
	printf("reporting_area_type :\n%s\n",
	       cJSON_Print(jsonreporting_area_type_1));
	reporting_area_type_t *reporting_area_type_2 =
		reporting_area_type_parseFromJSON(jsonreporting_area_type_1);
	cJSON *jsonreporting_area_type_2 = reporting_area_type_convertToJSON(
		reporting_area_type_2);
	printf("repeating reporting_area_type:\n%s\n",
	       cJSON_Print(jsonreporting_area_type_2));
}

int main() {
	test_reporting_area_type(1);
	test_reporting_area_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // reporting_area_type_MAIN
#endif // reporting_area_type_TEST
