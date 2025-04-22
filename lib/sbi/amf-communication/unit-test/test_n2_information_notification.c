#ifndef n2_information_notification_TEST
#define n2_information_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_information_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_information_notification.h"
n2_information_notification_t *instantiate_n2_information_notification(
	int include_optional);

#include "test_n2_info_container.c"
#include "test_global_ran_node_id.c"
#include "test_ipv6_addr.c"
#include "test_guami.c"


n2_information_notification_t *instantiate_n2_information_notification(
	int include_optional) {
	n2_information_notification_t *n2_information_notification = NULL;
	if(include_optional) {
		n2_information_notification =
			n2_information_notification_create(
				"0",
				// false, not to have infinite recursion
				instantiate_n2_info_container(0),
				list_createList(),
				"0",
				namf_communication_n2_information_notification__HANDOVER_COMPLETED,
				list_createList(),
				// false, not to have infinite recursion
				instantiate_global_ran_node_id(0),
				"a",
				"198.51.100.1",
				"2001:db8:85a3::8a2e:370:7334",
				// false, not to have infinite recursion
				instantiate_guami(0),
				1,
				"0"
				);
	} else {
		n2_information_notification =
			n2_information_notification_create(
				"0",
				NULL,
				list_createList(),
				"0",
				namf_communication_n2_information_notification__HANDOVER_COMPLETED,
				list_createList(),
				NULL,
				"a",
				"198.51.100.1",
				"2001:db8:85a3::8a2e:370:7334",
				NULL,
				1,
				"0"
				);
	}

	return n2_information_notification;
}


#ifdef n2_information_notification_MAIN

void test_n2_information_notification(int include_optional) {
	n2_information_notification_t *n2_information_notification_1 =
		instantiate_n2_information_notification(include_optional);

	cJSON *jsonn2_information_notification_1 =
		n2_information_notification_convertToJSON(
			n2_information_notification_1);
	printf("n2_information_notification :\n%s\n",
	       cJSON_Print(jsonn2_information_notification_1));
	n2_information_notification_t *n2_information_notification_2 =
		n2_information_notification_parseFromJSON(
			jsonn2_information_notification_1);
	cJSON *jsonn2_information_notification_2 =
		n2_information_notification_convertToJSON(
			n2_information_notification_2);
	printf("repeating n2_information_notification:\n%s\n",
	       cJSON_Print(jsonn2_information_notification_2));
}

int main() {
	test_n2_information_notification(1);
	test_n2_information_notification(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_information_notification_MAIN
#endif // n2_information_notification_TEST
