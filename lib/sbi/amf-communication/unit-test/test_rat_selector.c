#ifndef rat_selector_TEST
#define rat_selector_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rat_selector_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rat_selector.h"
rat_selector_t *instantiate_rat_selector(int include_optional);



rat_selector_t *instantiate_rat_selector(int include_optional) {
	rat_selector_t *rat_selector = NULL;
	if(include_optional) {
		rat_selector = rat_selector_create(
			);
	} else {
		rat_selector = rat_selector_create(
			);
	}

	return rat_selector;
}


#ifdef rat_selector_MAIN

void test_rat_selector(int include_optional) {
	rat_selector_t *rat_selector_1 = instantiate_rat_selector(
		include_optional);

	cJSON *jsonrat_selector_1 = rat_selector_convertToJSON(rat_selector_1);
	printf("rat_selector :\n%s\n", cJSON_Print(jsonrat_selector_1));
	rat_selector_t *rat_selector_2 = rat_selector_parseFromJSON(
		jsonrat_selector_1);
	cJSON *jsonrat_selector_2 = rat_selector_convertToJSON(rat_selector_2);
	printf("repeating rat_selector:\n%s\n",
	       cJSON_Print(jsonrat_selector_2));
}

int main() {
	test_rat_selector(1);
	test_rat_selector(0);

	printf("Hello world \n");
	return 0;
}

#endif // rat_selector_MAIN
#endif // rat_selector_TEST
