#ifndef network_perf_requirement_TEST
#define network_perf_requirement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_perf_requirement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_perf_requirement.h"
network_perf_requirement_t *instantiate_network_perf_requirement(
	int include_optional);

#include "test_network_perf_type.c"
#include "test_network_perf_order_criterion.c"
#include "test_resource_usage_requirement.c"


network_perf_requirement_t *instantiate_network_perf_requirement(
	int include_optional) {
	network_perf_requirement_t *network_perf_requirement = NULL;
	if(include_optional) {
		network_perf_requirement = network_perf_requirement_create(
			null,
			1,
			0,
			null,
			// false, not to have infinite recursion
			instantiate_resource_usage_requirement(0)
			);
	} else {
		network_perf_requirement = network_perf_requirement_create(
			null,
			1,
			0,
			null,
			NULL
			);
	}

	return network_perf_requirement;
}


#ifdef network_perf_requirement_MAIN

void test_network_perf_requirement(int include_optional) {
	network_perf_requirement_t *network_perf_requirement_1 =
		instantiate_network_perf_requirement(include_optional);

	cJSON *jsonnetwork_perf_requirement_1 =
		network_perf_requirement_convertToJSON(
			network_perf_requirement_1);
	printf("network_perf_requirement :\n%s\n",
	       cJSON_Print(jsonnetwork_perf_requirement_1));
	network_perf_requirement_t *network_perf_requirement_2 =
		network_perf_requirement_parseFromJSON(
			jsonnetwork_perf_requirement_1);
	cJSON *jsonnetwork_perf_requirement_2 =
		network_perf_requirement_convertToJSON(
			network_perf_requirement_2);
	printf("repeating network_perf_requirement:\n%s\n",
	       cJSON_Print(jsonnetwork_perf_requirement_2));
}

int main() {
	test_network_perf_requirement(1);
	test_network_perf_requirement(0);

	printf("Hello world \n");
	return 0;
}

#endif // network_perf_requirement_MAIN
#endif // network_perf_requirement_TEST
