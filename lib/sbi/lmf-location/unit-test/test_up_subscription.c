#ifndef up_subscription_TEST
#define up_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_subscription.h"
up_subscription_t *instantiate_up_subscription(int include_optional);



up_subscription_t *instantiate_up_subscription(int include_optional) {
	up_subscription_t *up_subscription = NULL;
	if(include_optional) {
		up_subscription = up_subscription_create(
			"0",
			"0",
			"a",
			"a"
			);
	} else {
		up_subscription = up_subscription_create(
			"0",
			"0",
			"a",
			"a"
			);
	}

	return up_subscription;
}


#ifdef up_subscription_MAIN

void test_up_subscription(int include_optional) {
	up_subscription_t *up_subscription_1 = instantiate_up_subscription(
		include_optional);

	cJSON *jsonup_subscription_1 = up_subscription_convertToJSON(
		up_subscription_1);
	printf("up_subscription :\n%s\n", cJSON_Print(jsonup_subscription_1));
	up_subscription_t *up_subscription_2 = up_subscription_parseFromJSON(
		jsonup_subscription_1);
	cJSON *jsonup_subscription_2 = up_subscription_convertToJSON(
		up_subscription_2);
	printf("repeating up_subscription:\n%s\n",
	       cJSON_Print(jsonup_subscription_2));
}

int main() {
	test_up_subscription(1);
	test_up_subscription(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_subscription_MAIN
#endif // up_subscription_TEST
