#ifndef n2_sm_information_TEST
#define n2_sm_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_sm_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_sm_information.h"
n2_sm_information_t *instantiate_n2_sm_information(int include_optional);

#include "test_n2_info_content.c"
#include "test_snssai.c"
#include "test_snssai.c"
#include "test_snssai.c"


n2_sm_information_t *instantiate_n2_sm_information(int include_optional) {
	n2_sm_information_t *n2_sm_information = NULL;
	if(include_optional) {
		n2_sm_information = n2_sm_information_create(
			0,
			// false, not to have infinite recursion
			instantiate_n2_info_content(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0),
			1
			);
	} else {
		n2_sm_information = n2_sm_information_create(
			0,
			NULL,
			NULL,
			NULL,
			NULL,
			1
			);
	}

	return n2_sm_information;
}


#ifdef n2_sm_information_MAIN

void test_n2_sm_information(int include_optional) {
	n2_sm_information_t *n2_sm_information_1 =
		instantiate_n2_sm_information(include_optional);

	cJSON *jsonn2_sm_information_1 = n2_sm_information_convertToJSON(
		n2_sm_information_1);
	printf("n2_sm_information :\n%s\n",
	       cJSON_Print(jsonn2_sm_information_1));
	n2_sm_information_t *n2_sm_information_2 =
		n2_sm_information_parseFromJSON(jsonn2_sm_information_1);
	cJSON *jsonn2_sm_information_2 = n2_sm_information_convertToJSON(
		n2_sm_information_2);
	printf("repeating n2_sm_information:\n%s\n",
	       cJSON_Print(jsonn2_sm_information_2));
}

int main() {
	test_n2_sm_information(1);
	test_n2_sm_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_sm_information_MAIN
#endif // n2_sm_information_TEST
