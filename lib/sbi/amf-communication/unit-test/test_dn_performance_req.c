#ifndef dn_performance_req_TEST
#define dn_performance_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dn_performance_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dn_performance_req.h"
dn_performance_req_t *instantiate_dn_performance_req(int include_optional);

#include "test_dn_perf_ordering_criterion.c"
#include "test_matching_direction.c"


dn_performance_req_t *instantiate_dn_performance_req(int include_optional) {
	dn_performance_req_t *dn_performance_req = NULL;
	if(include_optional) {
		dn_performance_req = dn_performance_req_create(
			null,
			null,
			list_createList()
			);
	} else {
		dn_performance_req = dn_performance_req_create(
			null,
			null,
			list_createList()
			);
	}

	return dn_performance_req;
}


#ifdef dn_performance_req_MAIN

void test_dn_performance_req(int include_optional) {
	dn_performance_req_t *dn_performance_req_1 =
		instantiate_dn_performance_req(include_optional);

	cJSON *jsondn_performance_req_1 = dn_performance_req_convertToJSON(
		dn_performance_req_1);
	printf("dn_performance_req :\n%s\n",
	       cJSON_Print(jsondn_performance_req_1));
	dn_performance_req_t *dn_performance_req_2 =
		dn_performance_req_parseFromJSON(jsondn_performance_req_1);
	cJSON *jsondn_performance_req_2 = dn_performance_req_convertToJSON(
		dn_performance_req_2);
	printf("repeating dn_performance_req:\n%s\n",
	       cJSON_Print(jsondn_performance_req_2));
}

int main() {
	test_dn_performance_req(1);
	test_dn_performance_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // dn_performance_req_MAIN
#endif // dn_performance_req_TEST
