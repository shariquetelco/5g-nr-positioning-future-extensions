#ifndef accuracy_req_TEST
#define accuracy_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accuracy_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accuracy_req.h"
accuracy_req_t *instantiate_accuracy_req(int include_optional);

#include "test_time_window.c"


accuracy_req_t *instantiate_accuracy_req(int include_optional) {
	accuracy_req_t *accuracy_req = NULL;
	if(include_optional) {
		accuracy_req = accuracy_req_create(
			// false, not to have infinite recursion
			instantiate_time_window(0),
			56,
			0,
			0,
			1,
			56
			);
	} else {
		accuracy_req = accuracy_req_create(
			NULL,
			56,
			0,
			0,
			1,
			56
			);
	}

	return accuracy_req;
}


#ifdef accuracy_req_MAIN

void test_accuracy_req(int include_optional) {
	accuracy_req_t *accuracy_req_1 = instantiate_accuracy_req(
		include_optional);

	cJSON *jsonaccuracy_req_1 = accuracy_req_convertToJSON(accuracy_req_1);
	printf("accuracy_req :\n%s\n", cJSON_Print(jsonaccuracy_req_1));
	accuracy_req_t *accuracy_req_2 = accuracy_req_parseFromJSON(
		jsonaccuracy_req_1);
	cJSON *jsonaccuracy_req_2 = accuracy_req_convertToJSON(accuracy_req_2);
	printf("repeating accuracy_req:\n%s\n",
	       cJSON_Print(jsonaccuracy_req_2));
}

int main() {
	test_accuracy_req(1);
	test_accuracy_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // accuracy_req_MAIN
#endif // accuracy_req_TEST
