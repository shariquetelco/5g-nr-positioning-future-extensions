#ifndef e2e_data_vol_trans_time_criterion_any_of_TEST
#define e2e_data_vol_trans_time_criterion_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e2e_data_vol_trans_time_criterion_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e2e_data_vol_trans_time_criterion_any_of.h"
e2e_data_vol_trans_time_criterion_any_of_t *
instantiate_e2e_data_vol_trans_time_criterion_any_of(int include_optional);



e2e_data_vol_trans_time_criterion_any_of_t *
instantiate_e2e_data_vol_trans_time_criterion_any_of(int include_optional) {
	e2e_data_vol_trans_time_criterion_any_of_t *
	        e2e_data_vol_trans_time_criterion_any_of = NULL;
	if(include_optional) {
		e2e_data_vol_trans_time_criterion_any_of =
			e2e_data_vol_trans_time_criterion_any_of_create(
				);
	} else {
		e2e_data_vol_trans_time_criterion_any_of =
			e2e_data_vol_trans_time_criterion_any_of_create(
				);
	}

	return e2e_data_vol_trans_time_criterion_any_of;
}


#ifdef e2e_data_vol_trans_time_criterion_any_of_MAIN

void test_e2e_data_vol_trans_time_criterion_any_of(int include_optional) {
	e2e_data_vol_trans_time_criterion_any_of_t *
	        e2e_data_vol_trans_time_criterion_any_of_1 =
		instantiate_e2e_data_vol_trans_time_criterion_any_of(
			include_optional);

	cJSON *jsone2e_data_vol_trans_time_criterion_any_of_1 =
		e2e_data_vol_trans_time_criterion_any_of_convertToJSON(
			e2e_data_vol_trans_time_criterion_any_of_1);
	printf("e2e_data_vol_trans_time_criterion_any_of :\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_criterion_any_of_1));
	e2e_data_vol_trans_time_criterion_any_of_t *
	        e2e_data_vol_trans_time_criterion_any_of_2 =
		e2e_data_vol_trans_time_criterion_any_of_parseFromJSON(
			jsone2e_data_vol_trans_time_criterion_any_of_1);
	cJSON *jsone2e_data_vol_trans_time_criterion_any_of_2 =
		e2e_data_vol_trans_time_criterion_any_of_convertToJSON(
			e2e_data_vol_trans_time_criterion_any_of_2);
	printf("repeating e2e_data_vol_trans_time_criterion_any_of:\n%s\n", cJSON_Print(
		       jsone2e_data_vol_trans_time_criterion_any_of_2));
}

int main() {
	test_e2e_data_vol_trans_time_criterion_any_of(1);
	test_e2e_data_vol_trans_time_criterion_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // e2e_data_vol_trans_time_criterion_any_of_MAIN
#endif // e2e_data_vol_trans_time_criterion_any_of_TEST
