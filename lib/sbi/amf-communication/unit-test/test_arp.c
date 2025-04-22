#ifndef arp_TEST
#define arp_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define arp_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/arp.h"
arp_t *instantiate_arp(int include_optional);

#include "test_preemption_capability.c"
#include "test_preemption_vulnerability.c"


arp_t *instantiate_arp(int include_optional) {
	arp_t *arp = NULL;
	if(include_optional) {
		arp = arp_create(
			1,
			null,
			null
			);
	} else {
		arp = arp_create(
			1,
			null,
			null
			);
	}

	return arp;
}


#ifdef arp_MAIN

void test_arp(int include_optional) {
	arp_t *arp_1 = instantiate_arp(include_optional);

	cJSON *jsonarp_1 = arp_convertToJSON(arp_1);
	printf("arp :\n%s\n", cJSON_Print(jsonarp_1));
	arp_t *arp_2 = arp_parseFromJSON(jsonarp_1);
	cJSON *jsonarp_2 = arp_convertToJSON(arp_2);
	printf("repeating arp:\n%s\n", cJSON_Print(jsonarp_2));
}

int main() {
	test_arp(1);
	test_arp(0);

	printf("Hello world \n");
	return 0;
}

#endif // arp_MAIN
#endif // arp_TEST
