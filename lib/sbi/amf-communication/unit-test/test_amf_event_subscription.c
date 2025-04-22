#ifndef amf_event_subscription_TEST
#define amf_event_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_subscription.h"
amf_event_subscription_t *instantiate_amf_event_subscription(
	int include_optional);

#include "test_amf_event_mode.c"
#include "test_nf_type.c"


amf_event_subscription_t *instantiate_amf_event_subscription(
	int include_optional) {
	amf_event_subscription_t *amf_event_subscription = NULL;
	if(include_optional) {
		amf_event_subscription = amf_event_subscription_create(
			list_createList(),
			"0",
			"0",
			"0",
			"0",
			"0",
			"a",
			"a",
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			"a",
			"a",
			1,
			// false, not to have infinite recursion
			instantiate_amf_event_mode(0),
			null,
			1
			);
	} else {
		amf_event_subscription = amf_event_subscription_create(
			list_createList(),
			"0",
			"0",
			"0",
			"0",
			"0",
			"a",
			"a",
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			"a",
			"a",
			1,
			NULL,
			null,
			1
			);
	}

	return amf_event_subscription;
}


#ifdef amf_event_subscription_MAIN

void test_amf_event_subscription(int include_optional) {
	amf_event_subscription_t *amf_event_subscription_1 =
		instantiate_amf_event_subscription(include_optional);

	cJSON *jsonamf_event_subscription_1 =
		amf_event_subscription_convertToJSON(amf_event_subscription_1);
	printf("amf_event_subscription :\n%s\n",
	       cJSON_Print(jsonamf_event_subscription_1));
	amf_event_subscription_t *amf_event_subscription_2 =
		amf_event_subscription_parseFromJSON(
			jsonamf_event_subscription_1);
	cJSON *jsonamf_event_subscription_2 =
		amf_event_subscription_convertToJSON(amf_event_subscription_2);
	printf("repeating amf_event_subscription:\n%s\n",
	       cJSON_Print(jsonamf_event_subscription_2));
}

int main() {
	test_amf_event_subscription(1);
	test_amf_event_subscription(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_subscription_MAIN
#endif // amf_event_subscription_TEST
