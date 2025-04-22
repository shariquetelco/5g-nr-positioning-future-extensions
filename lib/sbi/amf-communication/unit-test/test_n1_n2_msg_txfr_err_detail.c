#ifndef n1_n2_msg_txfr_err_detail_TEST
#define n1_n2_msg_txfr_err_detail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_n2_msg_txfr_err_detail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_n2_msg_txfr_err_detail.h"
n1_n2_msg_txfr_err_detail_t *instantiate_n1_n2_msg_txfr_err_detail(
	int include_optional);

#include "test_arp.c"


n1_n2_msg_txfr_err_detail_t *instantiate_n1_n2_msg_txfr_err_detail(
	int include_optional) {
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail = NULL;
	if(include_optional) {
		n1_n2_msg_txfr_err_detail = n1_n2_msg_txfr_err_detail_create(
			0,
			// false, not to have infinite recursion
			instantiate_arp(0),
			56
			);
	} else {
		n1_n2_msg_txfr_err_detail = n1_n2_msg_txfr_err_detail_create(
			0,
			NULL,
			56
			);
	}

	return n1_n2_msg_txfr_err_detail;
}


#ifdef n1_n2_msg_txfr_err_detail_MAIN

void test_n1_n2_msg_txfr_err_detail(int include_optional) {
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_1 =
		instantiate_n1_n2_msg_txfr_err_detail(include_optional);

	cJSON *jsonn1_n2_msg_txfr_err_detail_1 =
		n1_n2_msg_txfr_err_detail_convertToJSON(
			n1_n2_msg_txfr_err_detail_1);
	printf("n1_n2_msg_txfr_err_detail :\n%s\n",
	       cJSON_Print(jsonn1_n2_msg_txfr_err_detail_1));
	n1_n2_msg_txfr_err_detail_t *n1_n2_msg_txfr_err_detail_2 =
		n1_n2_msg_txfr_err_detail_parseFromJSON(
			jsonn1_n2_msg_txfr_err_detail_1);
	cJSON *jsonn1_n2_msg_txfr_err_detail_2 =
		n1_n2_msg_txfr_err_detail_convertToJSON(
			n1_n2_msg_txfr_err_detail_2);
	printf("repeating n1_n2_msg_txfr_err_detail:\n%s\n",
	       cJSON_Print(jsonn1_n2_msg_txfr_err_detail_2));
}

int main() {
	test_n1_n2_msg_txfr_err_detail(1);
	test_n1_n2_msg_txfr_err_detail(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_n2_msg_txfr_err_detail_MAIN
#endif // n1_n2_msg_txfr_err_detail_TEST
