#ifndef immediate_mdt_conf_TEST
#define immediate_mdt_conf_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define immediate_mdt_conf_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/immediate_mdt_conf.h"
immediate_mdt_conf_t *instantiate_immediate_mdt_conf(int include_optional);

#include "test_job_type.c"
#include "test_report_interval_mdt.c"
#include "test_report_interval_nr_mdt.c"
#include "test_report_amount_mdt.c"
#include "test_collection_period_rmm_lte_mdt.c"
#include "test_collection_period_rmm_nr_mdt.c"
#include "test_measurement_period_lte_mdt.c"
#include "test_area_scope.c"
#include "test_positioning_method_mdt.c"


immediate_mdt_conf_t *instantiate_immediate_mdt_conf(int include_optional) {
	immediate_mdt_conf_t *immediate_mdt_conf = NULL;
	if(include_optional) {
		immediate_mdt_conf = immediate_mdt_conf_create(
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			null,
			null,
			0,
			0,
			0,
			0,
			null,
			null,
			null,
			// false, not to have infinite recursion
			instantiate_area_scope(0),
			null,
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		immediate_mdt_conf = immediate_mdt_conf_create(
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			null,
			null,
			0,
			0,
			0,
			0,
			null,
			null,
			null,
			NULL,
			null,
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return immediate_mdt_conf;
}


#ifdef immediate_mdt_conf_MAIN

void test_immediate_mdt_conf(int include_optional) {
	immediate_mdt_conf_t *immediate_mdt_conf_1 =
		instantiate_immediate_mdt_conf(include_optional);

	cJSON *jsonimmediate_mdt_conf_1 = immediate_mdt_conf_convertToJSON(
		immediate_mdt_conf_1);
	printf("immediate_mdt_conf :\n%s\n",
	       cJSON_Print(jsonimmediate_mdt_conf_1));
	immediate_mdt_conf_t *immediate_mdt_conf_2 =
		immediate_mdt_conf_parseFromJSON(jsonimmediate_mdt_conf_1);
	cJSON *jsonimmediate_mdt_conf_2 = immediate_mdt_conf_convertToJSON(
		immediate_mdt_conf_2);
	printf("repeating immediate_mdt_conf:\n%s\n",
	       cJSON_Print(jsonimmediate_mdt_conf_2));
}

int main() {
	test_immediate_mdt_conf(1);
	test_immediate_mdt_conf(0);

	printf("Hello world \n");
	return 0;
}

#endif // immediate_mdt_conf_MAIN
#endif // immediate_mdt_conf_TEST
