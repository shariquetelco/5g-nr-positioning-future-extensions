#ifndef area_of_interest_event_state_TEST
#define area_of_interest_event_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define area_of_interest_event_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/area_of_interest_event_state.h"
area_of_interest_event_state_t *instantiate_area_of_interest_event_state(
	int include_optional);

#include "test_presence_state.c"


area_of_interest_event_state_t *instantiate_area_of_interest_event_state(
	int include_optional) {
	area_of_interest_event_state_t *area_of_interest_event_state = NULL;
	if(include_optional) {
		area_of_interest_event_state =
			area_of_interest_event_state_create(
				null,
				list_createList()
				);
	} else {
		area_of_interest_event_state =
			area_of_interest_event_state_create(
				null,
				list_createList()
				);
	}

	return area_of_interest_event_state;
}


#ifdef area_of_interest_event_state_MAIN

void test_area_of_interest_event_state(int include_optional) {
	area_of_interest_event_state_t *area_of_interest_event_state_1 =
		instantiate_area_of_interest_event_state(include_optional);

	cJSON *jsonarea_of_interest_event_state_1 =
		area_of_interest_event_state_convertToJSON(
			area_of_interest_event_state_1);
	printf("area_of_interest_event_state :\n%s\n",
	       cJSON_Print(jsonarea_of_interest_event_state_1));
	area_of_interest_event_state_t *area_of_interest_event_state_2 =
		area_of_interest_event_state_parseFromJSON(
			jsonarea_of_interest_event_state_1);
	cJSON *jsonarea_of_interest_event_state_2 =
		area_of_interest_event_state_convertToJSON(
			area_of_interest_event_state_2);
	printf("repeating area_of_interest_event_state:\n%s\n",
	       cJSON_Print(jsonarea_of_interest_event_state_2));
}

int main() {
	test_area_of_interest_event_state(1);
	test_area_of_interest_event_state(0);

	printf("Hello world \n");
	return 0;
}

#endif // area_of_interest_event_state_MAIN
#endif // area_of_interest_event_state_TEST
