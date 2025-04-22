#ifndef periodic_event_info_TEST
#define periodic_event_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define periodic_event_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/periodic_event_info.h"
periodic_event_info_t *instantiate_periodic_event_info(int include_optional);



periodic_event_info_t *instantiate_periodic_event_info(int include_optional) {
	periodic_event_info_t *periodic_event_info = NULL;
	if(include_optional) {
		periodic_event_info = periodic_event_info_create(
			1,
			1,
			lmf_location_periodic_event_info_REPORTINGINFINITEIND_true,
			1
			);
	} else {
		periodic_event_info = periodic_event_info_create(
			1,
			1,
			lmf_location_periodic_event_info_REPORTINGINFINITEIND_true,
			1
			);
	}

	return periodic_event_info;
}


#ifdef periodic_event_info_MAIN

void test_periodic_event_info(int include_optional) {
	periodic_event_info_t *periodic_event_info_1 =
		instantiate_periodic_event_info(include_optional);

	cJSON *jsonperiodic_event_info_1 = periodic_event_info_convertToJSON(
		periodic_event_info_1);
	printf("periodic_event_info :\n%s\n",
	       cJSON_Print(jsonperiodic_event_info_1));
	periodic_event_info_t *periodic_event_info_2 =
		periodic_event_info_parseFromJSON(jsonperiodic_event_info_1);
	cJSON *jsonperiodic_event_info_2 = periodic_event_info_convertToJSON(
		periodic_event_info_2);
	printf("repeating periodic_event_info:\n%s\n",
	       cJSON_Print(jsonperiodic_event_info_2));
}

int main() {
	test_periodic_event_info(1);
	test_periodic_event_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // periodic_event_info_MAIN
#endif // periodic_event_info_TEST
