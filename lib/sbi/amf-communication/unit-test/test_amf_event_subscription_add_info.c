#ifndef amf_event_subscription_add_info_TEST
#define amf_event_subscription_add_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_event_subscription_add_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_event_subscription_add_info.h"
amf_event_subscription_add_info_t *instantiate_amf_event_subscription_add_info(
	int include_optional);

#include "test_nf_type.c"


amf_event_subscription_add_info_t *instantiate_amf_event_subscription_add_info(
	int include_optional) {
	amf_event_subscription_add_info_t *amf_event_subscription_add_info =
		NULL;
	if(include_optional) {
		amf_event_subscription_add_info =
			amf_event_subscription_add_info_create(
				list_createList(),
				null,
				1,
				list_createList(),
				list_createList(),
				"0"
				);
	} else {
		amf_event_subscription_add_info =
			amf_event_subscription_add_info_create(
				list_createList(),
				null,
				1,
				list_createList(),
				list_createList(),
				"0"
				);
	}

	return amf_event_subscription_add_info;
}


#ifdef amf_event_subscription_add_info_MAIN

void test_amf_event_subscription_add_info(int include_optional) {
	amf_event_subscription_add_info_t *amf_event_subscription_add_info_1 =
		instantiate_amf_event_subscription_add_info(include_optional);

	cJSON *jsonamf_event_subscription_add_info_1 =
		amf_event_subscription_add_info_convertToJSON(
			amf_event_subscription_add_info_1);
	printf("amf_event_subscription_add_info :\n%s\n",
	       cJSON_Print(jsonamf_event_subscription_add_info_1));
	amf_event_subscription_add_info_t *amf_event_subscription_add_info_2 =
		amf_event_subscription_add_info_parseFromJSON(
			jsonamf_event_subscription_add_info_1);
	cJSON *jsonamf_event_subscription_add_info_2 =
		amf_event_subscription_add_info_convertToJSON(
			amf_event_subscription_add_info_2);
	printf("repeating amf_event_subscription_add_info:\n%s\n",
	       cJSON_Print(jsonamf_event_subscription_add_info_2));
}

int main() {
	test_amf_event_subscription_add_info(1);
	test_amf_event_subscription_add_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_event_subscription_add_info_MAIN
#endif // amf_event_subscription_add_info_TEST
