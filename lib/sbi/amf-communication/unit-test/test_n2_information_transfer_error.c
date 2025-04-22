#ifndef n2_information_transfer_error_TEST
#define n2_information_transfer_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_information_transfer_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_information_transfer_error.h"
n2_information_transfer_error_t *instantiate_n2_information_transfer_error(
	int include_optional);

#include "test_problem_details.c"
#include "test_pws_error_data.c"


n2_information_transfer_error_t *instantiate_n2_information_transfer_error(
	int include_optional) {
	n2_information_transfer_error_t *n2_information_transfer_error = NULL;
	if(include_optional) {
		n2_information_transfer_error =
			n2_information_transfer_error_create(
				// false, not to have infinite recursion
				instantiate_problem_details(0),
				// false, not to have infinite recursion
				instantiate_pws_error_data(0)
				);
	} else {
		n2_information_transfer_error =
			n2_information_transfer_error_create(
				NULL,
				NULL
				);
	}

	return n2_information_transfer_error;
}


#ifdef n2_information_transfer_error_MAIN

void test_n2_information_transfer_error(int include_optional) {
	n2_information_transfer_error_t *n2_information_transfer_error_1 =
		instantiate_n2_information_transfer_error(include_optional);

	cJSON *jsonn2_information_transfer_error_1 =
		n2_information_transfer_error_convertToJSON(
			n2_information_transfer_error_1);
	printf("n2_information_transfer_error :\n%s\n",
	       cJSON_Print(jsonn2_information_transfer_error_1));
	n2_information_transfer_error_t *n2_information_transfer_error_2 =
		n2_information_transfer_error_parseFromJSON(
			jsonn2_information_transfer_error_1);
	cJSON *jsonn2_information_transfer_error_2 =
		n2_information_transfer_error_convertToJSON(
			n2_information_transfer_error_2);
	printf("repeating n2_information_transfer_error:\n%s\n",
	       cJSON_Print(jsonn2_information_transfer_error_2));
}

int main() {
	test_n2_information_transfer_error(1);
	test_n2_information_transfer_error(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_information_transfer_error_MAIN
#endif // n2_information_transfer_error_TEST
