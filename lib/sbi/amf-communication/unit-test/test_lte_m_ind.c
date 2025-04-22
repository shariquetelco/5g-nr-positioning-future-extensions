#ifndef lte_m_ind_TEST
#define lte_m_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lte_m_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lte_m_ind.h"
lte_m_ind_t *instantiate_lte_m_ind(int include_optional);



lte_m_ind_t *instantiate_lte_m_ind(int include_optional) {
	lte_m_ind_t *lte_m_ind = NULL;
	if(include_optional) {
		lte_m_ind = lte_m_ind_create(
			1
			);
	} else {
		lte_m_ind = lte_m_ind_create(
			1
			);
	}

	return lte_m_ind;
}


#ifdef lte_m_ind_MAIN

void test_lte_m_ind(int include_optional) {
	lte_m_ind_t *lte_m_ind_1 = instantiate_lte_m_ind(include_optional);

	cJSON *jsonlte_m_ind_1 = lte_m_ind_convertToJSON(lte_m_ind_1);
	printf("lte_m_ind :\n%s\n", cJSON_Print(jsonlte_m_ind_1));
	lte_m_ind_t *lte_m_ind_2 = lte_m_ind_parseFromJSON(jsonlte_m_ind_1);
	cJSON *jsonlte_m_ind_2 = lte_m_ind_convertToJSON(lte_m_ind_2);
	printf("repeating lte_m_ind:\n%s\n", cJSON_Print(jsonlte_m_ind_2));
}

int main() {
	test_lte_m_ind(1);
	test_lte_m_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // lte_m_ind_MAIN
#endif // lte_m_ind_TEST
