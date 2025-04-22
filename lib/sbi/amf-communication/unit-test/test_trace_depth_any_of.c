#ifndef trace_depth_any_of_TEST
#define trace_depth_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trace_depth_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trace_depth_any_of.h"
trace_depth_any_of_t *instantiate_trace_depth_any_of(int include_optional);



trace_depth_any_of_t *instantiate_trace_depth_any_of(int include_optional) {
	trace_depth_any_of_t *trace_depth_any_of = NULL;
	if(include_optional) {
		trace_depth_any_of = trace_depth_any_of_create(
			);
	} else {
		trace_depth_any_of = trace_depth_any_of_create(
			);
	}

	return trace_depth_any_of;
}


#ifdef trace_depth_any_of_MAIN

void test_trace_depth_any_of(int include_optional) {
	trace_depth_any_of_t *trace_depth_any_of_1 =
		instantiate_trace_depth_any_of(include_optional);

	cJSON *jsontrace_depth_any_of_1 = trace_depth_any_of_convertToJSON(
		trace_depth_any_of_1);
	printf("trace_depth_any_of :\n%s\n",
	       cJSON_Print(jsontrace_depth_any_of_1));
	trace_depth_any_of_t *trace_depth_any_of_2 =
		trace_depth_any_of_parseFromJSON(jsontrace_depth_any_of_1);
	cJSON *jsontrace_depth_any_of_2 = trace_depth_any_of_convertToJSON(
		trace_depth_any_of_2);
	printf("repeating trace_depth_any_of:\n%s\n",
	       cJSON_Print(jsontrace_depth_any_of_2));
}

int main() {
	test_trace_depth_any_of(1);
	test_trace_depth_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // trace_depth_any_of_MAIN
#endif // trace_depth_any_of_TEST
