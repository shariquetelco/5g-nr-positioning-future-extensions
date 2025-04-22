#ifndef n3ga_location_TEST
#define n3ga_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define n3ga_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/n3ga_location.h"
n3ga_location_t *instantiate_n3ga_location(int include_optional);

#include "test_tai.c"
#include "test_ipv6_addr.c"
#include "test_transport_protocol.c"
#include "test_tnap_id.c"
#include "test_twap_id.c"
#include "test_hfc_node_id.c"
#include "test_line_type.c"


n3ga_location_t *instantiate_n3ga_location(int include_optional) {
	n3ga_location_t *n3ga_location = NULL;
	if(include_optional) {
		n3ga_location = n3ga_location_create(
			// false, not to have infinite recursion
			instantiate_tai(0),
			"a",
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			0,
			null,
			// false, not to have infinite recursion
			instantiate_tnap_id(0),
			// false, not to have infinite recursion
			instantiate_twap_id(0),
			// false, not to have infinite recursion
			instantiate_hfc_node_id(0),
			"YQ==",
			null,
			"0"
			);
	} else {
		n3ga_location = n3ga_location_create(
			NULL,
			"a",
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			0,
			null,
			NULL,
			NULL,
			NULL,
			"YQ==",
			null,
			"0"
			);
	}

	return n3ga_location;
}


#ifdef n3ga_location_MAIN

void test_n3ga_location(int include_optional) {
	n3ga_location_t *n3ga_location_1 = instantiate_n3ga_location(
		include_optional);

	cJSON *jsonn3ga_location_1 =
		n3ga_location_convertToJSON(n3ga_location_1);
	printf("n3ga_location :\n%s\n", cJSON_Print(jsonn3ga_location_1));
	n3ga_location_t *n3ga_location_2 = n3ga_location_parseFromJSON(
		jsonn3ga_location_1);
	cJSON *jsonn3ga_location_2 =
		n3ga_location_convertToJSON(n3ga_location_2);
	printf("repeating n3ga_location:\n%s\n", cJSON_Print(
		       jsonn3ga_location_2));
}

int main() {
	test_n3ga_location(1);
	test_n3ga_location(0);

	printf("Hello world \n");
	return 0;
}

#endif // n3ga_location_MAIN
#endif // n3ga_location_TEST
