#ifndef updp_subscription_data_TEST
#define updp_subscription_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define updp_subscription_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/updp_subscription_data.h"
updp_subscription_data_t *instantiate_updp_subscription_data(
	int include_optional);



updp_subscription_data_t *instantiate_updp_subscription_data(
	int include_optional) {
	updp_subscription_data_t *updp_subscription_data = NULL;
	if(include_optional) {
		updp_subscription_data = updp_subscription_data_create(
			"0",
			"0",
			"a",
			"0"
			);
	} else {
		updp_subscription_data = updp_subscription_data_create(
			"0",
			"0",
			"a",
			"0"
			);
	}

	return updp_subscription_data;
}


#ifdef updp_subscription_data_MAIN

void test_updp_subscription_data(int include_optional) {
	updp_subscription_data_t *updp_subscription_data_1 =
		instantiate_updp_subscription_data(include_optional);

	cJSON *jsonupdp_subscription_data_1 =
		updp_subscription_data_convertToJSON(updp_subscription_data_1);
	printf("updp_subscription_data :\n%s\n",
	       cJSON_Print(jsonupdp_subscription_data_1));
	updp_subscription_data_t *updp_subscription_data_2 =
		updp_subscription_data_parseFromJSON(
			jsonupdp_subscription_data_1);
	cJSON *jsonupdp_subscription_data_2 =
		updp_subscription_data_convertToJSON(updp_subscription_data_2);
	printf("repeating updp_subscription_data:\n%s\n",
	       cJSON_Print(jsonupdp_subscription_data_2));
}

int main() {
	test_updp_subscription_data(1);
	test_updp_subscription_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // updp_subscription_data_MAIN
#endif // updp_subscription_data_TEST
