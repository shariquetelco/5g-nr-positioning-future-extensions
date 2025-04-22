#ifndef report_interval_mdt_TEST
#define report_interval_mdt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define report_interval_mdt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/report_interval_mdt.h"
report_interval_mdt_t *instantiate_report_interval_mdt(int include_optional);



report_interval_mdt_t *instantiate_report_interval_mdt(int include_optional) {
	report_interval_mdt_t *report_interval_mdt = NULL;
	if(include_optional) {
		report_interval_mdt = report_interval_mdt_create(
			);
	} else {
		report_interval_mdt = report_interval_mdt_create(
			);
	}

	return report_interval_mdt;
}


#ifdef report_interval_mdt_MAIN

void test_report_interval_mdt(int include_optional) {
	report_interval_mdt_t *report_interval_mdt_1 =
		instantiate_report_interval_mdt(include_optional);

	cJSON *jsonreport_interval_mdt_1 = report_interval_mdt_convertToJSON(
		report_interval_mdt_1);
	printf("report_interval_mdt :\n%s\n",
	       cJSON_Print(jsonreport_interval_mdt_1));
	report_interval_mdt_t *report_interval_mdt_2 =
		report_interval_mdt_parseFromJSON(jsonreport_interval_mdt_1);
	cJSON *jsonreport_interval_mdt_2 = report_interval_mdt_convertToJSON(
		report_interval_mdt_2);
	printf("repeating report_interval_mdt:\n%s\n",
	       cJSON_Print(jsonreport_interval_mdt_2));
}

int main() {
	test_report_interval_mdt(1);
	test_report_interval_mdt(0);

	printf("Hello world \n");
	return 0;
}

#endif // report_interval_mdt_MAIN
#endif // report_interval_mdt_TEST
