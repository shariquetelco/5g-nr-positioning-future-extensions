#ifndef ue_mobility_TEST
#define ue_mobility_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_mobility_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_mobility.h"
ue_mobility_t *instantiate_ue_mobility(int include_optional);

#include "test_scheduled_communication_time_1.c"


ue_mobility_t *instantiate_ue_mobility(int include_optional) {
	ue_mobility_t *ue_mobility = NULL;
	if(include_optional) {
		ue_mobility = ue_mobility_create(
			"2013-10-20T19:20:30+01:00",
			// false, not to have infinite recursion
			instantiate_scheduled_communication_time_1(0),
			56,
			1.337,
			list_createList(),
			list_createList()
			);
	} else {
		ue_mobility = ue_mobility_create(
			"2013-10-20T19:20:30+01:00",
			NULL,
			56,
			1.337,
			list_createList(),
			list_createList()
			);
	}

	return ue_mobility;
}


#ifdef ue_mobility_MAIN

void test_ue_mobility(int include_optional) {
	ue_mobility_t *ue_mobility_1 =
		instantiate_ue_mobility(include_optional);

	cJSON *jsonue_mobility_1 = ue_mobility_convertToJSON(ue_mobility_1);
	printf("ue_mobility :\n%s\n", cJSON_Print(jsonue_mobility_1));
	ue_mobility_t *ue_mobility_2 = ue_mobility_parseFromJSON(
		jsonue_mobility_1);
	cJSON *jsonue_mobility_2 = ue_mobility_convertToJSON(ue_mobility_2);
	printf("repeating ue_mobility:\n%s\n", cJSON_Print(jsonue_mobility_2));
}

int main() {
	test_ue_mobility(1);
	test_ue_mobility(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_mobility_MAIN
#endif // ue_mobility_TEST
