#ifndef buffered_notifications_action_TEST
#define buffered_notifications_action_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define buffered_notifications_action_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/buffered_notifications_action.h"
buffered_notifications_action_t *instantiate_buffered_notifications_action(
	int include_optional);



buffered_notifications_action_t *instantiate_buffered_notifications_action(
	int include_optional) {
	buffered_notifications_action_t *buffered_notifications_action = NULL;
	if(include_optional) {
		buffered_notifications_action =
			buffered_notifications_action_create(
				);
	} else {
		buffered_notifications_action =
			buffered_notifications_action_create(
				);
	}

	return buffered_notifications_action;
}


#ifdef buffered_notifications_action_MAIN

void test_buffered_notifications_action(int include_optional) {
	buffered_notifications_action_t *buffered_notifications_action_1 =
		instantiate_buffered_notifications_action(include_optional);

	cJSON *jsonbuffered_notifications_action_1 =
		buffered_notifications_action_convertToJSON(
			buffered_notifications_action_1);
	printf("buffered_notifications_action :\n%s\n",
	       cJSON_Print(jsonbuffered_notifications_action_1));
	buffered_notifications_action_t *buffered_notifications_action_2 =
		buffered_notifications_action_parseFromJSON(
			jsonbuffered_notifications_action_1);
	cJSON *jsonbuffered_notifications_action_2 =
		buffered_notifications_action_convertToJSON(
			buffered_notifications_action_2);
	printf("repeating buffered_notifications_action:\n%s\n",
	       cJSON_Print(jsonbuffered_notifications_action_2));
}

int main() {
	test_buffered_notifications_action(1);
	test_buffered_notifications_action(0);

	printf("Hello world \n");
	return 0;
}

#endif // buffered_notifications_action_MAIN
#endif // buffered_notifications_action_TEST
