#ifndef non_ue_n2_message_transfer_request_TEST
#define non_ue_n2_message_transfer_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define non_ue_n2_message_transfer_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/non_ue_n2_message_transfer_request.h"
non_ue_n2_message_transfer_request_t *
instantiate_non_ue_n2_message_transfer_request(int include_optional);

#include "test_n2_information_transfer_req_data.c"


non_ue_n2_message_transfer_request_t *
instantiate_non_ue_n2_message_transfer_request(int include_optional) {
	non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request
	        = NULL;
	if(include_optional) {
		non_ue_n2_message_transfer_request =
			non_ue_n2_message_transfer_request_create(
				// false, not to have infinite recursion
				instantiate_n2_information_transfer_req_data(0),
				instantiate_binary_t("blah", 5)
				);
	} else {
		non_ue_n2_message_transfer_request =
			non_ue_n2_message_transfer_request_create(
				NULL,
				instantiate_binary_t("blah", 5)
				);
	}

	return non_ue_n2_message_transfer_request;
}


#ifdef non_ue_n2_message_transfer_request_MAIN

void test_non_ue_n2_message_transfer_request(int include_optional) {
	non_ue_n2_message_transfer_request_t *
	        non_ue_n2_message_transfer_request_1 =
		instantiate_non_ue_n2_message_transfer_request(include_optional);

	cJSON *jsonnon_ue_n2_message_transfer_request_1 =
		non_ue_n2_message_transfer_request_convertToJSON(
			non_ue_n2_message_transfer_request_1);
	printf("non_ue_n2_message_transfer_request :\n%s\n",
	       cJSON_Print(jsonnon_ue_n2_message_transfer_request_1));
	non_ue_n2_message_transfer_request_t *
	        non_ue_n2_message_transfer_request_2 =
		non_ue_n2_message_transfer_request_parseFromJSON(
			jsonnon_ue_n2_message_transfer_request_1);
	cJSON *jsonnon_ue_n2_message_transfer_request_2 =
		non_ue_n2_message_transfer_request_convertToJSON(
			non_ue_n2_message_transfer_request_2);
	printf("repeating non_ue_n2_message_transfer_request:\n%s\n", cJSON_Print(
		       jsonnon_ue_n2_message_transfer_request_2));
}

int main() {
	test_non_ue_n2_message_transfer_request(1);
	test_non_ue_n2_message_transfer_request(0);

	printf("Hello world \n");
	return 0;
}

#endif // non_ue_n2_message_transfer_request_MAIN
#endif // non_ue_n2_message_transfer_request_TEST
