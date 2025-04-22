#ifndef analytics_metadata_info_TEST
#define analytics_metadata_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_metadata_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_metadata_info.h"
analytics_metadata_info_t *instantiate_analytics_metadata_info(
	int include_optional);

#include "test_time_window.c"
#include "test_output_strategy.c"
#include "test_accuracy.c"


analytics_metadata_info_t *instantiate_analytics_metadata_info(
	int include_optional) {
	analytics_metadata_info_t *analytics_metadata_info = NULL;
	if(include_optional) {
		analytics_metadata_info = analytics_metadata_info_create(
			0,
			// false, not to have infinite recursion
			instantiate_time_window(0),
			list_createList(),
			null,
			null
			);
	} else {
		analytics_metadata_info = analytics_metadata_info_create(
			0,
			NULL,
			list_createList(),
			null,
			null
			);
	}

	return analytics_metadata_info;
}


#ifdef analytics_metadata_info_MAIN

void test_analytics_metadata_info(int include_optional) {
	analytics_metadata_info_t *analytics_metadata_info_1 =
		instantiate_analytics_metadata_info(include_optional);

	cJSON *jsonanalytics_metadata_info_1 =
		analytics_metadata_info_convertToJSON(analytics_metadata_info_1);
	printf("analytics_metadata_info :\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_info_1));
	analytics_metadata_info_t *analytics_metadata_info_2 =
		analytics_metadata_info_parseFromJSON(
			jsonanalytics_metadata_info_1);
	cJSON *jsonanalytics_metadata_info_2 =
		analytics_metadata_info_convertToJSON(analytics_metadata_info_2);
	printf("repeating analytics_metadata_info:\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_info_2));
}

int main() {
	test_analytics_metadata_info(1);
	test_analytics_metadata_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_metadata_info_MAIN
#endif // analytics_metadata_info_TEST
