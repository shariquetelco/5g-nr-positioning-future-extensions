#ifndef preemption_capability_TEST
#define preemption_capability_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define preemption_capability_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/preemption_capability.h"
preemption_capability_t *instantiate_preemption_capability(
	int include_optional);



preemption_capability_t *instantiate_preemption_capability(int include_optional)
{
	preemption_capability_t *preemption_capability = NULL;
	if(include_optional) {
		preemption_capability = preemption_capability_create(
			);
	} else {
		preemption_capability = preemption_capability_create(
			);
	}

	return preemption_capability;
}


#ifdef preemption_capability_MAIN

void test_preemption_capability(int include_optional) {
	preemption_capability_t *preemption_capability_1 =
		instantiate_preemption_capability(include_optional);

	cJSON *jsonpreemption_capability_1 =
		preemption_capability_convertToJSON(preemption_capability_1);
	printf("preemption_capability :\n%s\n",
	       cJSON_Print(jsonpreemption_capability_1));
	preemption_capability_t *preemption_capability_2 =
		preemption_capability_parseFromJSON(jsonpreemption_capability_1);
	cJSON *jsonpreemption_capability_2 =
		preemption_capability_convertToJSON(preemption_capability_2);
	printf("repeating preemption_capability:\n%s\n",
	       cJSON_Print(jsonpreemption_capability_2));
}

int main() {
	test_preemption_capability(1);
	test_preemption_capability(0);

	printf("Hello world \n");
	return 0;
}

#endif // preemption_capability_MAIN
#endif // preemption_capability_TEST
