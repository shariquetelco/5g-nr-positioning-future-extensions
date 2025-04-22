#ifndef status_change_TEST
#define status_change_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define status_change_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/status_change.h"
status_change_t *instantiate_status_change(int include_optional);



status_change_t *instantiate_status_change(int include_optional) {
	status_change_t *status_change = NULL;
	if(include_optional) {
		status_change = status_change_create(
			);
	} else {
		status_change = status_change_create(
			);
	}

	return status_change;
}


#ifdef status_change_MAIN

void test_status_change(int include_optional) {
	status_change_t *status_change_1 = instantiate_status_change(
		include_optional);

	cJSON *jsonstatus_change_1 =
		status_change_convertToJSON(status_change_1);
	printf("status_change :\n%s\n", cJSON_Print(jsonstatus_change_1));
	status_change_t *status_change_2 = status_change_parseFromJSON(
		jsonstatus_change_1);
	cJSON *jsonstatus_change_2 =
		status_change_convertToJSON(status_change_2);
	printf("repeating status_change:\n%s\n", cJSON_Print(
		       jsonstatus_change_2));
}

int main() {
	test_status_change(1);
	test_status_change(0);

	printf("Hello world \n");
	return 0;
}

#endif // status_change_MAIN
#endif // status_change_TEST
