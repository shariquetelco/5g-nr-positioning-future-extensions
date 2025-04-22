#ifndef ue_context_transfer_request_TEST
#define ue_context_transfer_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_transfer_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context_transfer_request.h"
ue_context_transfer_request_t *instantiate_ue_context_transfer_request(
	int include_optional);

#include "test_ue_context_transfer_req_data.c"


ue_context_transfer_request_t *instantiate_ue_context_transfer_request(
	int include_optional) {
	ue_context_transfer_request_t *ue_context_transfer_request = NULL;
	if(include_optional) {
		ue_context_transfer_request =
			ue_context_transfer_request_create(
				// false, not to have infinite recursion
				instantiate_ue_context_transfer_req_data(0),
				instantiate_binary_t("blah", 5)
				);
	} else {
		ue_context_transfer_request =
			ue_context_transfer_request_create(
				NULL,
				instantiate_binary_t("blah", 5)
				);
	}

	return ue_context_transfer_request;
}


#ifdef ue_context_transfer_request_MAIN

void test_ue_context_transfer_request(int include_optional) {
	ue_context_transfer_request_t *ue_context_transfer_request_1 =
		instantiate_ue_context_transfer_request(include_optional);

	cJSON *jsonue_context_transfer_request_1 =
		ue_context_transfer_request_convertToJSON(
			ue_context_transfer_request_1);
	printf("ue_context_transfer_request :\n%s\n",
	       cJSON_Print(jsonue_context_transfer_request_1));
	ue_context_transfer_request_t *ue_context_transfer_request_2 =
		ue_context_transfer_request_parseFromJSON(
			jsonue_context_transfer_request_1);
	cJSON *jsonue_context_transfer_request_2 =
		ue_context_transfer_request_convertToJSON(
			ue_context_transfer_request_2);
	printf("repeating ue_context_transfer_request:\n%s\n",
	       cJSON_Print(jsonue_context_transfer_request_2));
}

int main() {
	test_ue_context_transfer_request(1);
	test_ue_context_transfer_request(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_transfer_request_MAIN
#endif // ue_context_transfer_request_TEST
