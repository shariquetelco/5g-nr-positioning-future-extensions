#ifndef cancel_loc_data_TEST
#define cancel_loc_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cancel_loc_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cancel_loc_data.h"
cancel_loc_data_t *instantiate_cancel_loc_data(int include_optional);



cancel_loc_data_t *instantiate_cancel_loc_data(int include_optional) {
	cancel_loc_data_t *cancel_loc_data = NULL;
	if(include_optional) {
		cancel_loc_data = cancel_loc_data_create(
			"a",
			"a",
			"a",
			"a",
			"0",
			"01",
			"0",
			"a"
			);
	} else {
		cancel_loc_data = cancel_loc_data_create(
			"a",
			"a",
			"a",
			"a",
			"0",
			"01",
			"0",
			"a"
			);
	}

	return cancel_loc_data;
}


#ifdef cancel_loc_data_MAIN

void test_cancel_loc_data(int include_optional) {
	cancel_loc_data_t *cancel_loc_data_1 = instantiate_cancel_loc_data(
		include_optional);

	cJSON *jsoncancel_loc_data_1 = cancel_loc_data_convertToJSON(
		cancel_loc_data_1);
	printf("cancel_loc_data :\n%s\n", cJSON_Print(jsoncancel_loc_data_1));
	cancel_loc_data_t *cancel_loc_data_2 = cancel_loc_data_parseFromJSON(
		jsoncancel_loc_data_1);
	cJSON *jsoncancel_loc_data_2 = cancel_loc_data_convertToJSON(
		cancel_loc_data_2);
	printf("repeating cancel_loc_data:\n%s\n",
	       cJSON_Print(jsoncancel_loc_data_2));
}

int main() {
	test_cancel_loc_data(1);
	test_cancel_loc_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // cancel_loc_data_MAIN
#endif // cancel_loc_data_TEST
