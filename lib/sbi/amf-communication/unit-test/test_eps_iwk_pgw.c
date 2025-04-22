#ifndef eps_iwk_pgw_TEST
#define eps_iwk_pgw_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define eps_iwk_pgw_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/eps_iwk_pgw.h"
eps_iwk_pgw_t *instantiate_eps_iwk_pgw(int include_optional);

#include "test_plmn_id.c"


eps_iwk_pgw_t *instantiate_eps_iwk_pgw(int include_optional) {
	eps_iwk_pgw_t *eps_iwk_pgw = NULL;
	if(include_optional) {
		eps_iwk_pgw = eps_iwk_pgw_create(
			"a",
			"0",
			// false, not to have infinite recursion
			instantiate_plmn_id(0)
			);
	} else {
		eps_iwk_pgw = eps_iwk_pgw_create(
			"a",
			"0",
			NULL
			);
	}

	return eps_iwk_pgw;
}


#ifdef eps_iwk_pgw_MAIN

void test_eps_iwk_pgw(int include_optional) {
	eps_iwk_pgw_t *eps_iwk_pgw_1 =
		instantiate_eps_iwk_pgw(include_optional);

	cJSON *jsoneps_iwk_pgw_1 = eps_iwk_pgw_convertToJSON(eps_iwk_pgw_1);
	printf("eps_iwk_pgw :\n%s\n", cJSON_Print(jsoneps_iwk_pgw_1));
	eps_iwk_pgw_t *eps_iwk_pgw_2 = eps_iwk_pgw_parseFromJSON(
		jsoneps_iwk_pgw_1);
	cJSON *jsoneps_iwk_pgw_2 = eps_iwk_pgw_convertToJSON(eps_iwk_pgw_2);
	printf("repeating eps_iwk_pgw:\n%s\n", cJSON_Print(jsoneps_iwk_pgw_2));
}

int main() {
	test_eps_iwk_pgw(1);
	test_eps_iwk_pgw(0);

	printf("Hello world \n");
	return 0;
}

#endif // eps_iwk_pgw_MAIN
#endif // eps_iwk_pgw_TEST
