#ifndef ue_context_release_TEST
#define ue_context_release_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_release_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context_release.h"
ue_context_release_t *instantiate_ue_context_release(int include_optional);

#include "test_ng_ap_cause.c"


ue_context_release_t *instantiate_ue_context_release(int include_optional) {
	ue_context_release_t *ue_context_release = NULL;
	if(include_optional) {
		ue_context_release = ue_context_release_create(
			"a",
			1,
			// false, not to have infinite recursion
			instantiate_ng_ap_cause(0)
			);
	} else {
		ue_context_release = ue_context_release_create(
			"a",
			1,
			NULL
			);
	}

	return ue_context_release;
}


#ifdef ue_context_release_MAIN

void test_ue_context_release(int include_optional) {
	ue_context_release_t *ue_context_release_1 =
		instantiate_ue_context_release(include_optional);

	cJSON *jsonue_context_release_1 = ue_context_release_convertToJSON(
		ue_context_release_1);
	printf("ue_context_release :\n%s\n",
	       cJSON_Print(jsonue_context_release_1));
	ue_context_release_t *ue_context_release_2 =
		ue_context_release_parseFromJSON(jsonue_context_release_1);
	cJSON *jsonue_context_release_2 = ue_context_release_convertToJSON(
		ue_context_release_2);
	printf("repeating ue_context_release:\n%s\n",
	       cJSON_Print(jsonue_context_release_2));
}

int main() {
	test_ue_context_release(1);
	test_ue_context_release(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_release_MAIN
#endif // ue_context_release_TEST
