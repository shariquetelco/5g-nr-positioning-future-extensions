#ifndef e2e_data_vol_trans_time_per_ue_TEST
#define e2e_data_vol_trans_time_per_ue_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e2e_data_vol_trans_time_per_ue_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e2e_data_vol_trans_time_per_ue.h"
e2e_data_vol_trans_time_per_ue_t *instantiate_e2e_data_vol_trans_time_per_ue(
	int include_optional);

#include "test_snssai.c"
#include "test_user_location.c"
#include "test_network_area_info.c"
#include "test_time_window.c"
#include "test_data_volume_transfer_time.c"


e2e_data_vol_trans_time_per_ue_t *instantiate_e2e_data_vol_trans_time_per_ue(
	int include_optional) {
	e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue = NULL;
	if(include_optional) {
		e2e_data_vol_trans_time_per_ue =
			e2e_data_vol_trans_time_per_ue_create(
				"a",
				"a",
				// false, not to have infinite recursion
				instantiate_snssai(0),
				"0",
				// false, not to have infinite recursion
				instantiate_user_location(0),
				"0",
				// false, not to have infinite recursion
				instantiate_network_area_info(0),
				// false, not to have infinite recursion
				instantiate_time_window(0),
				// false, not to have infinite recursion
				instantiate_data_volume_transfer_time(0)
				);
	} else {
		e2e_data_vol_trans_time_per_ue =
			e2e_data_vol_trans_time_per_ue_create(
				"a",
				"a",
				NULL,
				"0",
				NULL,
				"0",
				NULL,
				NULL,
				NULL
				);
	}

	return e2e_data_vol_trans_time_per_ue;
}


#ifdef e2e_data_vol_trans_time_per_ue_MAIN

void test_e2e_data_vol_trans_time_per_ue(int include_optional) {
	e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_1 =
		instantiate_e2e_data_vol_trans_time_per_ue(include_optional);

	cJSON *jsone2e_data_vol_trans_time_per_ue_1 =
		e2e_data_vol_trans_time_per_ue_convertToJSON(
			e2e_data_vol_trans_time_per_ue_1);
	printf("e2e_data_vol_trans_time_per_ue :\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_per_ue_1));
	e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_2 =
		e2e_data_vol_trans_time_per_ue_parseFromJSON(
			jsone2e_data_vol_trans_time_per_ue_1);
	cJSON *jsone2e_data_vol_trans_time_per_ue_2 =
		e2e_data_vol_trans_time_per_ue_convertToJSON(
			e2e_data_vol_trans_time_per_ue_2);
	printf("repeating e2e_data_vol_trans_time_per_ue:\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_per_ue_2));
}

int main() {
	test_e2e_data_vol_trans_time_per_ue(1);
	test_e2e_data_vol_trans_time_per_ue(0);

	printf("Hello world \n");
	return 0;
}

#endif // e2e_data_vol_trans_time_per_ue_MAIN
#endif // e2e_data_vol_trans_time_per_ue_TEST
