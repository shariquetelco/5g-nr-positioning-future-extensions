#ifndef ue_context_transfer_req_data_TEST
#define ue_context_transfer_req_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_context_transfer_req_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_context_transfer_req_data.h"
ue_context_transfer_req_data_t *instantiate_ue_context_transfer_req_data(
	int include_optional);

#include "test_plmn_id_nid.c"
#include "test_n1_message_container.c"


ue_context_transfer_req_data_t *instantiate_ue_context_transfer_req_data(
	int include_optional) {
	ue_context_transfer_req_data_t *ue_context_transfer_req_data = NULL;
	if(include_optional) {
		ue_context_transfer_req_data =
			ue_context_transfer_req_data_create(
				namf_communication_ue_context_transfer_req_data__INIT_REG,
				namf_communication_ue_context_transfer_req_data__3GPP_ACCESS,
				// false, not to have infinite recursion
				instantiate_plmn_id_nid(0),
				// false, not to have infinite recursion
				instantiate_n1_message_container(0),
				"a"
				);
	} else {
		ue_context_transfer_req_data =
			ue_context_transfer_req_data_create(
				namf_communication_ue_context_transfer_req_data__INIT_REG,
				namf_communication_ue_context_transfer_req_data__3GPP_ACCESS,
				NULL,
				NULL,
				"a"
				);
	}

	return ue_context_transfer_req_data;
}


#ifdef ue_context_transfer_req_data_MAIN

void test_ue_context_transfer_req_data(int include_optional) {
	ue_context_transfer_req_data_t *ue_context_transfer_req_data_1 =
		instantiate_ue_context_transfer_req_data(include_optional);

	cJSON *jsonue_context_transfer_req_data_1 =
		ue_context_transfer_req_data_convertToJSON(
			ue_context_transfer_req_data_1);
	printf("ue_context_transfer_req_data :\n%s\n",
	       cJSON_Print(jsonue_context_transfer_req_data_1));
	ue_context_transfer_req_data_t *ue_context_transfer_req_data_2 =
		ue_context_transfer_req_data_parseFromJSON(
			jsonue_context_transfer_req_data_1);
	cJSON *jsonue_context_transfer_req_data_2 =
		ue_context_transfer_req_data_convertToJSON(
			ue_context_transfer_req_data_2);
	printf("repeating ue_context_transfer_req_data:\n%s\n",
	       cJSON_Print(jsonue_context_transfer_req_data_2));
}

int main() {
	test_ue_context_transfer_req_data(1);
	test_ue_context_transfer_req_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_context_transfer_req_data_MAIN
#endif // ue_context_transfer_req_data_TEST
