#ifndef dn_perf_info_TEST
#define dn_perf_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dn_perf_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dn_perf_info.h"
dn_perf_info_t *instantiate_dn_perf_info(int include_optional);

#include "test_snssai.c"


dn_perf_info_t *instantiate_dn_perf_info(int include_optional) {
	dn_perf_info_t *dn_perf_info = NULL;
	if(include_optional) {
		dn_perf_info = dn_perf_info_create(
			"0",
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList(),
			0
			);
	} else {
		dn_perf_info = dn_perf_info_create(
			"0",
			"0",
			NULL,
			list_createList(),
			0
			);
	}

	return dn_perf_info;
}


#ifdef dn_perf_info_MAIN

void test_dn_perf_info(int include_optional) {
	dn_perf_info_t *dn_perf_info_1 = instantiate_dn_perf_info(
		include_optional);

	cJSON *jsondn_perf_info_1 = dn_perf_info_convertToJSON(dn_perf_info_1);
	printf("dn_perf_info :\n%s\n", cJSON_Print(jsondn_perf_info_1));
	dn_perf_info_t *dn_perf_info_2 = dn_perf_info_parseFromJSON(
		jsondn_perf_info_1);
	cJSON *jsondn_perf_info_2 = dn_perf_info_convertToJSON(dn_perf_info_2);
	printf("repeating dn_perf_info:\n%s\n",
	       cJSON_Print(jsondn_perf_info_2));
}

int main() {
	test_dn_perf_info(1);
	test_dn_perf_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // dn_perf_info_MAIN
#endif // dn_perf_info_TEST
