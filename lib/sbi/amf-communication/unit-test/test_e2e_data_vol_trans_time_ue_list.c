#ifndef e2e_data_vol_trans_time_ue_list_TEST
#define e2e_data_vol_trans_time_ue_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e2e_data_vol_trans_time_ue_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e2e_data_vol_trans_time_ue_list.h"
e2e_data_vol_trans_time_ue_list_t *instantiate_e2e_data_vol_trans_time_ue_list(
	int include_optional);

#include "test_network_area_info.c"
#include "test_time_window.c"


e2e_data_vol_trans_time_ue_list_t *instantiate_e2e_data_vol_trans_time_ue_list(
	int include_optional) {
	e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list =
		NULL;
	if(include_optional) {
		e2e_data_vol_trans_time_ue_list =
			e2e_data_vol_trans_time_ue_list_create(
				list_createList(),
				list_createList(),
				list_createList(),
				1,
				1,
				1,
				// false, not to have infinite recursion
				instantiate_network_area_info(0),
				// false, not to have infinite recursion
				instantiate_time_window(0)
				);
	} else {
		e2e_data_vol_trans_time_ue_list =
			e2e_data_vol_trans_time_ue_list_create(
				list_createList(),
				list_createList(),
				list_createList(),
				1,
				1,
				1,
				NULL,
				NULL
				);
	}

	return e2e_data_vol_trans_time_ue_list;
}


#ifdef e2e_data_vol_trans_time_ue_list_MAIN

void test_e2e_data_vol_trans_time_ue_list(int include_optional) {
	e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list_1 =
		instantiate_e2e_data_vol_trans_time_ue_list(include_optional);

	cJSON *jsone2e_data_vol_trans_time_ue_list_1 =
		e2e_data_vol_trans_time_ue_list_convertToJSON(
			e2e_data_vol_trans_time_ue_list_1);
	printf("e2e_data_vol_trans_time_ue_list :\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_ue_list_1));
	e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list_2 =
		e2e_data_vol_trans_time_ue_list_parseFromJSON(
			jsone2e_data_vol_trans_time_ue_list_1);
	cJSON *jsone2e_data_vol_trans_time_ue_list_2 =
		e2e_data_vol_trans_time_ue_list_convertToJSON(
			e2e_data_vol_trans_time_ue_list_2);
	printf("repeating e2e_data_vol_trans_time_ue_list:\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_ue_list_2));
}

int main() {
	test_e2e_data_vol_trans_time_ue_list(1);
	test_e2e_data_vol_trans_time_ue_list(0);

	printf("Hello world \n");
	return 0;
}

#endif // e2e_data_vol_trans_time_ue_list_MAIN
#endif // e2e_data_vol_trans_time_ue_list_TEST
