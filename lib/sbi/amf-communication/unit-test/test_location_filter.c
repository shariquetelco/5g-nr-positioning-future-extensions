#ifndef location_filter_TEST
#define location_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_filter.h"
location_filter_t *instantiate_location_filter(int include_optional);



location_filter_t *instantiate_location_filter(int include_optional) {
	location_filter_t *location_filter = NULL;
	if(include_optional) {
		location_filter = location_filter_create(
			);
	} else {
		location_filter = location_filter_create(
			);
	}

	return location_filter;
}


#ifdef location_filter_MAIN

void test_location_filter(int include_optional) {
	location_filter_t *location_filter_1 = instantiate_location_filter(
		include_optional);

	cJSON *jsonlocation_filter_1 = location_filter_convertToJSON(
		location_filter_1);
	printf("location_filter :\n%s\n", cJSON_Print(jsonlocation_filter_1));
	location_filter_t *location_filter_2 = location_filter_parseFromJSON(
		jsonlocation_filter_1);
	cJSON *jsonlocation_filter_2 = location_filter_convertToJSON(
		location_filter_2);
	printf("repeating location_filter:\n%s\n",
	       cJSON_Print(jsonlocation_filter_2));
}

int main() {
	test_location_filter(1);
	test_location_filter(0);

	printf("Hello world \n");
	return 0;
}

#endif // location_filter_MAIN
#endif // location_filter_TEST
