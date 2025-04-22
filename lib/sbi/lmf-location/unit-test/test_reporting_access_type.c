#ifndef reporting_access_type_TEST
#define reporting_access_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reporting_access_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reporting_access_type.h"
reporting_access_type_t *instantiate_reporting_access_type(
	int include_optional);



reporting_access_type_t *instantiate_reporting_access_type(int include_optional)
{
	reporting_access_type_t *reporting_access_type = NULL;
	if(include_optional) {
		reporting_access_type = reporting_access_type_create(
			);
	} else {
		reporting_access_type = reporting_access_type_create(
			);
	}

	return reporting_access_type;
}


#ifdef reporting_access_type_MAIN

void test_reporting_access_type(int include_optional) {
	reporting_access_type_t *reporting_access_type_1 =
		instantiate_reporting_access_type(include_optional);

	cJSON *jsonreporting_access_type_1 =
		reporting_access_type_convertToJSON(reporting_access_type_1);
	printf("reporting_access_type :\n%s\n",
	       cJSON_Print(jsonreporting_access_type_1));
	reporting_access_type_t *reporting_access_type_2 =
		reporting_access_type_parseFromJSON(jsonreporting_access_type_1);
	cJSON *jsonreporting_access_type_2 =
		reporting_access_type_convertToJSON(reporting_access_type_2);
	printf("repeating reporting_access_type:\n%s\n",
	       cJSON_Print(jsonreporting_access_type_2));
}

int main() {
	test_reporting_access_type(1);
	test_reporting_access_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // reporting_access_type_MAIN
#endif // reporting_access_type_TEST
