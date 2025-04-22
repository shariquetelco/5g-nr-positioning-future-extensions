#ifndef pseudonym_indicator_TEST
#define pseudonym_indicator_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pseudonym_indicator_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pseudonym_indicator.h"
pseudonym_indicator_t *instantiate_pseudonym_indicator(int include_optional);



pseudonym_indicator_t *instantiate_pseudonym_indicator(int include_optional) {
	pseudonym_indicator_t *pseudonym_indicator = NULL;
	if(include_optional) {
		pseudonym_indicator = pseudonym_indicator_create(
			);
	} else {
		pseudonym_indicator = pseudonym_indicator_create(
			);
	}

	return pseudonym_indicator;
}


#ifdef pseudonym_indicator_MAIN

void test_pseudonym_indicator(int include_optional) {
	pseudonym_indicator_t *pseudonym_indicator_1 =
		instantiate_pseudonym_indicator(include_optional);

	cJSON *jsonpseudonym_indicator_1 = pseudonym_indicator_convertToJSON(
		pseudonym_indicator_1);
	printf("pseudonym_indicator :\n%s\n",
	       cJSON_Print(jsonpseudonym_indicator_1));
	pseudonym_indicator_t *pseudonym_indicator_2 =
		pseudonym_indicator_parseFromJSON(jsonpseudonym_indicator_1);
	cJSON *jsonpseudonym_indicator_2 = pseudonym_indicator_convertToJSON(
		pseudonym_indicator_2);
	printf("repeating pseudonym_indicator:\n%s\n",
	       cJSON_Print(jsonpseudonym_indicator_2));
}

int main() {
	test_pseudonym_indicator(1);
	test_pseudonym_indicator(0);

	printf("Hello world \n");
	return 0;
}

#endif // pseudonym_indicator_MAIN
#endif // pseudonym_indicator_TEST
