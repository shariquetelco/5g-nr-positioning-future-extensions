#ifndef data_availability_TEST
#define data_availability_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define data_availability_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/data_availability.h"
data_availability_t *instantiate_data_availability(int include_optional);



data_availability_t *instantiate_data_availability(int include_optional) {
	data_availability_t *data_availability = NULL;
	if(include_optional) {
		data_availability = data_availability_create(
			);
	} else {
		data_availability = data_availability_create(
			);
	}

	return data_availability;
}


#ifdef data_availability_MAIN

void test_data_availability(int include_optional) {
	data_availability_t *data_availability_1 =
		instantiate_data_availability(include_optional);

	cJSON *jsondata_availability_1 = data_availability_convertToJSON(
		data_availability_1);
	printf("data_availability :\n%s\n",
	       cJSON_Print(jsondata_availability_1));
	data_availability_t *data_availability_2 =
		data_availability_parseFromJSON(jsondata_availability_1);
	cJSON *jsondata_availability_2 = data_availability_convertToJSON(
		data_availability_2);
	printf("repeating data_availability:\n%s\n",
	       cJSON_Print(jsondata_availability_2));
}

int main() {
	test_data_availability(1);
	test_data_availability(0);

	printf("Hello world \n");
	return 0;
}

#endif // data_availability_MAIN
#endif // data_availability_TEST
