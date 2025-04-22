#ifndef device_type_any_of_TEST
#define device_type_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define device_type_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/device_type_any_of.h"
device_type_any_of_t *instantiate_device_type_any_of(int include_optional);



device_type_any_of_t *instantiate_device_type_any_of(int include_optional) {
	device_type_any_of_t *device_type_any_of = NULL;
	if(include_optional) {
		device_type_any_of = device_type_any_of_create(
			);
	} else {
		device_type_any_of = device_type_any_of_create(
			);
	}

	return device_type_any_of;
}


#ifdef device_type_any_of_MAIN

void test_device_type_any_of(int include_optional) {
	device_type_any_of_t *device_type_any_of_1 =
		instantiate_device_type_any_of(include_optional);

	cJSON *jsondevice_type_any_of_1 = device_type_any_of_convertToJSON(
		device_type_any_of_1);
	printf("device_type_any_of :\n%s\n",
	       cJSON_Print(jsondevice_type_any_of_1));
	device_type_any_of_t *device_type_any_of_2 =
		device_type_any_of_parseFromJSON(jsondevice_type_any_of_1);
	cJSON *jsondevice_type_any_of_2 = device_type_any_of_convertToJSON(
		device_type_any_of_2);
	printf("repeating device_type_any_of:\n%s\n",
	       cJSON_Print(jsondevice_type_any_of_2));
}

int main() {
	test_device_type_any_of(1);
	test_device_type_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // device_type_any_of_MAIN
#endif // device_type_any_of_TEST
