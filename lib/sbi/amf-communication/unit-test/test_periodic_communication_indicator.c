#ifndef periodic_communication_indicator_TEST
#define periodic_communication_indicator_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define periodic_communication_indicator_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/periodic_communication_indicator.h"
periodic_communication_indicator_t *instantiate_periodic_communication_indicator(
	int include_optional);



periodic_communication_indicator_t *instantiate_periodic_communication_indicator(
	int include_optional) {
	periodic_communication_indicator_t *periodic_communication_indicator =
		NULL;
	if(include_optional) {
		periodic_communication_indicator =
			periodic_communication_indicator_create(
				);
	} else {
		periodic_communication_indicator =
			periodic_communication_indicator_create(
				);
	}

	return periodic_communication_indicator;
}


#ifdef periodic_communication_indicator_MAIN

void test_periodic_communication_indicator(int include_optional) {
	periodic_communication_indicator_t *periodic_communication_indicator_1 =
		instantiate_periodic_communication_indicator(include_optional);

	cJSON *jsonperiodic_communication_indicator_1 =
		periodic_communication_indicator_convertToJSON(
			periodic_communication_indicator_1);
	printf("periodic_communication_indicator :\n%s\n",
	       cJSON_Print(jsonperiodic_communication_indicator_1));
	periodic_communication_indicator_t *periodic_communication_indicator_2 =
		periodic_communication_indicator_parseFromJSON(
			jsonperiodic_communication_indicator_1);
	cJSON *jsonperiodic_communication_indicator_2 =
		periodic_communication_indicator_convertToJSON(
			periodic_communication_indicator_2);
	printf("repeating periodic_communication_indicator:\n%s\n",
	       cJSON_Print(jsonperiodic_communication_indicator_2));
}

int main() {
	test_periodic_communication_indicator(1);
	test_periodic_communication_indicator(0);

	printf("Hello world \n");
	return 0;
}

#endif // periodic_communication_indicator_MAIN
#endif // periodic_communication_indicator_TEST
