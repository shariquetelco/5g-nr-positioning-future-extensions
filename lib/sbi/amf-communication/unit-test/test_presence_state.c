#ifndef presence_state_TEST
#define presence_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define presence_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/presence_state.h"
presence_state_t *instantiate_presence_state(int include_optional);



presence_state_t *instantiate_presence_state(int include_optional) {
	presence_state_t *presence_state = NULL;
	if(include_optional) {
		presence_state = presence_state_create(
			);
	} else {
		presence_state = presence_state_create(
			);
	}

	return presence_state;
}


#ifdef presence_state_MAIN

void test_presence_state(int include_optional) {
	presence_state_t *presence_state_1 = instantiate_presence_state(
		include_optional);

	cJSON *jsonpresence_state_1 = presence_state_convertToJSON(
		presence_state_1);
	printf("presence_state :\n%s\n", cJSON_Print(jsonpresence_state_1));
	presence_state_t *presence_state_2 = presence_state_parseFromJSON(
		jsonpresence_state_1);
	cJSON *jsonpresence_state_2 = presence_state_convertToJSON(
		presence_state_2);
	printf("repeating presence_state:\n%s\n",
	       cJSON_Print(jsonpresence_state_2));
}

int main() {
	test_presence_state(1);
	test_presence_state(0);

	printf("Hello world \n");
	return 0;
}

#endif // presence_state_MAIN
#endif // presence_state_TEST
