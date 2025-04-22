#ifndef ipv6_prefix_TEST
#define ipv6_prefix_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipv6_prefix_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipv6_prefix.h"
ipv6_prefix_t *instantiate_ipv6_prefix(int include_optional);



ipv6_prefix_t *instantiate_ipv6_prefix(int include_optional) {
	ipv6_prefix_t *ipv6_prefix = NULL;
	if(include_optional) {
		ipv6_prefix = ipv6_prefix_create(
			);
	} else {
		ipv6_prefix = ipv6_prefix_create(
			);
	}

	return ipv6_prefix;
}


#ifdef ipv6_prefix_MAIN

void test_ipv6_prefix(int include_optional) {
	ipv6_prefix_t *ipv6_prefix_1 =
		instantiate_ipv6_prefix(include_optional);

	cJSON *jsonipv6_prefix_1 = ipv6_prefix_convertToJSON(ipv6_prefix_1);
	printf("ipv6_prefix :\n%s\n", cJSON_Print(jsonipv6_prefix_1));
	ipv6_prefix_t *ipv6_prefix_2 = ipv6_prefix_parseFromJSON(
		jsonipv6_prefix_1);
	cJSON *jsonipv6_prefix_2 = ipv6_prefix_convertToJSON(ipv6_prefix_2);
	printf("repeating ipv6_prefix:\n%s\n", cJSON_Print(jsonipv6_prefix_2));
}

int main() {
	test_ipv6_prefix(1);
	test_ipv6_prefix(0);

	printf("Hello world \n");
	return 0;
}

#endif // ipv6_prefix_MAIN
#endif // ipv6_prefix_TEST
