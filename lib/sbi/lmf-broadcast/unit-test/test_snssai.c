#ifndef snssai_TEST
#define snssai_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snssai_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snssai.h"
snssai_t *instantiate_snssai(int include_optional);



snssai_t *instantiate_snssai(int include_optional) {
	snssai_t *snssai = NULL;
	if(include_optional) {
		snssai = snssai_create(
			0,
			"a"
			);
	} else {
		snssai = snssai_create(
			0,
			"a"
			);
	}

	return snssai;
}


#ifdef snssai_MAIN

void test_snssai(int include_optional) {
	snssai_t *snssai_1 = instantiate_snssai(include_optional);

	cJSON *jsonsnssai_1 = snssai_convertToJSON(snssai_1);
	printf("snssai :\n%s\n", cJSON_Print(jsonsnssai_1));
	snssai_t *snssai_2 = snssai_parseFromJSON(jsonsnssai_1);
	cJSON *jsonsnssai_2 = snssai_convertToJSON(snssai_2);
	printf("repeating snssai:\n%s\n", cJSON_Print(jsonsnssai_2));
}

int main() {
	test_snssai(1);
	test_snssai(0);

	printf("Hello world \n");
	return 0;
}

#endif // snssai_MAIN
#endif // snssai_TEST
