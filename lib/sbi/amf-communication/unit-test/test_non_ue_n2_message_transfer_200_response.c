#ifndef non_ue_n2_message_transfer_200_response_TEST
#define non_ue_n2_message_transfer_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define non_ue_n2_message_transfer_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/non_ue_n2_message_transfer_200_response.h"
non_ue_n2_message_transfer_200_response_t *
instantiate_non_ue_n2_message_transfer_200_response(int include_optional);

#include "test_n2_information_transfer_rsp_data.c"


non_ue_n2_message_transfer_200_response_t *
instantiate_non_ue_n2_message_transfer_200_response(int include_optional) {
	non_ue_n2_message_transfer_200_response_t *
	        non_ue_n2_message_transfer_200_response = NULL;
	if(include_optional) {
		non_ue_n2_message_transfer_200_response =
			non_ue_n2_message_transfer_200_response_create(
				// false, not to have infinite recursion
				instantiate_n2_information_transfer_rsp_data(0),
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
		non_ue_n2_message_transfer_200_response =
			non_ue_n2_message_transfer_200_response_create(
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
				instantiate_binary_t("blah", 5)
				);
	}

	return non_ue_n2_message_transfer_200_response;
}


#ifdef non_ue_n2_message_transfer_200_response_MAIN

void test_non_ue_n2_message_transfer_200_response(int include_optional) {
	non_ue_n2_message_transfer_200_response_t *
	        non_ue_n2_message_transfer_200_response_1 =
		instantiate_non_ue_n2_message_transfer_200_response(
			include_optional);

	cJSON *jsonnon_ue_n2_message_transfer_200_response_1 =
		non_ue_n2_message_transfer_200_response_convertToJSON(
			non_ue_n2_message_transfer_200_response_1);
	printf("non_ue_n2_message_transfer_200_response :\n%s\n",
	       cJSON_Print(jsonnon_ue_n2_message_transfer_200_response_1));
	non_ue_n2_message_transfer_200_response_t *
	        non_ue_n2_message_transfer_200_response_2 =
		non_ue_n2_message_transfer_200_response_parseFromJSON(
			jsonnon_ue_n2_message_transfer_200_response_1);
	cJSON *jsonnon_ue_n2_message_transfer_200_response_2 =
		non_ue_n2_message_transfer_200_response_convertToJSON(
			non_ue_n2_message_transfer_200_response_2);
	printf("repeating non_ue_n2_message_transfer_200_response:\n%s\n", cJSON_Print(
		       jsonnon_ue_n2_message_transfer_200_response_2));
}

int main() {
	test_non_ue_n2_message_transfer_200_response(1);
	test_non_ue_n2_message_transfer_200_response(0);

	printf("Hello world \n");
	return 0;
}

#endif // non_ue_n2_message_transfer_200_response_MAIN
#endif // non_ue_n2_message_transfer_200_response_TEST
