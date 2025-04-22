#ifndef create_ue_context_201_response_TEST
#define create_ue_context_201_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_ue_context_201_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_ue_context_201_response.h"
create_ue_context_201_response_t *instantiate_create_ue_context_201_response(
	int include_optional);

#include "test_ue_context_created_data.c"


create_ue_context_201_response_t *instantiate_create_ue_context_201_response(
	int include_optional) {
	create_ue_context_201_response_t *create_ue_context_201_response = NULL;
	if(include_optional) {
		create_ue_context_201_response =
			create_ue_context_201_response_create(
				// false, not to have infinite recursion
				instantiate_ue_context_created_data(0),
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
		create_ue_context_201_response =
			create_ue_context_201_response_create(
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
				instantiate_binary_t("blah", 5)
				);
	}

	return create_ue_context_201_response;
}


#ifdef create_ue_context_201_response_MAIN

void test_create_ue_context_201_response(int include_optional) {
	create_ue_context_201_response_t *create_ue_context_201_response_1 =
		instantiate_create_ue_context_201_response(include_optional);

	cJSON *jsoncreate_ue_context_201_response_1 =
		create_ue_context_201_response_convertToJSON(
			create_ue_context_201_response_1);
	printf("create_ue_context_201_response :\n%s\n",
	       cJSON_Print(jsoncreate_ue_context_201_response_1));
	create_ue_context_201_response_t *create_ue_context_201_response_2 =
		create_ue_context_201_response_parseFromJSON(
			jsoncreate_ue_context_201_response_1);
	cJSON *jsoncreate_ue_context_201_response_2 =
		create_ue_context_201_response_convertToJSON(
			create_ue_context_201_response_2);
	printf("repeating create_ue_context_201_response:\n%s\n",
	       cJSON_Print(jsoncreate_ue_context_201_response_2));
}

int main() {
	test_create_ue_context_201_response(1);
	test_create_ue_context_201_response(0);

	printf("Hello world \n");
	return 0;
}

#endif // create_ue_context_201_response_MAIN
#endif // create_ue_context_201_response_TEST
