#ifndef e2e_data_vol_trans_time_per_ts_TEST
#define e2e_data_vol_trans_time_per_ts_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e2e_data_vol_trans_time_per_ts_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e2e_data_vol_trans_time_per_ts.h"
e2e_data_vol_trans_time_per_ts_t *instantiate_e2e_data_vol_trans_time_per_ts(
	int include_optional);



e2e_data_vol_trans_time_per_ts_t *instantiate_e2e_data_vol_trans_time_per_ts(
	int include_optional) {
	e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts = NULL;
	if(include_optional) {
		e2e_data_vol_trans_time_per_ts =
			e2e_data_vol_trans_time_per_ts_create(
				"2013-10-20T19:20:30+01:00",
				56,
				list_createList()
				);
	} else {
		e2e_data_vol_trans_time_per_ts =
			e2e_data_vol_trans_time_per_ts_create(
				"2013-10-20T19:20:30+01:00",
				56,
				list_createList()
				);
	}

	return e2e_data_vol_trans_time_per_ts;
}


#ifdef e2e_data_vol_trans_time_per_ts_MAIN

void test_e2e_data_vol_trans_time_per_ts(int include_optional) {
	e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts_1 =
		instantiate_e2e_data_vol_trans_time_per_ts(include_optional);

	cJSON *jsone2e_data_vol_trans_time_per_ts_1 =
		e2e_data_vol_trans_time_per_ts_convertToJSON(
			e2e_data_vol_trans_time_per_ts_1);
	printf("e2e_data_vol_trans_time_per_ts :\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_per_ts_1));
	e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts_2 =
		e2e_data_vol_trans_time_per_ts_parseFromJSON(
			jsone2e_data_vol_trans_time_per_ts_1);
	cJSON *jsone2e_data_vol_trans_time_per_ts_2 =
		e2e_data_vol_trans_time_per_ts_convertToJSON(
			e2e_data_vol_trans_time_per_ts_2);
	printf("repeating e2e_data_vol_trans_time_per_ts:\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_per_ts_2));
}

int main() {
	test_e2e_data_vol_trans_time_per_ts(1);
	test_e2e_data_vol_trans_time_per_ts(0);

	printf("Hello world \n");
	return 0;
}

#endif // e2e_data_vol_trans_time_per_ts_MAIN
#endif // e2e_data_vol_trans_time_per_ts_TEST
