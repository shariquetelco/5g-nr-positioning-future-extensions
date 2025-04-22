#ifndef ue_proximity_TEST
#define ue_proximity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_proximity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_proximity.h"
ue_proximity_t *instantiate_ue_proximity(int include_optional);

#include "test_velocity_estimate.c"
#include "test_location_orientation.c"


ue_proximity_t *instantiate_ue_proximity(int include_optional) {
	ue_proximity_t *ue_proximity = NULL;
	if(include_optional) {
		ue_proximity = ue_proximity_create(
			56,
			null,
			1.337,
			null,
			list_createList(),
			1
			);
	} else {
		ue_proximity = ue_proximity_create(
			56,
			null,
			1.337,
			null,
			list_createList(),
			1
			);
	}

	return ue_proximity;
}


#ifdef ue_proximity_MAIN

void test_ue_proximity(int include_optional) {
	ue_proximity_t *ue_proximity_1 = instantiate_ue_proximity(
		include_optional);

	cJSON *jsonue_proximity_1 = ue_proximity_convertToJSON(ue_proximity_1);
	printf("ue_proximity :\n%s\n", cJSON_Print(jsonue_proximity_1));
	ue_proximity_t *ue_proximity_2 = ue_proximity_parseFromJSON(
		jsonue_proximity_1);
	cJSON *jsonue_proximity_2 = ue_proximity_convertToJSON(ue_proximity_2);
	printf("repeating ue_proximity:\n%s\n",
	       cJSON_Print(jsonue_proximity_2));
}

int main() {
	test_ue_proximity(1);
	test_ue_proximity(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_proximity_MAIN
#endif // ue_proximity_TEST
