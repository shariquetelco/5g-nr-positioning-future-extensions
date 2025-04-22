#ifndef traffic_direction_any_of_TEST
#define traffic_direction_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define traffic_direction_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/traffic_direction_any_of.h"
traffic_direction_any_of_t *instantiate_traffic_direction_any_of(
	int include_optional);



traffic_direction_any_of_t *instantiate_traffic_direction_any_of(
	int include_optional) {
	traffic_direction_any_of_t *traffic_direction_any_of = NULL;
	if(include_optional) {
		traffic_direction_any_of = traffic_direction_any_of_create(
			);
	} else {
		traffic_direction_any_of = traffic_direction_any_of_create(
			);
	}

	return traffic_direction_any_of;
}


#ifdef traffic_direction_any_of_MAIN

void test_traffic_direction_any_of(int include_optional) {
	traffic_direction_any_of_t *traffic_direction_any_of_1 =
		instantiate_traffic_direction_any_of(include_optional);

	cJSON *jsontraffic_direction_any_of_1 =
		traffic_direction_any_of_convertToJSON(
			traffic_direction_any_of_1);
	printf("traffic_direction_any_of :\n%s\n",
	       cJSON_Print(jsontraffic_direction_any_of_1));
	traffic_direction_any_of_t *traffic_direction_any_of_2 =
		traffic_direction_any_of_parseFromJSON(
			jsontraffic_direction_any_of_1);
	cJSON *jsontraffic_direction_any_of_2 =
		traffic_direction_any_of_convertToJSON(
			traffic_direction_any_of_2);
	printf("repeating traffic_direction_any_of:\n%s\n",
	       cJSON_Print(jsontraffic_direction_any_of_2));
}

int main() {
	test_traffic_direction_any_of(1);
	test_traffic_direction_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // traffic_direction_any_of_MAIN
#endif // traffic_direction_any_of_TEST
