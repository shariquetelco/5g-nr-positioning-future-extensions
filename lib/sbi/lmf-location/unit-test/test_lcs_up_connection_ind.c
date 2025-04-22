#ifndef lcs_up_connection_ind_TEST
#define lcs_up_connection_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lcs_up_connection_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lcs_up_connection_ind.h"
lcs_up_connection_ind_t *instantiate_lcs_up_connection_ind(
	int include_optional);



lcs_up_connection_ind_t *instantiate_lcs_up_connection_ind(int include_optional)
{
	lcs_up_connection_ind_t *lcs_up_connection_ind = NULL;
	if(include_optional) {
		lcs_up_connection_ind = lcs_up_connection_ind_create(
			);
	} else {
		lcs_up_connection_ind = lcs_up_connection_ind_create(
			);
	}

	return lcs_up_connection_ind;
}


#ifdef lcs_up_connection_ind_MAIN

void test_lcs_up_connection_ind(int include_optional) {
	lcs_up_connection_ind_t *lcs_up_connection_ind_1 =
		instantiate_lcs_up_connection_ind(include_optional);

	cJSON *jsonlcs_up_connection_ind_1 =
		lcs_up_connection_ind_convertToJSON(lcs_up_connection_ind_1);
	printf("lcs_up_connection_ind :\n%s\n",
	       cJSON_Print(jsonlcs_up_connection_ind_1));
	lcs_up_connection_ind_t *lcs_up_connection_ind_2 =
		lcs_up_connection_ind_parseFromJSON(jsonlcs_up_connection_ind_1);
	cJSON *jsonlcs_up_connection_ind_2 =
		lcs_up_connection_ind_convertToJSON(lcs_up_connection_ind_2);
	printf("repeating lcs_up_connection_ind:\n%s\n",
	       cJSON_Print(jsonlcs_up_connection_ind_2));
}

int main() {
	test_lcs_up_connection_ind(1);
	test_lcs_up_connection_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // lcs_up_connection_ind_MAIN
#endif // lcs_up_connection_ind_TEST
