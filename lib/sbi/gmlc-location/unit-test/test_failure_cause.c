#ifndef failure_cause_TEST
#define failure_cause_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define failure_cause_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/failure_cause.h"
failure_cause_t *instantiate_failure_cause(int include_optional);



failure_cause_t *instantiate_failure_cause(int include_optional) {
	failure_cause_t *failure_cause = NULL;
	if(include_optional) {
		failure_cause = failure_cause_create(
			);
	} else {
		failure_cause = failure_cause_create(
			);
	}

	return failure_cause;
}


#ifdef failure_cause_MAIN

void test_failure_cause(int include_optional) {
	failure_cause_t *failure_cause_1 = instantiate_failure_cause(
		include_optional);

	cJSON *jsonfailure_cause_1 =
		failure_cause_convertToJSON(failure_cause_1);
	printf("failure_cause :\n%s\n", cJSON_Print(jsonfailure_cause_1));
	failure_cause_t *failure_cause_2 = failure_cause_parseFromJSON(
		jsonfailure_cause_1);
	cJSON *jsonfailure_cause_2 =
		failure_cause_convertToJSON(failure_cause_2);
	printf("repeating failure_cause:\n%s\n", cJSON_Print(
		       jsonfailure_cause_2));
}

int main() {
	test_failure_cause(1);
	test_failure_cause(0);

	printf("Hello world \n");
	return 0;
}

#endif // failure_cause_MAIN
#endif // failure_cause_TEST
