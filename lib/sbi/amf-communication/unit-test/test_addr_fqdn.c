#ifndef addr_fqdn_TEST
#define addr_fqdn_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define addr_fqdn_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/addr_fqdn.h"
addr_fqdn_t *instantiate_addr_fqdn(int include_optional);

#include "test_ip_addr.c"


addr_fqdn_t *instantiate_addr_fqdn(int include_optional) {
	addr_fqdn_t *addr_fqdn = NULL;
	if(include_optional) {
		addr_fqdn = addr_fqdn_create(
			// false, not to have infinite recursion
			instantiate_ip_addr(0),
			"0"
			);
	} else {
		addr_fqdn = addr_fqdn_create(
			NULL,
			"0"
			);
	}

	return addr_fqdn;
}


#ifdef addr_fqdn_MAIN

void test_addr_fqdn(int include_optional) {
	addr_fqdn_t *addr_fqdn_1 = instantiate_addr_fqdn(include_optional);

	cJSON *jsonaddr_fqdn_1 = addr_fqdn_convertToJSON(addr_fqdn_1);
	printf("addr_fqdn :\n%s\n", cJSON_Print(jsonaddr_fqdn_1));
	addr_fqdn_t *addr_fqdn_2 = addr_fqdn_parseFromJSON(jsonaddr_fqdn_1);
	cJSON *jsonaddr_fqdn_2 = addr_fqdn_convertToJSON(addr_fqdn_2);
	printf("repeating addr_fqdn:\n%s\n", cJSON_Print(jsonaddr_fqdn_2));
}

int main() {
	test_addr_fqdn(1);
	test_addr_fqdn(0);

	printf("Hello world \n");
	return 0;
}

#endif // addr_fqdn_MAIN
#endif // addr_fqdn_TEST
