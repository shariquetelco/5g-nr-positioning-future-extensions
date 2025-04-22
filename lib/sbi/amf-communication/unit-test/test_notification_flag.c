#ifndef notification_flag_TEST
#define notification_flag_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define notification_flag_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/notification_flag.h"
notification_flag_t *instantiate_notification_flag(int include_optional);



notification_flag_t *instantiate_notification_flag(int include_optional) {
	notification_flag_t *notification_flag = NULL;
	if(include_optional) {
		notification_flag = notification_flag_create(
			);
	} else {
		notification_flag = notification_flag_create(
			);
	}

	return notification_flag;
}


#ifdef notification_flag_MAIN

void test_notification_flag(int include_optional) {
	notification_flag_t *notification_flag_1 =
		instantiate_notification_flag(include_optional);

	cJSON *jsonnotification_flag_1 = notification_flag_convertToJSON(
		notification_flag_1);
	printf("notification_flag :\n%s\n",
	       cJSON_Print(jsonnotification_flag_1));
	notification_flag_t *notification_flag_2 =
		notification_flag_parseFromJSON(jsonnotification_flag_1);
	cJSON *jsonnotification_flag_2 = notification_flag_convertToJSON(
		notification_flag_2);
	printf("repeating notification_flag:\n%s\n",
	       cJSON_Print(jsonnotification_flag_2));
}

int main() {
	test_notification_flag(1);
	test_notification_flag(0);

	printf("Hello world \n");
	return 0;
}

#endif // notification_flag_MAIN
#endif // notification_flag_TEST
