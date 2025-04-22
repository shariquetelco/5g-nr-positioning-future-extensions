#ifndef ue_n1_n2_info_subscription_create_data_TEST
#define ue_n1_n2_info_subscription_create_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_n1_n2_info_subscription_create_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_n1_n2_info_subscription_create_data.h"
ue_n1_n2_info_subscription_create_data_t *
instantiate_ue_n1_n2_info_subscription_create_data(int include_optional);

#include "test_guami.c"


ue_n1_n2_info_subscription_create_data_t *
instantiate_ue_n1_n2_info_subscription_create_data(int include_optional) {
	ue_n1_n2_info_subscription_create_data_t *
	        ue_n1_n2_info_subscription_create_data = NULL;
	if(include_optional) {
		ue_n1_n2_info_subscription_create_data =
			ue_n1_n2_info_subscription_create_data_create(
				namf_communication_ue_n1_n2_info_subscription_create_data__SM,
				"0",
				namf_communication_ue_n1_n2_info_subscription_create_data__5GMM,
				"0",
				"0",
				"a",
				// false, not to have infinite recursion
				instantiate_guami(0)
				);
	} else {
		ue_n1_n2_info_subscription_create_data =
			ue_n1_n2_info_subscription_create_data_create(
				namf_communication_ue_n1_n2_info_subscription_create_data__SM,
				"0",
				namf_communication_ue_n1_n2_info_subscription_create_data__5GMM,
				"0",
				"0",
				"a",
				NULL
				);
	}

	return ue_n1_n2_info_subscription_create_data;
}


#ifdef ue_n1_n2_info_subscription_create_data_MAIN

void test_ue_n1_n2_info_subscription_create_data(int include_optional) {
	ue_n1_n2_info_subscription_create_data_t *
	        ue_n1_n2_info_subscription_create_data_1 =
		instantiate_ue_n1_n2_info_subscription_create_data(
			include_optional);

	cJSON *jsonue_n1_n2_info_subscription_create_data_1 =
		ue_n1_n2_info_subscription_create_data_convertToJSON(
			ue_n1_n2_info_subscription_create_data_1);
	printf("ue_n1_n2_info_subscription_create_data :\n%s\n",
	       cJSON_Print(jsonue_n1_n2_info_subscription_create_data_1));
	ue_n1_n2_info_subscription_create_data_t *
	        ue_n1_n2_info_subscription_create_data_2 =
		ue_n1_n2_info_subscription_create_data_parseFromJSON(
			jsonue_n1_n2_info_subscription_create_data_1);
	cJSON *jsonue_n1_n2_info_subscription_create_data_2 =
		ue_n1_n2_info_subscription_create_data_convertToJSON(
			ue_n1_n2_info_subscription_create_data_2);
	printf("repeating ue_n1_n2_info_subscription_create_data:\n%s\n", cJSON_Print(
		       jsonue_n1_n2_info_subscription_create_data_2));
}

int main() {
	test_ue_n1_n2_info_subscription_create_data(1);
	test_ue_n1_n2_info_subscription_create_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_n1_n2_info_subscription_create_data_MAIN
#endif // ue_n1_n2_info_subscription_create_data_TEST
