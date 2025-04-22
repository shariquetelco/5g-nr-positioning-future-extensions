#ifndef mm_context_TEST
#define mm_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mm_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mm_context.h"
mm_context_t *instantiate_mm_context(int include_optional);

#include "test_nas_security_mode.c"
#include "test_eps_nas_security_mode.c"
#include "test_expected_ue_behavior.c"
#include "test_ue_differentiation_info.c"
#include "test_global_ran_node_id.c"
#include "test_global_ran_node_id.c"
#include "test_global_ran_node_id.c"


mm_context_t *instantiate_mm_context(int include_optional) {
	mm_context_t *mm_context = NULL;
	if(include_optional) {
		mm_context = mm_context_create(
			namf_communication_mm_context__3GPP_ACCESS,
			// false, not to have infinite recursion
			instantiate_nas_security_mode(0),
			// false, not to have infinite recursion
			instantiate_eps_nas_security_mode(0),
			0,
			0,
			"YQ==",
			"YQ==",
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_expected_ue_behavior(0),
			// false, not to have infinite recursion
			instantiate_ue_differentiation_info(0),
			"YQ==",
			"YQ==",
			"0",
			// false, not to have infinite recursion
			instantiate_global_ran_node_id(0),
			// false, not to have infinite recursion
			instantiate_global_ran_node_id(0),
			// false, not to have infinite recursion
			instantiate_global_ran_node_id(0),
			56,
			list_createList(),
			list_createList(),
			namf_communication_mm_context__SUCCESS,
			list_createList(),
			1
			);
	} else {
		mm_context = mm_context_create(
			namf_communication_mm_context__3GPP_ACCESS,
			NULL,
			NULL,
			0,
			0,
			"YQ==",
			"YQ==",
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			NULL,
			NULL,
			"YQ==",
			"YQ==",
			"0",
			NULL,
			NULL,
			NULL,
			56,
			list_createList(),
			list_createList(),
			namf_communication_mm_context__SUCCESS,
			list_createList(),
			1
			);
	}

	return mm_context;
}


#ifdef mm_context_MAIN

void test_mm_context(int include_optional) {
	mm_context_t *mm_context_1 = instantiate_mm_context(include_optional);

	cJSON *jsonmm_context_1 = mm_context_convertToJSON(mm_context_1);
	printf("mm_context :\n%s\n", cJSON_Print(jsonmm_context_1));
	mm_context_t *mm_context_2 = mm_context_parseFromJSON(jsonmm_context_1);
	cJSON *jsonmm_context_2 = mm_context_convertToJSON(mm_context_2);
	printf("repeating mm_context:\n%s\n", cJSON_Print(jsonmm_context_2));
}

int main() {
	test_mm_context(1);
	test_mm_context(0);

	printf("Hello world \n");
	return 0;
}

#endif // mm_context_MAIN
#endif // mm_context_TEST
