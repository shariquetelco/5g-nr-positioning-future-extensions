#ifndef n1_n2_message_transfer_error_TEST
#define n1_n2_message_transfer_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_n2_message_transfer_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_n2_message_transfer_error.h"
n1_n2_message_transfer_error_t *instantiate_n1_n2_message_transfer_error(
	int include_optional);

#include "test_problem_details.c"
#include "test_n1_n2_msg_txfr_err_detail.c"


n1_n2_message_transfer_error_t *instantiate_n1_n2_message_transfer_error(
	int include_optional) {
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error = NULL;
	if(include_optional) {
		n1_n2_message_transfer_error =
			n1_n2_message_transfer_error_create(
				// false, not to have infinite recursion
				instantiate_problem_details(0),
				// false, not to have infinite recursion
				instantiate_n1_n2_msg_txfr_err_detail(0)
				);
	} else {
		n1_n2_message_transfer_error =
			n1_n2_message_transfer_error_create(
				NULL,
				NULL
				);
	}

	return n1_n2_message_transfer_error;
}


#ifdef n1_n2_message_transfer_error_MAIN

void test_n1_n2_message_transfer_error(int include_optional) {
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_1 =
		instantiate_n1_n2_message_transfer_error(include_optional);

	cJSON *jsonn1_n2_message_transfer_error_1 =
		n1_n2_message_transfer_error_convertToJSON(
			n1_n2_message_transfer_error_1);
	printf("n1_n2_message_transfer_error :\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_error_1));
	n1_n2_message_transfer_error_t *n1_n2_message_transfer_error_2 =
		n1_n2_message_transfer_error_parseFromJSON(
			jsonn1_n2_message_transfer_error_1);
	cJSON *jsonn1_n2_message_transfer_error_2 =
		n1_n2_message_transfer_error_convertToJSON(
			n1_n2_message_transfer_error_2);
	printf("repeating n1_n2_message_transfer_error:\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_error_2));
}

int main() {
	test_n1_n2_message_transfer_error(1);
	test_n1_n2_message_transfer_error(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_n2_message_transfer_error_MAIN
#endif // n1_n2_message_transfer_error_TEST
