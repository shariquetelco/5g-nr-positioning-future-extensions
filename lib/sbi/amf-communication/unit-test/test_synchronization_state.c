#ifndef synchronization_state_TEST
#define synchronization_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define synchronization_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/synchronization_state.h"
synchronization_state_t *instantiate_synchronization_state(
	int include_optional);



synchronization_state_t *instantiate_synchronization_state(int include_optional)
{
	synchronization_state_t *synchronization_state = NULL;
	if(include_optional) {
		synchronization_state = synchronization_state_create(
			);
	} else {
		synchronization_state = synchronization_state_create(
			);
	}

	return synchronization_state;
}


#ifdef synchronization_state_MAIN

void test_synchronization_state(int include_optional) {
	synchronization_state_t *synchronization_state_1 =
		instantiate_synchronization_state(include_optional);

	cJSON *jsonsynchronization_state_1 =
		synchronization_state_convertToJSON(synchronization_state_1);
	printf("synchronization_state :\n%s\n",
	       cJSON_Print(jsonsynchronization_state_1));
	synchronization_state_t *synchronization_state_2 =
		synchronization_state_parseFromJSON(jsonsynchronization_state_1);
	cJSON *jsonsynchronization_state_2 =
		synchronization_state_convertToJSON(synchronization_state_2);
	printf("repeating synchronization_state:\n%s\n",
	       cJSON_Print(jsonsynchronization_state_2));
}

int main() {
	test_synchronization_state(1);
	test_synchronization_state(0);

	printf("Hello world \n");
	return 0;
}

#endif // synchronization_state_MAIN
#endif // synchronization_state_TEST
