#ifndef n1_n2_message_transfer_cause_TEST
#define n1_n2_message_transfer_cause_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_n2_message_transfer_cause_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_n2_message_transfer_cause.h"
n1_n2_message_transfer_cause_t *instantiate_n1_n2_message_transfer_cause(
	int include_optional);



n1_n2_message_transfer_cause_t *instantiate_n1_n2_message_transfer_cause(
	int include_optional) {
	n1_n2_message_transfer_cause_t *n1_n2_message_transfer_cause = NULL;
	if(include_optional) {
		n1_n2_message_transfer_cause =
			n1_n2_message_transfer_cause_create(
				);
	} else {
		n1_n2_message_transfer_cause =
			n1_n2_message_transfer_cause_create(
				);
	}

	return n1_n2_message_transfer_cause;
}


#ifdef n1_n2_message_transfer_cause_MAIN

void test_n1_n2_message_transfer_cause(int include_optional) {
	n1_n2_message_transfer_cause_t *n1_n2_message_transfer_cause_1 =
		instantiate_n1_n2_message_transfer_cause(include_optional);

	cJSON *jsonn1_n2_message_transfer_cause_1 =
		n1_n2_message_transfer_cause_convertToJSON(
			n1_n2_message_transfer_cause_1);
	printf("n1_n2_message_transfer_cause :\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_cause_1));
	n1_n2_message_transfer_cause_t *n1_n2_message_transfer_cause_2 =
		n1_n2_message_transfer_cause_parseFromJSON(
			jsonn1_n2_message_transfer_cause_1);
	cJSON *jsonn1_n2_message_transfer_cause_2 =
		n1_n2_message_transfer_cause_convertToJSON(
			n1_n2_message_transfer_cause_2);
	printf("repeating n1_n2_message_transfer_cause:\n%s\n",
	       cJSON_Print(jsonn1_n2_message_transfer_cause_2));
}

int main() {
	test_n1_n2_message_transfer_cause(1);
	test_n1_n2_message_transfer_cause(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_n2_message_transfer_cause_MAIN
#endif // n1_n2_message_transfer_cause_TEST
