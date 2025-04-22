#ifndef snssai_extension_TEST
#define snssai_extension_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snssai_extension_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snssai_extension.h"
snssai_extension_t *instantiate_snssai_extension(int include_optional);



snssai_extension_t *instantiate_snssai_extension(int include_optional) {
	snssai_extension_t *snssai_extension = NULL;
	if(include_optional) {
		snssai_extension = snssai_extension_create(
			list_createList(),
			namf_communication_snssai_extension_WILDCARDSD_true
			);
	} else {
		snssai_extension = snssai_extension_create(
			list_createList(),
			namf_communication_snssai_extension_WILDCARDSD_true
			);
	}

	return snssai_extension;
}


#ifdef snssai_extension_MAIN

void test_snssai_extension(int include_optional) {
	snssai_extension_t *snssai_extension_1 = instantiate_snssai_extension(
		include_optional);

	cJSON *jsonsnssai_extension_1 = snssai_extension_convertToJSON(
		snssai_extension_1);
	printf("snssai_extension :\n%s\n", cJSON_Print(jsonsnssai_extension_1));
	snssai_extension_t *snssai_extension_2 = snssai_extension_parseFromJSON(
		jsonsnssai_extension_1);
	cJSON *jsonsnssai_extension_2 = snssai_extension_convertToJSON(
		snssai_extension_2);
	printf("repeating snssai_extension:\n%s\n",
	       cJSON_Print(jsonsnssai_extension_2));
}

int main() {
	test_snssai_extension(1);
	test_snssai_extension(0);

	printf("Hello world \n");
	return 0;
}

#endif // snssai_extension_MAIN
#endif // snssai_extension_TEST
