#ifndef candidate_for_replacement_TEST
#define candidate_for_replacement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define candidate_for_replacement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/candidate_for_replacement.h"
candidate_for_replacement_t *instantiate_candidate_for_replacement(
	int include_optional);

#include "test_snssai.c"


candidate_for_replacement_t *instantiate_candidate_for_replacement(
	int include_optional) {
	candidate_for_replacement_t *candidate_for_replacement = NULL;
	if(include_optional) {
		candidate_for_replacement = candidate_for_replacement_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList()
			);
	} else {
		candidate_for_replacement = candidate_for_replacement_create(
			NULL,
			list_createList()
			);
	}

	return candidate_for_replacement;
}


#ifdef candidate_for_replacement_MAIN

void test_candidate_for_replacement(int include_optional) {
	candidate_for_replacement_t *candidate_for_replacement_1 =
		instantiate_candidate_for_replacement(include_optional);

	cJSON *jsoncandidate_for_replacement_1 =
		candidate_for_replacement_convertToJSON(
			candidate_for_replacement_1);
	printf("candidate_for_replacement :\n%s\n",
	       cJSON_Print(jsoncandidate_for_replacement_1));
	candidate_for_replacement_t *candidate_for_replacement_2 =
		candidate_for_replacement_parseFromJSON(
			jsoncandidate_for_replacement_1);
	cJSON *jsoncandidate_for_replacement_2 =
		candidate_for_replacement_convertToJSON(
			candidate_for_replacement_2);
	printf("repeating candidate_for_replacement:\n%s\n",
	       cJSON_Print(jsoncandidate_for_replacement_2));
}

int main() {
	test_candidate_for_replacement(1);
	test_candidate_for_replacement(0);

	printf("Hello world \n");
	return 0;
}

#endif // candidate_for_replacement_MAIN
#endif // candidate_for_replacement_TEST
