#ifndef exception_id_TEST
#define exception_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define exception_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/exception_id.h"
exception_id_t *instantiate_exception_id(int include_optional);



exception_id_t *instantiate_exception_id(int include_optional) {
	exception_id_t *exception_id = NULL;
	if(include_optional) {
		exception_id = exception_id_create(
			);
	} else {
		exception_id = exception_id_create(
			);
	}

	return exception_id;
}


#ifdef exception_id_MAIN

void test_exception_id(int include_optional) {
	exception_id_t *exception_id_1 = instantiate_exception_id(
		include_optional);

	cJSON *jsonexception_id_1 = exception_id_convertToJSON(exception_id_1);
	printf("exception_id :\n%s\n", cJSON_Print(jsonexception_id_1));
	exception_id_t *exception_id_2 = exception_id_parseFromJSON(
		jsonexception_id_1);
	cJSON *jsonexception_id_2 = exception_id_convertToJSON(exception_id_2);
	printf("repeating exception_id:\n%s\n",
	       cJSON_Print(jsonexception_id_2));
}

int main() {
	test_exception_id(1);
	test_exception_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // exception_id_MAIN
#endif // exception_id_TEST
