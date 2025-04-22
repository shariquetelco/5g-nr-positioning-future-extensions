#ifndef subscription_action_TEST
#define subscription_action_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define subscription_action_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/subscription_action.h"
subscription_action_t *instantiate_subscription_action(int include_optional);



subscription_action_t *instantiate_subscription_action(int include_optional) {
	subscription_action_t *subscription_action = NULL;
	if(include_optional) {
		subscription_action = subscription_action_create(
			);
	} else {
		subscription_action = subscription_action_create(
			);
	}

	return subscription_action;
}


#ifdef subscription_action_MAIN

void test_subscription_action(int include_optional) {
	subscription_action_t *subscription_action_1 =
		instantiate_subscription_action(include_optional);

	cJSON *jsonsubscription_action_1 = subscription_action_convertToJSON(
		subscription_action_1);
	printf("subscription_action :\n%s\n",
	       cJSON_Print(jsonsubscription_action_1));
	subscription_action_t *subscription_action_2 =
		subscription_action_parseFromJSON(jsonsubscription_action_1);
	cJSON *jsonsubscription_action_2 = subscription_action_convertToJSON(
		subscription_action_2);
	printf("repeating subscription_action:\n%s\n",
	       cJSON_Print(jsonsubscription_action_2));
}

int main() {
	test_subscription_action(1);
	test_subscription_action(0);

	printf("Hello world \n");
	return 0;
}

#endif // subscription_action_MAIN
#endif // subscription_action_TEST
