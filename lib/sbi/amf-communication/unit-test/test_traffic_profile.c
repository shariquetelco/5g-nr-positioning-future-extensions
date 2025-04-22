#ifndef traffic_profile_TEST
#define traffic_profile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define traffic_profile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/traffic_profile.h"
traffic_profile_t *instantiate_traffic_profile(int include_optional);



traffic_profile_t *instantiate_traffic_profile(int include_optional) {
	traffic_profile_t *traffic_profile = NULL;
	if(include_optional) {
		traffic_profile = traffic_profile_create(
			);
	} else {
		traffic_profile = traffic_profile_create(
			);
	}

	return traffic_profile;
}


#ifdef traffic_profile_MAIN

void test_traffic_profile(int include_optional) {
	traffic_profile_t *traffic_profile_1 = instantiate_traffic_profile(
		include_optional);

	cJSON *jsontraffic_profile_1 = traffic_profile_convertToJSON(
		traffic_profile_1);
	printf("traffic_profile :\n%s\n", cJSON_Print(jsontraffic_profile_1));
	traffic_profile_t *traffic_profile_2 = traffic_profile_parseFromJSON(
		jsontraffic_profile_1);
	cJSON *jsontraffic_profile_2 = traffic_profile_convertToJSON(
		traffic_profile_2);
	printf("repeating traffic_profile:\n%s\n",
	       cJSON_Print(jsontraffic_profile_2));
}

int main() {
	test_traffic_profile(1);
	test_traffic_profile(0);

	printf("Hello world \n");
	return 0;
}

#endif // traffic_profile_MAIN
#endif // traffic_profile_TEST
