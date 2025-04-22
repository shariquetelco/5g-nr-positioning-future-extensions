#ifndef trace_depth_TEST
#define trace_depth_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trace_depth_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trace_depth.h"
trace_depth_t *instantiate_trace_depth(int include_optional);



trace_depth_t *instantiate_trace_depth(int include_optional) {
	trace_depth_t *trace_depth = NULL;
	if(include_optional) {
		trace_depth = trace_depth_create(
			);
	} else {
		trace_depth = trace_depth_create(
			);
	}

	return trace_depth;
}


#ifdef trace_depth_MAIN

void test_trace_depth(int include_optional) {
	trace_depth_t *trace_depth_1 =
		instantiate_trace_depth(include_optional);

	cJSON *jsontrace_depth_1 = trace_depth_convertToJSON(trace_depth_1);
	printf("trace_depth :\n%s\n", cJSON_Print(jsontrace_depth_1));
	trace_depth_t *trace_depth_2 = trace_depth_parseFromJSON(
		jsontrace_depth_1);
	cJSON *jsontrace_depth_2 = trace_depth_convertToJSON(trace_depth_2);
	printf("repeating trace_depth:\n%s\n", cJSON_Print(jsontrace_depth_2));
}

int main() {
	test_trace_depth(1);
	test_trace_depth(0);

	printf("Hello world \n");
	return 0;
}

#endif // trace_depth_MAIN
#endif // trace_depth_TEST
