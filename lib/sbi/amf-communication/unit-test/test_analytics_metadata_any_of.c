#ifndef analytics_metadata_any_of_TEST
#define analytics_metadata_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_metadata_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_metadata_any_of.h"
analytics_metadata_any_of_t *instantiate_analytics_metadata_any_of(
	int include_optional);



analytics_metadata_any_of_t *instantiate_analytics_metadata_any_of(
	int include_optional) {
	analytics_metadata_any_of_t *analytics_metadata_any_of = NULL;
	if(include_optional) {
		analytics_metadata_any_of = analytics_metadata_any_of_create(
			);
	} else {
		analytics_metadata_any_of = analytics_metadata_any_of_create(
			);
	}

	return analytics_metadata_any_of;
}


#ifdef analytics_metadata_any_of_MAIN

void test_analytics_metadata_any_of(int include_optional) {
	analytics_metadata_any_of_t *analytics_metadata_any_of_1 =
		instantiate_analytics_metadata_any_of(include_optional);

	cJSON *jsonanalytics_metadata_any_of_1 =
		analytics_metadata_any_of_convertToJSON(
			analytics_metadata_any_of_1);
	printf("analytics_metadata_any_of :\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_any_of_1));
	analytics_metadata_any_of_t *analytics_metadata_any_of_2 =
		analytics_metadata_any_of_parseFromJSON(
			jsonanalytics_metadata_any_of_1);
	cJSON *jsonanalytics_metadata_any_of_2 =
		analytics_metadata_any_of_convertToJSON(
			analytics_metadata_any_of_2);
	printf("repeating analytics_metadata_any_of:\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_any_of_2));
}

int main() {
	test_analytics_metadata_any_of(1);
	test_analytics_metadata_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_metadata_any_of_MAIN
#endif // analytics_metadata_any_of_TEST
