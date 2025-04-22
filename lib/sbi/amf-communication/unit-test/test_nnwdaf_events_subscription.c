#ifndef nnwdaf_events_subscription_TEST
#define nnwdaf_events_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nnwdaf_events_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nnwdaf_events_subscription.h"
nnwdaf_events_subscription_t *instantiate_nnwdaf_events_subscription(
	int include_optional);

#include "test_reporting_information.c"
#include "test_prev_sub_info.c"
#include "test_consumer_nf_information.c"


nnwdaf_events_subscription_t *instantiate_nnwdaf_events_subscription(
	int include_optional) {
	nnwdaf_events_subscription_t *nnwdaf_events_subscription = NULL;
	if(include_optional) {
		nnwdaf_events_subscription = nnwdaf_events_subscription_create(
			list_createList(),
			// false, not to have infinite recursion
			instantiate_reporting_information(0),
			"0",
			"0",
			"a",
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_prev_sub_info(0),
			// false, not to have infinite recursion
			instantiate_consumer_nf_information(0)
			);
	} else {
		nnwdaf_events_subscription = nnwdaf_events_subscription_create(
			list_createList(),
			NULL,
			"0",
			"0",
			"a",
			list_createList(),
			list_createList(),
			NULL,
			NULL
			);
	}

	return nnwdaf_events_subscription;
}


#ifdef nnwdaf_events_subscription_MAIN

void test_nnwdaf_events_subscription(int include_optional) {
	nnwdaf_events_subscription_t *nnwdaf_events_subscription_1 =
		instantiate_nnwdaf_events_subscription(include_optional);

	cJSON *jsonnnwdaf_events_subscription_1 =
		nnwdaf_events_subscription_convertToJSON(
			nnwdaf_events_subscription_1);
	printf("nnwdaf_events_subscription :\n%s\n",
	       cJSON_Print(jsonnnwdaf_events_subscription_1));
	nnwdaf_events_subscription_t *nnwdaf_events_subscription_2 =
		nnwdaf_events_subscription_parseFromJSON(
			jsonnnwdaf_events_subscription_1);
	cJSON *jsonnnwdaf_events_subscription_2 =
		nnwdaf_events_subscription_convertToJSON(
			nnwdaf_events_subscription_2);
	printf("repeating nnwdaf_events_subscription:\n%s\n",
	       cJSON_Print(jsonnnwdaf_events_subscription_2));
}

int main() {
	test_nnwdaf_events_subscription(1);
	test_nnwdaf_events_subscription(0);

	printf("Hello world \n");
	return 0;
}

#endif // nnwdaf_events_subscription_MAIN
#endif // nnwdaf_events_subscription_TEST
