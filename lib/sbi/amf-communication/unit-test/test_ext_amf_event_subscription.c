#ifndef ext_amf_event_subscription_TEST
#define ext_amf_event_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ext_amf_event_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ext_amf_event_subscription.h"
ext_amf_event_subscription_t *instantiate_ext_amf_event_subscription(
	int include_optional);

#include "test_amf_event_mode.c"
#include "test_nf_type.c"
#include "test_nf_type.c"


ext_amf_event_subscription_t *instantiate_ext_amf_event_subscription(
	int include_optional) {
	ext_amf_event_subscription_t *ext_amf_event_subscription = NULL;
	if(include_optional) {
		ext_amf_event_subscription = ext_amf_event_subscription_create(
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
			1,
			list_createList(),
			null,
			1,
			list_createList(),
			list_createList(),
			"0"
			);
	} else {
		ext_amf_event_subscription = ext_amf_event_subscription_create(
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
			1,
			list_createList(),
			null,
			1,
			list_createList(),
			list_createList(),
			"0"
			);
	}

	return ext_amf_event_subscription;
}


#ifdef ext_amf_event_subscription_MAIN

void test_ext_amf_event_subscription(int include_optional) {
	ext_amf_event_subscription_t *ext_amf_event_subscription_1 =
		instantiate_ext_amf_event_subscription(include_optional);

	cJSON *jsonext_amf_event_subscription_1 =
		ext_amf_event_subscription_convertToJSON(
			ext_amf_event_subscription_1);
	printf("ext_amf_event_subscription :\n%s\n",
	       cJSON_Print(jsonext_amf_event_subscription_1));
	ext_amf_event_subscription_t *ext_amf_event_subscription_2 =
		ext_amf_event_subscription_parseFromJSON(
			jsonext_amf_event_subscription_1);
	cJSON *jsonext_amf_event_subscription_2 =
		ext_amf_event_subscription_convertToJSON(
			ext_amf_event_subscription_2);
	printf("repeating ext_amf_event_subscription:\n%s\n",
	       cJSON_Print(jsonext_amf_event_subscription_2));
}

int main() {
	test_ext_amf_event_subscription(1);
	test_ext_amf_event_subscription(0);

	printf("Hello world \n");
	return 0;
}

#endif // ext_amf_event_subscription_MAIN
#endif // ext_amf_event_subscription_TEST
