#ifndef allowed_nssai_TEST
#define allowed_nssai_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define allowed_nssai_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/allowed_nssai.h"
allowed_nssai_t *instantiate_allowed_nssai(int include_optional);



allowed_nssai_t *instantiate_allowed_nssai(int include_optional) {
	allowed_nssai_t *allowed_nssai = NULL;
	if(include_optional) {
		allowed_nssai = allowed_nssai_create(
			list_createList(),
			namf_communication_allowed_nssai__3GPP_ACCESS
			);
	} else {
		allowed_nssai = allowed_nssai_create(
			list_createList(),
			namf_communication_allowed_nssai__3GPP_ACCESS
			);
	}

	return allowed_nssai;
}


#ifdef allowed_nssai_MAIN

void test_allowed_nssai(int include_optional) {
	allowed_nssai_t *allowed_nssai_1 = instantiate_allowed_nssai(
		include_optional);

	cJSON *jsonallowed_nssai_1 =
		allowed_nssai_convertToJSON(allowed_nssai_1);
	printf("allowed_nssai :\n%s\n", cJSON_Print(jsonallowed_nssai_1));
	allowed_nssai_t *allowed_nssai_2 = allowed_nssai_parseFromJSON(
		jsonallowed_nssai_1);
	cJSON *jsonallowed_nssai_2 =
		allowed_nssai_convertToJSON(allowed_nssai_2);
	printf("repeating allowed_nssai:\n%s\n", cJSON_Print(
		       jsonallowed_nssai_2));
}

int main() {
	test_allowed_nssai(1);
	test_allowed_nssai(0);

	printf("Hello world \n");
	return 0;
}

#endif // allowed_nssai_MAIN
#endif // allowed_nssai_TEST
