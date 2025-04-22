#ifndef transport_protocol_any_of_TEST
#define transport_protocol_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transport_protocol_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transport_protocol_any_of.h"
transport_protocol_any_of_t *instantiate_transport_protocol_any_of(
	int include_optional);



transport_protocol_any_of_t *instantiate_transport_protocol_any_of(
	int include_optional) {
	transport_protocol_any_of_t *transport_protocol_any_of = NULL;
	if(include_optional) {
		transport_protocol_any_of = transport_protocol_any_of_create(
			);
	} else {
		transport_protocol_any_of = transport_protocol_any_of_create(
			);
	}

	return transport_protocol_any_of;
}


#ifdef transport_protocol_any_of_MAIN

void test_transport_protocol_any_of(int include_optional) {
	transport_protocol_any_of_t *transport_protocol_any_of_1 =
		instantiate_transport_protocol_any_of(include_optional);

	cJSON *jsontransport_protocol_any_of_1 =
		transport_protocol_any_of_convertToJSON(
			transport_protocol_any_of_1);
	printf("transport_protocol_any_of :\n%s\n",
	       cJSON_Print(jsontransport_protocol_any_of_1));
	transport_protocol_any_of_t *transport_protocol_any_of_2 =
		transport_protocol_any_of_parseFromJSON(
			jsontransport_protocol_any_of_1);
	cJSON *jsontransport_protocol_any_of_2 =
		transport_protocol_any_of_convertToJSON(
			transport_protocol_any_of_2);
	printf("repeating transport_protocol_any_of:\n%s\n",
	       cJSON_Print(jsontransport_protocol_any_of_2));
}

int main() {
	test_transport_protocol_any_of(1);
	test_transport_protocol_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // transport_protocol_any_of_MAIN
#endif // transport_protocol_any_of_TEST
