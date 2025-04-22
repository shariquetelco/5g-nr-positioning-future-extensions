#ifndef ip_eth_flow_description_TEST
#define ip_eth_flow_description_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ip_eth_flow_description_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ip_eth_flow_description.h"
ip_eth_flow_description_t *instantiate_ip_eth_flow_description(
	int include_optional);

#include "test_eth_flow_description.c"


ip_eth_flow_description_t *instantiate_ip_eth_flow_description(
	int include_optional) {
	ip_eth_flow_description_t *ip_eth_flow_description = NULL;
	if(include_optional) {
		ip_eth_flow_description = ip_eth_flow_description_create(
			"0",
			// false, not to have infinite recursion
			instantiate_eth_flow_description(0)
			);
	} else {
		ip_eth_flow_description = ip_eth_flow_description_create(
			"0",
			NULL
			);
	}

	return ip_eth_flow_description;
}


#ifdef ip_eth_flow_description_MAIN

void test_ip_eth_flow_description(int include_optional) {
	ip_eth_flow_description_t *ip_eth_flow_description_1 =
		instantiate_ip_eth_flow_description(include_optional);

	cJSON *jsonip_eth_flow_description_1 =
		ip_eth_flow_description_convertToJSON(ip_eth_flow_description_1);
	printf("ip_eth_flow_description :\n%s\n",
	       cJSON_Print(jsonip_eth_flow_description_1));
	ip_eth_flow_description_t *ip_eth_flow_description_2 =
		ip_eth_flow_description_parseFromJSON(
			jsonip_eth_flow_description_1);
	cJSON *jsonip_eth_flow_description_2 =
		ip_eth_flow_description_convertToJSON(ip_eth_flow_description_2);
	printf("repeating ip_eth_flow_description:\n%s\n",
	       cJSON_Print(jsonip_eth_flow_description_2));
}

int main() {
	test_ip_eth_flow_description(1);
	test_ip_eth_flow_description(0);

	printf("Hello world \n");
	return 0;
}

#endif // ip_eth_flow_description_MAIN
#endif // ip_eth_flow_description_TEST
