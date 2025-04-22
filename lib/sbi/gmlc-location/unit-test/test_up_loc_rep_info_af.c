#ifndef up_loc_rep_info_af_TEST
#define up_loc_rep_info_af_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_loc_rep_info_af_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_loc_rep_info_af.h"
up_loc_rep_info_af_t *instantiate_up_loc_rep_info_af(int include_optional);

#include "test_up_loc_rep_addr_af_rm.c"
#include "test_up_cum_evt_rpt_criteria.c"


up_loc_rep_info_af_t *instantiate_up_loc_rep_info_af(int include_optional) {
	up_loc_rep_info_af_t *up_loc_rep_info_af = NULL;
	if(include_optional) {
		up_loc_rep_info_af = up_loc_rep_info_af_create(
			ngmlc_location_up_loc_rep_info_af_UPLOCREPAFIND_true,
			// false, not to have infinite recursion
			instantiate_up_loc_rep_addr_af_rm(0),
			// false, not to have infinite recursion
			instantiate_up_cum_evt_rpt_criteria(0)
			);
	} else {
		up_loc_rep_info_af = up_loc_rep_info_af_create(
			ngmlc_location_up_loc_rep_info_af_UPLOCREPAFIND_true,
			NULL,
			NULL
			);
	}

	return up_loc_rep_info_af;
}


#ifdef up_loc_rep_info_af_MAIN

void test_up_loc_rep_info_af(int include_optional) {
	up_loc_rep_info_af_t *up_loc_rep_info_af_1 =
		instantiate_up_loc_rep_info_af(include_optional);

	cJSON *jsonup_loc_rep_info_af_1 = up_loc_rep_info_af_convertToJSON(
		up_loc_rep_info_af_1);
	printf("up_loc_rep_info_af :\n%s\n",
	       cJSON_Print(jsonup_loc_rep_info_af_1));
	up_loc_rep_info_af_t *up_loc_rep_info_af_2 =
		up_loc_rep_info_af_parseFromJSON(jsonup_loc_rep_info_af_1);
	cJSON *jsonup_loc_rep_info_af_2 = up_loc_rep_info_af_convertToJSON(
		up_loc_rep_info_af_2);
	printf("repeating up_loc_rep_info_af:\n%s\n",
	       cJSON_Print(jsonup_loc_rep_info_af_2));
}

int main() {
	test_up_loc_rep_info_af(1);
	test_up_loc_rep_info_af(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_loc_rep_info_af_MAIN
#endif // up_loc_rep_info_af_TEST
