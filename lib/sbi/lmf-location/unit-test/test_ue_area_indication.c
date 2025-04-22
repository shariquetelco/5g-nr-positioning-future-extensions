#ifndef ue_area_indication_TEST
#define ue_area_indication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_area_indication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_area_indication.h"
ue_area_indication_t *instantiate_ue_area_indication(int include_optional);



ue_area_indication_t *instantiate_ue_area_indication(int include_optional) {
	ue_area_indication_t *ue_area_indication = NULL;
	if(include_optional) {
		ue_area_indication = ue_area_indication_create(
			"0",
			1
			);
	} else {
		ue_area_indication = ue_area_indication_create(
			"0",
			1
			);
	}

	return ue_area_indication;
}


#ifdef ue_area_indication_MAIN

void test_ue_area_indication(int include_optional) {
	ue_area_indication_t *ue_area_indication_1 =
		instantiate_ue_area_indication(include_optional);

	cJSON *jsonue_area_indication_1 = ue_area_indication_convertToJSON(
		ue_area_indication_1);
	printf("ue_area_indication :\n%s\n",
	       cJSON_Print(jsonue_area_indication_1));
	ue_area_indication_t *ue_area_indication_2 =
		ue_area_indication_parseFromJSON(jsonue_area_indication_1);
	cJSON *jsonue_area_indication_2 = ue_area_indication_convertToJSON(
		ue_area_indication_2);
	printf("repeating ue_area_indication:\n%s\n",
	       cJSON_Print(jsonue_area_indication_2));
}

int main() {
	test_ue_area_indication(1);
	test_ue_area_indication(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_area_indication_MAIN
#endif // ue_area_indication_TEST
