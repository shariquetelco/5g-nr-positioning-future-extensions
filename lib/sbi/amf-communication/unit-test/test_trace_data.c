#ifndef trace_data_TEST
#define trace_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trace_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trace_data.h"
trace_data_t *instantiate_trace_data(int include_optional);

#include "test_trace_depth.c"
#include "test_ipv6_addr.c"


trace_data_t *instantiate_trace_data(int include_optional) {
	trace_data_t *trace_data = NULL;
	if(include_optional) {
		trace_data = trace_data_create(
			"a",
			null,
			"a",
			"a",
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			"0",
			"a"
			);
	} else {
		trace_data = trace_data_create(
			"a",
			null,
			"a",
			"a",
			"198.51.100.1",
			"2001:db8:85a3::8a2e:370:7334",
			"0",
			"a"
			);
	}

	return trace_data;
}


#ifdef trace_data_MAIN

void test_trace_data(int include_optional) {
	trace_data_t *trace_data_1 = instantiate_trace_data(include_optional);

	cJSON *jsontrace_data_1 = trace_data_convertToJSON(trace_data_1);
	printf("trace_data :\n%s\n", cJSON_Print(jsontrace_data_1));
	trace_data_t *trace_data_2 = trace_data_parseFromJSON(jsontrace_data_1);
	cJSON *jsontrace_data_2 = trace_data_convertToJSON(trace_data_2);
	printf("repeating trace_data:\n%s\n", cJSON_Print(jsontrace_data_2));
}

int main() {
	test_trace_data(1);
	test_trace_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // trace_data_MAIN
#endif // trace_data_TEST
