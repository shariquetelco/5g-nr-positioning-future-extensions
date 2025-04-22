#ifndef analytics_accuracy_indication_TEST
#define analytics_accuracy_indication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_accuracy_indication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_accuracy_indication.h"
analytics_accuracy_indication_t *instantiate_analytics_accuracy_indication(
	int include_optional);



analytics_accuracy_indication_t *instantiate_analytics_accuracy_indication(
	int include_optional) {
	analytics_accuracy_indication_t *analytics_accuracy_indication = NULL;
	if(include_optional) {
		analytics_accuracy_indication =
			analytics_accuracy_indication_create(
				);
	} else {
		analytics_accuracy_indication =
			analytics_accuracy_indication_create(
				);
	}

	return analytics_accuracy_indication;
}


#ifdef analytics_accuracy_indication_MAIN

void test_analytics_accuracy_indication(int include_optional) {
	analytics_accuracy_indication_t *analytics_accuracy_indication_1 =
		instantiate_analytics_accuracy_indication(include_optional);

	cJSON *jsonanalytics_accuracy_indication_1 =
		analytics_accuracy_indication_convertToJSON(
			analytics_accuracy_indication_1);
	printf("analytics_accuracy_indication :\n%s\n",
	       cJSON_Print(jsonanalytics_accuracy_indication_1));
	analytics_accuracy_indication_t *analytics_accuracy_indication_2 =
		analytics_accuracy_indication_parseFromJSON(
			jsonanalytics_accuracy_indication_1);
	cJSON *jsonanalytics_accuracy_indication_2 =
		analytics_accuracy_indication_convertToJSON(
			analytics_accuracy_indication_2);
	printf("repeating analytics_accuracy_indication:\n%s\n",
	       cJSON_Print(jsonanalytics_accuracy_indication_2));
}

int main() {
	test_analytics_accuracy_indication(1);
	test_analytics_accuracy_indication(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_accuracy_indication_MAIN
#endif // analytics_accuracy_indication_TEST
