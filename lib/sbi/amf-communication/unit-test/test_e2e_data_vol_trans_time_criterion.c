#ifndef e2e_data_vol_trans_time_criterion_TEST
#define e2e_data_vol_trans_time_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e2e_data_vol_trans_time_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e2e_data_vol_trans_time_criterion.h"
e2e_data_vol_trans_time_criterion_t *
instantiate_e2e_data_vol_trans_time_criterion(int include_optional);



e2e_data_vol_trans_time_criterion_t *
instantiate_e2e_data_vol_trans_time_criterion(int include_optional) {
	e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion =
		NULL;
	if(include_optional) {
		e2e_data_vol_trans_time_criterion =
			e2e_data_vol_trans_time_criterion_create(
				);
	} else {
		e2e_data_vol_trans_time_criterion =
			e2e_data_vol_trans_time_criterion_create(
				);
	}

	return e2e_data_vol_trans_time_criterion;
}


#ifdef e2e_data_vol_trans_time_criterion_MAIN

void test_e2e_data_vol_trans_time_criterion(int include_optional) {
	e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion_1
	        = instantiate_e2e_data_vol_trans_time_criterion(include_optional);

	cJSON *jsone2e_data_vol_trans_time_criterion_1 =
		e2e_data_vol_trans_time_criterion_convertToJSON(
			e2e_data_vol_trans_time_criterion_1);
	printf("e2e_data_vol_trans_time_criterion :\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_criterion_1));
	e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion_2
	        = e2e_data_vol_trans_time_criterion_parseFromJSON(
			  jsone2e_data_vol_trans_time_criterion_1);
	cJSON *jsone2e_data_vol_trans_time_criterion_2 =
		e2e_data_vol_trans_time_criterion_convertToJSON(
			e2e_data_vol_trans_time_criterion_2);
	printf("repeating e2e_data_vol_trans_time_criterion:\n%s\n", cJSON_Print(
		       jsone2e_data_vol_trans_time_criterion_2));
}

int main() {
	test_e2e_data_vol_trans_time_criterion(1);
	test_e2e_data_vol_trans_time_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // e2e_data_vol_trans_time_criterion_MAIN
#endif // e2e_data_vol_trans_time_criterion_TEST
