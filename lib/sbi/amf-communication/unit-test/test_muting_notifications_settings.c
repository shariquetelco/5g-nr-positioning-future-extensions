#ifndef muting_notifications_settings_TEST
#define muting_notifications_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define muting_notifications_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/muting_notifications_settings.h"
muting_notifications_settings_t *instantiate_muting_notifications_settings(
	int include_optional);



muting_notifications_settings_t *instantiate_muting_notifications_settings(
	int include_optional) {
	muting_notifications_settings_t *muting_notifications_settings = NULL;
	if(include_optional) {
		muting_notifications_settings =
			muting_notifications_settings_create(
				56,
				56
				);
	} else {
		muting_notifications_settings =
			muting_notifications_settings_create(
				56,
				56
				);
	}

	return muting_notifications_settings;
}


#ifdef muting_notifications_settings_MAIN

void test_muting_notifications_settings(int include_optional) {
	muting_notifications_settings_t *muting_notifications_settings_1 =
		instantiate_muting_notifications_settings(include_optional);

	cJSON *jsonmuting_notifications_settings_1 =
		muting_notifications_settings_convertToJSON(
			muting_notifications_settings_1);
	printf("muting_notifications_settings :\n%s\n",
	       cJSON_Print(jsonmuting_notifications_settings_1));
	muting_notifications_settings_t *muting_notifications_settings_2 =
		muting_notifications_settings_parseFromJSON(
			jsonmuting_notifications_settings_1);
	cJSON *jsonmuting_notifications_settings_2 =
		muting_notifications_settings_convertToJSON(
			muting_notifications_settings_2);
	printf("repeating muting_notifications_settings:\n%s\n",
	       cJSON_Print(jsonmuting_notifications_settings_2));
}

int main() {
	test_muting_notifications_settings(1);
	test_muting_notifications_settings(0);

	printf("Hello world \n");
	return 0;
}

#endif // muting_notifications_settings_MAIN
#endif // muting_notifications_settings_TEST
