#ifndef pru_ind_any_of_TEST
#define pru_ind_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pru_ind_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pru_ind_any_of.h"
pru_ind_any_of_t *instantiate_pru_ind_any_of(int include_optional);



pru_ind_any_of_t *instantiate_pru_ind_any_of(int include_optional) {
	pru_ind_any_of_t *pru_ind_any_of = NULL;
	if(include_optional) {
		pru_ind_any_of = pru_ind_any_of_create(
			);
	} else {
		pru_ind_any_of = pru_ind_any_of_create(
			);
	}

	return pru_ind_any_of;
}


#ifdef pru_ind_any_of_MAIN

void test_pru_ind_any_of(int include_optional) {
	pru_ind_any_of_t *pru_ind_any_of_1 = instantiate_pru_ind_any_of(
		include_optional);

	cJSON *jsonpru_ind_any_of_1 = pru_ind_any_of_convertToJSON(
		pru_ind_any_of_1);
	printf("pru_ind_any_of :\n%s\n", cJSON_Print(jsonpru_ind_any_of_1));
	pru_ind_any_of_t *pru_ind_any_of_2 = pru_ind_any_of_parseFromJSON(
		jsonpru_ind_any_of_1);
	cJSON *jsonpru_ind_any_of_2 = pru_ind_any_of_convertToJSON(
		pru_ind_any_of_2);
	printf("repeating pru_ind_any_of:\n%s\n",
	       cJSON_Print(jsonpru_ind_any_of_2));
}

int main() {
	test_pru_ind_any_of(1);
	test_pru_ind_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // pru_ind_any_of_MAIN
#endif // pru_ind_any_of_TEST
