#ifndef buffered_notifications_action_any_of_TEST
#define buffered_notifications_action_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define buffered_notifications_action_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/buffered_notifications_action_any_of.h"
buffered_notifications_action_any_of_t *
instantiate_buffered_notifications_action_any_of(int include_optional);



buffered_notifications_action_any_of_t *
instantiate_buffered_notifications_action_any_of(int include_optional) {
	buffered_notifications_action_any_of_t *
	        buffered_notifications_action_any_of = NULL;
	if(include_optional) {
		buffered_notifications_action_any_of =
			buffered_notifications_action_any_of_create(
				);
	} else {
		buffered_notifications_action_any_of =
			buffered_notifications_action_any_of_create(
				);
	}

	return buffered_notifications_action_any_of;
}


#ifdef buffered_notifications_action_any_of_MAIN

void test_buffered_notifications_action_any_of(int include_optional) {
	buffered_notifications_action_any_of_t *
	        buffered_notifications_action_any_of_1 =
		instantiate_buffered_notifications_action_any_of(
			include_optional);

	cJSON *jsonbuffered_notifications_action_any_of_1 =
		buffered_notifications_action_any_of_convertToJSON(
			buffered_notifications_action_any_of_1);
	printf("buffered_notifications_action_any_of :\n%s\n",
	       cJSON_Print(jsonbuffered_notifications_action_any_of_1));
	buffered_notifications_action_any_of_t *
	        buffered_notifications_action_any_of_2 =
		buffered_notifications_action_any_of_parseFromJSON(
			jsonbuffered_notifications_action_any_of_1);
	cJSON *jsonbuffered_notifications_action_any_of_2 =
		buffered_notifications_action_any_of_convertToJSON(
			buffered_notifications_action_any_of_2);
	printf("repeating buffered_notifications_action_any_of:\n%s\n", cJSON_Print(
		       jsonbuffered_notifications_action_any_of_2));
}

int main() {
	test_buffered_notifications_action_any_of(1);
	test_buffered_notifications_action_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // buffered_notifications_action_any_of_MAIN
#endif // buffered_notifications_action_any_of_TEST
