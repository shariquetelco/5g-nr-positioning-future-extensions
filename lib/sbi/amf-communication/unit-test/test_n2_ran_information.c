#ifndef n2_ran_information_TEST
#define n2_ran_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_ran_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_ran_information.h"
n2_ran_information_t *instantiate_n2_ran_information(int include_optional);

#include "test_n2_info_content.c"


n2_ran_information_t *instantiate_n2_ran_information(int include_optional) {
	n2_ran_information_t *n2_ran_information = NULL;
	if(include_optional) {
		n2_ran_information = n2_ran_information_create(
			// false, not to have infinite recursion
			instantiate_n2_info_content(0)
			);
	} else {
		n2_ran_information = n2_ran_information_create(
			NULL
			);
	}

	return n2_ran_information;
}


#ifdef n2_ran_information_MAIN

void test_n2_ran_information(int include_optional) {
	n2_ran_information_t *n2_ran_information_1 =
		instantiate_n2_ran_information(include_optional);

	cJSON *jsonn2_ran_information_1 = n2_ran_information_convertToJSON(
		n2_ran_information_1);
	printf("n2_ran_information :\n%s\n",
	       cJSON_Print(jsonn2_ran_information_1));
	n2_ran_information_t *n2_ran_information_2 =
		n2_ran_information_parseFromJSON(jsonn2_ran_information_1);
	cJSON *jsonn2_ran_information_2 = n2_ran_information_convertToJSON(
		n2_ran_information_2);
	printf("repeating n2_ran_information:\n%s\n",
	       cJSON_Print(jsonn2_ran_information_2));
}

int main() {
	test_n2_ran_information(1);
	test_n2_ran_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_ran_information_MAIN
#endif // n2_ran_information_TEST
