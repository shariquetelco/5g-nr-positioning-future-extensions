#ifndef traffic_information_TEST
#define traffic_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define traffic_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/traffic_information.h"
traffic_information_t *instantiate_traffic_information(int include_optional);



traffic_information_t *instantiate_traffic_information(int include_optional) {
	traffic_information_t *traffic_information = NULL;
	if(include_optional) {
		traffic_information = traffic_information_create(
			"a",
			"a",
			0,
			0,
			0
			);
	} else {
		traffic_information = traffic_information_create(
			"a",
			"a",
			0,
			0,
			0
			);
	}

	return traffic_information;
}


#ifdef traffic_information_MAIN

void test_traffic_information(int include_optional) {
	traffic_information_t *traffic_information_1 =
		instantiate_traffic_information(include_optional);

	cJSON *jsontraffic_information_1 = traffic_information_convertToJSON(
		traffic_information_1);
	printf("traffic_information :\n%s\n",
	       cJSON_Print(jsontraffic_information_1));
	traffic_information_t *traffic_information_2 =
		traffic_information_parseFromJSON(jsontraffic_information_1);
	cJSON *jsontraffic_information_2 = traffic_information_convertToJSON(
		traffic_information_2);
	printf("repeating traffic_information:\n%s\n",
	       cJSON_Print(jsontraffic_information_2));
}

int main() {
	test_traffic_information(1);
	test_traffic_information(0);

	printf("Hello world \n");
	return 0;
}

#endif // traffic_information_MAIN
#endif // traffic_information_TEST
