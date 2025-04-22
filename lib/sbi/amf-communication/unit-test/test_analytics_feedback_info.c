#ifndef analytics_feedback_info_TEST
#define analytics_feedback_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define analytics_feedback_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/analytics_feedback_info.h"
analytics_feedback_info_t *instantiate_analytics_feedback_info(
	int include_optional);



analytics_feedback_info_t *instantiate_analytics_feedback_info(
	int include_optional) {
	analytics_feedback_info_t *analytics_feedback_info = NULL;
	if(include_optional) {
		analytics_feedback_info = analytics_feedback_info_create(
			list_createList(),
			list_createList(),
			1
			);
	} else {
		analytics_feedback_info = analytics_feedback_info_create(
			list_createList(),
			list_createList(),
			1
			);
	}

	return analytics_feedback_info;
}


#ifdef analytics_feedback_info_MAIN

void test_analytics_feedback_info(int include_optional) {
	analytics_feedback_info_t *analytics_feedback_info_1 =
		instantiate_analytics_feedback_info(include_optional);

	cJSON *jsonanalytics_feedback_info_1 =
		analytics_feedback_info_convertToJSON(analytics_feedback_info_1);
	printf("analytics_feedback_info :\n%s\n",
	       cJSON_Print(jsonanalytics_feedback_info_1));
	analytics_feedback_info_t *analytics_feedback_info_2 =
		analytics_feedback_info_parseFromJSON(
			jsonanalytics_feedback_info_1);
	cJSON *jsonanalytics_feedback_info_2 =
		analytics_feedback_info_convertToJSON(analytics_feedback_info_2);
	printf("repeating analytics_feedback_info:\n%s\n",
	       cJSON_Print(jsonanalytics_feedback_info_2));
}

int main() {
	test_analytics_feedback_info(1);
	test_analytics_feedback_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // analytics_feedback_info_MAIN
#endif // analytics_feedback_info_TEST
