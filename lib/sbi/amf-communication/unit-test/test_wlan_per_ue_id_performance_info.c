#ifndef wlan_per_ue_id_performance_info_TEST
#define wlan_per_ue_id_performance_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define wlan_per_ue_id_performance_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/wlan_per_ue_id_performance_info.h"
wlan_per_ue_id_performance_info_t *instantiate_wlan_per_ue_id_performance_info(
	int include_optional);



wlan_per_ue_id_performance_info_t *instantiate_wlan_per_ue_id_performance_info(
	int include_optional) {
	wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info =
		NULL;
	if(include_optional) {
		wlan_per_ue_id_performance_info =
			wlan_per_ue_id_performance_info_create(
				"a",
				"a",
				list_createList()
				);
	} else {
		wlan_per_ue_id_performance_info =
			wlan_per_ue_id_performance_info_create(
				"a",
				"a",
				list_createList()
				);
	}

	return wlan_per_ue_id_performance_info;
}


#ifdef wlan_per_ue_id_performance_info_MAIN

void test_wlan_per_ue_id_performance_info(int include_optional) {
	wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_1 =
		instantiate_wlan_per_ue_id_performance_info(include_optional);

	cJSON *jsonwlan_per_ue_id_performance_info_1 =
		wlan_per_ue_id_performance_info_convertToJSON(
			wlan_per_ue_id_performance_info_1);
	printf("wlan_per_ue_id_performance_info :\n%s\n",
	       cJSON_Print(jsonwlan_per_ue_id_performance_info_1));
	wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_2 =
		wlan_per_ue_id_performance_info_parseFromJSON(
			jsonwlan_per_ue_id_performance_info_1);
	cJSON *jsonwlan_per_ue_id_performance_info_2 =
		wlan_per_ue_id_performance_info_convertToJSON(
			wlan_per_ue_id_performance_info_2);
	printf("repeating wlan_per_ue_id_performance_info:\n%s\n",
	       cJSON_Print(jsonwlan_per_ue_id_performance_info_2));
}

int main() {
	test_wlan_per_ue_id_performance_info(1);
	test_wlan_per_ue_id_performance_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // wlan_per_ue_id_performance_info_MAIN
#endif // wlan_per_ue_id_performance_info_TEST
