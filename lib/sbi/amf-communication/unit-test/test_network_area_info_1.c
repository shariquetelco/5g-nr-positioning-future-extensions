#ifndef network_area_info_1_TEST
#define network_area_info_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_area_info_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_area_info_1.h"
network_area_info_1_t *instantiate_network_area_info_1(int include_optional);



network_area_info_1_t *instantiate_network_area_info_1(int include_optional) {
	network_area_info_1_t *network_area_info_1 = NULL;
	if(include_optional) {
		network_area_info_1 = network_area_info_1_create(
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		network_area_info_1 = network_area_info_1_create(
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return network_area_info_1;
}


#ifdef network_area_info_1_MAIN

void test_network_area_info_1(int include_optional) {
	network_area_info_1_t *network_area_info_1_1 =
		instantiate_network_area_info_1(include_optional);

	cJSON *jsonnetwork_area_info_1_1 = network_area_info_1_convertToJSON(
		network_area_info_1_1);
	printf("network_area_info_1 :\n%s\n",
	       cJSON_Print(jsonnetwork_area_info_1_1));
	network_area_info_1_t *network_area_info_1_2 =
		network_area_info_1_parseFromJSON(jsonnetwork_area_info_1_1);
	cJSON *jsonnetwork_area_info_1_2 = network_area_info_1_convertToJSON(
		network_area_info_1_2);
	printf("repeating network_area_info_1:\n%s\n",
	       cJSON_Print(jsonnetwork_area_info_1_2));
}

int main() {
	test_network_area_info_1(1);
	test_network_area_info_1(0);

	printf("Hello world \n");
	return 0;
}

#endif // network_area_info_1_MAIN
#endif // network_area_info_1_TEST
