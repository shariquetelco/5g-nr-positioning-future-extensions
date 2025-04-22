#ifndef up_connection_status_TEST
#define up_connection_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_connection_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_connection_status.h"
up_connection_status_t *instantiate_up_connection_status(int include_optional);



up_connection_status_t *instantiate_up_connection_status(int include_optional) {
	up_connection_status_t *up_connection_status = NULL;
	if(include_optional) {
		up_connection_status = up_connection_status_create(
			);
	} else {
		up_connection_status = up_connection_status_create(
			);
	}

	return up_connection_status;
}


#ifdef up_connection_status_MAIN

void test_up_connection_status(int include_optional) {
	up_connection_status_t *up_connection_status_1 =
		instantiate_up_connection_status(include_optional);

	cJSON *jsonup_connection_status_1 = up_connection_status_convertToJSON(
		up_connection_status_1);
	printf("up_connection_status :\n%s\n",
	       cJSON_Print(jsonup_connection_status_1));
	up_connection_status_t *up_connection_status_2 =
		up_connection_status_parseFromJSON(jsonup_connection_status_1);
	cJSON *jsonup_connection_status_2 = up_connection_status_convertToJSON(
		up_connection_status_2);
	printf("repeating up_connection_status:\n%s\n",
	       cJSON_Print(jsonup_connection_status_2));
}

int main() {
	test_up_connection_status(1);
	test_up_connection_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_connection_status_MAIN
#endif // up_connection_status_TEST
