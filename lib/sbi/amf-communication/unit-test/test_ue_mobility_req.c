#ifndef ue_mobility_req_TEST
#define ue_mobility_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_mobility_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_mobility_req.h"
ue_mobility_req_t *instantiate_ue_mobility_req(int include_optional);

#include "test_ue_mobility_order_criterion.c"
#include "test_matching_direction.c"


ue_mobility_req_t *instantiate_ue_mobility_req(int include_optional) {
	ue_mobility_req_t *ue_mobility_req = NULL;
	if(include_optional) {
		ue_mobility_req = ue_mobility_req_create(
			null,
			null,
			1,
			list_createList()
			);
	} else {
		ue_mobility_req = ue_mobility_req_create(
			null,
			null,
			1,
			list_createList()
			);
	}

	return ue_mobility_req;
}


#ifdef ue_mobility_req_MAIN

void test_ue_mobility_req(int include_optional) {
	ue_mobility_req_t *ue_mobility_req_1 = instantiate_ue_mobility_req(
		include_optional);

	cJSON *jsonue_mobility_req_1 = ue_mobility_req_convertToJSON(
		ue_mobility_req_1);
	printf("ue_mobility_req :\n%s\n", cJSON_Print(jsonue_mobility_req_1));
	ue_mobility_req_t *ue_mobility_req_2 = ue_mobility_req_parseFromJSON(
		jsonue_mobility_req_1);
	cJSON *jsonue_mobility_req_2 = ue_mobility_req_convertToJSON(
		ue_mobility_req_2);
	printf("repeating ue_mobility_req:\n%s\n",
	       cJSON_Print(jsonue_mobility_req_2));
}

int main() {
	test_ue_mobility_req(1);
	test_ue_mobility_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_mobility_req_MAIN
#endif // ue_mobility_req_TEST
