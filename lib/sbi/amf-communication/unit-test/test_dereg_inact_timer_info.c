#ifndef dereg_inact_timer_info_TEST
#define dereg_inact_timer_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dereg_inact_timer_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dereg_inact_timer_info.h"
dereg_inact_timer_info_t *instantiate_dereg_inact_timer_info(
	int include_optional);

#include "test_nssaa_status.c"


dereg_inact_timer_info_t *instantiate_dereg_inact_timer_info(
	int include_optional) {
	dereg_inact_timer_info_t *dereg_inact_timer_info = NULL;
	if(include_optional) {
		dereg_inact_timer_info = dereg_inact_timer_info_create(
			// false, not to have infinite recursion
			instantiate_nssaa_status(0)
			);
	} else {
		dereg_inact_timer_info = dereg_inact_timer_info_create(
			NULL
			);
	}

	return dereg_inact_timer_info;
}


#ifdef dereg_inact_timer_info_MAIN

void test_dereg_inact_timer_info(int include_optional) {
	dereg_inact_timer_info_t *dereg_inact_timer_info_1 =
		instantiate_dereg_inact_timer_info(include_optional);

	cJSON *jsondereg_inact_timer_info_1 =
		dereg_inact_timer_info_convertToJSON(dereg_inact_timer_info_1);
	printf("dereg_inact_timer_info :\n%s\n",
	       cJSON_Print(jsondereg_inact_timer_info_1));
	dereg_inact_timer_info_t *dereg_inact_timer_info_2 =
		dereg_inact_timer_info_parseFromJSON(
			jsondereg_inact_timer_info_1);
	cJSON *jsondereg_inact_timer_info_2 =
		dereg_inact_timer_info_convertToJSON(dereg_inact_timer_info_2);
	printf("repeating dereg_inact_timer_info:\n%s\n",
	       cJSON_Print(jsondereg_inact_timer_info_2));
}

int main() {
	test_dereg_inact_timer_info(1);
	test_dereg_inact_timer_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // dereg_inact_timer_info_MAIN
#endif // dereg_inact_timer_info_TEST
