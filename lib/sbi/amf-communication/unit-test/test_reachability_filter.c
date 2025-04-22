#ifndef reachability_filter_TEST
#define reachability_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reachability_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reachability_filter.h"
reachability_filter_t *instantiate_reachability_filter(int include_optional);



reachability_filter_t *instantiate_reachability_filter(int include_optional) {
	reachability_filter_t *reachability_filter = NULL;
	if(include_optional) {
		reachability_filter = reachability_filter_create(
			);
	} else {
		reachability_filter = reachability_filter_create(
			);
	}

	return reachability_filter;
}


#ifdef reachability_filter_MAIN

void test_reachability_filter(int include_optional) {
	reachability_filter_t *reachability_filter_1 =
		instantiate_reachability_filter(include_optional);

	cJSON *jsonreachability_filter_1 = reachability_filter_convertToJSON(
		reachability_filter_1);
	printf("reachability_filter :\n%s\n",
	       cJSON_Print(jsonreachability_filter_1));
	reachability_filter_t *reachability_filter_2 =
		reachability_filter_parseFromJSON(jsonreachability_filter_1);
	cJSON *jsonreachability_filter_2 = reachability_filter_convertToJSON(
		reachability_filter_2);
	printf("repeating reachability_filter:\n%s\n",
	       cJSON_Print(jsonreachability_filter_2));
}

int main() {
	test_reachability_filter(1);
	test_reachability_filter(0);

	printf("Hello world \n");
	return 0;
}

#endif // reachability_filter_MAIN
#endif // reachability_filter_TEST
