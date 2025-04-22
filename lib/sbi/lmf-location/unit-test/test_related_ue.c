#ifndef related_ue_TEST
#define related_ue_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define related_ue_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/related_ue.h"
related_ue_t *instantiate_related_ue(int include_optional);



related_ue_t *instantiate_related_ue(int include_optional) {
	related_ue_t *related_ue = NULL;
	if(include_optional) {
		related_ue = related_ue_create(
			"0",
			lmf_location_related_ue__LOCATED_UE
			);
	} else {
		related_ue = related_ue_create(
			"0",
			lmf_location_related_ue__LOCATED_UE
			);
	}

	return related_ue;
}


#ifdef related_ue_MAIN

void test_related_ue(int include_optional) {
	related_ue_t *related_ue_1 = instantiate_related_ue(include_optional);

	cJSON *jsonrelated_ue_1 = related_ue_convertToJSON(related_ue_1);
	printf("related_ue :\n%s\n", cJSON_Print(jsonrelated_ue_1));
	related_ue_t *related_ue_2 = related_ue_parseFromJSON(jsonrelated_ue_1);
	cJSON *jsonrelated_ue_2 = related_ue_convertToJSON(related_ue_2);
	printf("repeating related_ue:\n%s\n", cJSON_Print(jsonrelated_ue_2));
}

int main() {
	test_related_ue(1);
	test_related_ue(0);

	printf("Hello world \n");
	return 0;
}

#endif // related_ue_MAIN
#endif // related_ue_TEST
