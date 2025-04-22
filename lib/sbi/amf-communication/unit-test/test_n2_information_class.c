#ifndef n2_information_class_TEST
#define n2_information_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_information_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_information_class.h"
n2_information_class_t *instantiate_n2_information_class(int include_optional);



n2_information_class_t *instantiate_n2_information_class(int include_optional) {
	n2_information_class_t *n2_information_class = NULL;
	if(include_optional) {
		n2_information_class = n2_information_class_create(
			);
	} else {
		n2_information_class = n2_information_class_create(
			);
	}

	return n2_information_class;
}


#ifdef n2_information_class_MAIN

void test_n2_information_class(int include_optional) {
	n2_information_class_t *n2_information_class_1 =
		instantiate_n2_information_class(include_optional);

	cJSON *jsonn2_information_class_1 = n2_information_class_convertToJSON(
		n2_information_class_1);
	printf("n2_information_class :\n%s\n",
	       cJSON_Print(jsonn2_information_class_1));
	n2_information_class_t *n2_information_class_2 =
		n2_information_class_parseFromJSON(jsonn2_information_class_1);
	cJSON *jsonn2_information_class_2 = n2_information_class_convertToJSON(
		n2_information_class_2);
	printf("repeating n2_information_class:\n%s\n",
	       cJSON_Print(jsonn2_information_class_2));
}

int main() {
	test_n2_information_class(1);
	test_n2_information_class(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_information_class_MAIN
#endif // n2_information_class_TEST
