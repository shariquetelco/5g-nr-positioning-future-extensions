#ifndef ecgi_TEST
#define ecgi_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ecgi_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ecgi.h"
ecgi_t *instantiate_ecgi(int include_optional);

#include "test_plmn_id.c"


ecgi_t *instantiate_ecgi(int include_optional) {
	ecgi_t *ecgi = NULL;
	if(include_optional) {
		ecgi = ecgi_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			"a"
			);
	} else {
		ecgi = ecgi_create(
			NULL,
			"a",
			"a"
			);
	}

	return ecgi;
}


#ifdef ecgi_MAIN

void test_ecgi(int include_optional) {
	ecgi_t *ecgi_1 = instantiate_ecgi(include_optional);

	cJSON *jsonecgi_1 = ecgi_convertToJSON(ecgi_1);
	printf("ecgi :\n%s\n", cJSON_Print(jsonecgi_1));
	ecgi_t *ecgi_2 = ecgi_parseFromJSON(jsonecgi_1);
	cJSON *jsonecgi_2 = ecgi_convertToJSON(ecgi_2);
	printf("repeating ecgi:\n%s\n", cJSON_Print(jsonecgi_2));
}

int main() {
	test_ecgi(1);
	test_ecgi(0);

	printf("Hello world \n");
	return 0;
}

#endif // ecgi_MAIN
#endif // ecgi_TEST
