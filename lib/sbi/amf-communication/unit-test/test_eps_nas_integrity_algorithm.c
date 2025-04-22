#ifndef eps_nas_integrity_algorithm_TEST
#define eps_nas_integrity_algorithm_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eps_nas_integrity_algorithm_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eps_nas_integrity_algorithm.h"
eps_nas_integrity_algorithm_t *instantiate_eps_nas_integrity_algorithm(
	int include_optional);



eps_nas_integrity_algorithm_t *instantiate_eps_nas_integrity_algorithm(
	int include_optional) {
	eps_nas_integrity_algorithm_t *eps_nas_integrity_algorithm = NULL;
	if(include_optional) {
		eps_nas_integrity_algorithm =
			eps_nas_integrity_algorithm_create(
				);
	} else {
		eps_nas_integrity_algorithm =
			eps_nas_integrity_algorithm_create(
				);
	}

	return eps_nas_integrity_algorithm;
}


#ifdef eps_nas_integrity_algorithm_MAIN

void test_eps_nas_integrity_algorithm(int include_optional) {
	eps_nas_integrity_algorithm_t *eps_nas_integrity_algorithm_1 =
		instantiate_eps_nas_integrity_algorithm(include_optional);

	cJSON *jsoneps_nas_integrity_algorithm_1 =
		eps_nas_integrity_algorithm_convertToJSON(
			eps_nas_integrity_algorithm_1);
	printf("eps_nas_integrity_algorithm :\n%s\n",
	       cJSON_Print(jsoneps_nas_integrity_algorithm_1));
	eps_nas_integrity_algorithm_t *eps_nas_integrity_algorithm_2 =
		eps_nas_integrity_algorithm_parseFromJSON(
			jsoneps_nas_integrity_algorithm_1);
	cJSON *jsoneps_nas_integrity_algorithm_2 =
		eps_nas_integrity_algorithm_convertToJSON(
			eps_nas_integrity_algorithm_2);
	printf("repeating eps_nas_integrity_algorithm:\n%s\n",
	       cJSON_Print(jsoneps_nas_integrity_algorithm_2));
}

int main() {
	test_eps_nas_integrity_algorithm(1);
	test_eps_nas_integrity_algorithm(0);

	printf("Hello world \n");
	return 0;
}

#endif // eps_nas_integrity_algorithm_MAIN
#endif // eps_nas_integrity_algorithm_TEST
