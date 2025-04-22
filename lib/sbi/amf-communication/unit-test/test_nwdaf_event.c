#ifndef nwdaf_event_TEST
#define nwdaf_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nwdaf_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nwdaf_event.h"
nwdaf_event_t *instantiate_nwdaf_event(int include_optional);



nwdaf_event_t *instantiate_nwdaf_event(int include_optional) {
	nwdaf_event_t *nwdaf_event = NULL;
	if(include_optional) {
		nwdaf_event = nwdaf_event_create(
			);
	} else {
		nwdaf_event = nwdaf_event_create(
			);
	}

	return nwdaf_event;
}


#ifdef nwdaf_event_MAIN

void test_nwdaf_event(int include_optional) {
	nwdaf_event_t *nwdaf_event_1 =
		instantiate_nwdaf_event(include_optional);

	cJSON *jsonnwdaf_event_1 = nwdaf_event_convertToJSON(nwdaf_event_1);
	printf("nwdaf_event :\n%s\n", cJSON_Print(jsonnwdaf_event_1));
	nwdaf_event_t *nwdaf_event_2 = nwdaf_event_parseFromJSON(
		jsonnwdaf_event_1);
	cJSON *jsonnwdaf_event_2 = nwdaf_event_convertToJSON(nwdaf_event_2);
	printf("repeating nwdaf_event:\n%s\n", cJSON_Print(jsonnwdaf_event_2));
}

int main() {
	test_nwdaf_event(1);
	test_nwdaf_event(0);

	printf("Hello world \n");
	return 0;
}

#endif // nwdaf_event_MAIN
#endif // nwdaf_event_TEST
