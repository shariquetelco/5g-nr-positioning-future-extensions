#ifndef traffic_profile_any_of_TEST
#define traffic_profile_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define traffic_profile_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/traffic_profile_any_of.h"
traffic_profile_any_of_t *instantiate_traffic_profile_any_of(
	int include_optional);



traffic_profile_any_of_t *instantiate_traffic_profile_any_of(
	int include_optional) {
	traffic_profile_any_of_t *traffic_profile_any_of = NULL;
	if(include_optional) {
		traffic_profile_any_of = traffic_profile_any_of_create(
			);
	} else {
		traffic_profile_any_of = traffic_profile_any_of_create(
			);
	}

	return traffic_profile_any_of;
}


#ifdef traffic_profile_any_of_MAIN

void test_traffic_profile_any_of(int include_optional) {
	traffic_profile_any_of_t *traffic_profile_any_of_1 =
		instantiate_traffic_profile_any_of(include_optional);

	cJSON *jsontraffic_profile_any_of_1 =
		traffic_profile_any_of_convertToJSON(traffic_profile_any_of_1);
	printf("traffic_profile_any_of :\n%s\n",
	       cJSON_Print(jsontraffic_profile_any_of_1));
	traffic_profile_any_of_t *traffic_profile_any_of_2 =
		traffic_profile_any_of_parseFromJSON(
			jsontraffic_profile_any_of_1);
	cJSON *jsontraffic_profile_any_of_2 =
		traffic_profile_any_of_convertToJSON(traffic_profile_any_of_2);
	printf("repeating traffic_profile_any_of:\n%s\n",
	       cJSON_Print(jsontraffic_profile_any_of_2));
}

int main() {
	test_traffic_profile_any_of(1);
	test_traffic_profile_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // traffic_profile_any_of_MAIN
#endif // traffic_profile_any_of_TEST
