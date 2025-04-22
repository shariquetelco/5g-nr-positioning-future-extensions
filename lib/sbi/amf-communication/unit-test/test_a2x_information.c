#ifndef a2x_information_TEST
#define a2x_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define a2x_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/a2x_information.h"
a2x_information_t *instantiate_a2x_information(int include_optional);

#include "test_n2_info_content.c"


a2x_information_t *instantiate_a2x_information(int include_optional) {
	a2x_information_t *a2x_information = NULL;
	if(include_optional) {
		a2x_information = a2x_information_create(
			// false, not to have infinite recursion
			instantiate_n2_info_content(0)
			);
	} else {
		a2x_information = a2x_information_create(
			NULL
			);
	}

	return a2x_information;
}


#ifdef a2x_information_MAIN

void test_a2x_information(int include_optional) {
	a2x_information_t *a2x_information_1 = instantiate_a2x_information(
		include_optional);

	cJSON *jsona2x_information_1 = a2x_information_convertToJSON(
		a2x_information_1);
	printf("a2x_information :\n%s\n", cJSON_Print(jsona2x_information_1));
	a2x_information_t *a2x_information_2 = a2x_information_parseFromJSON(
		jsona2x_information_1);
	cJSON *jsona2x_information_2 = a2x_information_convertToJSON(
		a2x_information_2);
	printf("repeating a2x_information:\n%s\n",
	       cJSON_Print(jsona2x_information_2));
}

int main() {
	test_a2x_information(1);
	test_a2x_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // a2x_information_MAIN
#endif // a2x_information_TEST
