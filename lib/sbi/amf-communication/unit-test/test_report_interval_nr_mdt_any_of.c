#ifndef report_interval_nr_mdt_any_of_TEST
#define report_interval_nr_mdt_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define report_interval_nr_mdt_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/report_interval_nr_mdt_any_of.h"
report_interval_nr_mdt_any_of_t *instantiate_report_interval_nr_mdt_any_of(
	int include_optional);



report_interval_nr_mdt_any_of_t *instantiate_report_interval_nr_mdt_any_of(
	int include_optional) {
	report_interval_nr_mdt_any_of_t *report_interval_nr_mdt_any_of = NULL;
	if(include_optional) {
		report_interval_nr_mdt_any_of =
			report_interval_nr_mdt_any_of_create(
				);
	} else {
		report_interval_nr_mdt_any_of =
			report_interval_nr_mdt_any_of_create(
				);
	}

	return report_interval_nr_mdt_any_of;
}


#ifdef report_interval_nr_mdt_any_of_MAIN

void test_report_interval_nr_mdt_any_of(int include_optional) {
	report_interval_nr_mdt_any_of_t *report_interval_nr_mdt_any_of_1 =
		instantiate_report_interval_nr_mdt_any_of(include_optional);

	cJSON *jsonreport_interval_nr_mdt_any_of_1 =
		report_interval_nr_mdt_any_of_convertToJSON(
			report_interval_nr_mdt_any_of_1);
	printf("report_interval_nr_mdt_any_of :\n%s\n",
	       cJSON_Print(jsonreport_interval_nr_mdt_any_of_1));
	report_interval_nr_mdt_any_of_t *report_interval_nr_mdt_any_of_2 =
		report_interval_nr_mdt_any_of_parseFromJSON(
			jsonreport_interval_nr_mdt_any_of_1);
	cJSON *jsonreport_interval_nr_mdt_any_of_2 =
		report_interval_nr_mdt_any_of_convertToJSON(
			report_interval_nr_mdt_any_of_2);
	printf("repeating report_interval_nr_mdt_any_of:\n%s\n",
	       cJSON_Print(jsonreport_interval_nr_mdt_any_of_2));
}

int main() {
	test_report_interval_nr_mdt_any_of(1);
	test_report_interval_nr_mdt_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // report_interval_nr_mdt_any_of_MAIN
#endif // report_interval_nr_mdt_any_of_TEST
