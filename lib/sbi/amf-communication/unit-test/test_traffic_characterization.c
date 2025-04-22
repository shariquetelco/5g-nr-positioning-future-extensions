#ifndef traffic_characterization_TEST
#define traffic_characterization_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define traffic_characterization_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/traffic_characterization.h"
traffic_characterization_t *instantiate_traffic_characterization(
	int include_optional);

#include "test_snssai.c"


traffic_characterization_t *instantiate_traffic_characterization(
	int include_optional) {
	traffic_characterization_t *traffic_characterization = NULL;
	if(include_optional) {
		traffic_characterization = traffic_characterization_create(
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0",
			list_createList(),
			0,
			1.337,
			0,
			1.337
			);
	} else {
		traffic_characterization = traffic_characterization_create(
			"0",
			NULL,
			"0",
			list_createList(),
			0,
			1.337,
			0,
			1.337
			);
	}

	return traffic_characterization;
}


#ifdef traffic_characterization_MAIN

void test_traffic_characterization(int include_optional) {
	traffic_characterization_t *traffic_characterization_1 =
		instantiate_traffic_characterization(include_optional);

	cJSON *jsontraffic_characterization_1 =
		traffic_characterization_convertToJSON(
			traffic_characterization_1);
	printf("traffic_characterization :\n%s\n",
	       cJSON_Print(jsontraffic_characterization_1));
	traffic_characterization_t *traffic_characterization_2 =
		traffic_characterization_parseFromJSON(
			jsontraffic_characterization_1);
	cJSON *jsontraffic_characterization_2 =
		traffic_characterization_convertToJSON(
			traffic_characterization_2);
	printf("repeating traffic_characterization:\n%s\n",
	       cJSON_Print(jsontraffic_characterization_2));
}

int main() {
	test_traffic_characterization(1);
	test_traffic_characterization(0);

	printf("Hello world \n");
	return 0;
}

#endif // traffic_characterization_MAIN
#endif // traffic_characterization_TEST
