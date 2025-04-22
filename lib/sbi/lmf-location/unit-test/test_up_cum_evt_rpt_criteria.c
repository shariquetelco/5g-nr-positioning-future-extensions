#ifndef up_cum_evt_rpt_criteria_TEST
#define up_cum_evt_rpt_criteria_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_cum_evt_rpt_criteria_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_cum_evt_rpt_criteria.h"
up_cum_evt_rpt_criteria_t *instantiate_up_cum_evt_rpt_criteria(
	int include_optional);



up_cum_evt_rpt_criteria_t *instantiate_up_cum_evt_rpt_criteria(
	int include_optional) {
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria = NULL;
	if(include_optional) {
		up_cum_evt_rpt_criteria = up_cum_evt_rpt_criteria_create(
			56,
			56
			);
	} else {
		up_cum_evt_rpt_criteria = up_cum_evt_rpt_criteria_create(
			56,
			56
			);
	}

	return up_cum_evt_rpt_criteria;
}


#ifdef up_cum_evt_rpt_criteria_MAIN

void test_up_cum_evt_rpt_criteria(int include_optional) {
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_1 =
		instantiate_up_cum_evt_rpt_criteria(include_optional);

	cJSON *jsonup_cum_evt_rpt_criteria_1 =
		up_cum_evt_rpt_criteria_convertToJSON(up_cum_evt_rpt_criteria_1);
	printf("up_cum_evt_rpt_criteria :\n%s\n",
	       cJSON_Print(jsonup_cum_evt_rpt_criteria_1));
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_2 =
		up_cum_evt_rpt_criteria_parseFromJSON(
			jsonup_cum_evt_rpt_criteria_1);
	cJSON *jsonup_cum_evt_rpt_criteria_2 =
		up_cum_evt_rpt_criteria_convertToJSON(up_cum_evt_rpt_criteria_2);
	printf("repeating up_cum_evt_rpt_criteria:\n%s\n",
	       cJSON_Print(jsonup_cum_evt_rpt_criteria_2));
}

int main() {
	test_up_cum_evt_rpt_criteria(1);
	test_up_cum_evt_rpt_criteria(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_cum_evt_rpt_criteria_MAIN
#endif // up_cum_evt_rpt_criteria_TEST
