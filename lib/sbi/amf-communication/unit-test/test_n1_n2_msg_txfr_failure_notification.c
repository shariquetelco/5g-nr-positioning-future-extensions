#ifndef n1_n2_msg_txfr_failure_notification_TEST
#define n1_n2_msg_txfr_failure_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n1_n2_msg_txfr_failure_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n1_n2_msg_txfr_failure_notification.h"
n1_n2_msg_txfr_failure_notification_t *
instantiate_n1_n2_msg_txfr_failure_notification(int include_optional);



n1_n2_msg_txfr_failure_notification_t *
instantiate_n1_n2_msg_txfr_failure_notification(int include_optional) {
	n1_n2_msg_txfr_failure_notification_t *
	        n1_n2_msg_txfr_failure_notification = NULL;
	if(include_optional) {
		n1_n2_msg_txfr_failure_notification =
			n1_n2_msg_txfr_failure_notification_create(
				namf_communication_n1_n2_msg_txfr_failure_notification__ATTEMPTING_TO_REACH_UE,
				"0",
				0
				);
	} else {
		n1_n2_msg_txfr_failure_notification =
			n1_n2_msg_txfr_failure_notification_create(
				namf_communication_n1_n2_msg_txfr_failure_notification__ATTEMPTING_TO_REACH_UE,
				"0",
				0
				);
	}

	return n1_n2_msg_txfr_failure_notification;
}


#ifdef n1_n2_msg_txfr_failure_notification_MAIN

void test_n1_n2_msg_txfr_failure_notification(int include_optional) {
	n1_n2_msg_txfr_failure_notification_t *
	        n1_n2_msg_txfr_failure_notification_1 =
		instantiate_n1_n2_msg_txfr_failure_notification(include_optional);

	cJSON *jsonn1_n2_msg_txfr_failure_notification_1 =
		n1_n2_msg_txfr_failure_notification_convertToJSON(
			n1_n2_msg_txfr_failure_notification_1);
	printf("n1_n2_msg_txfr_failure_notification :\n%s\n",
	       cJSON_Print(jsonn1_n2_msg_txfr_failure_notification_1));
	n1_n2_msg_txfr_failure_notification_t *
	        n1_n2_msg_txfr_failure_notification_2 =
		n1_n2_msg_txfr_failure_notification_parseFromJSON(
			jsonn1_n2_msg_txfr_failure_notification_1);
	cJSON *jsonn1_n2_msg_txfr_failure_notification_2 =
		n1_n2_msg_txfr_failure_notification_convertToJSON(
			n1_n2_msg_txfr_failure_notification_2);
	printf("repeating n1_n2_msg_txfr_failure_notification:\n%s\n", cJSON_Print(
		       jsonn1_n2_msg_txfr_failure_notification_2));
}

int main() {
	test_n1_n2_msg_txfr_failure_notification(1);
	test_n1_n2_msg_txfr_failure_notification(0);

	printf("Hello world \n");
	return 0;
}

#endif // n1_n2_msg_txfr_failure_notification_MAIN
#endif // n1_n2_msg_txfr_failure_notification_TEST
