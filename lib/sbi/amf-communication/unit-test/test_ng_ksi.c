#ifndef ng_ksi_TEST
#define ng_ksi_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ng_ksi_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ng_ksi.h"
ng_ksi_t *instantiate_ng_ksi(int include_optional);



ng_ksi_t *instantiate_ng_ksi(int include_optional) {
	ng_ksi_t *ng_ksi = NULL;
	if(include_optional) {
		ng_ksi = ng_ksi_create(
			namf_communication_ng_ksi__NATIVE,
			0
			);
	} else {
		ng_ksi = ng_ksi_create(
			namf_communication_ng_ksi__NATIVE,
			0
			);
	}

	return ng_ksi;
}


#ifdef ng_ksi_MAIN

void test_ng_ksi(int include_optional) {
	ng_ksi_t *ng_ksi_1 = instantiate_ng_ksi(include_optional);

	cJSON *jsonng_ksi_1 = ng_ksi_convertToJSON(ng_ksi_1);
	printf("ng_ksi :\n%s\n", cJSON_Print(jsonng_ksi_1));
	ng_ksi_t *ng_ksi_2 = ng_ksi_parseFromJSON(jsonng_ksi_1);
	cJSON *jsonng_ksi_2 = ng_ksi_convertToJSON(ng_ksi_2);
	printf("repeating ng_ksi:\n%s\n", cJSON_Print(jsonng_ksi_2));
}

int main() {
	test_ng_ksi(1);
	test_ng_ksi(0);

	printf("Hello world \n");
	return 0;
}

#endif // ng_ksi_MAIN
#endif // ng_ksi_TEST
