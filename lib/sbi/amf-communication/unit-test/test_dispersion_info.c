#ifndef dispersion_info_TEST
#define dispersion_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dispersion_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dispersion_info.h"
dispersion_info_t *instantiate_dispersion_info(int include_optional);

#include "test_dispersion_type.c"


dispersion_info_t *instantiate_dispersion_info(int include_optional) {
	dispersion_info_t *dispersion_info = NULL;
	if(include_optional) {
		dispersion_info = dispersion_info_create(
			"2013-10-20T19:20:30+01:00",
			56,
			list_createList(),
			null
			);
	} else {
		dispersion_info = dispersion_info_create(
			"2013-10-20T19:20:30+01:00",
			56,
			list_createList(),
			null
			);
	}

	return dispersion_info;
}


#ifdef dispersion_info_MAIN

void test_dispersion_info(int include_optional) {
	dispersion_info_t *dispersion_info_1 = instantiate_dispersion_info(
		include_optional);

	cJSON *jsondispersion_info_1 = dispersion_info_convertToJSON(
		dispersion_info_1);
	printf("dispersion_info :\n%s\n", cJSON_Print(jsondispersion_info_1));
	dispersion_info_t *dispersion_info_2 = dispersion_info_parseFromJSON(
		jsondispersion_info_1);
	cJSON *jsondispersion_info_2 = dispersion_info_convertToJSON(
		dispersion_info_2);
	printf("repeating dispersion_info:\n%s\n",
	       cJSON_Print(jsondispersion_info_2));
}

int main() {
	test_dispersion_info(1);
	test_dispersion_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // dispersion_info_MAIN
#endif // dispersion_info_TEST
