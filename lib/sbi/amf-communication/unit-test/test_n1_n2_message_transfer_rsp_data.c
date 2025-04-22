#ifndef n1_n2_message_transfer_rsp_data_TEST
#define n1_n2_message_transfer_rsp_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_n2_message_transfer_rsp_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_n2_message_transfer_rsp_data.h"
n1_n2_message_transfer_rsp_data_t *instantiate_n1_n2_message_transfer_rsp_data(
	int include_optional);



n1_n2_message_transfer_rsp_data_t *instantiate_n1_n2_message_transfer_rsp_data(
	int include_optional) {
	n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data =
		NULL;
	if(include_optional) {
		n1_n2_message_transfer_rsp_data =
			n1_n2_message_transfer_rsp_data_create(
				namf_communication_n1_n2_message_transfer_rsp_data__ATTEMPTING_TO_REACH_UE,
				"a"
				);
	} else {
		n1_n2_message_transfer_rsp_data =
			n1_n2_message_transfer_rsp_data_create(
				namf_communication_n1_n2_message_transfer_rsp_data__ATTEMPTING_TO_REACH_UE,
				"a"
				);
	}

	return n1_n2_message_transfer_rsp_data;
}


#ifdef n1_n2_message_transfer_rsp_data_MAIN

void test_n1_n2_message_transfer_rsp_data(int include_optional) {
	n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_1 =
		instantiate_n1_n2_message_transfer_rsp_data(include_optional);

	cJSON *jsonn1_n2_message_transfer_rsp_data_1 =
		n1_n2_message_transfer_rsp_data_convertToJSON(
			n1_n2_message_transfer_rsp_data_1);
	printf("n1_n2_message_transfer_rsp_data :\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_rsp_data_1));
	n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_2 =
		n1_n2_message_transfer_rsp_data_parseFromJSON(
			jsonn1_n2_message_transfer_rsp_data_1);
	cJSON *jsonn1_n2_message_transfer_rsp_data_2 =
		n1_n2_message_transfer_rsp_data_convertToJSON(
			n1_n2_message_transfer_rsp_data_2);
	printf("repeating n1_n2_message_transfer_rsp_data:\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_rsp_data_2));
}

int main() {
	test_n1_n2_message_transfer_rsp_data(1);
	test_n1_n2_message_transfer_rsp_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_n2_message_transfer_rsp_data_MAIN
#endif // n1_n2_message_transfer_rsp_data_TEST
