#ifndef network_perf_info_TEST
#define network_perf_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_perf_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_perf_info.h"
network_perf_info_t *instantiate_network_perf_info(int include_optional);

#include "test_network_area_info.c"
#include "test_network_perf_type.c"
#include "test_time_window.c"
#include "test_resource_usage_requirement.c"


network_perf_info_t *instantiate_network_perf_info(int include_optional) {
	network_perf_info_t *network_perf_info = NULL;
	if(include_optional) {
		network_perf_info = network_perf_info_create(
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			null,
			// false, not to have infinite recursion
			instantiate_time_window(0),
			1,
			0,
			// false, not to have infinite recursion
			instantiate_resource_usage_requirement(0),
			0
			);
	} else {
		network_perf_info = network_perf_info_create(
			NULL,
			null,
			NULL,
			1,
			0,
			NULL,
			0
			);
	}

	return network_perf_info;
}


#ifdef network_perf_info_MAIN

void test_network_perf_info(int include_optional) {
	network_perf_info_t *network_perf_info_1 =
		instantiate_network_perf_info(include_optional);

	cJSON *jsonnetwork_perf_info_1 = network_perf_info_convertToJSON(
		network_perf_info_1);
	printf("network_perf_info :\n%s\n",
	       cJSON_Print(jsonnetwork_perf_info_1));
	network_perf_info_t *network_perf_info_2 =
		network_perf_info_parseFromJSON(jsonnetwork_perf_info_1);
	cJSON *jsonnetwork_perf_info_2 = network_perf_info_convertToJSON(
		network_perf_info_2);
	printf("repeating network_perf_info:\n%s\n",
	       cJSON_Print(jsonnetwork_perf_info_2));
}

int main() {
	test_network_perf_info(1);
	test_network_perf_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // network_perf_info_MAIN
#endif // network_perf_info_TEST
