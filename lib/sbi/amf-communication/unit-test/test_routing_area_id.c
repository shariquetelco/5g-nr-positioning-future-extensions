#ifndef routing_area_id_TEST
#define routing_area_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define routing_area_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/routing_area_id.h"
routing_area_id_t *instantiate_routing_area_id(int include_optional);

#include "test_plmn_id.c"


routing_area_id_t *instantiate_routing_area_id(int include_optional) {
	routing_area_id_t *routing_area_id = NULL;
	if(include_optional) {
		routing_area_id = routing_area_id_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			"a"
			);
	} else {
		routing_area_id = routing_area_id_create(
			NULL,
			"a",
			"a"
			);
	}

	return routing_area_id;
}


#ifdef routing_area_id_MAIN

void test_routing_area_id(int include_optional) {
	routing_area_id_t *routing_area_id_1 = instantiate_routing_area_id(
		include_optional);

	cJSON *jsonrouting_area_id_1 = routing_area_id_convertToJSON(
		routing_area_id_1);
	printf("routing_area_id :\n%s\n", cJSON_Print(jsonrouting_area_id_1));
	routing_area_id_t *routing_area_id_2 = routing_area_id_parseFromJSON(
		jsonrouting_area_id_1);
	cJSON *jsonrouting_area_id_2 = routing_area_id_convertToJSON(
		routing_area_id_2);
	printf("repeating routing_area_id:\n%s\n",
	       cJSON_Print(jsonrouting_area_id_2));
}

int main() {
	test_routing_area_id(1);
	test_routing_area_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // routing_area_id_MAIN
#endif // routing_area_id_TEST
