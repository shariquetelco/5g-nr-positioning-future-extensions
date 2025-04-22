#ifndef ip_addr_TEST
#define ip_addr_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ip_addr_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ip_addr.h"
ip_addr_t *instantiate_ip_addr(int include_optional);

#include "test_ipv6_addr.c"
#include "test_ipv6_prefix.c"


ip_addr_t *instantiate_ip_addr(int include_optional) {
	ip_addr_t *ip_addr = NULL;
	if(include_optional) {
		ip_addr = ip_addr_create(
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			"2001:db8:abcd:12::0/64"
			);
	} else {
		ip_addr = ip_addr_create(
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			"2001:db8:abcd:12::0/64"
			);
	}

	return ip_addr;
}


#ifdef ip_addr_MAIN

void test_ip_addr(int include_optional) {
	ip_addr_t *ip_addr_1 = instantiate_ip_addr(include_optional);

	cJSON *jsonip_addr_1 = ip_addr_convertToJSON(ip_addr_1);
	printf("ip_addr :\n%s\n", cJSON_Print(jsonip_addr_1));
	ip_addr_t *ip_addr_2 = ip_addr_parseFromJSON(jsonip_addr_1);
	cJSON *jsonip_addr_2 = ip_addr_convertToJSON(ip_addr_2);
	printf("repeating ip_addr:\n%s\n", cJSON_Print(jsonip_addr_2));
}

int main() {
	test_ip_addr(1);
	test_ip_addr(0);

	printf("Hello world \n");
	return 0;
}

#endif // ip_addr_MAIN
#endif // ip_addr_TEST
