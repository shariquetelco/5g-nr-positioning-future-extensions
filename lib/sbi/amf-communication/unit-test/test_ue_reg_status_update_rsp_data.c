#ifndef ue_reg_status_update_rsp_data_TEST
#define ue_reg_status_update_rsp_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_reg_status_update_rsp_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_reg_status_update_rsp_data.h"
ue_reg_status_update_rsp_data_t *instantiate_ue_reg_status_update_rsp_data(
	int include_optional);



ue_reg_status_update_rsp_data_t *instantiate_ue_reg_status_update_rsp_data(
	int include_optional) {
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data = NULL;
	if(include_optional) {
		ue_reg_status_update_rsp_data =
			ue_reg_status_update_rsp_data_create(
				1
				);
	} else {
		ue_reg_status_update_rsp_data =
			ue_reg_status_update_rsp_data_create(
				1
				);
	}

	return ue_reg_status_update_rsp_data;
}


#ifdef ue_reg_status_update_rsp_data_MAIN

void test_ue_reg_status_update_rsp_data(int include_optional) {
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_1 =
		instantiate_ue_reg_status_update_rsp_data(include_optional);

	cJSON *jsonue_reg_status_update_rsp_data_1 =
		ue_reg_status_update_rsp_data_convertToJSON(
			ue_reg_status_update_rsp_data_1);
	printf("ue_reg_status_update_rsp_data :\n%s\n",
	       cJSON_Print(jsonue_reg_status_update_rsp_data_1));
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_2 =
		ue_reg_status_update_rsp_data_parseFromJSON(
			jsonue_reg_status_update_rsp_data_1);
	cJSON *jsonue_reg_status_update_rsp_data_2 =
		ue_reg_status_update_rsp_data_convertToJSON(
			ue_reg_status_update_rsp_data_2);
	printf("repeating ue_reg_status_update_rsp_data:\n%s\n",
	       cJSON_Print(jsonue_reg_status_update_rsp_data_2));
}

int main() {
	test_ue_reg_status_update_rsp_data(1);
	test_ue_reg_status_update_rsp_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_reg_status_update_rsp_data_MAIN
#endif // ue_reg_status_update_rsp_data_TEST
