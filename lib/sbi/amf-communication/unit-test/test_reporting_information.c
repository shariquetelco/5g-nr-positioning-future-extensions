#ifndef reporting_information_TEST
#define reporting_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reporting_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reporting_information.h"
reporting_information_t *instantiate_reporting_information(
	int include_optional);

#include "test_notification_method_1.c"
#include "test_notification_flag.c"
#include "test_muting_exception_instructions.c"
#include "test_muting_notifications_settings.c"


reporting_information_t *instantiate_reporting_information(int include_optional)
{
	reporting_information_t *reporting_information = NULL;
	if(include_optional) {
		reporting_information = reporting_information_create(
			1,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			56,
			1,
			list_createList(),
			56,
			null,
			// false, not to have infinite recursion
			instantiate_muting_exception_instructions(0),
			// false, not to have infinite recursion
			instantiate_muting_notifications_settings(0)
			);
	} else {
		reporting_information = reporting_information_create(
			1,
			null,
			0,
			"2013-10-20T19:20:30+01:00",
			56,
			1,
			list_createList(),
			56,
			null,
			NULL,
			NULL
			);
	}

	return reporting_information;
}


#ifdef reporting_information_MAIN

void test_reporting_information(int include_optional) {
	reporting_information_t *reporting_information_1 =
		instantiate_reporting_information(include_optional);

	cJSON *jsonreporting_information_1 =
		reporting_information_convertToJSON(reporting_information_1);
	printf("reporting_information :\n%s\n",
	       cJSON_Print(jsonreporting_information_1));
	reporting_information_t *reporting_information_2 =
		reporting_information_parseFromJSON(jsonreporting_information_1);
	cJSON *jsonreporting_information_2 =
		reporting_information_convertToJSON(reporting_information_2);
	printf("repeating reporting_information:\n%s\n",
	       cJSON_Print(jsonreporting_information_2));
}

int main() {
	test_reporting_information(1);
	test_reporting_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // reporting_information_MAIN
#endif // reporting_information_TEST
