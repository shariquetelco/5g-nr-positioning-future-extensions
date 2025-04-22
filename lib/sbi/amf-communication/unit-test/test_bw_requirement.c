#ifndef bw_requirement_TEST
#define bw_requirement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bw_requirement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bw_requirement.h"
bw_requirement_t *instantiate_bw_requirement(int include_optional);



bw_requirement_t *instantiate_bw_requirement(int include_optional) {
	bw_requirement_t *bw_requirement = NULL;
	if(include_optional) {
		bw_requirement = bw_requirement_create(
			"0",
			"a",
			"a",
			"a",
			"a"
			);
	} else {
		bw_requirement = bw_requirement_create(
			"0",
			"a",
			"a",
			"a",
			"a"
			);
	}

	return bw_requirement;
}


#ifdef bw_requirement_MAIN

void test_bw_requirement(int include_optional) {
	bw_requirement_t *bw_requirement_1 = instantiate_bw_requirement(
		include_optional);

	cJSON *jsonbw_requirement_1 = bw_requirement_convertToJSON(
		bw_requirement_1);
	printf("bw_requirement :\n%s\n", cJSON_Print(jsonbw_requirement_1));
	bw_requirement_t *bw_requirement_2 = bw_requirement_parseFromJSON(
		jsonbw_requirement_1);
	cJSON *jsonbw_requirement_2 = bw_requirement_convertToJSON(
		bw_requirement_2);
	printf("repeating bw_requirement:\n%s\n",
	       cJSON_Print(jsonbw_requirement_2));
}

int main() {
	test_bw_requirement(1);
	test_bw_requirement(0);

	printf("Hello world \n");
	return 0;
}

#endif // bw_requirement_MAIN
#endif // bw_requirement_TEST
