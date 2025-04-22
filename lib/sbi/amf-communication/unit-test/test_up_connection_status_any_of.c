#ifndef up_connection_status_any_of_TEST
#define up_connection_status_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_connection_status_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_connection_status_any_of.h"
up_connection_status_any_of_t *instantiate_up_connection_status_any_of(
	int include_optional);



up_connection_status_any_of_t *instantiate_up_connection_status_any_of(
	int include_optional) {
	up_connection_status_any_of_t *up_connection_status_any_of = NULL;
	if(include_optional) {
		up_connection_status_any_of =
			up_connection_status_any_of_create(
				);
	} else {
		up_connection_status_any_of =
			up_connection_status_any_of_create(
				);
	}

	return up_connection_status_any_of;
}


#ifdef up_connection_status_any_of_MAIN

void test_up_connection_status_any_of(int include_optional) {
	up_connection_status_any_of_t *up_connection_status_any_of_1 =
		instantiate_up_connection_status_any_of(include_optional);

	cJSON *jsonup_connection_status_any_of_1 =
		up_connection_status_any_of_convertToJSON(
			up_connection_status_any_of_1);
	printf("up_connection_status_any_of :\n%s\n",
	       cJSON_Print(jsonup_connection_status_any_of_1));
	up_connection_status_any_of_t *up_connection_status_any_of_2 =
		up_connection_status_any_of_parseFromJSON(
			jsonup_connection_status_any_of_1);
	cJSON *jsonup_connection_status_any_of_2 =
		up_connection_status_any_of_convertToJSON(
			up_connection_status_any_of_2);
	printf("repeating up_connection_status_any_of:\n%s\n",
	       cJSON_Print(jsonup_connection_status_any_of_2));
}

int main() {
	test_up_connection_status_any_of(1);
	test_up_connection_status_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_connection_status_any_of_MAIN
#endif // up_connection_status_any_of_TEST
