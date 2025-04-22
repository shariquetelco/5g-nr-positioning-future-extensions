#ifndef ambr_TEST
#define ambr_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ambr_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ambr.h"
ambr_t *instantiate_ambr(int include_optional);



ambr_t *instantiate_ambr(int include_optional) {
	ambr_t *ambr = NULL;
	if(include_optional) {
		ambr = ambr_create(
			"a",
			"a"
			);
	} else {
		ambr = ambr_create(
			"a",
			"a"
			);
	}

	return ambr;
}


#ifdef ambr_MAIN

void test_ambr(int include_optional) {
	ambr_t *ambr_1 = instantiate_ambr(include_optional);

	cJSON *jsonambr_1 = ambr_convertToJSON(ambr_1);
	printf("ambr :\n%s\n", cJSON_Print(jsonambr_1));
	ambr_t *ambr_2 = ambr_parseFromJSON(jsonambr_1);
	cJSON *jsonambr_2 = ambr_convertToJSON(ambr_2);
	printf("repeating ambr:\n%s\n", cJSON_Print(jsonambr_2));
}

int main() {
	test_ambr(1);
	test_ambr(0);

	printf("Hello world \n");
	return 0;
}

#endif // ambr_MAIN
#endif // ambr_TEST
