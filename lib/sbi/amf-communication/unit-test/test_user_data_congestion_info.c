#ifndef user_data_congestion_info_TEST
#define user_data_congestion_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_data_congestion_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_data_congestion_info.h"
user_data_congestion_info_t *instantiate_user_data_congestion_info(
	int include_optional);

#include "test_network_area_info.c"
#include "test_congestion_info.c"
#include "test_snssai.c"


user_data_congestion_info_t *instantiate_user_data_congestion_info(
	int include_optional) {
	user_data_congestion_info_t *user_data_congestion_info = NULL;
	if(include_optional) {
		user_data_congestion_info = user_data_congestion_info_create(
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			// false, not to have infinite recursion
			instantiate_congestion_info(0),
			// false, not to have infinite recursion
			instantiate_snssai(0)
			);
	} else {
		user_data_congestion_info = user_data_congestion_info_create(
			NULL,
			NULL,
			NULL
			);
	}

	return user_data_congestion_info;
}


#ifdef user_data_congestion_info_MAIN

void test_user_data_congestion_info(int include_optional) {
	user_data_congestion_info_t *user_data_congestion_info_1 =
		instantiate_user_data_congestion_info(include_optional);

	cJSON *jsonuser_data_congestion_info_1 =
		user_data_congestion_info_convertToJSON(
			user_data_congestion_info_1);
	printf("user_data_congestion_info :\n%s\n",
	       cJSON_Print(jsonuser_data_congestion_info_1));
	user_data_congestion_info_t *user_data_congestion_info_2 =
		user_data_congestion_info_parseFromJSON(
			jsonuser_data_congestion_info_1);
	cJSON *jsonuser_data_congestion_info_2 =
		user_data_congestion_info_convertToJSON(
			user_data_congestion_info_2);
	printf("repeating user_data_congestion_info:\n%s\n",
	       cJSON_Print(jsonuser_data_congestion_info_2));
}

int main() {
	test_user_data_congestion_info(1);
	test_user_data_congestion_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // user_data_congestion_info_MAIN
#endif // user_data_congestion_info_TEST
