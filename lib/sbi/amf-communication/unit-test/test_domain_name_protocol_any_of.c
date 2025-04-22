#ifndef domain_name_protocol_any_of_TEST
#define domain_name_protocol_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_name_protocol_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_name_protocol_any_of.h"
domain_name_protocol_any_of_t *instantiate_domain_name_protocol_any_of(
	int include_optional);



domain_name_protocol_any_of_t *instantiate_domain_name_protocol_any_of(
	int include_optional) {
	domain_name_protocol_any_of_t *domain_name_protocol_any_of = NULL;
	if(include_optional) {
		domain_name_protocol_any_of =
			domain_name_protocol_any_of_create(
				);
	} else {
		domain_name_protocol_any_of =
			domain_name_protocol_any_of_create(
				);
	}

	return domain_name_protocol_any_of;
}


#ifdef domain_name_protocol_any_of_MAIN

void test_domain_name_protocol_any_of(int include_optional) {
	domain_name_protocol_any_of_t *domain_name_protocol_any_of_1 =
		instantiate_domain_name_protocol_any_of(include_optional);

	cJSON *jsondomain_name_protocol_any_of_1 =
		domain_name_protocol_any_of_convertToJSON(
			domain_name_protocol_any_of_1);
	printf("domain_name_protocol_any_of :\n%s\n",
	       cJSON_Print(jsondomain_name_protocol_any_of_1));
	domain_name_protocol_any_of_t *domain_name_protocol_any_of_2 =
		domain_name_protocol_any_of_parseFromJSON(
			jsondomain_name_protocol_any_of_1);
	cJSON *jsondomain_name_protocol_any_of_2 =
		domain_name_protocol_any_of_convertToJSON(
			domain_name_protocol_any_of_2);
	printf("repeating domain_name_protocol_any_of:\n%s\n",
	       cJSON_Print(jsondomain_name_protocol_any_of_2));
}

int main() {
	test_domain_name_protocol_any_of(1);
	test_domain_name_protocol_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // domain_name_protocol_any_of_MAIN
#endif // domain_name_protocol_any_of_TEST
