#ifndef presence_state_any_of_TEST
#define presence_state_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define presence_state_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/presence_state_any_of.h"
presence_state_any_of_t *instantiate_presence_state_any_of(
	int include_optional);



presence_state_any_of_t *instantiate_presence_state_any_of(int include_optional)
{
	presence_state_any_of_t *presence_state_any_of = NULL;
	if(include_optional) {
		presence_state_any_of = presence_state_any_of_create(
			);
	} else {
		presence_state_any_of = presence_state_any_of_create(
			);
	}

	return presence_state_any_of;
}


#ifdef presence_state_any_of_MAIN

void test_presence_state_any_of(int include_optional) {
	presence_state_any_of_t *presence_state_any_of_1 =
		instantiate_presence_state_any_of(include_optional);

	cJSON *jsonpresence_state_any_of_1 =
		presence_state_any_of_convertToJSON(presence_state_any_of_1);
	printf("presence_state_any_of :\n%s\n",
	       cJSON_Print(jsonpresence_state_any_of_1));
	presence_state_any_of_t *presence_state_any_of_2 =
		presence_state_any_of_parseFromJSON(jsonpresence_state_any_of_1);
	cJSON *jsonpresence_state_any_of_2 =
		presence_state_any_of_convertToJSON(presence_state_any_of_2);
	printf("repeating presence_state_any_of:\n%s\n",
	       cJSON_Print(jsonpresence_state_any_of_2));
}

int main() {
	test_presence_state_any_of(1);
	test_presence_state_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // presence_state_any_of_MAIN
#endif // presence_state_any_of_TEST
