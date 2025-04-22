#ifndef network_perf_order_criterion_TEST
#define network_perf_order_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_perf_order_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_perf_order_criterion.h"
network_perf_order_criterion_t *instantiate_network_perf_order_criterion(
	int include_optional);



network_perf_order_criterion_t *instantiate_network_perf_order_criterion(
	int include_optional) {
	network_perf_order_criterion_t *network_perf_order_criterion = NULL;
	if(include_optional) {
		network_perf_order_criterion =
			network_perf_order_criterion_create(
				);
	} else {
		network_perf_order_criterion =
			network_perf_order_criterion_create(
				);
	}

	return network_perf_order_criterion;
}


#ifdef network_perf_order_criterion_MAIN

void test_network_perf_order_criterion(int include_optional) {
	network_perf_order_criterion_t *network_perf_order_criterion_1 =
		instantiate_network_perf_order_criterion(include_optional);

	cJSON *jsonnetwork_perf_order_criterion_1 =
		network_perf_order_criterion_convertToJSON(
			network_perf_order_criterion_1);
	printf("network_perf_order_criterion :\n%s\n",
	       cJSON_Print(jsonnetwork_perf_order_criterion_1));
	network_perf_order_criterion_t *network_perf_order_criterion_2 =
		network_perf_order_criterion_parseFromJSON(
			jsonnetwork_perf_order_criterion_1);
	cJSON *jsonnetwork_perf_order_criterion_2 =
		network_perf_order_criterion_convertToJSON(
			network_perf_order_criterion_2);
	printf("repeating network_perf_order_criterion:\n%s\n",
	       cJSON_Print(jsonnetwork_perf_order_criterion_2));
}

int main() {
	test_network_perf_order_criterion(1);
	test_network_perf_order_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // network_perf_order_criterion_MAIN
#endif // network_perf_order_criterion_TEST
