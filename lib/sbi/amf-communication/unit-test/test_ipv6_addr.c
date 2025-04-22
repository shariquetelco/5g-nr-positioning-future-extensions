#ifndef ipv6_addr_TEST
#define ipv6_addr_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipv6_addr_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipv6_addr.h"
ipv6_addr_t *instantiate_ipv6_addr(int include_optional);



ipv6_addr_t *instantiate_ipv6_addr(int include_optional) {
	ipv6_addr_t *ipv6_addr = NULL;
	if(include_optional) {
		ipv6_addr = ipv6_addr_create(
			);
	} else {
		ipv6_addr = ipv6_addr_create(
			);
	}

	return ipv6_addr;
}


#ifdef ipv6_addr_MAIN

void test_ipv6_addr(int include_optional) {
	ipv6_addr_t *ipv6_addr_1 = instantiate_ipv6_addr(include_optional);

	cJSON *jsonipv6_addr_1 = ipv6_addr_convertToJSON(ipv6_addr_1);
	printf("ipv6_addr :\n%s\n", cJSON_Print(jsonipv6_addr_1));
	ipv6_addr_t *ipv6_addr_2 = ipv6_addr_parseFromJSON(jsonipv6_addr_1);
	cJSON *jsonipv6_addr_2 = ipv6_addr_convertToJSON(ipv6_addr_2);
	printf("repeating ipv6_addr:\n%s\n", cJSON_Print(jsonipv6_addr_2));
}

int main() {
	test_ipv6_addr(1);
	test_ipv6_addr(0);

	printf("Hello world \n");
	return 0;
}

#endif // ipv6_addr_MAIN
#endif // ipv6_addr_TEST
