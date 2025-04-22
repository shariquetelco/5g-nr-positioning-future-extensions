#ifndef data_volume_transfer_time_TEST
#define data_volume_transfer_time_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define data_volume_transfer_time_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/data_volume_transfer_time.h"
data_volume_transfer_time_t *instantiate_data_volume_transfer_time(
	int include_optional);



data_volume_transfer_time_t *instantiate_data_volume_transfer_time(
	int include_optional) {
	data_volume_transfer_time_t *data_volume_transfer_time = NULL;
	if(include_optional) {
		data_volume_transfer_time = data_volume_transfer_time_create(
			0,
			0,
			1.337,
			0,
			0,
			1.337
			);
	} else {
		data_volume_transfer_time = data_volume_transfer_time_create(
			0,
			0,
			1.337,
			0,
			0,
			1.337
			);
	}

	return data_volume_transfer_time;
}


#ifdef data_volume_transfer_time_MAIN

void test_data_volume_transfer_time(int include_optional) {
	data_volume_transfer_time_t *data_volume_transfer_time_1 =
		instantiate_data_volume_transfer_time(include_optional);

	cJSON *jsondata_volume_transfer_time_1 =
		data_volume_transfer_time_convertToJSON(
			data_volume_transfer_time_1);
	printf("data_volume_transfer_time :\n%s\n",
	       cJSON_Print(jsondata_volume_transfer_time_1));
	data_volume_transfer_time_t *data_volume_transfer_time_2 =
		data_volume_transfer_time_parseFromJSON(
			jsondata_volume_transfer_time_1);
	cJSON *jsondata_volume_transfer_time_2 =
		data_volume_transfer_time_convertToJSON(
			data_volume_transfer_time_2);
	printf("repeating data_volume_transfer_time:\n%s\n",
	       cJSON_Print(jsondata_volume_transfer_time_2));
}

int main() {
	test_data_volume_transfer_time(1);
	test_data_volume_transfer_time(0);

	printf("Hello world \n");
	return 0;
}

#endif // data_volume_transfer_time_MAIN
#endif // data_volume_transfer_time_TEST
