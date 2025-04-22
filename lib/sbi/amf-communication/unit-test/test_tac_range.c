#ifndef tac_range_TEST
#define tac_range_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tac_range_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tac_range.h"
tac_range_t *instantiate_tac_range(int include_optional);



tac_range_t *instantiate_tac_range(int include_optional) {
	tac_range_t *tac_range = NULL;
	if(include_optional) {
		tac_range = tac_range_create(
			"a",
			"a",
			"0"
			);
	} else {
		tac_range = tac_range_create(
			"a",
			"a",
			"0"
			);
	}

	return tac_range;
}


#ifdef tac_range_MAIN

void test_tac_range(int include_optional) {
	tac_range_t *tac_range_1 = instantiate_tac_range(include_optional);

	cJSON *jsontac_range_1 = tac_range_convertToJSON(tac_range_1);
	printf("tac_range :\n%s\n", cJSON_Print(jsontac_range_1));
	tac_range_t *tac_range_2 = tac_range_parseFromJSON(jsontac_range_1);
	cJSON *jsontac_range_2 = tac_range_convertToJSON(tac_range_2);
	printf("repeating tac_range:\n%s\n", cJSON_Print(jsontac_range_2));
}

int main() {
	test_tac_range(1);
	test_tac_range(0);

	printf("Hello world \n");
	return 0;
}

#endif // tac_range_MAIN
#endif // tac_range_TEST
