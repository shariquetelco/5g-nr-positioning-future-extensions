#ifndef valid_time_period_TEST
#define valid_time_period_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define valid_time_period_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/valid_time_period.h"
valid_time_period_t *instantiate_valid_time_period(int include_optional);



valid_time_period_t *instantiate_valid_time_period(int include_optional) {
	valid_time_period_t *valid_time_period = NULL;
	if(include_optional) {
		valid_time_period = valid_time_period_create(
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00"
			);
	} else {
		valid_time_period = valid_time_period_create(
			"2013-10-20T19:20:30+01:00",
			"2013-10-20T19:20:30+01:00"
			);
	}

	return valid_time_period;
}


#ifdef valid_time_period_MAIN

void test_valid_time_period(int include_optional) {
	valid_time_period_t *valid_time_period_1 =
		instantiate_valid_time_period(include_optional);

	cJSON *jsonvalid_time_period_1 = valid_time_period_convertToJSON(
		valid_time_period_1);
	printf("valid_time_period :\n%s\n",
	       cJSON_Print(jsonvalid_time_period_1));
	valid_time_period_t *valid_time_period_2 =
		valid_time_period_parseFromJSON(jsonvalid_time_period_1);
	cJSON *jsonvalid_time_period_2 = valid_time_period_convertToJSON(
		valid_time_period_2);
	printf("repeating valid_time_period:\n%s\n",
	       cJSON_Print(jsonvalid_time_period_2));
}

int main() {
	test_valid_time_period(1);
	test_valid_time_period(0);

	printf("Hello world \n");
	return 0;
}

#endif // valid_time_period_MAIN
#endif // valid_time_period_TEST
