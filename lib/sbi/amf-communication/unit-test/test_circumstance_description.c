#ifndef circumstance_description_TEST
#define circumstance_description_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define circumstance_description_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/circumstance_description.h"
circumstance_description_t *instantiate_circumstance_description(
	int include_optional);

#include "test_network_area_info.c"


circumstance_description_t *instantiate_circumstance_description(
	int include_optional) {
	circumstance_description_t *circumstance_description = NULL;
	if(include_optional) {
		circumstance_description = circumstance_description_create(
			1.337,
			"2013-10-20T19:20:30+01:00",
			// false, not to have infinite recursion
			instantiate_network_area_info(0),
			0
			);
	} else {
		circumstance_description = circumstance_description_create(
			1.337,
			"2013-10-20T19:20:30+01:00",
			NULL,
			0
			);
	}

	return circumstance_description;
}


#ifdef circumstance_description_MAIN

void test_circumstance_description(int include_optional) {
	circumstance_description_t *circumstance_description_1 =
		instantiate_circumstance_description(include_optional);

	cJSON *jsoncircumstance_description_1 =
		circumstance_description_convertToJSON(
			circumstance_description_1);
	printf("circumstance_description :\n%s\n",
	       cJSON_Print(jsoncircumstance_description_1));
	circumstance_description_t *circumstance_description_2 =
		circumstance_description_parseFromJSON(
			jsoncircumstance_description_1);
	cJSON *jsoncircumstance_description_2 =
		circumstance_description_convertToJSON(
			circumstance_description_2);
	printf("repeating circumstance_description:\n%s\n",
	       cJSON_Print(jsoncircumstance_description_2));
}

int main() {
	test_circumstance_description(1);
	test_circumstance_description(0);

	printf("Hello world \n");
	return 0;
}

#endif // circumstance_description_MAIN
#endif // circumstance_description_TEST
