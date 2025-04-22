#ifndef subscription_action_any_of_TEST
#define subscription_action_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define subscription_action_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/subscription_action_any_of.h"
subscription_action_any_of_t *instantiate_subscription_action_any_of(
	int include_optional);



subscription_action_any_of_t *instantiate_subscription_action_any_of(
	int include_optional) {
	subscription_action_any_of_t *subscription_action_any_of = NULL;
	if(include_optional) {
		subscription_action_any_of = subscription_action_any_of_create(
			);
	} else {
		subscription_action_any_of = subscription_action_any_of_create(
			);
	}

	return subscription_action_any_of;
}


#ifdef subscription_action_any_of_MAIN

void test_subscription_action_any_of(int include_optional) {
	subscription_action_any_of_t *subscription_action_any_of_1 =
		instantiate_subscription_action_any_of(include_optional);

	cJSON *jsonsubscription_action_any_of_1 =
		subscription_action_any_of_convertToJSON(
			subscription_action_any_of_1);
	printf("subscription_action_any_of :\n%s\n",
	       cJSON_Print(jsonsubscription_action_any_of_1));
	subscription_action_any_of_t *subscription_action_any_of_2 =
		subscription_action_any_of_parseFromJSON(
			jsonsubscription_action_any_of_1);
	cJSON *jsonsubscription_action_any_of_2 =
		subscription_action_any_of_convertToJSON(
			subscription_action_any_of_2);
	printf("repeating subscription_action_any_of:\n%s\n",
	       cJSON_Print(jsonsubscription_action_any_of_2));
}

int main() {
	test_subscription_action_any_of(1);
	test_subscription_action_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // subscription_action_any_of_MAIN
#endif // subscription_action_any_of_TEST
