#ifndef nsi_load_level_info_TEST
#define nsi_load_level_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nsi_load_level_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nsi_load_level_info.h"
nsi_load_level_info_t *instantiate_nsi_load_level_info(int include_optional);

#include "test_snssai.c"
#include "test_resource_usage.c"
#include "test_network_area_info.c"
#include "test_time_window.c"
#include "test_number_average.c"
#include "test_number_average.c"


nsi_load_level_info_t *instantiate_nsi_load_level_info(int include_optional) {
	nsi_load_level_info_t *nsi_load_level_info = NULL;
	if(include_optional) {
		nsi_load_level_info = nsi_load_level_info_create(
			56,
			// false, not to have infinite recursion
			instantiate_snssai(0),
			"0",
			// false, not to have infinite recursion
			instantiate_resource_usage(0),
			0,
			1,
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			// false, not to have infinite recursion
			instantiate_time_window(0),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_number_average(0),
			// false, not to have infinite recursion
			instantiate_number_average(0),
			0
			);
	} else {
		nsi_load_level_info = nsi_load_level_info_create(
			56,
			NULL,
			"0",
			NULL,
			0,
			1,
			NULL,
			NULL,
			list_createList(),
			NULL,
			NULL,
			0
			);
	}

	return nsi_load_level_info;
}


#ifdef nsi_load_level_info_MAIN

void test_nsi_load_level_info(int include_optional) {
	nsi_load_level_info_t *nsi_load_level_info_1 =
		instantiate_nsi_load_level_info(include_optional);

	cJSON *jsonnsi_load_level_info_1 = nsi_load_level_info_convertToJSON(
		nsi_load_level_info_1);
	printf("nsi_load_level_info :\n%s\n",
	       cJSON_Print(jsonnsi_load_level_info_1));
	nsi_load_level_info_t *nsi_load_level_info_2 =
		nsi_load_level_info_parseFromJSON(jsonnsi_load_level_info_1);
	cJSON *jsonnsi_load_level_info_2 = nsi_load_level_info_convertToJSON(
		nsi_load_level_info_2);
	printf("repeating nsi_load_level_info:\n%s\n",
	       cJSON_Print(jsonnsi_load_level_info_2));
}

int main() {
	test_nsi_load_level_info(1);
	test_nsi_load_level_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // nsi_load_level_info_MAIN
#endif // nsi_load_level_info_TEST
