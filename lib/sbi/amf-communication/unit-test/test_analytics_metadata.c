#ifndef analytics_metadata_TEST
#define analytics_metadata_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_metadata_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_metadata.h"
analytics_metadata_t *instantiate_analytics_metadata(int include_optional);



analytics_metadata_t *instantiate_analytics_metadata(int include_optional) {
	analytics_metadata_t *analytics_metadata = NULL;
	if(include_optional) {
		analytics_metadata = analytics_metadata_create(
			);
	} else {
		analytics_metadata = analytics_metadata_create(
			);
	}

	return analytics_metadata;
}


#ifdef analytics_metadata_MAIN

void test_analytics_metadata(int include_optional) {
	analytics_metadata_t *analytics_metadata_1 =
		instantiate_analytics_metadata(include_optional);

	cJSON *jsonanalytics_metadata_1 = analytics_metadata_convertToJSON(
		analytics_metadata_1);
	printf("analytics_metadata :\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_1));
	analytics_metadata_t *analytics_metadata_2 =
		analytics_metadata_parseFromJSON(jsonanalytics_metadata_1);
	cJSON *jsonanalytics_metadata_2 = analytics_metadata_convertToJSON(
		analytics_metadata_2);
	printf("repeating analytics_metadata:\n%s\n",
	       cJSON_Print(jsonanalytics_metadata_2));
}

int main() {
	test_analytics_metadata(1);
	test_analytics_metadata(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_metadata_MAIN
#endif // analytics_metadata_TEST
