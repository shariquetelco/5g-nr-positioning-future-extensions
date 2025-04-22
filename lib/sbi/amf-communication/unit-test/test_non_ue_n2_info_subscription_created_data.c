#ifndef non_ue_n2_info_subscription_created_data_TEST
#define non_ue_n2_info_subscription_created_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define non_ue_n2_info_subscription_created_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/non_ue_n2_info_subscription_created_data.h"
non_ue_n2_info_subscription_created_data_t *
instantiate_non_ue_n2_info_subscription_created_data(int include_optional);



non_ue_n2_info_subscription_created_data_t *
instantiate_non_ue_n2_info_subscription_created_data(int include_optional) {
	non_ue_n2_info_subscription_created_data_t *
	        non_ue_n2_info_subscription_created_data = NULL;
	if(include_optional) {
		non_ue_n2_info_subscription_created_data =
			non_ue_n2_info_subscription_created_data_create(
				"0",
				"a",
				namf_communication_non_ue_n2_info_subscription_created_data__SM
				);
	} else {
		non_ue_n2_info_subscription_created_data =
			non_ue_n2_info_subscription_created_data_create(
				"0",
				"a",
				namf_communication_non_ue_n2_info_subscription_created_data__SM
				);
	}

	return non_ue_n2_info_subscription_created_data;
}


#ifdef non_ue_n2_info_subscription_created_data_MAIN

void test_non_ue_n2_info_subscription_created_data(int include_optional) {
	non_ue_n2_info_subscription_created_data_t *
	        non_ue_n2_info_subscription_created_data_1 =
		instantiate_non_ue_n2_info_subscription_created_data(
			include_optional);

	cJSON *jsonnon_ue_n2_info_subscription_created_data_1 =
		non_ue_n2_info_subscription_created_data_convertToJSON(
			non_ue_n2_info_subscription_created_data_1);
	printf("non_ue_n2_info_subscription_created_data :\n%s\n",
	       cJSON_Print(jsonnon_ue_n2_info_subscription_created_data_1));
	non_ue_n2_info_subscription_created_data_t *
	        non_ue_n2_info_subscription_created_data_2 =
		non_ue_n2_info_subscription_created_data_parseFromJSON(
			jsonnon_ue_n2_info_subscription_created_data_1);
	cJSON *jsonnon_ue_n2_info_subscription_created_data_2 =
		non_ue_n2_info_subscription_created_data_convertToJSON(
			non_ue_n2_info_subscription_created_data_2);
	printf("repeating non_ue_n2_info_subscription_created_data:\n%s\n", cJSON_Print(
		       jsonnon_ue_n2_info_subscription_created_data_2));
}

int main() {
	test_non_ue_n2_info_subscription_created_data(1);
	test_non_ue_n2_info_subscription_created_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // non_ue_n2_info_subscription_created_data_MAIN
#endif // non_ue_n2_info_subscription_created_data_TEST
