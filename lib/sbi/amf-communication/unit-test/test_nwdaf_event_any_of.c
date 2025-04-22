#ifndef nwdaf_event_any_of_TEST
#define nwdaf_event_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nwdaf_event_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nwdaf_event_any_of.h"
nwdaf_event_any_of_t *instantiate_nwdaf_event_any_of(int include_optional);



nwdaf_event_any_of_t *instantiate_nwdaf_event_any_of(int include_optional) {
	nwdaf_event_any_of_t *nwdaf_event_any_of = NULL;
	if(include_optional) {
		nwdaf_event_any_of = nwdaf_event_any_of_create(
			);
	} else {
		nwdaf_event_any_of = nwdaf_event_any_of_create(
			);
	}

	return nwdaf_event_any_of;
}


#ifdef nwdaf_event_any_of_MAIN

void test_nwdaf_event_any_of(int include_optional) {
	nwdaf_event_any_of_t *nwdaf_event_any_of_1 =
		instantiate_nwdaf_event_any_of(include_optional);

	cJSON *jsonnwdaf_event_any_of_1 = nwdaf_event_any_of_convertToJSON(
		nwdaf_event_any_of_1);
	printf("nwdaf_event_any_of :\n%s\n",
	       cJSON_Print(jsonnwdaf_event_any_of_1));
	nwdaf_event_any_of_t *nwdaf_event_any_of_2 =
		nwdaf_event_any_of_parseFromJSON(jsonnwdaf_event_any_of_1);
	cJSON *jsonnwdaf_event_any_of_2 = nwdaf_event_any_of_convertToJSON(
		nwdaf_event_any_of_2);
	printf("repeating nwdaf_event_any_of:\n%s\n",
	       cJSON_Print(jsonnwdaf_event_any_of_2));
}

int main() {
	test_nwdaf_event_any_of(1);
	test_nwdaf_event_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // nwdaf_event_any_of_MAIN
#endif // nwdaf_event_any_of_TEST
