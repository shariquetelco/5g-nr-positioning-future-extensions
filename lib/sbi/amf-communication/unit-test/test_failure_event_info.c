#ifndef failure_event_info_TEST
#define failure_event_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define failure_event_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/failure_event_info.h"
failure_event_info_t *instantiate_failure_event_info(int include_optional);

#include "test_nwdaf_event.c"
#include "test_nwdaf_failure_code.c"


failure_event_info_t *instantiate_failure_event_info(int include_optional) {
	failure_event_info_t *failure_event_info = NULL;
	if(include_optional) {
		failure_event_info = failure_event_info_create(
			null,
			null
			);
	} else {
		failure_event_info = failure_event_info_create(
			null,
			null
			);
	}

	return failure_event_info;
}


#ifdef failure_event_info_MAIN

void test_failure_event_info(int include_optional) {
	failure_event_info_t *failure_event_info_1 =
		instantiate_failure_event_info(include_optional);

	cJSON *jsonfailure_event_info_1 = failure_event_info_convertToJSON(
		failure_event_info_1);
	printf("failure_event_info :\n%s\n",
	       cJSON_Print(jsonfailure_event_info_1));
	failure_event_info_t *failure_event_info_2 =
		failure_event_info_parseFromJSON(jsonfailure_event_info_1);
	cJSON *jsonfailure_event_info_2 = failure_event_info_convertToJSON(
		failure_event_info_2);
	printf("repeating failure_event_info:\n%s\n",
	       cJSON_Print(jsonfailure_event_info_2));
}

int main() {
	test_failure_event_info(1);
	test_failure_event_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // failure_event_info_MAIN
#endif // failure_event_info_TEST
