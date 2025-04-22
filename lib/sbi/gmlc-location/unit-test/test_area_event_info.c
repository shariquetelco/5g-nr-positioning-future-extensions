#ifndef area_event_info_TEST
#define area_event_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define area_event_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/area_event_info.h"
area_event_info_t *instantiate_area_event_info(int include_optional);



area_event_info_t *instantiate_area_event_info(int include_optional) {
	area_event_info_t *area_event_info = NULL;
	if(include_optional) {
		area_event_info = area_event_info_create(
			list_createList(),
			ngmlc_location_area_event_info__ONE_TIME_EVENT,
			1,
			1,
			1,
			1,
			1
			);
	} else {
		area_event_info = area_event_info_create(
			list_createList(),
			ngmlc_location_area_event_info__ONE_TIME_EVENT,
			1,
			1,
			1,
			1,
			1
			);
	}

	return area_event_info;
}


#ifdef area_event_info_MAIN

void test_area_event_info(int include_optional) {
	area_event_info_t *area_event_info_1 = instantiate_area_event_info(
		include_optional);

	cJSON *jsonarea_event_info_1 = area_event_info_convertToJSON(
		area_event_info_1);
	printf("area_event_info :\n%s\n", cJSON_Print(jsonarea_event_info_1));
	area_event_info_t *area_event_info_2 = area_event_info_parseFromJSON(
		jsonarea_event_info_1);
	cJSON *jsonarea_event_info_2 = area_event_info_convertToJSON(
		area_event_info_2);
	printf("repeating area_event_info:\n%s\n",
	       cJSON_Print(jsonarea_event_info_2));
}

int main() {
	test_area_event_info(1);
	test_area_event_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // area_event_info_MAIN
#endif // area_event_info_TEST
