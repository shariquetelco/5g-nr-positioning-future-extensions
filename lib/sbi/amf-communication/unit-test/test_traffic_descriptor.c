#ifndef traffic_descriptor_TEST
#define traffic_descriptor_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define traffic_descriptor_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/traffic_descriptor.h"
traffic_descriptor_t *instantiate_traffic_descriptor(int include_optional);

#include "test_snssai.c"


traffic_descriptor_t *instantiate_traffic_descriptor(int include_optional) {
	traffic_descriptor_t *traffic_descriptor = NULL;
	if(include_optional) {
		traffic_descriptor = traffic_descriptor_create(
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList()
			);
	} else {
		traffic_descriptor = traffic_descriptor_create(
			"0",
			NULL,
			list_createList()
			);
	}

	return traffic_descriptor;
}


#ifdef traffic_descriptor_MAIN

void test_traffic_descriptor(int include_optional) {
	traffic_descriptor_t *traffic_descriptor_1 =
		instantiate_traffic_descriptor(include_optional);

	cJSON *jsontraffic_descriptor_1 = traffic_descriptor_convertToJSON(
		traffic_descriptor_1);
	printf("traffic_descriptor :\n%s\n",
	       cJSON_Print(jsontraffic_descriptor_1));
	traffic_descriptor_t *traffic_descriptor_2 =
		traffic_descriptor_parseFromJSON(jsontraffic_descriptor_1);
	cJSON *jsontraffic_descriptor_2 = traffic_descriptor_convertToJSON(
		traffic_descriptor_2);
	printf("repeating traffic_descriptor:\n%s\n",
	       cJSON_Print(jsontraffic_descriptor_2));
}

int main() {
	test_traffic_descriptor(1);
	test_traffic_descriptor(0);

	printf("Hello world \n");
	return 0;
}

#endif // traffic_descriptor_MAIN
#endif // traffic_descriptor_TEST
