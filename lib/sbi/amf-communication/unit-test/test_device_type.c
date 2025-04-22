#ifndef device_type_TEST
#define device_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define device_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/device_type.h"
device_type_t *instantiate_device_type(int include_optional);



device_type_t *instantiate_device_type(int include_optional) {
	device_type_t *device_type = NULL;
	if(include_optional) {
		device_type = device_type_create(
			);
	} else {
		device_type = device_type_create(
			);
	}

	return device_type;
}


#ifdef device_type_MAIN

void test_device_type(int include_optional) {
	device_type_t *device_type_1 =
		instantiate_device_type(include_optional);

	cJSON *jsondevice_type_1 = device_type_convertToJSON(device_type_1);
	printf("device_type :\n%s\n", cJSON_Print(jsondevice_type_1));
	device_type_t *device_type_2 = device_type_parseFromJSON(
		jsondevice_type_1);
	cJSON *jsondevice_type_2 = device_type_convertToJSON(device_type_2);
	printf("repeating device_type:\n%s\n", cJSON_Print(jsondevice_type_2));
}

int main() {
	test_device_type(1);
	test_device_type(0);

	printf("Hello world \n");
	return 0;
}

#endif // device_type_MAIN
#endif // device_type_TEST
