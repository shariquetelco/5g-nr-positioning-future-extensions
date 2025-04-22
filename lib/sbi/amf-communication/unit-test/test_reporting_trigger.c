#ifndef reporting_trigger_TEST
#define reporting_trigger_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reporting_trigger_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reporting_trigger.h"
reporting_trigger_t *instantiate_reporting_trigger(int include_optional);



reporting_trigger_t *instantiate_reporting_trigger(int include_optional) {
	reporting_trigger_t *reporting_trigger = NULL;
	if(include_optional) {
		reporting_trigger = reporting_trigger_create(
			);
	} else {
		reporting_trigger = reporting_trigger_create(
			);
	}

	return reporting_trigger;
}


#ifdef reporting_trigger_MAIN

void test_reporting_trigger(int include_optional) {
	reporting_trigger_t *reporting_trigger_1 =
		instantiate_reporting_trigger(include_optional);

	cJSON *jsonreporting_trigger_1 = reporting_trigger_convertToJSON(
		reporting_trigger_1);
	printf("reporting_trigger :\n%s\n",
	       cJSON_Print(jsonreporting_trigger_1));
	reporting_trigger_t *reporting_trigger_2 =
		reporting_trigger_parseFromJSON(jsonreporting_trigger_1);
	cJSON *jsonreporting_trigger_2 = reporting_trigger_convertToJSON(
		reporting_trigger_2);
	printf("repeating reporting_trigger:\n%s\n",
	       cJSON_Print(jsonreporting_trigger_2));
}

int main() {
	test_reporting_trigger(1);
	test_reporting_trigger(0);

	printf("Hello world \n");
	return 0;
}

#endif // reporting_trigger_MAIN
#endif // reporting_trigger_TEST
