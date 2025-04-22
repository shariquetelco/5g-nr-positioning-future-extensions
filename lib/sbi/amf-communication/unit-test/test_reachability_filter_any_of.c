#ifndef reachability_filter_any_of_TEST
#define reachability_filter_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reachability_filter_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reachability_filter_any_of.h"
reachability_filter_any_of_t *instantiate_reachability_filter_any_of(
	int include_optional);



reachability_filter_any_of_t *instantiate_reachability_filter_any_of(
	int include_optional) {
	reachability_filter_any_of_t *reachability_filter_any_of = NULL;
	if(include_optional) {
		reachability_filter_any_of = reachability_filter_any_of_create(
			);
	} else {
		reachability_filter_any_of = reachability_filter_any_of_create(
			);
	}

	return reachability_filter_any_of;
}


#ifdef reachability_filter_any_of_MAIN

void test_reachability_filter_any_of(int include_optional) {
	reachability_filter_any_of_t *reachability_filter_any_of_1 =
		instantiate_reachability_filter_any_of(include_optional);

	cJSON *jsonreachability_filter_any_of_1 =
		reachability_filter_any_of_convertToJSON(
			reachability_filter_any_of_1);
	printf("reachability_filter_any_of :\n%s\n",
	       cJSON_Print(jsonreachability_filter_any_of_1));
	reachability_filter_any_of_t *reachability_filter_any_of_2 =
		reachability_filter_any_of_parseFromJSON(
			jsonreachability_filter_any_of_1);
	cJSON *jsonreachability_filter_any_of_2 =
		reachability_filter_any_of_convertToJSON(
			reachability_filter_any_of_2);
	printf("repeating reachability_filter_any_of:\n%s\n",
	       cJSON_Print(jsonreachability_filter_any_of_2));
}

int main() {
	test_reachability_filter_any_of(1);
	test_reachability_filter_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // reachability_filter_any_of_MAIN
#endif // reachability_filter_any_of_TEST
