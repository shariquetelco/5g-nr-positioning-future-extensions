#ifndef ddd_traffic_descriptor_TEST
#define ddd_traffic_descriptor_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ddd_traffic_descriptor_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ddd_traffic_descriptor.h"
ddd_traffic_descriptor_t *instantiate_ddd_traffic_descriptor(
	int include_optional);

#include "test_ipv6_addr.c"


ddd_traffic_descriptor_t *instantiate_ddd_traffic_descriptor(
	int include_optional) {
	ddd_traffic_descriptor_t *ddd_traffic_descriptor = NULL;
	if(include_optional) {
		ddd_traffic_descriptor = ddd_traffic_descriptor_create(
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			0,
			"a"
			);
	} else {
		ddd_traffic_descriptor = ddd_traffic_descriptor_create(
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			0,
			"a"
			);
	}

	return ddd_traffic_descriptor;
}


#ifdef ddd_traffic_descriptor_MAIN

void test_ddd_traffic_descriptor(int include_optional) {
	ddd_traffic_descriptor_t *ddd_traffic_descriptor_1 =
		instantiate_ddd_traffic_descriptor(include_optional);

	cJSON *jsonddd_traffic_descriptor_1 =
		ddd_traffic_descriptor_convertToJSON(ddd_traffic_descriptor_1);
	printf("ddd_traffic_descriptor :\n%s\n",
	       cJSON_Print(jsonddd_traffic_descriptor_1));
	ddd_traffic_descriptor_t *ddd_traffic_descriptor_2 =
		ddd_traffic_descriptor_parseFromJSON(
			jsonddd_traffic_descriptor_1);
	cJSON *jsonddd_traffic_descriptor_2 =
		ddd_traffic_descriptor_convertToJSON(ddd_traffic_descriptor_2);
	printf("repeating ddd_traffic_descriptor:\n%s\n",
	       cJSON_Print(jsonddd_traffic_descriptor_2));
}

int main() {
	test_ddd_traffic_descriptor(1);
	test_ddd_traffic_descriptor(0);

	printf("Hello world \n");
	return 0;
}

#endif // ddd_traffic_descriptor_MAIN
#endif // ddd_traffic_descriptor_TEST
