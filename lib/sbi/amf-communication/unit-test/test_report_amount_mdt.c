#ifndef report_amount_mdt_TEST
#define report_amount_mdt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define report_amount_mdt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/report_amount_mdt.h"
report_amount_mdt_t *instantiate_report_amount_mdt(int include_optional);



report_amount_mdt_t *instantiate_report_amount_mdt(int include_optional) {
	report_amount_mdt_t *report_amount_mdt = NULL;
	if(include_optional) {
		report_amount_mdt = report_amount_mdt_create(
			);
	} else {
		report_amount_mdt = report_amount_mdt_create(
			);
	}

	return report_amount_mdt;
}


#ifdef report_amount_mdt_MAIN

void test_report_amount_mdt(int include_optional) {
	report_amount_mdt_t *report_amount_mdt_1 =
		instantiate_report_amount_mdt(include_optional);

	cJSON *jsonreport_amount_mdt_1 = report_amount_mdt_convertToJSON(
		report_amount_mdt_1);
	printf("report_amount_mdt :\n%s\n",
	       cJSON_Print(jsonreport_amount_mdt_1));
	report_amount_mdt_t *report_amount_mdt_2 =
		report_amount_mdt_parseFromJSON(jsonreport_amount_mdt_1);
	cJSON *jsonreport_amount_mdt_2 = report_amount_mdt_convertToJSON(
		report_amount_mdt_2);
	printf("repeating report_amount_mdt:\n%s\n",
	       cJSON_Print(jsonreport_amount_mdt_2));
}

int main() {
	test_report_amount_mdt(1);
	test_report_amount_mdt(0);

	printf("Hello world \n");
	return 0;
}

#endif // report_amount_mdt_MAIN
#endif // report_amount_mdt_TEST
