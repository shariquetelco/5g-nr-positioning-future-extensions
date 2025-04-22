#ifndef redirect_response_TEST
#define redirect_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define redirect_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/redirect_response.h"
redirect_response_t *instantiate_redirect_response(int include_optional);



redirect_response_t *instantiate_redirect_response(int include_optional) {
	redirect_response_t *redirect_response = NULL;
	if(include_optional) {
		redirect_response = redirect_response_create(
			"0",
			"0",
			"0"
			);
	} else {
		redirect_response = redirect_response_create(
			"0",
			"0",
			"0"
			);
	}

	return redirect_response;
}


#ifdef redirect_response_MAIN

void test_redirect_response(int include_optional) {
	redirect_response_t *redirect_response_1 =
		instantiate_redirect_response(include_optional);

	cJSON *jsonredirect_response_1 = redirect_response_convertToJSON(
		redirect_response_1);
	printf("redirect_response :\n%s\n",
	       cJSON_Print(jsonredirect_response_1));
	redirect_response_t *redirect_response_2 =
		redirect_response_parseFromJSON(jsonredirect_response_1);
	cJSON *jsonredirect_response_2 = redirect_response_convertToJSON(
		redirect_response_2);
	printf("repeating redirect_response:\n%s\n",
	       cJSON_Print(jsonredirect_response_2));
}

int main() {
	test_redirect_response(1);
	test_redirect_response(0);

	printf("Hello world \n");
	return 0;
}

#endif // redirect_response_MAIN
#endif // redirect_response_TEST
