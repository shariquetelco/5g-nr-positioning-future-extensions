#ifndef ue_privacy_requirements_TEST
#define ue_privacy_requirements_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_privacy_requirements_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_privacy_requirements.h"
ue_privacy_requirements_t *instantiate_ue_privacy_requirements(
	int include_optional);

#include "test_lcs_service_auth.c"


ue_privacy_requirements_t *instantiate_ue_privacy_requirements(
	int include_optional) {
	ue_privacy_requirements_t *ue_privacy_requirements = NULL;
	if(include_optional) {
		ue_privacy_requirements = ue_privacy_requirements_create(
			null,
			1
			);
	} else {
		ue_privacy_requirements = ue_privacy_requirements_create(
			null,
			1
			);
	}

	return ue_privacy_requirements;
}


#ifdef ue_privacy_requirements_MAIN

void test_ue_privacy_requirements(int include_optional) {
	ue_privacy_requirements_t *ue_privacy_requirements_1 =
		instantiate_ue_privacy_requirements(include_optional);

	cJSON *jsonue_privacy_requirements_1 =
		ue_privacy_requirements_convertToJSON(ue_privacy_requirements_1);
	printf("ue_privacy_requirements :\n%s\n",
	       cJSON_Print(jsonue_privacy_requirements_1));
	ue_privacy_requirements_t *ue_privacy_requirements_2 =
		ue_privacy_requirements_parseFromJSON(
			jsonue_privacy_requirements_1);
	cJSON *jsonue_privacy_requirements_2 =
		ue_privacy_requirements_convertToJSON(ue_privacy_requirements_2);
	printf("repeating ue_privacy_requirements:\n%s\n",
	       cJSON_Print(jsonue_privacy_requirements_2));
}

int main() {
	test_ue_privacy_requirements(1);
	test_ue_privacy_requirements(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_privacy_requirements_MAIN
#endif // ue_privacy_requirements_TEST
