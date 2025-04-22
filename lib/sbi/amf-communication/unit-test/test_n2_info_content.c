#ifndef n2_info_content_TEST
#define n2_info_content_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_info_content_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_info_content.h"
n2_info_content_t *instantiate_n2_info_content(int include_optional);

#include "test_ref_to_binary_data.c"


n2_info_content_t *instantiate_n2_info_content(int include_optional) {
	n2_info_content_t *n2_info_content = NULL;
	if(include_optional) {
		n2_info_content = n2_info_content_create(
			0,
			namf_communication_n2_info_content__PDU_RES_SETUP_REQ,
			// false, not to have infinite recursion
			instantiate_ref_to_binary_data(0)
			);
	} else {
		n2_info_content = n2_info_content_create(
			0,
			namf_communication_n2_info_content__PDU_RES_SETUP_REQ,
			NULL
			);
	}

	return n2_info_content;
}


#ifdef n2_info_content_MAIN

void test_n2_info_content(int include_optional) {
	n2_info_content_t *n2_info_content_1 = instantiate_n2_info_content(
		include_optional);

	cJSON *jsonn2_info_content_1 = n2_info_content_convertToJSON(
		n2_info_content_1);
	printf("n2_info_content :\n%s\n", cJSON_Print(jsonn2_info_content_1));
	n2_info_content_t *n2_info_content_2 = n2_info_content_parseFromJSON(
		jsonn2_info_content_1);
	cJSON *jsonn2_info_content_2 = n2_info_content_convertToJSON(
		n2_info_content_2);
	printf("repeating n2_info_content:\n%s\n",
	       cJSON_Print(jsonn2_info_content_2));
}

int main() {
	test_n2_info_content(1);
	test_n2_info_content(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_info_content_MAIN
#endif // n2_info_content_TEST
