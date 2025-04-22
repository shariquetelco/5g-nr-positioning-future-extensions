#ifndef network_perf_type_any_of_TEST
#define network_perf_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_perf_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_perf_type_any_of.h"
network_perf_type_any_of_t *instantiate_network_perf_type_any_of(
	int include_optional);



network_perf_type_any_of_t *instantiate_network_perf_type_any_of(
	int include_optional) {
	network_perf_type_any_of_t *network_perf_type_any_of = NULL;
	if(include_optional) {
		network_perf_type_any_of = network_perf_type_any_of_create(
			);
	} else {
		network_perf_type_any_of = network_perf_type_any_of_create(
			);
	}

	return network_perf_type_any_of;
}


#ifdef network_perf_type_any_of_MAIN

void test_network_perf_type_any_of(int include_optional) {
	network_perf_type_any_of_t *network_perf_type_any_of_1 =
		instantiate_network_perf_type_any_of(include_optional);

	cJSON *jsonnetwork_perf_type_any_of_1 =
		network_perf_type_any_of_convertToJSON(
			network_perf_type_any_of_1);
	printf("network_perf_type_any_of :\n%s\n",
	       cJSON_Print(jsonnetwork_perf_type_any_of_1));
	network_perf_type_any_of_t *network_perf_type_any_of_2 =
		network_perf_type_any_of_parseFromJSON(
			jsonnetwork_perf_type_any_of_1);
	cJSON *jsonnetwork_perf_type_any_of_2 =
		network_perf_type_any_of_convertToJSON(
			network_perf_type_any_of_2);
	printf("repeating network_perf_type_any_of:\n%s\n",
	       cJSON_Print(jsonnetwork_perf_type_any_of_2));
}

int main() {
	test_network_perf_type_any_of(1);
	test_network_perf_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // network_perf_type_any_of_MAIN
#endif // network_perf_type_any_of_TEST
