#ifndef synchronization_state_any_of_TEST
#define synchronization_state_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define synchronization_state_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/synchronization_state_any_of.h"
synchronization_state_any_of_t *instantiate_synchronization_state_any_of(
	int include_optional);



synchronization_state_any_of_t *instantiate_synchronization_state_any_of(
	int include_optional) {
	synchronization_state_any_of_t *synchronization_state_any_of = NULL;
	if(include_optional) {
		synchronization_state_any_of =
			synchronization_state_any_of_create(
				);
	} else {
		synchronization_state_any_of =
			synchronization_state_any_of_create(
				);
	}

	return synchronization_state_any_of;
}


#ifdef synchronization_state_any_of_MAIN

void test_synchronization_state_any_of(int include_optional) {
	synchronization_state_any_of_t *synchronization_state_any_of_1 =
		instantiate_synchronization_state_any_of(include_optional);

	cJSON *jsonsynchronization_state_any_of_1 =
		synchronization_state_any_of_convertToJSON(
			synchronization_state_any_of_1);
	printf("synchronization_state_any_of :\n%s\n",
	       cJSON_Print(jsonsynchronization_state_any_of_1));
	synchronization_state_any_of_t *synchronization_state_any_of_2 =
		synchronization_state_any_of_parseFromJSON(
			jsonsynchronization_state_any_of_1);
	cJSON *jsonsynchronization_state_any_of_2 =
		synchronization_state_any_of_convertToJSON(
			synchronization_state_any_of_2);
	printf("repeating synchronization_state_any_of:\n%s\n",
	       cJSON_Print(jsonsynchronization_state_any_of_2));
}

int main() {
	test_synchronization_state_any_of(1);
	test_synchronization_state_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // synchronization_state_any_of_MAIN
#endif // synchronization_state_any_of_TEST
