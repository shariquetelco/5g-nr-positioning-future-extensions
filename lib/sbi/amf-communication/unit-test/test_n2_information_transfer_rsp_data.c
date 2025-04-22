#ifndef n2_information_transfer_rsp_data_TEST
#define n2_information_transfer_rsp_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_information_transfer_rsp_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_information_transfer_rsp_data.h"
n2_information_transfer_rsp_data_t *instantiate_n2_information_transfer_rsp_data(
	int include_optional);

#include "test_pws_response_data.c"


n2_information_transfer_rsp_data_t *instantiate_n2_information_transfer_rsp_data(
	int include_optional) {
	n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data =
		NULL;
	if(include_optional) {
		n2_information_transfer_rsp_data =
			n2_information_transfer_rsp_data_create(
				namf_communication_n2_information_transfer_rsp_data__N2_INFO_TRANSFER_INITIATED,
				// false, not to have infinite recursion
				instantiate_pws_response_data(0),
				"a",
				list_createList()
				);
	} else {
		n2_information_transfer_rsp_data =
			n2_information_transfer_rsp_data_create(
				namf_communication_n2_information_transfer_rsp_data__N2_INFO_TRANSFER_INITIATED,
				NULL,
				"a",
				list_createList()
				);
	}

	return n2_information_transfer_rsp_data;
}


#ifdef n2_information_transfer_rsp_data_MAIN

void test_n2_information_transfer_rsp_data(int include_optional) {
	n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data_1 =
		instantiate_n2_information_transfer_rsp_data(include_optional);

	cJSON *jsonn2_information_transfer_rsp_data_1 =
		n2_information_transfer_rsp_data_convertToJSON(
			n2_information_transfer_rsp_data_1);
	printf("n2_information_transfer_rsp_data :\n%s\n",
	       cJSON_Print(jsonn2_information_transfer_rsp_data_1));
	n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data_2 =
		n2_information_transfer_rsp_data_parseFromJSON(
			jsonn2_information_transfer_rsp_data_1);
	cJSON *jsonn2_information_transfer_rsp_data_2 =
		n2_information_transfer_rsp_data_convertToJSON(
			n2_information_transfer_rsp_data_2);
	printf("repeating n2_information_transfer_rsp_data:\n%s\n",
	       cJSON_Print(jsonn2_information_transfer_rsp_data_2));
}

int main() {
	test_n2_information_transfer_rsp_data(1);
	test_n2_information_transfer_rsp_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_information_transfer_rsp_data_MAIN
#endif // n2_information_transfer_rsp_data_TEST
