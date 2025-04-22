#ifndef nwdaf_subscription_TEST
#define nwdaf_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nwdaf_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nwdaf_subscription.h"
nwdaf_subscription_t *instantiate_nwdaf_subscription(int include_optional);

#include "test_nnwdaf_events_subscription.c"


nwdaf_subscription_t *instantiate_nwdaf_subscription(int include_optional) {
	nwdaf_subscription_t *nwdaf_subscription = NULL;
	if(include_optional) {
		nwdaf_subscription = nwdaf_subscription_create(
			"0",
			// false, not to have infinite recursion
			instantiate_nnwdaf_events_subscription(0)
			);
	} else {
		nwdaf_subscription = nwdaf_subscription_create(
			"0",
			NULL
			);
	}

	return nwdaf_subscription;
}


#ifdef nwdaf_subscription_MAIN

void test_nwdaf_subscription(int include_optional) {
	nwdaf_subscription_t *nwdaf_subscription_1 =
		instantiate_nwdaf_subscription(include_optional);

	cJSON *jsonnwdaf_subscription_1 = nwdaf_subscription_convertToJSON(
		nwdaf_subscription_1);
	printf("nwdaf_subscription :\n%s\n",
	       cJSON_Print(jsonnwdaf_subscription_1));
	nwdaf_subscription_t *nwdaf_subscription_2 =
		nwdaf_subscription_parseFromJSON(jsonnwdaf_subscription_1);
	cJSON *jsonnwdaf_subscription_2 = nwdaf_subscription_convertToJSON(
		nwdaf_subscription_2);
	printf("repeating nwdaf_subscription:\n%s\n",
	       cJSON_Print(jsonnwdaf_subscription_2));
}

int main() {
	test_nwdaf_subscription(1);
	test_nwdaf_subscription(0);

	printf("Hello world \n");
	return 0;
}

#endif // nwdaf_subscription_MAIN
#endif // nwdaf_subscription_TEST
