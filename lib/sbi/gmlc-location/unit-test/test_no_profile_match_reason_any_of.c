#ifndef no_profile_match_reason_any_of_TEST
#define no_profile_match_reason_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define no_profile_match_reason_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/no_profile_match_reason_any_of.h"
no_profile_match_reason_any_of_t *instantiate_no_profile_match_reason_any_of(
	int include_optional);



no_profile_match_reason_any_of_t *instantiate_no_profile_match_reason_any_of(
	int include_optional) {
	no_profile_match_reason_any_of_t *no_profile_match_reason_any_of = NULL;
	if(include_optional) {
		no_profile_match_reason_any_of =
			no_profile_match_reason_any_of_create(
				);
	} else {
		no_profile_match_reason_any_of =
			no_profile_match_reason_any_of_create(
				);
	}

	return no_profile_match_reason_any_of;
}


#ifdef no_profile_match_reason_any_of_MAIN

void test_no_profile_match_reason_any_of(int include_optional) {
	no_profile_match_reason_any_of_t *no_profile_match_reason_any_of_1 =
		instantiate_no_profile_match_reason_any_of(include_optional);

	cJSON *jsonno_profile_match_reason_any_of_1 =
		no_profile_match_reason_any_of_convertToJSON(
			no_profile_match_reason_any_of_1);
	printf("no_profile_match_reason_any_of :\n%s\n",
	       cJSON_Print(jsonno_profile_match_reason_any_of_1));
	no_profile_match_reason_any_of_t *no_profile_match_reason_any_of_2 =
		no_profile_match_reason_any_of_parseFromJSON(
			jsonno_profile_match_reason_any_of_1);
	cJSON *jsonno_profile_match_reason_any_of_2 =
		no_profile_match_reason_any_of_convertToJSON(
			no_profile_match_reason_any_of_2);
	printf("repeating no_profile_match_reason_any_of:\n%s\n",
	       cJSON_Print(jsonno_profile_match_reason_any_of_2));
}

int main() {
	test_no_profile_match_reason_any_of(1);
	test_no_profile_match_reason_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // no_profile_match_reason_any_of_MAIN
#endif // no_profile_match_reason_any_of_TEST
