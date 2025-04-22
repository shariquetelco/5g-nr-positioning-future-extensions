#ifndef ue_context_cancel_relocate_data_TEST
#define ue_context_cancel_relocate_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_cancel_relocate_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context_cancel_relocate_data.h"
ue_context_cancel_relocate_data_t *instantiate_ue_context_cancel_relocate_data(
	int include_optional);

#include "test_ref_to_binary_data.c"


ue_context_cancel_relocate_data_t *instantiate_ue_context_cancel_relocate_data(
	int include_optional) {
	ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data =
		NULL;
	if(include_optional) {
		ue_context_cancel_relocate_data =
			ue_context_cancel_relocate_data_create(
				"a",
				// false, not to have infinite recursion
				instantiate_ref_to_binary_data(0)
				);
	} else {
		ue_context_cancel_relocate_data =
			ue_context_cancel_relocate_data_create(
				"a",
				NULL
				);
	}

	return ue_context_cancel_relocate_data;
}


#ifdef ue_context_cancel_relocate_data_MAIN

void test_ue_context_cancel_relocate_data(int include_optional) {
	ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_1 =
		instantiate_ue_context_cancel_relocate_data(include_optional);

	cJSON *jsonue_context_cancel_relocate_data_1 =
		ue_context_cancel_relocate_data_convertToJSON(
			ue_context_cancel_relocate_data_1);
	printf("ue_context_cancel_relocate_data :\n%s\n",
	       cJSON_Print(jsonue_context_cancel_relocate_data_1));
	ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_2 =
		ue_context_cancel_relocate_data_parseFromJSON(
			jsonue_context_cancel_relocate_data_1);
	cJSON *jsonue_context_cancel_relocate_data_2 =
		ue_context_cancel_relocate_data_convertToJSON(
			ue_context_cancel_relocate_data_2);
	printf("repeating ue_context_cancel_relocate_data:\n%s\n",
	       cJSON_Print(jsonue_context_cancel_relocate_data_2));
}

int main() {
	test_ue_context_cancel_relocate_data(1);
	test_ue_context_cancel_relocate_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_cancel_relocate_data_MAIN
#endif // ue_context_cancel_relocate_data_TEST
