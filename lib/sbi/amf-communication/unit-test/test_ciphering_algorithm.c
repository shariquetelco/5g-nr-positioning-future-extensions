#ifndef ciphering_algorithm_TEST
#define ciphering_algorithm_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ciphering_algorithm_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ciphering_algorithm.h"
ciphering_algorithm_t *instantiate_ciphering_algorithm(int include_optional);



ciphering_algorithm_t *instantiate_ciphering_algorithm(int include_optional) {
	ciphering_algorithm_t *ciphering_algorithm = NULL;
	if(include_optional) {
		ciphering_algorithm = ciphering_algorithm_create(
			);
	} else {
		ciphering_algorithm = ciphering_algorithm_create(
			);
	}

	return ciphering_algorithm;
}


#ifdef ciphering_algorithm_MAIN

void test_ciphering_algorithm(int include_optional) {
	ciphering_algorithm_t *ciphering_algorithm_1 =
		instantiate_ciphering_algorithm(include_optional);

	cJSON *jsonciphering_algorithm_1 = ciphering_algorithm_convertToJSON(
		ciphering_algorithm_1);
	printf("ciphering_algorithm :\n%s\n",
	       cJSON_Print(jsonciphering_algorithm_1));
	ciphering_algorithm_t *ciphering_algorithm_2 =
		ciphering_algorithm_parseFromJSON(jsonciphering_algorithm_1);
	cJSON *jsonciphering_algorithm_2 = ciphering_algorithm_convertToJSON(
		ciphering_algorithm_2);
	printf("repeating ciphering_algorithm:\n%s\n",
	       cJSON_Print(jsonciphering_algorithm_2));
}

int main() {
	test_ciphering_algorithm(1);
	test_ciphering_algorithm(0);

	printf("Hello world \n");
	return 0;
}

#endif // ciphering_algorithm_MAIN
#endif // ciphering_algorithm_TEST
