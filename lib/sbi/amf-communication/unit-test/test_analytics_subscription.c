#ifndef analytics_subscription_TEST
#define analytics_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_subscription.h"
analytics_subscription_t *instantiate_analytics_subscription(
	int include_optional);



analytics_subscription_t *instantiate_analytics_subscription(
	int include_optional) {
	analytics_subscription_t *analytics_subscription = NULL;
	if(include_optional) {
		analytics_subscription = analytics_subscription_create(
			"0",
			"0",
			list_createList()
			);
	} else {
		analytics_subscription = analytics_subscription_create(
			"0",
			"0",
			list_createList()
			);
	}

	return analytics_subscription;
}


#ifdef analytics_subscription_MAIN

void test_analytics_subscription(int include_optional) {
	analytics_subscription_t *analytics_subscription_1 =
		instantiate_analytics_subscription(include_optional);

	cJSON *jsonanalytics_subscription_1 =
		analytics_subscription_convertToJSON(analytics_subscription_1);
	printf("analytics_subscription :\n%s\n",
	       cJSON_Print(jsonanalytics_subscription_1));
	analytics_subscription_t *analytics_subscription_2 =
		analytics_subscription_parseFromJSON(
			jsonanalytics_subscription_1);
	cJSON *jsonanalytics_subscription_2 =
		analytics_subscription_convertToJSON(analytics_subscription_2);
	printf("repeating analytics_subscription:\n%s\n",
	       cJSON_Print(jsonanalytics_subscription_2));
}

int main() {
	test_analytics_subscription(1);
	test_analytics_subscription(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_subscription_MAIN
#endif // analytics_subscription_TEST
