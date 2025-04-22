#ifndef amf_status_change_notification_TEST
#define amf_status_change_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define amf_status_change_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/amf_status_change_notification.h"
amf_status_change_notification_t *instantiate_amf_status_change_notification(
	int include_optional);



amf_status_change_notification_t *instantiate_amf_status_change_notification(
	int include_optional) {
	amf_status_change_notification_t *amf_status_change_notification = NULL;
	if(include_optional) {
		amf_status_change_notification =
			amf_status_change_notification_create(
				list_createList()
				);
	} else {
		amf_status_change_notification =
			amf_status_change_notification_create(
				list_createList()
				);
	}

	return amf_status_change_notification;
}


#ifdef amf_status_change_notification_MAIN

void test_amf_status_change_notification(int include_optional) {
	amf_status_change_notification_t *amf_status_change_notification_1 =
		instantiate_amf_status_change_notification(include_optional);

	cJSON *jsonamf_status_change_notification_1 =
		amf_status_change_notification_convertToJSON(
			amf_status_change_notification_1);
	printf("amf_status_change_notification :\n%s\n",
	       cJSON_Print(jsonamf_status_change_notification_1));
	amf_status_change_notification_t *amf_status_change_notification_2 =
		amf_status_change_notification_parseFromJSON(
			jsonamf_status_change_notification_1);
	cJSON *jsonamf_status_change_notification_2 =
		amf_status_change_notification_convertToJSON(
			amf_status_change_notification_2);
	printf("repeating amf_status_change_notification:\n%s\n",
	       cJSON_Print(jsonamf_status_change_notification_2));
}

int main() {
	test_amf_status_change_notification(1);
	test_amf_status_change_notification(0);

	printf("Hello world \n");
	return 0;
}

#endif // amf_status_change_notification_MAIN
#endif // amf_status_change_notification_TEST
