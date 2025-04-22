#ifndef area_event_info_ext_TEST
#define area_event_info_ext_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define area_event_info_ext_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/area_event_info_ext.h"
area_event_info_ext_t *instantiate_area_event_info_ext(int include_optional);



area_event_info_ext_t *instantiate_area_event_info_ext(int include_optional) {
	area_event_info_ext_t *area_event_info_ext = NULL;
	if(include_optional) {
		area_event_info_ext = area_event_info_ext_create(
			list_createList(),
			ngmlc_location_area_event_info_ext__ONE_TIME_EVENT,
			1,
			1,
			1,
			1,
			1,
			list_createList(),
			1,
			1
			);
	} else {
		area_event_info_ext = area_event_info_ext_create(
			list_createList(),
			ngmlc_location_area_event_info_ext__ONE_TIME_EVENT,
			1,
			1,
			1,
			1,
			1,
			list_createList(),
			1,
			1
			);
	}

	return area_event_info_ext;
}


#ifdef area_event_info_ext_MAIN

void test_area_event_info_ext(int include_optional) {
	area_event_info_ext_t *area_event_info_ext_1 =
		instantiate_area_event_info_ext(include_optional);

	cJSON *jsonarea_event_info_ext_1 = area_event_info_ext_convertToJSON(
		area_event_info_ext_1);
	printf("area_event_info_ext :\n%s\n",
	       cJSON_Print(jsonarea_event_info_ext_1));
	area_event_info_ext_t *area_event_info_ext_2 =
		area_event_info_ext_parseFromJSON(jsonarea_event_info_ext_1);
	cJSON *jsonarea_event_info_ext_2 = area_event_info_ext_convertToJSON(
		area_event_info_ext_2);
	printf("repeating area_event_info_ext:\n%s\n",
	       cJSON_Print(jsonarea_event_info_ext_2));
}

int main() {
	test_area_event_info_ext(1);
	test_area_event_info_ext(0);

	printf("Hello world \n");
	return 0;
}

#endif // area_event_info_ext_MAIN
#endif // area_event_info_ext_TEST
