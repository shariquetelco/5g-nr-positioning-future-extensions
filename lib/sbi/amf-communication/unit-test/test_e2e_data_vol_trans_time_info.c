#ifndef e2e_data_vol_trans_time_info_TEST
#define e2e_data_vol_trans_time_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e2e_data_vol_trans_time_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e2e_data_vol_trans_time_info.h"
e2e_data_vol_trans_time_info_t *instantiate_e2e_data_vol_trans_time_info(
	int include_optional);



e2e_data_vol_trans_time_info_t *instantiate_e2e_data_vol_trans_time_info(
	int include_optional) {
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info = NULL;
	if(include_optional) {
		e2e_data_vol_trans_time_info =
			e2e_data_vol_trans_time_info_create(
				list_createList(),
				list_createList(),
				list_createList(),
				0
				);
	} else {
		e2e_data_vol_trans_time_info =
			e2e_data_vol_trans_time_info_create(
				list_createList(),
				list_createList(),
				list_createList(),
				0
				);
	}

	return e2e_data_vol_trans_time_info;
}


#ifdef e2e_data_vol_trans_time_info_MAIN

void test_e2e_data_vol_trans_time_info(int include_optional) {
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_1 =
		instantiate_e2e_data_vol_trans_time_info(include_optional);

	cJSON *jsone2e_data_vol_trans_time_info_1 =
		e2e_data_vol_trans_time_info_convertToJSON(
			e2e_data_vol_trans_time_info_1);
	printf("e2e_data_vol_trans_time_info :\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_info_1));
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_2 =
		e2e_data_vol_trans_time_info_parseFromJSON(
			jsone2e_data_vol_trans_time_info_1);
	cJSON *jsone2e_data_vol_trans_time_info_2 =
		e2e_data_vol_trans_time_info_convertToJSON(
			e2e_data_vol_trans_time_info_2);
	printf("repeating e2e_data_vol_trans_time_info:\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_info_2));
}

int main() {
	test_e2e_data_vol_trans_time_info(1);
	test_e2e_data_vol_trans_time_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // e2e_data_vol_trans_time_info_MAIN
#endif // e2e_data_vol_trans_time_info_TEST
