#ifndef location_qo_s_TEST
#define location_qo_s_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_qo_s_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_qo_s.h"
location_qo_s_t *instantiate_location_qo_s(int include_optional);



location_qo_s_t *instantiate_location_qo_s(int include_optional) {
	location_qo_s_t *location_qo_s = NULL;
	if(include_optional) {
		location_qo_s = location_qo_s_create(
			0,
			0,
			1,
			ngmlc_location_location_qo_s__LOW_DELAY,
			list_createList(),
			ngmlc_location_location_qo_s__BEST_EFFORT
			);
	} else {
		location_qo_s = location_qo_s_create(
			0,
			0,
			1,
			ngmlc_location_location_qo_s__LOW_DELAY,
			list_createList(),
			ngmlc_location_location_qo_s__BEST_EFFORT
			);
	}

	return location_qo_s;
}


#ifdef location_qo_s_MAIN

void test_location_qo_s(int include_optional) {
	location_qo_s_t *location_qo_s_1 = instantiate_location_qo_s(
		include_optional);

	cJSON *jsonlocation_qo_s_1 =
		location_qo_s_convertToJSON(location_qo_s_1);
	printf("location_qo_s :\n%s\n", cJSON_Print(jsonlocation_qo_s_1));
	location_qo_s_t *location_qo_s_2 = location_qo_s_parseFromJSON(
		jsonlocation_qo_s_1);
	cJSON *jsonlocation_qo_s_2 =
		location_qo_s_convertToJSON(location_qo_s_2);
	printf("repeating location_qo_s:\n%s\n", cJSON_Print(
		       jsonlocation_qo_s_2));
}

int main() {
	test_location_qo_s(1);
	test_location_qo_s(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_qo_s_MAIN
#endif // location_qo_s_TEST
