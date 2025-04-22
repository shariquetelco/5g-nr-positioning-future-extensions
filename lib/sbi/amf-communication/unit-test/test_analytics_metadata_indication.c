#ifndef analytics_metadata_indication_TEST
#define analytics_metadata_indication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_metadata_indication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_metadata_indication.h"
analytics_metadata_indication_t *instantiate_analytics_metadata_indication(
	int include_optional);

#include "test_time_window.c"
#include "test_output_strategy.c"


analytics_metadata_indication_t *instantiate_analytics_metadata_indication(
	int include_optional) {
	analytics_metadata_indication_t *analytics_metadata_indication = NULL;
	if(include_optional) {
		analytics_metadata_indication =
			analytics_metadata_indication_create(
				// false, not to have infinite recursion
				instantiate_time_window(0),
				list_createList(),
				null,
				list_createList()
				);
	} else {
		analytics_metadata_indication =
			analytics_metadata_indication_create(
				NULL,
				list_createList(),
				null,
				list_createList()
				);
	}

	return analytics_metadata_indication;
}


#ifdef analytics_metadata_indication_MAIN

void test_analytics_metadata_indication(int include_optional) {
	analytics_metadata_indication_t *analytics_metadata_indication_1 =
		instantiate_analytics_metadata_indication(include_optional);

	cJSON *jsonanalytics_metadata_indication_1 =
		analytics_metadata_indication_convertToJSON(
			analytics_metadata_indication_1);
	printf("analytics_metadata_indication :\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_indication_1));
	analytics_metadata_indication_t *analytics_metadata_indication_2 =
		analytics_metadata_indication_parseFromJSON(
			jsonanalytics_metadata_indication_1);
	cJSON *jsonanalytics_metadata_indication_2 =
		analytics_metadata_indication_convertToJSON(
			analytics_metadata_indication_2);
	printf("repeating analytics_metadata_indication:\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_indication_2));
}

int main() {
	test_analytics_metadata_indication(1);
	test_analytics_metadata_indication(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_metadata_indication_MAIN
#endif // analytics_metadata_indication_TEST
