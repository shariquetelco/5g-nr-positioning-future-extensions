#ifndef n1_n2_message_transfer_req_data_TEST
#define n1_n2_message_transfer_req_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_n2_message_transfer_req_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_n2_message_transfer_req_data.h"
n1_n2_message_transfer_req_data_t *instantiate_n1_n2_message_transfer_req_data(
	int include_optional);

#include "test_n1_message_container.c"
#include "test_n2_info_container.c"
#include "test_ref_to_binary_data.c"
#include "test_arp.c"
#include "test_area_of_validity.c"
#include "test_guami.c"


n1_n2_message_transfer_req_data_t *instantiate_n1_n2_message_transfer_req_data(
	int include_optional) {
	n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data =
		NULL;
	if(include_optional) {
		n1_n2_message_transfer_req_data =
			n1_n2_message_transfer_req_data_create(
				// false, not to have infinite recursion
				instantiate_n1_message_container(0),
				// false, not to have infinite recursion
				instantiate_n2_info_container(0),
				// false, not to have infinite recursion
				instantiate_ref_to_binary_data(0),
				1,
				1,
				0,
				"0",
				0,
				// false, not to have infinite recursion
				instantiate_arp(0),
				0,
				"0",
				1,
				// false, not to have infinite recursion
				instantiate_area_of_validity(0),
				"a",
				// false, not to have infinite recursion
				instantiate_guami(
					0),
				1,
				1,
				namf_communication_n1_n2_message_transfer_req_data__3GPP_ACCESS,
				"0",
				namf_communication_n1_n2_message_transfer_req_data_PRUIND_true
				);
	} else {
		n1_n2_message_transfer_req_data =
			n1_n2_message_transfer_req_data_create(
				NULL,
				NULL,
				NULL,
				1,
				1,
				0,
				"0",
				0,
				NULL,
				0,
				"0",
				1,
				NULL,
				"a",
				NULL,
				1,
				1,
				namf_communication_n1_n2_message_transfer_req_data__3GPP_ACCESS,
				"0",
				namf_communication_n1_n2_message_transfer_req_data_PRUIND_true
				);
	}

	return n1_n2_message_transfer_req_data;
}


#ifdef n1_n2_message_transfer_req_data_MAIN

void test_n1_n2_message_transfer_req_data(int include_optional) {
	n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data_1 =
		instantiate_n1_n2_message_transfer_req_data(include_optional);

	cJSON *jsonn1_n2_message_transfer_req_data_1 =
		n1_n2_message_transfer_req_data_convertToJSON(
			n1_n2_message_transfer_req_data_1);
	printf("n1_n2_message_transfer_req_data :\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_req_data_1));
	n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data_2 =
		n1_n2_message_transfer_req_data_parseFromJSON(
			jsonn1_n2_message_transfer_req_data_1);
	cJSON *jsonn1_n2_message_transfer_req_data_2 =
		n1_n2_message_transfer_req_data_convertToJSON(
			n1_n2_message_transfer_req_data_2);
	printf("repeating n1_n2_message_transfer_req_data:\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_req_data_2));
}

int main() {
	test_n1_n2_message_transfer_req_data(1);
	test_n1_n2_message_transfer_req_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_n2_message_transfer_req_data_MAIN
#endif // n1_n2_message_transfer_req_data_TEST
