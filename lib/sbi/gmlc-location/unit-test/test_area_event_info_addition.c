#ifndef area_event_info_addition_TEST
#define area_event_info_addition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define area_event_info_addition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/area_event_info_addition.h"
area_event_info_addition_t *instantiate_area_event_info_addition(
	int include_optional);



area_event_info_addition_t *instantiate_area_event_info_addition(
	int include_optional) {
	area_event_info_addition_t *area_event_info_addition = NULL;
	if(include_optional) {
		area_event_info_addition = area_event_info_addition_create(
			list_createList(),
			1,
			1
			);
	} else {
		area_event_info_addition = area_event_info_addition_create(
			list_createList(),
			1,
			1
			);
	}

	return area_event_info_addition;
}


#ifdef area_event_info_addition_MAIN

void test_area_event_info_addition(int include_optional) {
	area_event_info_addition_t *area_event_info_addition_1 =
		instantiate_area_event_info_addition(include_optional);

	cJSON *jsonarea_event_info_addition_1 =
		area_event_info_addition_convertToJSON(
			area_event_info_addition_1);
	printf("area_event_info_addition :\n%s\n",
	       cJSON_Print(jsonarea_event_info_addition_1));
	area_event_info_addition_t *area_event_info_addition_2 =
		area_event_info_addition_parseFromJSON(
			jsonarea_event_info_addition_1);
	cJSON *jsonarea_event_info_addition_2 =
		area_event_info_addition_convertToJSON(
			area_event_info_addition_2);
	printf("repeating area_event_info_addition:\n%s\n",
	       cJSON_Print(jsonarea_event_info_addition_2));
}

int main() {
	test_area_event_info_addition(1);
	test_area_event_info_addition(0);

	printf("Hello world \n");
	return 0;
}

#endif // area_event_info_addition_MAIN
#endif // area_event_info_addition_TEST
