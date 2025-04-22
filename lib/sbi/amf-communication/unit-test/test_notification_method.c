#ifndef notification_method_TEST
#define notification_method_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define notification_method_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/notification_method.h"
notification_method_t *instantiate_notification_method(int include_optional);



notification_method_t *instantiate_notification_method(int include_optional) {
	notification_method_t *notification_method = NULL;
	if(include_optional) {
		notification_method = notification_method_create(
			);
	} else {
		notification_method = notification_method_create(
			);
	}

	return notification_method;
}


#ifdef notification_method_MAIN

void test_notification_method(int include_optional) {
	notification_method_t *notification_method_1 =
		instantiate_notification_method(include_optional);

	cJSON *jsonnotification_method_1 = notification_method_convertToJSON(
		notification_method_1);
	printf("notification_method :\n%s\n",
	       cJSON_Print(jsonnotification_method_1));
	notification_method_t *notification_method_2 =
		notification_method_parseFromJSON(jsonnotification_method_1);
	cJSON *jsonnotification_method_2 = notification_method_convertToJSON(
		notification_method_2);
	printf("repeating notification_method:\n%s\n",
	       cJSON_Print(jsonnotification_method_2));
}

int main() {
	test_notification_method(1);
	test_notification_method(0);

	printf("Hello world \n");
	return 0;
}

#endif // notification_method_MAIN
#endif // notification_method_TEST
