#ifndef create_ue_context_request_TEST
#define create_ue_context_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_ue_context_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_ue_context_request.h"
create_ue_context_request_t *instantiate_create_ue_context_request(
	int include_optional);

#include "test_ue_context_create_data.c"


create_ue_context_request_t *instantiate_create_ue_context_request(
	int include_optional) {
	create_ue_context_request_t *create_ue_context_request = NULL;
	if(include_optional) {
		create_ue_context_request = create_ue_context_request_create(
			// false, not to have infinite recursion
			instantiate_ue_context_create_data(0),
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
		create_ue_context_request = create_ue_context_request_create(
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

	return create_ue_context_request;
}


#ifdef create_ue_context_request_MAIN

void test_create_ue_context_request(int include_optional) {
	create_ue_context_request_t *create_ue_context_request_1 =
		instantiate_create_ue_context_request(include_optional);

	cJSON *jsoncreate_ue_context_request_1 =
		create_ue_context_request_convertToJSON(
			create_ue_context_request_1);
	printf("create_ue_context_request :\n%s\n",
	       cJSON_Print(jsoncreate_ue_context_request_1));
	create_ue_context_request_t *create_ue_context_request_2 =
		create_ue_context_request_parseFromJSON(
			jsoncreate_ue_context_request_1);
	cJSON *jsoncreate_ue_context_request_2 =
		create_ue_context_request_convertToJSON(
			create_ue_context_request_2);
	printf("repeating create_ue_context_request:\n%s\n",
	       cJSON_Print(jsoncreate_ue_context_request_2));
}

int main() {
	test_create_ue_context_request(1);
	test_create_ue_context_request(0);

	printf("Hello world \n");
	return 0;
}

#endif // create_ue_context_request_MAIN
#endif // create_ue_context_request_TEST
