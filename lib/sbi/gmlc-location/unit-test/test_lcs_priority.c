#ifndef lcs_priority_TEST
#define lcs_priority_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lcs_priority_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lcs_priority.h"
lcs_priority_t *instantiate_lcs_priority(int include_optional);



lcs_priority_t *instantiate_lcs_priority(int include_optional) {
	lcs_priority_t *lcs_priority = NULL;
	if(include_optional) {
		lcs_priority = lcs_priority_create(
			);
	} else {
		lcs_priority = lcs_priority_create(
			);
	}

	return lcs_priority;
}


#ifdef lcs_priority_MAIN

void test_lcs_priority(int include_optional) {
	lcs_priority_t *lcs_priority_1 = instantiate_lcs_priority(
		include_optional);

	cJSON *jsonlcs_priority_1 = lcs_priority_convertToJSON(lcs_priority_1);
	printf("lcs_priority :\n%s\n", cJSON_Print(jsonlcs_priority_1));
	lcs_priority_t *lcs_priority_2 = lcs_priority_parseFromJSON(
		jsonlcs_priority_1);
	cJSON *jsonlcs_priority_2 = lcs_priority_convertToJSON(lcs_priority_2);
	printf("repeating lcs_priority:\n%s\n",
	       cJSON_Print(jsonlcs_priority_2));
}

int main() {
	test_lcs_priority(1);
	test_lcs_priority(0);

	printf("Hello world \n");
	return 0;
}

#endif // lcs_priority_MAIN
#endif // lcs_priority_TEST
