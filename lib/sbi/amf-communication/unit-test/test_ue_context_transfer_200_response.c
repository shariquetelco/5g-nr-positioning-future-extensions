#ifndef ue_context_transfer_200_response_TEST
#define ue_context_transfer_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_transfer_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context_transfer_200_response.h"
ue_context_transfer_200_response_t *instantiate_ue_context_transfer_200_response(
	int include_optional);

#include "test_ue_context_transfer_rsp_data.c"


ue_context_transfer_200_response_t *instantiate_ue_context_transfer_200_response(
	int include_optional) {
	ue_context_transfer_200_response_t *ue_context_transfer_200_response =
		NULL;
	if(include_optional) {
		ue_context_transfer_200_response =
			ue_context_transfer_200_response_create(
				// false, not to have infinite recursion
				instantiate_ue_context_transfer_rsp_data(0),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5)
				);
	} else {
		ue_context_transfer_200_response =
			ue_context_transfer_200_response_create(
				NULL,
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5)
				);
	}

	return ue_context_transfer_200_response;
}


#ifdef ue_context_transfer_200_response_MAIN

void test_ue_context_transfer_200_response(int include_optional) {
	ue_context_transfer_200_response_t *ue_context_transfer_200_response_1 =
		instantiate_ue_context_transfer_200_response(include_optional);

	cJSON *jsonue_context_transfer_200_response_1 =
		ue_context_transfer_200_response_convertToJSON(
			ue_context_transfer_200_response_1);
	printf("ue_context_transfer_200_response :\n%s\n",
	       cJSON_Print(jsonue_context_transfer_200_response_1));
	ue_context_transfer_200_response_t *ue_context_transfer_200_response_2 =
		ue_context_transfer_200_response_parseFromJSON(
			jsonue_context_transfer_200_response_1);
	cJSON *jsonue_context_transfer_200_response_2 =
		ue_context_transfer_200_response_convertToJSON(
			ue_context_transfer_200_response_2);
	printf("repeating ue_context_transfer_200_response:\n%s\n",
	       cJSON_Print(jsonue_context_transfer_200_response_2));
}

int main() {
	test_ue_context_transfer_200_response(1);
	test_ue_context_transfer_200_response(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_transfer_200_response_MAIN
#endif // ue_context_transfer_200_response_TEST
