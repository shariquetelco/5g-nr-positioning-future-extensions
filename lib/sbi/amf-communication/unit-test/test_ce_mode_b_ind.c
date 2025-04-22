#ifndef ce_mode_b_ind_TEST
#define ce_mode_b_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ce_mode_b_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ce_mode_b_ind.h"
ce_mode_b_ind_t *instantiate_ce_mode_b_ind(int include_optional);



ce_mode_b_ind_t *instantiate_ce_mode_b_ind(int include_optional) {
	ce_mode_b_ind_t *ce_mode_b_ind = NULL;
	if(include_optional) {
		ce_mode_b_ind = ce_mode_b_ind_create(
			1
			);
	} else {
		ce_mode_b_ind = ce_mode_b_ind_create(
			1
			);
	}

	return ce_mode_b_ind;
}


#ifdef ce_mode_b_ind_MAIN

void test_ce_mode_b_ind(int include_optional) {
	ce_mode_b_ind_t *ce_mode_b_ind_1 = instantiate_ce_mode_b_ind(
		include_optional);

	cJSON *jsonce_mode_b_ind_1 =
		ce_mode_b_ind_convertToJSON(ce_mode_b_ind_1);
	printf("ce_mode_b_ind :\n%s\n", cJSON_Print(jsonce_mode_b_ind_1));
	ce_mode_b_ind_t *ce_mode_b_ind_2 = ce_mode_b_ind_parseFromJSON(
		jsonce_mode_b_ind_1);
	cJSON *jsonce_mode_b_ind_2 =
		ce_mode_b_ind_convertToJSON(ce_mode_b_ind_2);
	printf("repeating ce_mode_b_ind:\n%s\n", cJSON_Print(
		       jsonce_mode_b_ind_2));
}

int main() {
	test_ce_mode_b_ind(1);
	test_ce_mode_b_ind(0);

	printf("Hello world \n");
	return 0;
}

#endif // ce_mode_b_ind_MAIN
#endif // ce_mode_b_ind_TEST
