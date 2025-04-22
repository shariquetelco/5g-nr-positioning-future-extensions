#ifndef dn_perf_ordering_criterion_TEST
#define dn_perf_ordering_criterion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dn_perf_ordering_criterion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dn_perf_ordering_criterion.h"
dn_perf_ordering_criterion_t *instantiate_dn_perf_ordering_criterion(
	int include_optional);



dn_perf_ordering_criterion_t *instantiate_dn_perf_ordering_criterion(
	int include_optional) {
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion = NULL;
	if(include_optional) {
		dn_perf_ordering_criterion = dn_perf_ordering_criterion_create(
			);
	} else {
		dn_perf_ordering_criterion = dn_perf_ordering_criterion_create(
			);
	}

	return dn_perf_ordering_criterion;
}


#ifdef dn_perf_ordering_criterion_MAIN

void test_dn_perf_ordering_criterion(int include_optional) {
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_1 =
		instantiate_dn_perf_ordering_criterion(include_optional);

	cJSON *jsondn_perf_ordering_criterion_1 =
		dn_perf_ordering_criterion_convertToJSON(
			dn_perf_ordering_criterion_1);
	printf("dn_perf_ordering_criterion :\n%s\n",
	       cJSON_Print(jsondn_perf_ordering_criterion_1));
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_2 =
		dn_perf_ordering_criterion_parseFromJSON(
			jsondn_perf_ordering_criterion_1);
	cJSON *jsondn_perf_ordering_criterion_2 =
		dn_perf_ordering_criterion_convertToJSON(
			dn_perf_ordering_criterion_2);
	printf("repeating dn_perf_ordering_criterion:\n%s\n",
	       cJSON_Print(jsondn_perf_ordering_criterion_2));
}

int main() {
	test_dn_perf_ordering_criterion(1);
	test_dn_perf_ordering_criterion(0);

	printf("Hello world \n");
	return 0;
}

#endif // dn_perf_ordering_criterion_MAIN
#endif // dn_perf_ordering_criterion_TEST
