#ifndef cancel_relocate_ue_context_request_TEST
#define cancel_relocate_ue_context_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cancel_relocate_ue_context_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cancel_relocate_ue_context_request.h"
cancel_relocate_ue_context_request_t *
instantiate_cancel_relocate_ue_context_request(int include_optional);

#include "test_ue_context_cancel_relocate_data.c"


cancel_relocate_ue_context_request_t *
instantiate_cancel_relocate_ue_context_request(int include_optional) {
	cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request
	        = NULL;
	if(include_optional) {
		cancel_relocate_ue_context_request =
			cancel_relocate_ue_context_request_create(
				// false, not to have infinite recursion
				instantiate_ue_context_cancel_relocate_data(0),
				instantiate_binary_t("blah", 5)
				);
	} else {
		cancel_relocate_ue_context_request =
			cancel_relocate_ue_context_request_create(
				NULL,
				instantiate_binary_t("blah", 5)
				);
	}

	return cancel_relocate_ue_context_request;
}


#ifdef cancel_relocate_ue_context_request_MAIN

void test_cancel_relocate_ue_context_request(int include_optional) {
	cancel_relocate_ue_context_request_t *
	        cancel_relocate_ue_context_request_1 =
		instantiate_cancel_relocate_ue_context_request(include_optional);

	cJSON *jsoncancel_relocate_ue_context_request_1 =
		cancel_relocate_ue_context_request_convertToJSON(
			cancel_relocate_ue_context_request_1);
	printf("cancel_relocate_ue_context_request :\n%s\n",
	       cJSON_Print(jsoncancel_relocate_ue_context_request_1));
	cancel_relocate_ue_context_request_t *
	        cancel_relocate_ue_context_request_2 =
		cancel_relocate_ue_context_request_parseFromJSON(
			jsoncancel_relocate_ue_context_request_1);
	cJSON *jsoncancel_relocate_ue_context_request_2 =
		cancel_relocate_ue_context_request_convertToJSON(
			cancel_relocate_ue_context_request_2);
	printf("repeating cancel_relocate_ue_context_request:\n%s\n", cJSON_Print(
		       jsoncancel_relocate_ue_context_request_2));
}

int main() {
	test_cancel_relocate_ue_context_request(1);
	test_cancel_relocate_ue_context_request(0);

	printf("Hello world \n");
	return 0;
}

#endif // cancel_relocate_ue_context_request_MAIN
#endif // cancel_relocate_ue_context_request_TEST
