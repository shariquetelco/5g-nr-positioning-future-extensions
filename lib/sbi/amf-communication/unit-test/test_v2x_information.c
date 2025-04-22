#ifndef v2x_information_TEST
#define v2x_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2x_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2x_information.h"
v2x_information_t *instantiate_v2x_information(int include_optional);

#include "test_n2_info_content.c"


v2x_information_t *instantiate_v2x_information(int include_optional) {
	v2x_information_t *v2x_information = NULL;
	if(include_optional) {
		v2x_information = v2x_information_create(
			// false, not to have infinite recursion
			instantiate_n2_info_content(0)
			);
	} else {
		v2x_information = v2x_information_create(
			NULL
			);
	}

	return v2x_information;
}


#ifdef v2x_information_MAIN

void test_v2x_information(int include_optional) {
	v2x_information_t *v2x_information_1 = instantiate_v2x_information(
		include_optional);

	cJSON *jsonv2x_information_1 = v2x_information_convertToJSON(
		v2x_information_1);
	printf("v2x_information :\n%s\n", cJSON_Print(jsonv2x_information_1));
	v2x_information_t *v2x_information_2 = v2x_information_parseFromJSON(
		jsonv2x_information_1);
	cJSON *jsonv2x_information_2 = v2x_information_convertToJSON(
		v2x_information_2);
	printf("repeating v2x_information:\n%s\n",
	       cJSON_Print(jsonv2x_information_2));
}

int main() {
	test_v2x_information(1);
	test_v2x_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // v2x_information_MAIN
#endif // v2x_information_TEST
