#ifndef user_data_con_order_crit_any_of_TEST
#define user_data_con_order_crit_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_data_con_order_crit_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_data_con_order_crit_any_of.h"
user_data_con_order_crit_any_of_t *instantiate_user_data_con_order_crit_any_of(
	int include_optional);



user_data_con_order_crit_any_of_t *instantiate_user_data_con_order_crit_any_of(
	int include_optional) {
	user_data_con_order_crit_any_of_t *user_data_con_order_crit_any_of =
		NULL;
	if(include_optional) {
		user_data_con_order_crit_any_of =
			user_data_con_order_crit_any_of_create(
				);
	} else {
		user_data_con_order_crit_any_of =
			user_data_con_order_crit_any_of_create(
				);
	}

	return user_data_con_order_crit_any_of;
}


#ifdef user_data_con_order_crit_any_of_MAIN

void test_user_data_con_order_crit_any_of(int include_optional) {
	user_data_con_order_crit_any_of_t *user_data_con_order_crit_any_of_1 =
		instantiate_user_data_con_order_crit_any_of(include_optional);

	cJSON *jsonuser_data_con_order_crit_any_of_1 =
		user_data_con_order_crit_any_of_convertToJSON(
			user_data_con_order_crit_any_of_1);
	printf("user_data_con_order_crit_any_of :\n%s\n",
	       cJSON_Print(jsonuser_data_con_order_crit_any_of_1));
	user_data_con_order_crit_any_of_t *user_data_con_order_crit_any_of_2 =
		user_data_con_order_crit_any_of_parseFromJSON(
			jsonuser_data_con_order_crit_any_of_1);
	cJSON *jsonuser_data_con_order_crit_any_of_2 =
		user_data_con_order_crit_any_of_convertToJSON(
			user_data_con_order_crit_any_of_2);
	printf("repeating user_data_con_order_crit_any_of:\n%s\n",
	       cJSON_Print(jsonuser_data_con_order_crit_any_of_2));
}

int main() {
	test_user_data_con_order_crit_any_of(1);
	test_user_data_con_order_crit_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // user_data_con_order_crit_any_of_MAIN
#endif // user_data_con_order_crit_any_of_TEST
