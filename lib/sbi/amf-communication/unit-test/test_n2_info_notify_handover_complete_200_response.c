#ifndef n2_info_notify_handover_complete_200_response_TEST
#define n2_info_notify_handover_complete_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_info_notify_handover_complete_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_info_notify_handover_complete_200_response.h"
n2_info_notify_handover_complete_200_response_t *
instantiate_n2_info_notify_handover_complete_200_response(int include_optional);

#include "test_n2_info_notification_rsp_data.c"


n2_info_notify_handover_complete_200_response_t *
instantiate_n2_info_notify_handover_complete_200_response(int include_optional)
{
	n2_info_notify_handover_complete_200_response_t *
	        n2_info_notify_handover_complete_200_response = NULL;
	if(include_optional) {
		n2_info_notify_handover_complete_200_response =
			n2_info_notify_handover_complete_200_response_create(
				// false, not to have infinite recursion
				instantiate_n2_info_notification_rsp_data(0),
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
		n2_info_notify_handover_complete_200_response =
			n2_info_notify_handover_complete_200_response_create(
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

	return n2_info_notify_handover_complete_200_response;
}


#ifdef n2_info_notify_handover_complete_200_response_MAIN

void test_n2_info_notify_handover_complete_200_response(int include_optional) {
	n2_info_notify_handover_complete_200_response_t *
	        n2_info_notify_handover_complete_200_response_1 =
		instantiate_n2_info_notify_handover_complete_200_response(
			include_optional);

	cJSON *jsonn2_info_notify_handover_complete_200_response_1 =
		n2_info_notify_handover_complete_200_response_convertToJSON(
			n2_info_notify_handover_complete_200_response_1);
	printf("n2_info_notify_handover_complete_200_response :\n%s\n", cJSON_Print(
		       jsonn2_info_notify_handover_complete_200_response_1));
	n2_info_notify_handover_complete_200_response_t *
	        n2_info_notify_handover_complete_200_response_2 =
		n2_info_notify_handover_complete_200_response_parseFromJSON(
			jsonn2_info_notify_handover_complete_200_response_1);
	cJSON *jsonn2_info_notify_handover_complete_200_response_2 =
		n2_info_notify_handover_complete_200_response_convertToJSON(
			n2_info_notify_handover_complete_200_response_2);
	printf("repeating n2_info_notify_handover_complete_200_response:\n%s\n", cJSON_Print(
		       jsonn2_info_notify_handover_complete_200_response_2));
}

int main() {
	test_n2_info_notify_handover_complete_200_response(1);
	test_n2_info_notify_handover_complete_200_response(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_info_notify_handover_complete_200_response_MAIN
#endif // n2_info_notify_handover_complete_200_response_TEST
