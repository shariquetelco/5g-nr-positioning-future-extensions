#ifndef perf_data_TEST
#define perf_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define perf_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/perf_data.h"
perf_data_t *instantiate_perf_data(int include_optional);



perf_data_t *instantiate_perf_data(int include_optional) {
	perf_data_t *perf_data = NULL;
	if(include_optional) {
		perf_data = perf_data_create(
			"a",
			"a",
			"a",
			"a",
			1.337,
			list_createList(),
			1,
			1,
			1.337,
			list_createList(),
			0,
			0,
			1.337,
			list_createList(),
			0
			);
	} else {
		perf_data = perf_data_create(
			"a",
			"a",
			"a",
			"a",
			1.337,
			list_createList(),
			1,
			1,
			1.337,
			list_createList(),
			0,
			0,
			1.337,
			list_createList(),
			0
			);
	}

	return perf_data;
}


#ifdef perf_data_MAIN

void test_perf_data(int include_optional) {
	perf_data_t *perf_data_1 = instantiate_perf_data(include_optional);

	cJSON *jsonperf_data_1 = perf_data_convertToJSON(perf_data_1);
	printf("perf_data :\n%s\n", cJSON_Print(jsonperf_data_1));
	perf_data_t *perf_data_2 = perf_data_parseFromJSON(jsonperf_data_1);
	cJSON *jsonperf_data_2 = perf_data_convertToJSON(perf_data_2);
	printf("repeating perf_data:\n%s\n", cJSON_Print(jsonperf_data_2));
}

int main() {
	test_perf_data(1);
	test_perf_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // perf_data_MAIN
#endif // perf_data_TEST
