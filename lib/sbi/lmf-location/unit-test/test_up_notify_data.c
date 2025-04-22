#ifndef up_notify_data_TEST
#define up_notify_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define up_notify_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/up_notify_data.h"
up_notify_data_t *instantiate_up_notify_data(int include_optional);



up_notify_data_t *instantiate_up_notify_data(int include_optional) {
	up_notify_data_t *up_notify_data = NULL;
	if(include_optional) {
		up_notify_data = up_notify_data_create(
			"0",
			lmf_location_up_notify_data__ESTABLISHED,
			"0"
			);
	} else {
		up_notify_data = up_notify_data_create(
			"0",
			lmf_location_up_notify_data__ESTABLISHED,
			"0"
			);
	}

	return up_notify_data;
}


#ifdef up_notify_data_MAIN

void test_up_notify_data(int include_optional) {
	up_notify_data_t *up_notify_data_1 = instantiate_up_notify_data(
		include_optional);

	cJSON *jsonup_notify_data_1 = up_notify_data_convertToJSON(
		up_notify_data_1);
	printf("up_notify_data :\n%s\n", cJSON_Print(jsonup_notify_data_1));
	up_notify_data_t *up_notify_data_2 = up_notify_data_parseFromJSON(
		jsonup_notify_data_1);
	cJSON *jsonup_notify_data_2 = up_notify_data_convertToJSON(
		up_notify_data_2);
	printf("repeating up_notify_data:\n%s\n",
	       cJSON_Print(jsonup_notify_data_2));
}

int main() {
	test_up_notify_data(1);
	test_up_notify_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // up_notify_data_MAIN
#endif // up_notify_data_TEST
