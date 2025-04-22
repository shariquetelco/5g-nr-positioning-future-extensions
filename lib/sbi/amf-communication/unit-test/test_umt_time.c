#ifndef umt_time_TEST
#define umt_time_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define umt_time_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/umt_time.h"
umt_time_t *instantiate_umt_time(int include_optional);



umt_time_t *instantiate_umt_time(int include_optional) {
	umt_time_t *umt_time = NULL;
	if(include_optional) {
		umt_time = umt_time_create(
			"0",
			1
			);
	} else {
		umt_time = umt_time_create(
			"0",
			1
			);
	}

	return umt_time;
}


#ifdef umt_time_MAIN

void test_umt_time(int include_optional) {
	umt_time_t *umt_time_1 = instantiate_umt_time(include_optional);

	cJSON *jsonumt_time_1 = umt_time_convertToJSON(umt_time_1);
	printf("umt_time :\n%s\n", cJSON_Print(jsonumt_time_1));
	umt_time_t *umt_time_2 = umt_time_parseFromJSON(jsonumt_time_1);
	cJSON *jsonumt_time_2 = umt_time_convertToJSON(umt_time_2);
	printf("repeating umt_time:\n%s\n", cJSON_Print(jsonumt_time_2));
}

int main() {
	test_umt_time(1);
	test_umt_time(0);

	printf("Hello world \n");
	return 0;
}

#endif // umt_time_MAIN
#endif // umt_time_TEST
