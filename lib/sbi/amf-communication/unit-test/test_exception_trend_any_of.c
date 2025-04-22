#ifndef exception_trend_any_of_TEST
#define exception_trend_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define exception_trend_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/exception_trend_any_of.h"
exception_trend_any_of_t *instantiate_exception_trend_any_of(
	int include_optional);



exception_trend_any_of_t *instantiate_exception_trend_any_of(
	int include_optional) {
	exception_trend_any_of_t *exception_trend_any_of = NULL;
	if(include_optional) {
		exception_trend_any_of = exception_trend_any_of_create(
			);
	} else {
		exception_trend_any_of = exception_trend_any_of_create(
			);
	}

	return exception_trend_any_of;
}


#ifdef exception_trend_any_of_MAIN

void test_exception_trend_any_of(int include_optional) {
	exception_trend_any_of_t *exception_trend_any_of_1 =
		instantiate_exception_trend_any_of(include_optional);

	cJSON *jsonexception_trend_any_of_1 =
		exception_trend_any_of_convertToJSON(exception_trend_any_of_1);
	printf("exception_trend_any_of :\n%s\n",
	       cJSON_Print(jsonexception_trend_any_of_1));
	exception_trend_any_of_t *exception_trend_any_of_2 =
		exception_trend_any_of_parseFromJSON(
			jsonexception_trend_any_of_1);
	cJSON *jsonexception_trend_any_of_2 =
		exception_trend_any_of_convertToJSON(exception_trend_any_of_2);
	printf("repeating exception_trend_any_of:\n%s\n",
	       cJSON_Print(jsonexception_trend_any_of_2));
}

int main() {
	test_exception_trend_any_of(1);
	test_exception_trend_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // exception_trend_any_of_MAIN
#endif // exception_trend_any_of_TEST
