#ifndef n2_information_transfer_result_TEST
#define n2_information_transfer_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_information_transfer_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_information_transfer_result.h"
n2_information_transfer_result_t *instantiate_n2_information_transfer_result(
	int include_optional);



n2_information_transfer_result_t *instantiate_n2_information_transfer_result(
	int include_optional) {
	n2_information_transfer_result_t *n2_information_transfer_result = NULL;
	if(include_optional) {
		n2_information_transfer_result =
			n2_information_transfer_result_create(
				);
	} else {
		n2_information_transfer_result =
			n2_information_transfer_result_create(
				);
	}

	return n2_information_transfer_result;
}


#ifdef n2_information_transfer_result_MAIN

void test_n2_information_transfer_result(int include_optional) {
	n2_information_transfer_result_t *n2_information_transfer_result_1 =
		instantiate_n2_information_transfer_result(include_optional);

	cJSON *jsonn2_information_transfer_result_1 =
		n2_information_transfer_result_convertToJSON(
			n2_information_transfer_result_1);
	printf("n2_information_transfer_result :\n%s\n",
	       cJSON_Print(jsonn2_information_transfer_result_1));
	n2_information_transfer_result_t *n2_information_transfer_result_2 =
		n2_information_transfer_result_parseFromJSON(
			jsonn2_information_transfer_result_1);
	cJSON *jsonn2_information_transfer_result_2 =
		n2_information_transfer_result_convertToJSON(
			n2_information_transfer_result_2);
	printf("repeating n2_information_transfer_result:\n%s\n",
	       cJSON_Print(jsonn2_information_transfer_result_2));
}

int main() {
	test_n2_information_transfer_result(1);
	test_n2_information_transfer_result(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_information_transfer_result_MAIN
#endif // n2_information_transfer_result_TEST
