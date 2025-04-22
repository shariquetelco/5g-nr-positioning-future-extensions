#ifndef n1_message_notification_TEST
#define n1_message_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_message_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_message_notification.h"
n1_message_notification_t *instantiate_n1_message_notification(
	int include_optional);

#include "test_n1_message_container.c"
#include "test_registration_context_container.c"
#include "test_guami.c"
#include "test_ecgi.c"
#include "test_ncgi.c"
#include "test_tai.c"
#include "test_pru_ind.c"


n1_message_notification_t *instantiate_n1_message_notification(
	int include_optional) {
	n1_message_notification_t *n1_message_notification = NULL;
	if(include_optional) {
		n1_message_notification = n1_message_notification_create(
			"0",
			// false, not to have infinite recursion
			instantiate_n1_message_container(0),
			"0",
			// false, not to have infinite recursion
			instantiate_registration_context_container(0),
			"0",
			// false, not to have infinite recursion
			instantiate_guami(0),
			1,
			// false, not to have infinite recursion
			instantiate_ecgi(0),
			// false, not to have infinite recursion
			instantiate_ncgi(0),
			// false, not to have infinite recursion
			instantiate_tai(0),
			"a",
			null
			);
	} else {
		n1_message_notification = n1_message_notification_create(
			"0",
			NULL,
			"0",
			NULL,
			"0",
			NULL,
			1,
			NULL,
			NULL,
			NULL,
			"a",
			null
			);
	}

	return n1_message_notification;
}


#ifdef n1_message_notification_MAIN

void test_n1_message_notification(int include_optional) {
	n1_message_notification_t *n1_message_notification_1 =
		instantiate_n1_message_notification(include_optional);

	cJSON *jsonn1_message_notification_1 =
		n1_message_notification_convertToJSON(n1_message_notification_1);
	printf("n1_message_notification :\n%s\n",
	       cJSON_Print(jsonn1_message_notification_1));
	n1_message_notification_t *n1_message_notification_2 =
		n1_message_notification_parseFromJSON(
			jsonn1_message_notification_1);
	cJSON *jsonn1_message_notification_2 =
		n1_message_notification_convertToJSON(n1_message_notification_2);
	printf("repeating n1_message_notification:\n%s\n",
	       cJSON_Print(jsonn1_message_notification_2));
}

int main() {
	test_n1_message_notification(1);
	test_n1_message_notification(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_message_notification_MAIN
#endif // n1_message_notification_TEST
