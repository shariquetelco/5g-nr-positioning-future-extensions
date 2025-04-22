#ifndef reported_event_type_TEST
#define reported_event_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reported_event_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reported_event_type.h"
reported_event_type_t *instantiate_reported_event_type(int include_optional);



reported_event_type_t *instantiate_reported_event_type(int include_optional) {
	reported_event_type_t *reported_event_type = NULL;
	if(include_optional) {
		reported_event_type = reported_event_type_create(
			);
	} else {
		reported_event_type = reported_event_type_create(
			);
	}

	return reported_event_type;
}


#ifdef reported_event_type_MAIN

void test_reported_event_type(int include_optional) {
	reported_event_type_t *reported_event_type_1 =
		instantiate_reported_event_type(include_optional);

	cJSON *jsonreported_event_type_1 = reported_event_type_convertToJSON(
		reported_event_type_1);
	printf("reported_event_type :\n%s\n",
	       cJSON_Print(jsonreported_event_type_1));
	reported_event_type_t *reported_event_type_2 =
		reported_event_type_parseFromJSON(jsonreported_event_type_1);
	cJSON *jsonreported_event_type_2 = reported_event_type_convertToJSON(
		reported_event_type_2);
	printf("repeating reported_event_type:\n%s\n",
	       cJSON_Print(jsonreported_event_type_2));
}

int main() {
	test_reported_event_type(1);
	test_reported_event_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // reported_event_type_MAIN
#endif // reported_event_type_TEST
