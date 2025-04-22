#ifndef ue_up_positioning_capabilities_TEST
#define ue_up_positioning_capabilities_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_up_positioning_capabilities_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_up_positioning_capabilities.h"
ue_up_positioning_capabilities_t *instantiate_ue_up_positioning_capabilities(
	int include_optional);



ue_up_positioning_capabilities_t *instantiate_ue_up_positioning_capabilities(
	int include_optional) {
	ue_up_positioning_capabilities_t *ue_up_positioning_capabilities = NULL;
	if(include_optional) {
		ue_up_positioning_capabilities =
			ue_up_positioning_capabilities_create(
				);
	} else {
		ue_up_positioning_capabilities =
			ue_up_positioning_capabilities_create(
				);
	}

	return ue_up_positioning_capabilities;
}


#ifdef ue_up_positioning_capabilities_MAIN

void test_ue_up_positioning_capabilities(int include_optional) {
	ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_1 =
		instantiate_ue_up_positioning_capabilities(include_optional);

	cJSON *jsonue_up_positioning_capabilities_1 =
		ue_up_positioning_capabilities_convertToJSON(
			ue_up_positioning_capabilities_1);
	printf("ue_up_positioning_capabilities :\n%s\n",
	       cJSON_Print(jsonue_up_positioning_capabilities_1));
	ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_2 =
		ue_up_positioning_capabilities_parseFromJSON(
			jsonue_up_positioning_capabilities_1);
	cJSON *jsonue_up_positioning_capabilities_2 =
		ue_up_positioning_capabilities_convertToJSON(
			ue_up_positioning_capabilities_2);
	printf("repeating ue_up_positioning_capabilities:\n%s\n",
	       cJSON_Print(jsonue_up_positioning_capabilities_2));
}

int main() {
	test_ue_up_positioning_capabilities(1);
	test_ue_up_positioning_capabilities(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_up_positioning_capabilities_MAIN
#endif // ue_up_positioning_capabilities_TEST
