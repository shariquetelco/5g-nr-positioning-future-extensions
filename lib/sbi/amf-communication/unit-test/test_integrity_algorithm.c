#ifndef integrity_algorithm_TEST
#define integrity_algorithm_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define integrity_algorithm_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/integrity_algorithm.h"
integrity_algorithm_t *instantiate_integrity_algorithm(int include_optional);



integrity_algorithm_t *instantiate_integrity_algorithm(int include_optional) {
	integrity_algorithm_t *integrity_algorithm = NULL;
	if(include_optional) {
		integrity_algorithm = integrity_algorithm_create(
			);
	} else {
		integrity_algorithm = integrity_algorithm_create(
			);
	}

	return integrity_algorithm;
}


#ifdef integrity_algorithm_MAIN

void test_integrity_algorithm(int include_optional) {
	integrity_algorithm_t *integrity_algorithm_1 =
		instantiate_integrity_algorithm(include_optional);

	cJSON *jsonintegrity_algorithm_1 = integrity_algorithm_convertToJSON(
		integrity_algorithm_1);
	printf("integrity_algorithm :\n%s\n",
	       cJSON_Print(jsonintegrity_algorithm_1));
	integrity_algorithm_t *integrity_algorithm_2 =
		integrity_algorithm_parseFromJSON(jsonintegrity_algorithm_1);
	cJSON *jsonintegrity_algorithm_2 = integrity_algorithm_convertToJSON(
		integrity_algorithm_2);
	printf("repeating integrity_algorithm:\n%s\n",
	       cJSON_Print(jsonintegrity_algorithm_2));
}

int main() {
	test_integrity_algorithm(1);
	test_integrity_algorithm(0);

	printf("Hello world \n");
	return 0;
}

#endif // integrity_algorithm_MAIN
#endif // integrity_algorithm_TEST
