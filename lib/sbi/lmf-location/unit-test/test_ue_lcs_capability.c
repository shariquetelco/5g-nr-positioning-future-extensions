#ifndef ue_lcs_capability_TEST
#define ue_lcs_capability_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_lcs_capability_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_lcs_capability.h"
ue_lcs_capability_t *instantiate_ue_lcs_capability(int include_optional);



ue_lcs_capability_t *instantiate_ue_lcs_capability(int include_optional) {
	ue_lcs_capability_t *ue_lcs_capability = NULL;
	if(include_optional) {
		ue_lcs_capability = ue_lcs_capability_create(
			1,
			1
			);
	} else {
		ue_lcs_capability = ue_lcs_capability_create(
			1,
			1
			);
	}

	return ue_lcs_capability;
}


#ifdef ue_lcs_capability_MAIN

void test_ue_lcs_capability(int include_optional) {
	ue_lcs_capability_t *ue_lcs_capability_1 =
		instantiate_ue_lcs_capability(include_optional);

	cJSON *jsonue_lcs_capability_1 = ue_lcs_capability_convertToJSON(
		ue_lcs_capability_1);
	printf("ue_lcs_capability :\n%s\n",
	       cJSON_Print(jsonue_lcs_capability_1));
	ue_lcs_capability_t *ue_lcs_capability_2 =
		ue_lcs_capability_parseFromJSON(jsonue_lcs_capability_1);
	cJSON *jsonue_lcs_capability_2 = ue_lcs_capability_convertToJSON(
		ue_lcs_capability_2);
	printf("repeating ue_lcs_capability:\n%s\n",
	       cJSON_Print(jsonue_lcs_capability_2));
}

int main() {
	test_ue_lcs_capability(1);
	test_ue_lcs_capability(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_lcs_capability_MAIN
#endif // ue_lcs_capability_TEST
