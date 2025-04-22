#ifndef traffic_direction_TEST
#define traffic_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define traffic_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/traffic_direction.h"
traffic_direction_t *instantiate_traffic_direction(int include_optional);



traffic_direction_t *instantiate_traffic_direction(int include_optional) {
	traffic_direction_t *traffic_direction = NULL;
	if(include_optional) {
		traffic_direction = traffic_direction_create(
			);
	} else {
		traffic_direction = traffic_direction_create(
			);
	}

	return traffic_direction;
}


#ifdef traffic_direction_MAIN

void test_traffic_direction(int include_optional) {
	traffic_direction_t *traffic_direction_1 =
		instantiate_traffic_direction(include_optional);

	cJSON *jsontraffic_direction_1 = traffic_direction_convertToJSON(
		traffic_direction_1);
	printf("traffic_direction :\n%s\n",
	       cJSON_Print(jsontraffic_direction_1));
	traffic_direction_t *traffic_direction_2 =
		traffic_direction_parseFromJSON(jsontraffic_direction_1);
	cJSON *jsontraffic_direction_2 = traffic_direction_convertToJSON(
		traffic_direction_2);
	printf("repeating traffic_direction:\n%s\n",
	       cJSON_Print(jsontraffic_direction_2));
}

int main() {
	test_traffic_direction(1);
	test_traffic_direction(0);

	printf("Hello world \n");
	return 0;
}

#endif // traffic_direction_MAIN
#endif // traffic_direction_TEST
