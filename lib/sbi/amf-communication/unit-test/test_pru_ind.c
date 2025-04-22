#ifndef pru_ind_TEST
#define pru_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pru_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pru_ind.h"
pru_ind_t *instantiate_pru_ind(int include_optional);



pru_ind_t *instantiate_pru_ind(int include_optional) {
	pru_ind_t *pru_ind = NULL;
	if(include_optional) {
		pru_ind = pru_ind_create(
			);
	} else {
		pru_ind = pru_ind_create(
			);
	}

	return pru_ind;
}


#ifdef pru_ind_MAIN

void test_pru_ind(int include_optional) {
	pru_ind_t *pru_ind_1 = instantiate_pru_ind(include_optional);

	cJSON *jsonpru_ind_1 = pru_ind_convertToJSON(pru_ind_1);
	printf("pru_ind :\n%s\n", cJSON_Print(jsonpru_ind_1));
	pru_ind_t *pru_ind_2 = pru_ind_parseFromJSON(jsonpru_ind_1);
	cJSON *jsonpru_ind_2 = pru_ind_convertToJSON(pru_ind_2);
	printf("repeating pru_ind:\n%s\n", cJSON_Print(jsonpru_ind_2));
}

int main() {
	test_pru_ind(1);
	test_pru_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // pru_ind_MAIN
#endif // pru_ind_TEST
