#ifndef policy_req_trigger_TEST
#define policy_req_trigger_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define policy_req_trigger_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/policy_req_trigger.h"
policy_req_trigger_t *instantiate_policy_req_trigger(int include_optional);



policy_req_trigger_t *instantiate_policy_req_trigger(int include_optional) {
	policy_req_trigger_t *policy_req_trigger = NULL;
	if(include_optional) {
		policy_req_trigger = policy_req_trigger_create(
			);
	} else {
		policy_req_trigger = policy_req_trigger_create(
			);
	}

	return policy_req_trigger;
}


#ifdef policy_req_trigger_MAIN

void test_policy_req_trigger(int include_optional) {
	policy_req_trigger_t *policy_req_trigger_1 =
		instantiate_policy_req_trigger(include_optional);

	cJSON *jsonpolicy_req_trigger_1 = policy_req_trigger_convertToJSON(
		policy_req_trigger_1);
	printf("policy_req_trigger :\n%s\n",
	       cJSON_Print(jsonpolicy_req_trigger_1));
	policy_req_trigger_t *policy_req_trigger_2 =
		policy_req_trigger_parseFromJSON(jsonpolicy_req_trigger_1);
	cJSON *jsonpolicy_req_trigger_2 = policy_req_trigger_convertToJSON(
		policy_req_trigger_2);
	printf("repeating policy_req_trigger:\n%s\n",
	       cJSON_Print(jsonpolicy_req_trigger_2));
}

int main() {
	test_policy_req_trigger(1);
	test_policy_req_trigger(0);

	printf("Hello world \n");
	return 0;
}

#endif // policy_req_trigger_MAIN
#endif // policy_req_trigger_TEST
