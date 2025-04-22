#ifndef analytics_subset_TEST
#define analytics_subset_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_subset_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_subset.h"
analytics_subset_t *instantiate_analytics_subset(int include_optional);



analytics_subset_t *instantiate_analytics_subset(int include_optional) {
	analytics_subset_t *analytics_subset = NULL;
	if(include_optional) {
		analytics_subset = analytics_subset_create(
			);
	} else {
		analytics_subset = analytics_subset_create(
			);
	}

	return analytics_subset;
}


#ifdef analytics_subset_MAIN

void test_analytics_subset(int include_optional) {
	analytics_subset_t *analytics_subset_1 = instantiate_analytics_subset(
		include_optional);

	cJSON *jsonanalytics_subset_1 = analytics_subset_convertToJSON(
		analytics_subset_1);
	printf("analytics_subset :\n%s\n", cJSON_Print(jsonanalytics_subset_1));
	analytics_subset_t *analytics_subset_2 = analytics_subset_parseFromJSON(
		jsonanalytics_subset_1);
	cJSON *jsonanalytics_subset_2 = analytics_subset_convertToJSON(
		analytics_subset_2);
	printf("repeating analytics_subset:\n%s\n",
	       cJSON_Print(jsonanalytics_subset_2));
}

int main() {
	test_analytics_subset(1);
	test_analytics_subset(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_subset_MAIN
#endif // analytics_subset_TEST
