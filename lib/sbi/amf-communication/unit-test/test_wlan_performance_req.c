#ifndef wlan_performance_req_TEST
#define wlan_performance_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wlan_performance_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wlan_performance_req.h"
wlan_performance_req_t *instantiate_wlan_performance_req(int include_optional);

#include "test_wlan_ordering_criterion.c"
#include "test_matching_direction.c"


wlan_performance_req_t *instantiate_wlan_performance_req(int include_optional) {
	wlan_performance_req_t *wlan_performance_req = NULL;
	if(include_optional) {
		wlan_performance_req = wlan_performance_req_create(
			list_createList(),
			list_createList(),
			null,
			null
			);
	} else {
		wlan_performance_req = wlan_performance_req_create(
			list_createList(),
			list_createList(),
			null,
			null
			);
	}

	return wlan_performance_req;
}


#ifdef wlan_performance_req_MAIN

void test_wlan_performance_req(int include_optional) {
	wlan_performance_req_t *wlan_performance_req_1 =
		instantiate_wlan_performance_req(include_optional);

	cJSON *jsonwlan_performance_req_1 = wlan_performance_req_convertToJSON(
		wlan_performance_req_1);
	printf("wlan_performance_req :\n%s\n",
	       cJSON_Print(jsonwlan_performance_req_1));
	wlan_performance_req_t *wlan_performance_req_2 =
		wlan_performance_req_parseFromJSON(jsonwlan_performance_req_1);
	cJSON *jsonwlan_performance_req_2 = wlan_performance_req_convertToJSON(
		wlan_performance_req_2);
	printf("repeating wlan_performance_req:\n%s\n",
	       cJSON_Print(jsonwlan_performance_req_2));
}

int main() {
	test_wlan_performance_req(1);
	test_wlan_performance_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // wlan_performance_req_MAIN
#endif // wlan_performance_req_TEST
