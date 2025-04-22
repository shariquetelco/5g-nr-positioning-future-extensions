#ifndef ue_n1_n2_info_subscription_created_data_TEST
#define ue_n1_n2_info_subscription_created_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_n1_n2_info_subscription_created_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_n1_n2_info_subscription_created_data.h"
ue_n1_n2_info_subscription_created_data_t *
instantiate_ue_n1_n2_info_subscription_created_data(int include_optional);



ue_n1_n2_info_subscription_created_data_t *
instantiate_ue_n1_n2_info_subscription_created_data(int include_optional) {
	ue_n1_n2_info_subscription_created_data_t *
	        ue_n1_n2_info_subscription_created_data = NULL;
	if(include_optional) {
		ue_n1_n2_info_subscription_created_data =
			ue_n1_n2_info_subscription_created_data_create(
				"0",
				"a"
				);
	} else {
		ue_n1_n2_info_subscription_created_data =
			ue_n1_n2_info_subscription_created_data_create(
				"0",
				"a"
				);
	}

	return ue_n1_n2_info_subscription_created_data;
}


#ifdef ue_n1_n2_info_subscription_created_data_MAIN

void test_ue_n1_n2_info_subscription_created_data(int include_optional) {
	ue_n1_n2_info_subscription_created_data_t *
	        ue_n1_n2_info_subscription_created_data_1 =
		instantiate_ue_n1_n2_info_subscription_created_data(
			include_optional);

	cJSON *jsonue_n1_n2_info_subscription_created_data_1 =
		ue_n1_n2_info_subscription_created_data_convertToJSON(
			ue_n1_n2_info_subscription_created_data_1);
	printf("ue_n1_n2_info_subscription_created_data :\n%s\n",
	       cJSON_Print(jsonue_n1_n2_info_subscription_created_data_1));
	ue_n1_n2_info_subscription_created_data_t *
	        ue_n1_n2_info_subscription_created_data_2 =
		ue_n1_n2_info_subscription_created_data_parseFromJSON(
			jsonue_n1_n2_info_subscription_created_data_1);
	cJSON *jsonue_n1_n2_info_subscription_created_data_2 =
		ue_n1_n2_info_subscription_created_data_convertToJSON(
			ue_n1_n2_info_subscription_created_data_2);
	printf("repeating ue_n1_n2_info_subscription_created_data:\n%s\n", cJSON_Print(
		       jsonue_n1_n2_info_subscription_created_data_2));
}

int main() {
	test_ue_n1_n2_info_subscription_created_data(1);
	test_ue_n1_n2_info_subscription_created_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_n1_n2_info_subscription_created_data_MAIN
#endif // ue_n1_n2_info_subscription_created_data_TEST
