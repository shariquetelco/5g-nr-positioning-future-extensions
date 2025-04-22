#ifndef relocate_ue_context_request_TEST
#define relocate_ue_context_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define relocate_ue_context_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/relocate_ue_context_request.h"
relocate_ue_context_request_t *instantiate_relocate_ue_context_request(
	int include_optional);

#include "test_ue_context_relocate_data.c"


relocate_ue_context_request_t *instantiate_relocate_ue_context_request(
	int include_optional) {
	relocate_ue_context_request_t *relocate_ue_context_request = NULL;
	if(include_optional) {
		relocate_ue_context_request =
			relocate_ue_context_request_create(
				// false, not to have infinite recursion
				instantiate_ue_context_relocate_data(0),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5)
				);
	} else {
		relocate_ue_context_request =
			relocate_ue_context_request_create(
				NULL,
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5),
				instantiate_binary_t("blah", 5)
				);
	}

	return relocate_ue_context_request;
}


#ifdef relocate_ue_context_request_MAIN

void test_relocate_ue_context_request(int include_optional) {
	relocate_ue_context_request_t *relocate_ue_context_request_1 =
		instantiate_relocate_ue_context_request(include_optional);

	cJSON *jsonrelocate_ue_context_request_1 =
		relocate_ue_context_request_convertToJSON(
			relocate_ue_context_request_1);
	printf("relocate_ue_context_request :\n%s\n",
	       cJSON_Print(jsonrelocate_ue_context_request_1));
	relocate_ue_context_request_t *relocate_ue_context_request_2 =
		relocate_ue_context_request_parseFromJSON(
			jsonrelocate_ue_context_request_1);
	cJSON *jsonrelocate_ue_context_request_2 =
		relocate_ue_context_request_convertToJSON(
			relocate_ue_context_request_2);
	printf("repeating relocate_ue_context_request:\n%s\n",
	       cJSON_Print(jsonrelocate_ue_context_request_2));
}

int main() {
	test_relocate_ue_context_request(1);
	test_relocate_ue_context_request(0);

	printf("Hello world \n");
	return 0;
}

#endif // relocate_ue_context_request_MAIN
#endif // relocate_ue_context_request_TEST
