#ifndef ciphering_set_report_TEST
#define ciphering_set_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ciphering_set_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ciphering_set_report.h"
ciphering_set_report_t *instantiate_ciphering_set_report(int include_optional);



ciphering_set_report_t *instantiate_ciphering_set_report(int include_optional) {
	ciphering_set_report_t *ciphering_set_report = NULL;
	if(include_optional) {
		ciphering_set_report = ciphering_set_report_create(
			0,
			lmf_broadcast_ciphering_set_report__STORAGE_SUCCESSFUL
			);
	} else {
		ciphering_set_report = ciphering_set_report_create(
			0,
			lmf_broadcast_ciphering_set_report__STORAGE_SUCCESSFUL
			);
	}

	return ciphering_set_report;
}


#ifdef ciphering_set_report_MAIN

void test_ciphering_set_report(int include_optional) {
	ciphering_set_report_t *ciphering_set_report_1 =
		instantiate_ciphering_set_report(include_optional);

	cJSON *jsonciphering_set_report_1 = ciphering_set_report_convertToJSON(
		ciphering_set_report_1);
	printf("ciphering_set_report :\n%s\n",
	       cJSON_Print(jsonciphering_set_report_1));
	ciphering_set_report_t *ciphering_set_report_2 =
		ciphering_set_report_parseFromJSON(jsonciphering_set_report_1);
	cJSON *jsonciphering_set_report_2 = ciphering_set_report_convertToJSON(
		ciphering_set_report_2);
	printf("repeating ciphering_set_report:\n%s\n",
	       cJSON_Print(jsonciphering_set_report_2));
}

int main() {
	test_ciphering_set_report(1);
	test_ciphering_set_report(0);

	printf("Hello world \n");
	return 0;
}

#endif // ciphering_set_report_MAIN
#endif // ciphering_set_report_TEST
