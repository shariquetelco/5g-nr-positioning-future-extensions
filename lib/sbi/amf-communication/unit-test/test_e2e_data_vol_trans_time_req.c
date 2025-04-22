#ifndef e2e_data_vol_trans_time_req_TEST
#define e2e_data_vol_trans_time_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e2e_data_vol_trans_time_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e2e_data_vol_trans_time_req.h"
e2e_data_vol_trans_time_req_t *instantiate_e2e_data_vol_trans_time_req(
	int include_optional);

#include "test_e2e_data_vol_trans_time_criterion.c"
#include "test_matching_direction.c"
#include "test_data_volume.c"


e2e_data_vol_trans_time_req_t *instantiate_e2e_data_vol_trans_time_req(
	int include_optional) {
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req = NULL;
	if(include_optional) {
		e2e_data_vol_trans_time_req =
			e2e_data_vol_trans_time_req_create(
				null,
				null,
				0,
				0,
				0,
				"2013-10-20T19:20:30+01:00",
				// false, not to have infinite recursion
				instantiate_data_volume(0),
				0
				);
	} else {
		e2e_data_vol_trans_time_req =
			e2e_data_vol_trans_time_req_create(
				null,
				null,
				0,
				0,
				0,
				"2013-10-20T19:20:30+01:00",
				NULL,
				0
				);
	}

	return e2e_data_vol_trans_time_req;
}


#ifdef e2e_data_vol_trans_time_req_MAIN

void test_e2e_data_vol_trans_time_req(int include_optional) {
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_1 =
		instantiate_e2e_data_vol_trans_time_req(include_optional);

	cJSON *jsone2e_data_vol_trans_time_req_1 =
		e2e_data_vol_trans_time_req_convertToJSON(
			e2e_data_vol_trans_time_req_1);
	printf("e2e_data_vol_trans_time_req :\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_req_1));
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_2 =
		e2e_data_vol_trans_time_req_parseFromJSON(
			jsone2e_data_vol_trans_time_req_1);
	cJSON *jsone2e_data_vol_trans_time_req_2 =
		e2e_data_vol_trans_time_req_convertToJSON(
			e2e_data_vol_trans_time_req_2);
	printf("repeating e2e_data_vol_trans_time_req:\n%s\n",
	       cJSON_Print(jsone2e_data_vol_trans_time_req_2));
}

int main() {
	test_e2e_data_vol_trans_time_req(1);
	test_e2e_data_vol_trans_time_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // e2e_data_vol_trans_time_req_MAIN
#endif // e2e_data_vol_trans_time_req_TEST
