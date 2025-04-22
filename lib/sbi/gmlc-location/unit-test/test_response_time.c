#ifndef response_time_TEST
#define response_time_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_time_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_time.h"
response_time_t *instantiate_response_time(int include_optional);



response_time_t *instantiate_response_time(int include_optional) {
	response_time_t *response_time = NULL;
	if(include_optional) {
		response_time = response_time_create(
			);
	} else {
		response_time = response_time_create(
			);
	}

	return response_time;
}


#ifdef response_time_MAIN

void test_response_time(int include_optional) {
	response_time_t *response_time_1 = instantiate_response_time(
		include_optional);

	cJSON *jsonresponse_time_1 =
		response_time_convertToJSON(response_time_1);
	printf("response_time :\n%s\n", cJSON_Print(jsonresponse_time_1));
	response_time_t *response_time_2 = response_time_parseFromJSON(
		jsonresponse_time_1);
	cJSON *jsonresponse_time_2 =
		response_time_convertToJSON(response_time_2);
	printf("repeating response_time:\n%s\n", cJSON_Print(
		       jsonresponse_time_2));
}

int main() {
	test_response_time(1);
	test_response_time(0);

	printf("Hello world \n");
	return 0;
}

#endif // response_time_MAIN
#endif // response_time_TEST
