#ifndef n1_message_class_TEST
#define n1_message_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_message_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_message_class.h"
n1_message_class_t *instantiate_n1_message_class(int include_optional);



n1_message_class_t *instantiate_n1_message_class(int include_optional) {
	n1_message_class_t *n1_message_class = NULL;
	if(include_optional) {
		n1_message_class = n1_message_class_create(
			);
	} else {
		n1_message_class = n1_message_class_create(
			);
	}

	return n1_message_class;
}


#ifdef n1_message_class_MAIN

void test_n1_message_class(int include_optional) {
	n1_message_class_t *n1_message_class_1 = instantiate_n1_message_class(
		include_optional);

	cJSON *jsonn1_message_class_1 = n1_message_class_convertToJSON(
		n1_message_class_1);
	printf("n1_message_class :\n%s\n", cJSON_Print(jsonn1_message_class_1));
	n1_message_class_t *n1_message_class_2 = n1_message_class_parseFromJSON(
		jsonn1_message_class_1);
	cJSON *jsonn1_message_class_2 = n1_message_class_convertToJSON(
		n1_message_class_2);
	printf("repeating n1_message_class:\n%s\n",
	       cJSON_Print(jsonn1_message_class_2));
}

int main() {
	test_n1_message_class(1);
	test_n1_message_class(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_message_class_MAIN
#endif // n1_message_class_TEST
