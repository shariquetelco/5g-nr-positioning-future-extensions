#ifndef ip_address_TEST
#define ip_address_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ip_address_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ip_address.h"
ip_address_t *instantiate_ip_address(int include_optional);

#include "test_ipv6_addr.c"
#include "test_ipv6_prefix.c"


ip_address_t *instantiate_ip_address(int include_optional) {
	ip_address_t *ip_address = NULL;
	if(include_optional) {
		ip_address = ip_address_create(
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			"2001:db8:abcd:12::0/64"
			);
	} else {
		ip_address = ip_address_create(
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			"2001:db8:abcd:12::0/64"
			);
	}

	return ip_address;
}


#ifdef ip_address_MAIN

void test_ip_address(int include_optional) {
	ip_address_t *ip_address_1 = instantiate_ip_address(include_optional);

	cJSON *jsonip_address_1 = ip_address_convertToJSON(ip_address_1);
	printf("ip_address :\n%s\n", cJSON_Print(jsonip_address_1));
	ip_address_t *ip_address_2 = ip_address_parseFromJSON(jsonip_address_1);
	cJSON *jsonip_address_2 = ip_address_convertToJSON(ip_address_2);
	printf("repeating ip_address:\n%s\n", cJSON_Print(jsonip_address_2));
}

int main() {
	test_ip_address(1);
	test_ip_address(0);

	printf("Hello world \n");
	return 0;
}

#endif // ip_address_MAIN
#endif // ip_address_TEST
