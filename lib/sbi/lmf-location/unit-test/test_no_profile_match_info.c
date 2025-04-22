#ifndef no_profile_match_info_TEST
#define no_profile_match_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define no_profile_match_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/no_profile_match_info.h"
no_profile_match_info_t *instantiate_no_profile_match_info(
	int include_optional);

#include "test_no_profile_match_reason.c"


no_profile_match_info_t *instantiate_no_profile_match_info(int include_optional)
{
	no_profile_match_info_t *no_profile_match_info = NULL;
	if(include_optional) {
		no_profile_match_info = no_profile_match_info_create(
			null,
			list_createList()
			);
	} else {
		no_profile_match_info = no_profile_match_info_create(
			null,
			list_createList()
			);
	}

	return no_profile_match_info;
}


#ifdef no_profile_match_info_MAIN

void test_no_profile_match_info(int include_optional) {
	no_profile_match_info_t *no_profile_match_info_1 =
		instantiate_no_profile_match_info(include_optional);

	cJSON *jsonno_profile_match_info_1 =
		no_profile_match_info_convertToJSON(no_profile_match_info_1);
	printf("no_profile_match_info :\n%s\n",
	       cJSON_Print(jsonno_profile_match_info_1));
	no_profile_match_info_t *no_profile_match_info_2 =
		no_profile_match_info_parseFromJSON(jsonno_profile_match_info_1);
	cJSON *jsonno_profile_match_info_2 =
		no_profile_match_info_convertToJSON(no_profile_match_info_2);
	printf("repeating no_profile_match_info:\n%s\n",
	       cJSON_Print(jsonno_profile_match_info_2));
}

int main() {
	test_no_profile_match_info(1);
	test_no_profile_match_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // no_profile_match_info_MAIN
#endif // no_profile_match_info_TEST
