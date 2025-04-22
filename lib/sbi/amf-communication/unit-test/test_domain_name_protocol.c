#ifndef domain_name_protocol_TEST
#define domain_name_protocol_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_name_protocol_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_name_protocol.h"
domain_name_protocol_t *instantiate_domain_name_protocol(int include_optional);



domain_name_protocol_t *instantiate_domain_name_protocol(int include_optional) {
	domain_name_protocol_t *domain_name_protocol = NULL;
	if(include_optional) {
		domain_name_protocol = domain_name_protocol_create(
			);
	} else {
		domain_name_protocol = domain_name_protocol_create(
			);
	}

	return domain_name_protocol;
}


#ifdef domain_name_protocol_MAIN

void test_domain_name_protocol(int include_optional) {
	domain_name_protocol_t *domain_name_protocol_1 =
		instantiate_domain_name_protocol(include_optional);

	cJSON *jsondomain_name_protocol_1 = domain_name_protocol_convertToJSON(
		domain_name_protocol_1);
	printf("domain_name_protocol :\n%s\n",
	       cJSON_Print(jsondomain_name_protocol_1));
	domain_name_protocol_t *domain_name_protocol_2 =
		domain_name_protocol_parseFromJSON(jsondomain_name_protocol_1);
	cJSON *jsondomain_name_protocol_2 = domain_name_protocol_convertToJSON(
		domain_name_protocol_2);
	printf("repeating domain_name_protocol:\n%s\n",
	       cJSON_Print(jsondomain_name_protocol_2));
}

int main() {
	test_domain_name_protocol(1);
	test_domain_name_protocol(0);

	printf("Hello world \n");
	return 0;
}

#endif // domain_name_protocol_MAIN
#endif // domain_name_protocol_TEST
