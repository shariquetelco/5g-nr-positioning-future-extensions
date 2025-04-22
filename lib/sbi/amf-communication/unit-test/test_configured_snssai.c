#ifndef configured_snssai_TEST
#define configured_snssai_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define configured_snssai_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/configured_snssai.h"
configured_snssai_t *instantiate_configured_snssai(int include_optional);

#include "test_snssai.c"
#include "test_snssai.c"


configured_snssai_t *instantiate_configured_snssai(int include_optional) {
	configured_snssai_t *configured_snssai = NULL;
	if(include_optional) {
		configured_snssai = configured_snssai_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			// false, not to have infinite recursion
			instantiate_snssai(0)
			);
	} else {
		configured_snssai = configured_snssai_create(
			NULL,
			NULL
			);
	}

	return configured_snssai;
}


#ifdef configured_snssai_MAIN

void test_configured_snssai(int include_optional) {
	configured_snssai_t *configured_snssai_1 =
		instantiate_configured_snssai(include_optional);

	cJSON *jsonconfigured_snssai_1 = configured_snssai_convertToJSON(
		configured_snssai_1);
	printf("configured_snssai :\n%s\n",
	       cJSON_Print(jsonconfigured_snssai_1));
	configured_snssai_t *configured_snssai_2 =
		configured_snssai_parseFromJSON(jsonconfigured_snssai_1);
	cJSON *jsonconfigured_snssai_2 = configured_snssai_convertToJSON(
		configured_snssai_2);
	printf("repeating configured_snssai:\n%s\n",
	       cJSON_Print(jsonconfigured_snssai_2));
}

int main() {
	test_configured_snssai(1);
	test_configured_snssai(0);

	printf("Hello world \n");
	return 0;
}

#endif // configured_snssai_MAIN
#endif // configured_snssai_TEST
