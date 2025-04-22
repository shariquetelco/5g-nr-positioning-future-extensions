#ifndef top_application_TEST
#define top_application_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define top_application_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/top_application.h"
top_application_t *instantiate_top_application(int include_optional);

#include "test_flow_info.c"


top_application_t *instantiate_top_application(int include_optional) {
	top_application_t *top_application = NULL;
	if(include_optional) {
		top_application = top_application_create(
			"0",
			// false, not to have infinite recursion
			instantiate_flow_info(0),
			1
			);
	} else {
		top_application = top_application_create(
			"0",
			NULL,
			1
			);
	}

	return top_application;
}


#ifdef top_application_MAIN

void test_top_application(int include_optional) {
	top_application_t *top_application_1 = instantiate_top_application(
		include_optional);

	cJSON *jsontop_application_1 = top_application_convertToJSON(
		top_application_1);
	printf("top_application :\n%s\n", cJSON_Print(jsontop_application_1));
	top_application_t *top_application_2 = top_application_parseFromJSON(
		jsontop_application_1);
	cJSON *jsontop_application_2 = top_application_convertToJSON(
		top_application_2);
	printf("repeating top_application:\n%s\n",
	       cJSON_Print(jsontop_application_2));
}

int main() {
	test_top_application(1);
	test_top_application(0);

	printf("Hello world \n");
	return 0;
}

#endif // top_application_MAIN
#endif // top_application_TEST
