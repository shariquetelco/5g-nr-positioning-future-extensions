#ifndef ue_connectivity_state_TEST
#define ue_connectivity_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_connectivity_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_connectivity_state.h"
ue_connectivity_state_t *instantiate_ue_connectivity_state(
	int include_optional);

#include "test_cm_state.c"


ue_connectivity_state_t *instantiate_ue_connectivity_state(int include_optional)
{
	ue_connectivity_state_t *ue_connectivity_state = NULL;
	if(include_optional) {
		ue_connectivity_state = ue_connectivity_state_create(
			lmf_location_ue_connectivity_state__3GPP_ACCESS,
			null
			);
	} else {
		ue_connectivity_state = ue_connectivity_state_create(
			lmf_location_ue_connectivity_state__3GPP_ACCESS,
			null
			);
	}

	return ue_connectivity_state;
}


#ifdef ue_connectivity_state_MAIN

void test_ue_connectivity_state(int include_optional) {
	ue_connectivity_state_t *ue_connectivity_state_1 =
		instantiate_ue_connectivity_state(include_optional);

	cJSON *jsonue_connectivity_state_1 =
		ue_connectivity_state_convertToJSON(ue_connectivity_state_1);
	printf("ue_connectivity_state :\n%s\n",
	       cJSON_Print(jsonue_connectivity_state_1));
	ue_connectivity_state_t *ue_connectivity_state_2 =
		ue_connectivity_state_parseFromJSON(jsonue_connectivity_state_1);
	cJSON *jsonue_connectivity_state_2 =
		ue_connectivity_state_convertToJSON(ue_connectivity_state_2);
	printf("repeating ue_connectivity_state:\n%s\n",
	       cJSON_Print(jsonue_connectivity_state_2));
}

int main() {
	test_ue_connectivity_state(1);
	test_ue_connectivity_state(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_connectivity_state_MAIN
#endif // ue_connectivity_state_TEST
