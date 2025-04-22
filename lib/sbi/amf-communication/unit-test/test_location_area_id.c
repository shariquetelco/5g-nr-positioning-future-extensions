#ifndef location_area_id_TEST
#define location_area_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_area_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_area_id.h"
location_area_id_t *instantiate_location_area_id(int include_optional);

#include "test_plmn_id.c"


location_area_id_t *instantiate_location_area_id(int include_optional) {
	location_area_id_t *location_area_id = NULL;
	if(include_optional) {
		location_area_id = location_area_id_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a"
			);
	} else {
		location_area_id = location_area_id_create(
			NULL,
			"a"
			);
	}

	return location_area_id;
}


#ifdef location_area_id_MAIN

void test_location_area_id(int include_optional) {
	location_area_id_t *location_area_id_1 = instantiate_location_area_id(
		include_optional);

	cJSON *jsonlocation_area_id_1 = location_area_id_convertToJSON(
		location_area_id_1);
	printf("location_area_id :\n%s\n", cJSON_Print(jsonlocation_area_id_1));
	location_area_id_t *location_area_id_2 = location_area_id_parseFromJSON(
		jsonlocation_area_id_1);
	cJSON *jsonlocation_area_id_2 = location_area_id_convertToJSON(
		location_area_id_2);
	printf("repeating location_area_id:\n%s\n",
	       cJSON_Print(jsonlocation_area_id_2));
}

int main() {
	test_location_area_id(1);
	test_location_area_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_area_id_MAIN
#endif // location_area_id_TEST
