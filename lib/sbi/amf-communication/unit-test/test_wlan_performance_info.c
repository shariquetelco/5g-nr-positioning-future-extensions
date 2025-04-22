#ifndef wlan_performance_info_TEST
#define wlan_performance_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wlan_performance_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wlan_performance_info.h"
wlan_performance_info_t *instantiate_wlan_performance_info(
	int include_optional);

#include "test_network_area_info.c"


wlan_performance_info_t *instantiate_wlan_performance_info(int include_optional)
{
	wlan_performance_info_t *wlan_performance_info = NULL;
	if(include_optional) {
		wlan_performance_info = wlan_performance_info_create(
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			list_createList(),
			list_createList()
			);
	} else {
		wlan_performance_info = wlan_performance_info_create(
			NULL,
			list_createList(),
			list_createList()
			);
	}

	return wlan_performance_info;
}


#ifdef wlan_performance_info_MAIN

void test_wlan_performance_info(int include_optional) {
	wlan_performance_info_t *wlan_performance_info_1 =
		instantiate_wlan_performance_info(include_optional);

	cJSON *jsonwlan_performance_info_1 =
		wlan_performance_info_convertToJSON(wlan_performance_info_1);
	printf("wlan_performance_info :\n%s\n",
	       cJSON_Print(jsonwlan_performance_info_1));
	wlan_performance_info_t *wlan_performance_info_2 =
		wlan_performance_info_parseFromJSON(jsonwlan_performance_info_1);
	cJSON *jsonwlan_performance_info_2 =
		wlan_performance_info_convertToJSON(wlan_performance_info_2);
	printf("repeating wlan_performance_info:\n%s\n",
	       cJSON_Print(jsonwlan_performance_info_2));
}

int main() {
	test_wlan_performance_info(1);
	test_wlan_performance_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // wlan_performance_info_MAIN
#endif // wlan_performance_info_TEST
