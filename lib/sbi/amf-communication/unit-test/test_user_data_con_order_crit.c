#ifndef user_data_con_order_crit_TEST
#define user_data_con_order_crit_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_data_con_order_crit_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_data_con_order_crit.h"
user_data_con_order_crit_t *instantiate_user_data_con_order_crit(
	int include_optional);



user_data_con_order_crit_t *instantiate_user_data_con_order_crit(
	int include_optional) {
	user_data_con_order_crit_t *user_data_con_order_crit = NULL;
	if(include_optional) {
		user_data_con_order_crit = user_data_con_order_crit_create(
			);
	} else {
		user_data_con_order_crit = user_data_con_order_crit_create(
			);
	}

	return user_data_con_order_crit;
}


#ifdef user_data_con_order_crit_MAIN

void test_user_data_con_order_crit(int include_optional) {
	user_data_con_order_crit_t *user_data_con_order_crit_1 =
		instantiate_user_data_con_order_crit(include_optional);

	cJSON *jsonuser_data_con_order_crit_1 =
		user_data_con_order_crit_convertToJSON(
			user_data_con_order_crit_1);
	printf("user_data_con_order_crit :\n%s\n",
	       cJSON_Print(jsonuser_data_con_order_crit_1));
	user_data_con_order_crit_t *user_data_con_order_crit_2 =
		user_data_con_order_crit_parseFromJSON(
			jsonuser_data_con_order_crit_1);
	cJSON *jsonuser_data_con_order_crit_2 =
		user_data_con_order_crit_convertToJSON(
			user_data_con_order_crit_2);
	printf("repeating user_data_con_order_crit:\n%s\n",
	       cJSON_Print(jsonuser_data_con_order_crit_2));
}

int main() {
	test_user_data_con_order_crit(1);
	test_user_data_con_order_crit(0);

	printf("Hello world \n");
	return 0;
}

#endif // user_data_con_order_crit_MAIN
#endif // user_data_con_order_crit_TEST
