#ifndef network_perf_type_TEST
#define network_perf_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_perf_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_perf_type.h"
network_perf_type_t *instantiate_network_perf_type(int include_optional);



network_perf_type_t *instantiate_network_perf_type(int include_optional) {
	network_perf_type_t *network_perf_type = NULL;
	if(include_optional) {
		network_perf_type = network_perf_type_create(
			);
	} else {
		network_perf_type = network_perf_type_create(
			);
	}

	return network_perf_type;
}


#ifdef network_perf_type_MAIN

void test_network_perf_type(int include_optional) {
	network_perf_type_t *network_perf_type_1 =
		instantiate_network_perf_type(include_optional);

	cJSON *jsonnetwork_perf_type_1 = network_perf_type_convertToJSON(
		network_perf_type_1);
	printf("network_perf_type :\n%s\n",
	       cJSON_Print(jsonnetwork_perf_type_1));
	network_perf_type_t *network_perf_type_2 =
		network_perf_type_parseFromJSON(jsonnetwork_perf_type_1);
	cJSON *jsonnetwork_perf_type_2 = network_perf_type_convertToJSON(
		network_perf_type_2);
	printf("repeating network_perf_type:\n%s\n",
	       cJSON_Print(jsonnetwork_perf_type_2));
}

int main() {
	test_network_perf_type(1);
	test_network_perf_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // network_perf_type_MAIN
#endif // network_perf_type_TEST
