#ifndef ue_context_create_error_TEST
#define ue_context_create_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_create_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context_create_error.h"
ue_context_create_error_t *instantiate_ue_context_create_error(
	int include_optional);

#include "test_problem_details.c"
#include "test_ng_ap_cause.c"
#include "test_n2_info_content.c"


ue_context_create_error_t *instantiate_ue_context_create_error(
	int include_optional) {
	ue_context_create_error_t *ue_context_create_error = NULL;
	if(include_optional) {
		ue_context_create_error = ue_context_create_error_create(
			// false, not to have infinite recursion
			instantiate_problem_details(0),
			// false, not to have infinite recursion
			instantiate_ng_ap_cause(0),
			// false, not to have infinite recursion
			instantiate_n2_info_content(0)
			);
	} else {
		ue_context_create_error = ue_context_create_error_create(
			NULL,
			NULL,
			NULL
			);
	}

	return ue_context_create_error;
}


#ifdef ue_context_create_error_MAIN

void test_ue_context_create_error(int include_optional) {
	ue_context_create_error_t *ue_context_create_error_1 =
		instantiate_ue_context_create_error(include_optional);

	cJSON *jsonue_context_create_error_1 =
		ue_context_create_error_convertToJSON(ue_context_create_error_1);
	printf("ue_context_create_error :\n%s\n",
	       cJSON_Print(jsonue_context_create_error_1));
	ue_context_create_error_t *ue_context_create_error_2 =
		ue_context_create_error_parseFromJSON(
			jsonue_context_create_error_1);
	cJSON *jsonue_context_create_error_2 =
		ue_context_create_error_convertToJSON(ue_context_create_error_2);
	printf("repeating ue_context_create_error:\n%s\n",
	       cJSON_Print(jsonue_context_create_error_2));
}

int main() {
	test_ue_context_create_error(1);
	test_ue_context_create_error(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_create_error_MAIN
#endif // ue_context_create_error_TEST
