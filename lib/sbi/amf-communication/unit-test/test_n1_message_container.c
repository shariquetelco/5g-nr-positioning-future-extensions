#ifndef n1_message_container_TEST
#define n1_message_container_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_message_container_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_message_container.h"
n1_message_container_t *instantiate_n1_message_container(int include_optional);

#include "test_ref_to_binary_data.c"


n1_message_container_t *instantiate_n1_message_container(int include_optional) {
	n1_message_container_t *n1_message_container = NULL;
	if(include_optional) {
		n1_message_container = n1_message_container_create(
			namf_communication_n1_message_container__5GMM,
			// false, not to have infinite recursion
			instantiate_ref_to_binary_data(0),
			"0",
			"0"
			);
	} else {
		n1_message_container = n1_message_container_create(
			namf_communication_n1_message_container__5GMM,
			NULL,
			"0",
			"0"
			);
	}

	return n1_message_container;
}


#ifdef n1_message_container_MAIN

void test_n1_message_container(int include_optional) {
	n1_message_container_t *n1_message_container_1 =
		instantiate_n1_message_container(include_optional);

	cJSON *jsonn1_message_container_1 = n1_message_container_convertToJSON(
		n1_message_container_1);
	printf("n1_message_container :\n%s\n",
	       cJSON_Print(jsonn1_message_container_1));
	n1_message_container_t *n1_message_container_2 =
		n1_message_container_parseFromJSON(jsonn1_message_container_1);
	cJSON *jsonn1_message_container_2 = n1_message_container_convertToJSON(
		n1_message_container_2);
	printf("repeating n1_message_container:\n%s\n",
	       cJSON_Print(jsonn1_message_container_2));
}

int main() {
	test_n1_message_container(1);
	test_n1_message_container(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_message_container_MAIN
#endif // n1_message_container_TEST
