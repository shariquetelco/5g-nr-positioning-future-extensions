#ifndef ng_ap_cause_TEST
#define ng_ap_cause_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ng_ap_cause_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ng_ap_cause.h"
ng_ap_cause_t *instantiate_ng_ap_cause(int include_optional);



ng_ap_cause_t *instantiate_ng_ap_cause(int include_optional) {
	ng_ap_cause_t *ng_ap_cause = NULL;
	if(include_optional) {
		ng_ap_cause = ng_ap_cause_create(
			0,
			0
			);
	} else {
		ng_ap_cause = ng_ap_cause_create(
			0,
			0
			);
	}

	return ng_ap_cause;
}


#ifdef ng_ap_cause_MAIN

void test_ng_ap_cause(int include_optional) {
	ng_ap_cause_t *ng_ap_cause_1 =
		instantiate_ng_ap_cause(include_optional);

	cJSON *jsonng_ap_cause_1 = ng_ap_cause_convertToJSON(ng_ap_cause_1);
	printf("ng_ap_cause :\n%s\n", cJSON_Print(jsonng_ap_cause_1));
	ng_ap_cause_t *ng_ap_cause_2 = ng_ap_cause_parseFromJSON(
		jsonng_ap_cause_1);
	cJSON *jsonng_ap_cause_2 = ng_ap_cause_convertToJSON(ng_ap_cause_2);
	printf("repeating ng_ap_cause:\n%s\n", cJSON_Print(jsonng_ap_cause_2));
}

int main() {
	test_ng_ap_cause(1);
	test_ng_ap_cause(0);

	printf("Hello world \n");
	return 0;
}

#endif // ng_ap_cause_MAIN
#endif // ng_ap_cause_TEST
