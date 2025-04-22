#ifndef transport_protocol_TEST
#define transport_protocol_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transport_protocol_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transport_protocol.h"
transport_protocol_t *instantiate_transport_protocol(int include_optional);



transport_protocol_t *instantiate_transport_protocol(int include_optional) {
	transport_protocol_t *transport_protocol = NULL;
	if(include_optional) {
		transport_protocol = transport_protocol_create(
			);
	} else {
		transport_protocol = transport_protocol_create(
			);
	}

	return transport_protocol;
}


#ifdef transport_protocol_MAIN

void test_transport_protocol(int include_optional) {
	transport_protocol_t *transport_protocol_1 =
		instantiate_transport_protocol(include_optional);

	cJSON *jsontransport_protocol_1 = transport_protocol_convertToJSON(
		transport_protocol_1);
	printf("transport_protocol :\n%s\n",
	       cJSON_Print(jsontransport_protocol_1));
	transport_protocol_t *transport_protocol_2 =
		transport_protocol_parseFromJSON(jsontransport_protocol_1);
	cJSON *jsontransport_protocol_2 = transport_protocol_convertToJSON(
		transport_protocol_2);
	printf("repeating transport_protocol:\n%s\n",
	       cJSON_Print(jsontransport_protocol_2));
}

int main() {
	test_transport_protocol(1);
	test_transport_protocol(0);

	printf("Hello world \n");
	return 0;
}

#endif // transport_protocol_MAIN
#endif // transport_protocol_TEST
