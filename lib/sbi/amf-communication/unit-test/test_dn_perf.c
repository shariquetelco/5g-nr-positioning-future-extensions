#ifndef dn_perf_TEST
#define dn_perf_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dn_perf_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dn_perf.h"
dn_perf_t *instantiate_dn_perf(int include_optional);

#include "test_addr_fqdn.c"
#include "test_upf_information.c"
#include "test_perf_data.c"
#include "test_network_area_info.c"
#include "test_time_window.c"


dn_perf_t *instantiate_dn_perf(int include_optional) {
	dn_perf_t *dn_perf = NULL;
	if(include_optional) {
		dn_perf = dn_perf_create(
			// false, not to have infinite recursion
			instantiate_addr_fqdn(0),
			// false, not to have infinite recursion
			instantiate_upf_information(0),
			"0",
			// false, not to have infinite recursion
			instantiate_perf_data(0),
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			// false, not to have infinite recursion
			instantiate_time_window(0)
			);
	} else {
		dn_perf = dn_perf_create(
			NULL,
			NULL,
			"0",
			NULL,
			NULL,
			NULL
			);
	}

	return dn_perf;
}


#ifdef dn_perf_MAIN

void test_dn_perf(int include_optional) {
	dn_perf_t *dn_perf_1 = instantiate_dn_perf(include_optional);

	cJSON *jsondn_perf_1 = dn_perf_convertToJSON(dn_perf_1);
	printf("dn_perf :\n%s\n", cJSON_Print(jsondn_perf_1));
	dn_perf_t *dn_perf_2 = dn_perf_parseFromJSON(jsondn_perf_1);
	cJSON *jsondn_perf_2 = dn_perf_convertToJSON(dn_perf_2);
	printf("repeating dn_perf:\n%s\n", cJSON_Print(jsondn_perf_2));
}

int main() {
	test_dn_perf(1);
	test_dn_perf(0);

	printf("Hello world \n");
	return 0;
}

#endif // dn_perf_MAIN
#endif // dn_perf_TEST
