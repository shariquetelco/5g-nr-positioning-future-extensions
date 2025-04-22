#ifndef event_class_TEST
#define event_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define event_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/event_class.h"
event_class_t *instantiate_event_class(int include_optional);



event_class_t *instantiate_event_class(int include_optional) {
	event_class_t *event_class = NULL;
	if(include_optional) {
		event_class = event_class_create(
			);
	} else {
		event_class = event_class_create(
			);
	}

	return event_class;
}


#ifdef event_class_MAIN

void test_event_class(int include_optional) {
	event_class_t *event_class_1 =
		instantiate_event_class(include_optional);

	cJSON *jsonevent_class_1 = event_class_convertToJSON(event_class_1);
	printf("event_class :\n%s\n", cJSON_Print(jsonevent_class_1));
	event_class_t *event_class_2 = event_class_parseFromJSON(
		jsonevent_class_1);
	cJSON *jsonevent_class_2 = event_class_convertToJSON(event_class_2);
	printf("repeating event_class:\n%s\n", cJSON_Print(jsonevent_class_2));
}

int main() {
	test_event_class(1);
	test_event_class(0);

	printf("Hello world \n");
	return 0;
}

#endif // event_class_MAIN
#endif // event_class_TEST
