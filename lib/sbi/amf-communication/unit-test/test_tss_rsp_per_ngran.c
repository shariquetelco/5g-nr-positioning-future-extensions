#ifndef tss_rsp_per_ngran_TEST
#define tss_rsp_per_ngran_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tss_rsp_per_ngran_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tss_rsp_per_ngran.h"
tss_rsp_per_ngran_t *instantiate_tss_rsp_per_ngran(int include_optional);

#include "test_global_ran_node_id.c"
#include "test_n2_info_content.c"


tss_rsp_per_ngran_t *instantiate_tss_rsp_per_ngran(int include_optional) {
	tss_rsp_per_ngran_t *tss_rsp_per_ngran = NULL;
	if(include_optional) {
		tss_rsp_per_ngran = tss_rsp_per_ngran_create(
			// false, not to have infinite recursion
			instantiate_global_ran_node_id(
				0),
			namf_communication_tss_rsp_per_ngran__NG_RAN_NOT_REACHABLE,
			// false, not to have infinite recursion
			instantiate_n2_info_content(0)
			);
	} else {
		tss_rsp_per_ngran = tss_rsp_per_ngran_create(
			NULL,
			namf_communication_tss_rsp_per_ngran__NG_RAN_NOT_REACHABLE,
			NULL
			);
	}

	return tss_rsp_per_ngran;
}


#ifdef tss_rsp_per_ngran_MAIN

void test_tss_rsp_per_ngran(int include_optional) {
	tss_rsp_per_ngran_t *tss_rsp_per_ngran_1 =
		instantiate_tss_rsp_per_ngran(include_optional);

	cJSON *jsontss_rsp_per_ngran_1 = tss_rsp_per_ngran_convertToJSON(
		tss_rsp_per_ngran_1);
	printf("tss_rsp_per_ngran :\n%s\n",
	       cJSON_Print(jsontss_rsp_per_ngran_1));
	tss_rsp_per_ngran_t *tss_rsp_per_ngran_2 =
		tss_rsp_per_ngran_parseFromJSON(jsontss_rsp_per_ngran_1);
	cJSON *jsontss_rsp_per_ngran_2 = tss_rsp_per_ngran_convertToJSON(
		tss_rsp_per_ngran_2);
	printf("repeating tss_rsp_per_ngran:\n%s\n",
	       cJSON_Print(jsontss_rsp_per_ngran_2));
}

int main() {
	test_tss_rsp_per_ngran(1);
	test_tss_rsp_per_ngran(0);

	printf("Hello world \n");
	return 0;
}

#endif // tss_rsp_per_ngran_MAIN
#endif // tss_rsp_per_ngran_TEST
