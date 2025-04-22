#ifndef abnormal_behaviour_TEST
#define abnormal_behaviour_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define abnormal_behaviour_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/abnormal_behaviour.h"
abnormal_behaviour_t *instantiate_abnormal_behaviour(int include_optional);

#include "test_exception.c"
#include "test_snssai.c"
#include "test_additional_measurement.c"


abnormal_behaviour_t *instantiate_abnormal_behaviour(int include_optional) {
	abnormal_behaviour_t *abnormal_behaviour = NULL;
	if(include_optional) {
		abnormal_behaviour = abnormal_behaviour_create(
			list_createList(),
			// false, not to have infinite recursion
			instantiate_exception(0),
			"0",
			// false, not to have infinite recursion
			instantiate_snssai(0),
			1,
			0,
			// false, not to have infinite recursion
			instantiate_additional_measurement(0)
			);
	} else {
		abnormal_behaviour = abnormal_behaviour_create(
			list_createList(),
			NULL,
			"0",
			NULL,
			1,
			0,
			NULL
			);
	}

	return abnormal_behaviour;
}


#ifdef abnormal_behaviour_MAIN

void test_abnormal_behaviour(int include_optional) {
	abnormal_behaviour_t *abnormal_behaviour_1 =
		instantiate_abnormal_behaviour(include_optional);

	cJSON *jsonabnormal_behaviour_1 = abnormal_behaviour_convertToJSON(
		abnormal_behaviour_1);
	printf("abnormal_behaviour :\n%s\n",
	       cJSON_Print(jsonabnormal_behaviour_1));
	abnormal_behaviour_t *abnormal_behaviour_2 =
		abnormal_behaviour_parseFromJSON(jsonabnormal_behaviour_1);
	cJSON *jsonabnormal_behaviour_2 = abnormal_behaviour_convertToJSON(
		abnormal_behaviour_2);
	printf("repeating abnormal_behaviour:\n%s\n",
	       cJSON_Print(jsonabnormal_behaviour_2));
}

int main() {
	test_abnormal_behaviour(1);
	test_abnormal_behaviour(0);

	printf("Hello world \n");
	return 0;
}

#endif // abnormal_behaviour_MAIN
#endif // abnormal_behaviour_TEST
