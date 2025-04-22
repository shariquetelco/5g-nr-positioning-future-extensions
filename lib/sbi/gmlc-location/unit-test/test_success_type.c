#ifndef success_type_TEST
#define success_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define success_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/success_type.h"
success_type_t *instantiate_success_type(int include_optional);



success_type_t *instantiate_success_type(int include_optional) {
	success_type_t *success_type = NULL;
	if(include_optional) {
		success_type = success_type_create(
			);
	} else {
		success_type = success_type_create(
			);
	}

	return success_type;
}


#ifdef success_type_MAIN

void test_success_type(int include_optional) {
	success_type_t *success_type_1 = instantiate_success_type(
		include_optional);

	cJSON *jsonsuccess_type_1 = success_type_convertToJSON(success_type_1);
	printf("success_type :\n%s\n", cJSON_Print(jsonsuccess_type_1));
	success_type_t *success_type_2 = success_type_parseFromJSON(
		jsonsuccess_type_1);
	cJSON *jsonsuccess_type_2 = success_type_convertToJSON(success_type_2);
	printf("repeating success_type:\n%s\n",
	       cJSON_Print(jsonsuccess_type_2));
}

int main() {
	test_success_type(1);
	test_success_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // success_type_MAIN
#endif // success_type_TEST
