#ifndef network_area_info_TEST
#define network_area_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_area_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_area_info.h"
network_area_info_t *instantiate_network_area_info(int include_optional);



network_area_info_t *instantiate_network_area_info(int include_optional) {
	network_area_info_t *network_area_info = NULL;
	if(include_optional) {
		network_area_info = network_area_info_create(
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		network_area_info = network_area_info_create(
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return network_area_info;
}


#ifdef network_area_info_MAIN

void test_network_area_info(int include_optional) {
	network_area_info_t *network_area_info_1 =
		instantiate_network_area_info(include_optional);

	cJSON *jsonnetwork_area_info_1 = network_area_info_convertToJSON(
		network_area_info_1);
	printf("network_area_info :\n%s\n",
	       cJSON_Print(jsonnetwork_area_info_1));
	network_area_info_t *network_area_info_2 =
		network_area_info_parseFromJSON(jsonnetwork_area_info_1);
	cJSON *jsonnetwork_area_info_2 = network_area_info_convertToJSON(
		network_area_info_2);
	printf("repeating network_area_info:\n%s\n",
	       cJSON_Print(jsonnetwork_area_info_2));
}

int main() {
	test_network_area_info(1);
	test_network_area_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // network_area_info_MAIN
#endif // network_area_info_TEST
