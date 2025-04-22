#ifndef no_profile_match_reason_TEST
#define no_profile_match_reason_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define no_profile_match_reason_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/no_profile_match_reason.h"
no_profile_match_reason_t *instantiate_no_profile_match_reason(
	int include_optional);



no_profile_match_reason_t *instantiate_no_profile_match_reason(
	int include_optional) {
	no_profile_match_reason_t *no_profile_match_reason = NULL;
	if(include_optional) {
		no_profile_match_reason = no_profile_match_reason_create(
			);
	} else {
		no_profile_match_reason = no_profile_match_reason_create(
			);
	}

	return no_profile_match_reason;
}


#ifdef no_profile_match_reason_MAIN

void test_no_profile_match_reason(int include_optional) {
	no_profile_match_reason_t *no_profile_match_reason_1 =
		instantiate_no_profile_match_reason(include_optional);

	cJSON *jsonno_profile_match_reason_1 =
		no_profile_match_reason_convertToJSON(no_profile_match_reason_1);
	printf("no_profile_match_reason :\n%s\n",
	       cJSON_Print(jsonno_profile_match_reason_1));
	no_profile_match_reason_t *no_profile_match_reason_2 =
		no_profile_match_reason_parseFromJSON(
			jsonno_profile_match_reason_1);
	cJSON *jsonno_profile_match_reason_2 =
		no_profile_match_reason_convertToJSON(no_profile_match_reason_2);
	printf("repeating no_profile_match_reason:\n%s\n",
	       cJSON_Print(jsonno_profile_match_reason_2));
}

int main() {
	test_no_profile_match_reason(1);
	test_no_profile_match_reason(0);

	printf("Hello world \n");
	return 0;
}

#endif // no_profile_match_reason_MAIN
#endif // no_profile_match_reason_TEST
