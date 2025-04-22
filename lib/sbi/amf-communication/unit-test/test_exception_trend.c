#ifndef exception_trend_TEST
#define exception_trend_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define exception_trend_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/exception_trend.h"
exception_trend_t *instantiate_exception_trend(int include_optional);



exception_trend_t *instantiate_exception_trend(int include_optional) {
	exception_trend_t *exception_trend = NULL;
	if(include_optional) {
		exception_trend = exception_trend_create(
			);
	} else {
		exception_trend = exception_trend_create(
			);
	}

	return exception_trend;
}


#ifdef exception_trend_MAIN

void test_exception_trend(int include_optional) {
	exception_trend_t *exception_trend_1 = instantiate_exception_trend(
		include_optional);

	cJSON *jsonexception_trend_1 = exception_trend_convertToJSON(
		exception_trend_1);
	printf("exception_trend :\n%s\n", cJSON_Print(jsonexception_trend_1));
	exception_trend_t *exception_trend_2 = exception_trend_parseFromJSON(
		jsonexception_trend_1);
	cJSON *jsonexception_trend_2 = exception_trend_convertToJSON(
		exception_trend_2);
	printf("repeating exception_trend:\n%s\n",
	       cJSON_Print(jsonexception_trend_2));
}

int main() {
	test_exception_trend(1);
	test_exception_trend(0);

	printf("Hello world \n");
	return 0;
}

#endif // exception_trend_MAIN
#endif // exception_trend_TEST
