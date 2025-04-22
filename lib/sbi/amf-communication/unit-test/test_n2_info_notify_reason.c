#ifndef n2_info_notify_reason_TEST
#define n2_info_notify_reason_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n2_info_notify_reason_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n2_info_notify_reason.h"
n2_info_notify_reason_t *instantiate_n2_info_notify_reason(
	int include_optional);



n2_info_notify_reason_t *instantiate_n2_info_notify_reason(int include_optional)
{
	n2_info_notify_reason_t *n2_info_notify_reason = NULL;
	if(include_optional) {
		n2_info_notify_reason = n2_info_notify_reason_create(
			);
	} else {
		n2_info_notify_reason = n2_info_notify_reason_create(
			);
	}

	return n2_info_notify_reason;
}


#ifdef n2_info_notify_reason_MAIN

void test_n2_info_notify_reason(int include_optional) {
	n2_info_notify_reason_t *n2_info_notify_reason_1 =
		instantiate_n2_info_notify_reason(include_optional);

	cJSON *jsonn2_info_notify_reason_1 =
		n2_info_notify_reason_convertToJSON(n2_info_notify_reason_1);
	printf("n2_info_notify_reason :\n%s\n",
	       cJSON_Print(jsonn2_info_notify_reason_1));
	n2_info_notify_reason_t *n2_info_notify_reason_2 =
		n2_info_notify_reason_parseFromJSON(jsonn2_info_notify_reason_1);
	cJSON *jsonn2_info_notify_reason_2 =
		n2_info_notify_reason_convertToJSON(n2_info_notify_reason_2);
	printf("repeating n2_info_notify_reason:\n%s\n",
	       cJSON_Print(jsonn2_info_notify_reason_2));
}

int main() {
	test_n2_info_notify_reason(1);
	test_n2_info_notify_reason(0);

	printf("Hello world \n");
	return 0;
}

#endif // n2_info_notify_reason_MAIN
#endif // n2_info_notify_reason_TEST
