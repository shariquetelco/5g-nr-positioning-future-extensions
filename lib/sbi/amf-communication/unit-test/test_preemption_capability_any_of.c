#ifndef preemption_capability_any_of_TEST
#define preemption_capability_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define preemption_capability_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/preemption_capability_any_of.h"
preemption_capability_any_of_t *instantiate_preemption_capability_any_of(
	int include_optional);



preemption_capability_any_of_t *instantiate_preemption_capability_any_of(
	int include_optional) {
	preemption_capability_any_of_t *preemption_capability_any_of = NULL;
	if(include_optional) {
		preemption_capability_any_of =
			preemption_capability_any_of_create(
				);
	} else {
		preemption_capability_any_of =
			preemption_capability_any_of_create(
				);
	}

	return preemption_capability_any_of;
}


#ifdef preemption_capability_any_of_MAIN

void test_preemption_capability_any_of(int include_optional) {
	preemption_capability_any_of_t *preemption_capability_any_of_1 =
		instantiate_preemption_capability_any_of(include_optional);

	cJSON *jsonpreemption_capability_any_of_1 =
		preemption_capability_any_of_convertToJSON(
			preemption_capability_any_of_1);
	printf("preemption_capability_any_of :\n%s\n",
	       cJSON_Print(jsonpreemption_capability_any_of_1));
	preemption_capability_any_of_t *preemption_capability_any_of_2 =
		preemption_capability_any_of_parseFromJSON(
			jsonpreemption_capability_any_of_1);
	cJSON *jsonpreemption_capability_any_of_2 =
		preemption_capability_any_of_convertToJSON(
			preemption_capability_any_of_2);
	printf("repeating preemption_capability_any_of:\n%s\n",
	       cJSON_Print(jsonpreemption_capability_any_of_2));
}

int main() {
	test_preemption_capability_any_of(1);
	test_preemption_capability_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // preemption_capability_any_of_MAIN
#endif // preemption_capability_any_of_TEST
