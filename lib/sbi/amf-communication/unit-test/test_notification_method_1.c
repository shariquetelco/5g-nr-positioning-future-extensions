#ifndef notification_method_1_TEST
#define notification_method_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define notification_method_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/notification_method_1.h"
notification_method_1_t *instantiate_notification_method_1(
	int include_optional);



notification_method_1_t *instantiate_notification_method_1(int include_optional)
{
	notification_method_1_t *notification_method_1 = NULL;
	if(include_optional) {
		notification_method_1 = notification_method_1_create(
			);
	} else {
		notification_method_1 = notification_method_1_create(
			);
	}

	return notification_method_1;
}


#ifdef notification_method_1_MAIN

void test_notification_method_1(int include_optional) {
	notification_method_1_t *notification_method_1_1 =
		instantiate_notification_method_1(include_optional);

	cJSON *jsonnotification_method_1_1 =
		notification_method_1_convertToJSON(notification_method_1_1);
	printf("notification_method_1 :\n%s\n",
	       cJSON_Print(jsonnotification_method_1_1));
	notification_method_1_t *notification_method_1_2 =
		notification_method_1_parseFromJSON(jsonnotification_method_1_1);
	cJSON *jsonnotification_method_1_2 =
		notification_method_1_convertToJSON(notification_method_1_2);
	printf("repeating notification_method_1:\n%s\n",
	       cJSON_Print(jsonnotification_method_1_2));
}

int main() {
	test_notification_method_1(1);
	test_notification_method_1(0);

	printf("Hello world \n");
	return 0;
}

#endif // notification_method_1_MAIN
#endif // notification_method_1_TEST
