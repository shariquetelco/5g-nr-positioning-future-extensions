#ifndef problem_details_TEST
#define problem_details_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define problem_details_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/problem_details.h"
problem_details_t *instantiate_problem_details(int include_optional);

#include "test_access_token_err.c"
#include "test_access_token_req.c"
#include "test_no_profile_match_info.c"


problem_details_t *instantiate_problem_details(int include_optional) {
	problem_details_t *problem_details = NULL;
	if(include_optional) {
		problem_details = problem_details_create(
			"0",
			"0",
			56,
			"0",
			"0",
			"0",
			list_createList(),
			"a",
			// false, not to have infinite recursion
			instantiate_access_token_err(0),
			// false, not to have infinite recursion
			instantiate_access_token_req(0),
			"a",
			list_createList(),
			// false, not to have infinite recursion
			instantiate_no_profile_match_info(0)
			);
	} else {
		problem_details = problem_details_create(
			"0",
			"0",
			56,
			"0",
			"0",
			"0",
			list_createList(),
			"a",
			NULL,
			NULL,
			"a",
			list_createList(),
			NULL
			);
	}

	return problem_details;
}


#ifdef problem_details_MAIN

void test_problem_details(int include_optional) {
	problem_details_t *problem_details_1 = instantiate_problem_details(
		include_optional);

	cJSON *jsonproblem_details_1 = problem_details_convertToJSON(
		problem_details_1);
	printf("problem_details :\n%s\n", cJSON_Print(jsonproblem_details_1));
	problem_details_t *problem_details_2 = problem_details_parseFromJSON(
		jsonproblem_details_1);
	cJSON *jsonproblem_details_2 = problem_details_convertToJSON(
		problem_details_2);
	printf("repeating problem_details:\n%s\n",
	       cJSON_Print(jsonproblem_details_2));
}

int main() {
	test_problem_details(1);
	test_problem_details(0);

	printf("Hello world \n");
	return 0;
}

#endif // problem_details_MAIN
#endif // problem_details_TEST
