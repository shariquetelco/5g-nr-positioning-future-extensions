#ifndef nr_a2x_auth_TEST
#define nr_a2x_auth_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nr_a2x_auth_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nr_a2x_auth.h"
nr_a2x_auth_t *instantiate_nr_a2x_auth(int include_optional);

#include "test_ue_auth.c"


nr_a2x_auth_t *instantiate_nr_a2x_auth(int include_optional) {
	nr_a2x_auth_t *nr_a2x_auth = NULL;
	if(include_optional) {
		nr_a2x_auth = nr_a2x_auth_create(
			null
			);
	} else {
		nr_a2x_auth = nr_a2x_auth_create(
			null
			);
	}

	return nr_a2x_auth;
}


#ifdef nr_a2x_auth_MAIN

void test_nr_a2x_auth(int include_optional) {
	nr_a2x_auth_t *nr_a2x_auth_1 =
		instantiate_nr_a2x_auth(include_optional);

	cJSON *jsonnr_a2x_auth_1 = nr_a2x_auth_convertToJSON(nr_a2x_auth_1);
	printf("nr_a2x_auth :\n%s\n", cJSON_Print(jsonnr_a2x_auth_1));
	nr_a2x_auth_t *nr_a2x_auth_2 = nr_a2x_auth_parseFromJSON(
		jsonnr_a2x_auth_1);
	cJSON *jsonnr_a2x_auth_2 = nr_a2x_auth_convertToJSON(nr_a2x_auth_2);
	printf("repeating nr_a2x_auth:\n%s\n", cJSON_Print(jsonnr_a2x_auth_2));
}

int main() {
	test_nr_a2x_auth(1);
	test_nr_a2x_auth(0);

	printf("Hello world \n");
	return 0;
}

#endif // nr_a2x_auth_MAIN
#endif // nr_a2x_auth_TEST
