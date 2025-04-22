#ifndef ue_comm_req_TEST
#define ue_comm_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_comm_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_comm_req.h"
ue_comm_req_t *instantiate_ue_comm_req(int include_optional);

#include "test_ue_comm_order_criterion.c"
#include "test_matching_direction.c"


ue_comm_req_t *instantiate_ue_comm_req(int include_optional) {
	ue_comm_req_t *ue_comm_req = NULL;
	if(include_optional) {
		ue_comm_req = ue_comm_req_create(
			null,
			null
			);
	} else {
		ue_comm_req = ue_comm_req_create(
			null,
			null
			);
	}

	return ue_comm_req;
}


#ifdef ue_comm_req_MAIN

void test_ue_comm_req(int include_optional) {
	ue_comm_req_t *ue_comm_req_1 =
		instantiate_ue_comm_req(include_optional);

	cJSON *jsonue_comm_req_1 = ue_comm_req_convertToJSON(ue_comm_req_1);
	printf("ue_comm_req :\n%s\n", cJSON_Print(jsonue_comm_req_1));
	ue_comm_req_t *ue_comm_req_2 = ue_comm_req_parseFromJSON(
		jsonue_comm_req_1);
	cJSON *jsonue_comm_req_2 = ue_comm_req_convertToJSON(ue_comm_req_2);
	printf("repeating ue_comm_req:\n%s\n", cJSON_Print(jsonue_comm_req_2));
}

int main() {
	test_ue_comm_req(1);
	test_ue_comm_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_comm_req_MAIN
#endif // ue_comm_req_TEST
