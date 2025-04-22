#ifndef n2_info_notify_request_TEST
#define n2_info_notify_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_info_notify_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_info_notify_request.h"
n2_info_notify_request_t *instantiate_n2_info_notify_request(
	int include_optional);

#include "test_n2_information_notification.c"


n2_info_notify_request_t *instantiate_n2_info_notify_request(
	int include_optional) {
	n2_info_notify_request_t *n2_info_notify_request = NULL;
	if(include_optional) {
		n2_info_notify_request = n2_info_notify_request_create(
			// false, not to have infinite recursion
			instantiate_n2_information_notification(0),
			instantiate_binary_t("blah", 5),
			instantiate_binary_t("blah", 5)
			);
	} else {
		n2_info_notify_request = n2_info_notify_request_create(
			NULL,
			instantiate_binary_t("blah", 5),
			instantiate_binary_t("blah", 5)
			);
	}

	return n2_info_notify_request;
}


#ifdef n2_info_notify_request_MAIN

void test_n2_info_notify_request(int include_optional) {
	n2_info_notify_request_t *n2_info_notify_request_1 =
		instantiate_n2_info_notify_request(include_optional);

	cJSON *jsonn2_info_notify_request_1 =
		n2_info_notify_request_convertToJSON(n2_info_notify_request_1);
	printf("n2_info_notify_request :\n%s\n",
	       cJSON_Print(jsonn2_info_notify_request_1));
	n2_info_notify_request_t *n2_info_notify_request_2 =
		n2_info_notify_request_parseFromJSON(
			jsonn2_info_notify_request_1);
	cJSON *jsonn2_info_notify_request_2 =
		n2_info_notify_request_convertToJSON(n2_info_notify_request_2);
	printf("repeating n2_info_notify_request:\n%s\n",
	       cJSON_Print(jsonn2_info_notify_request_2));
}

int main() {
	test_n2_info_notify_request(1);
	test_n2_info_notify_request(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_info_notify_request_MAIN
#endif // n2_info_notify_request_TEST
