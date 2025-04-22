#ifndef data_volume_TEST
#define data_volume_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define data_volume_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/data_volume.h"
data_volume_t *instantiate_data_volume(int include_optional);



data_volume_t *instantiate_data_volume(int include_optional) {
	data_volume_t *data_volume = NULL;
	if(include_optional) {
		data_volume = data_volume_create(
			0,
			0
			);
	} else {
		data_volume = data_volume_create(
			0,
			0
			);
	}

	return data_volume;
}


#ifdef data_volume_MAIN

void test_data_volume(int include_optional) {
	data_volume_t *data_volume_1 =
		instantiate_data_volume(include_optional);

	cJSON *jsondata_volume_1 = data_volume_convertToJSON(data_volume_1);
	printf("data_volume :\n%s\n", cJSON_Print(jsondata_volume_1));
	data_volume_t *data_volume_2 = data_volume_parseFromJSON(
		jsondata_volume_1);
	cJSON *jsondata_volume_2 = data_volume_convertToJSON(data_volume_2);
	printf("repeating data_volume:\n%s\n", cJSON_Print(jsondata_volume_2));
}

int main() {
	test_data_volume(1);
	test_data_volume(0);

	printf("Hello world \n");
	return 0;
}

#endif // data_volume_MAIN
#endif // data_volume_TEST
