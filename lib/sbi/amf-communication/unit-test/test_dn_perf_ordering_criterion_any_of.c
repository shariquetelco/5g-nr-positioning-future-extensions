#ifndef dn_perf_ordering_criterion_any_of_TEST
#define dn_perf_ordering_criterion_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dn_perf_ordering_criterion_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dn_perf_ordering_criterion_any_of.h"
dn_perf_ordering_criterion_any_of_t *
instantiate_dn_perf_ordering_criterion_any_of(int include_optional);



dn_perf_ordering_criterion_any_of_t *
instantiate_dn_perf_ordering_criterion_any_of(int include_optional) {
	dn_perf_ordering_criterion_any_of_t *dn_perf_ordering_criterion_any_of =
		NULL;
	if(include_optional) {
		dn_perf_ordering_criterion_any_of =
			dn_perf_ordering_criterion_any_of_create(
				);
	} else {
		dn_perf_ordering_criterion_any_of =
			dn_perf_ordering_criterion_any_of_create(
				);
	}

	return dn_perf_ordering_criterion_any_of;
}


#ifdef dn_perf_ordering_criterion_any_of_MAIN

void test_dn_perf_ordering_criterion_any_of(int include_optional) {
	dn_perf_ordering_criterion_any_of_t *dn_perf_ordering_criterion_any_of_1
	        = instantiate_dn_perf_ordering_criterion_any_of(include_optional);

	cJSON *jsondn_perf_ordering_criterion_any_of_1 =
		dn_perf_ordering_criterion_any_of_convertToJSON(
			dn_perf_ordering_criterion_any_of_1);
	printf("dn_perf_ordering_criterion_any_of :\n%s\n",
	       cJSON_Print(jsondn_perf_ordering_criterion_any_of_1));
	dn_perf_ordering_criterion_any_of_t *dn_perf_ordering_criterion_any_of_2
	        = dn_perf_ordering_criterion_any_of_parseFromJSON(
			  jsondn_perf_ordering_criterion_any_of_1);
	cJSON *jsondn_perf_ordering_criterion_any_of_2 =
		dn_perf_ordering_criterion_any_of_convertToJSON(
			dn_perf_ordering_criterion_any_of_2);
	printf("repeating dn_perf_ordering_criterion_any_of:\n%s\n", cJSON_Print(
		       jsondn_perf_ordering_criterion_any_of_2));
}

int main() {
	test_dn_perf_ordering_criterion_any_of(1);
	test_dn_perf_ordering_criterion_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // dn_perf_ordering_criterion_any_of_MAIN
#endif // dn_perf_ordering_criterion_any_of_TEST
