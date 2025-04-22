#ifndef uuaa_mm_status_TEST
#define uuaa_mm_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define uuaa_mm_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/uuaa_mm_status.h"
uuaa_mm_status_t *instantiate_uuaa_mm_status(int include_optional);



uuaa_mm_status_t *instantiate_uuaa_mm_status(int include_optional) {
	uuaa_mm_status_t *uuaa_mm_status = NULL;
	if(include_optional) {
		uuaa_mm_status = uuaa_mm_status_create(
			);
	} else {
		uuaa_mm_status = uuaa_mm_status_create(
			);
	}

	return uuaa_mm_status;
}


#ifdef uuaa_mm_status_MAIN

void test_uuaa_mm_status(int include_optional) {
	uuaa_mm_status_t *uuaa_mm_status_1 = instantiate_uuaa_mm_status(
		include_optional);

	cJSON *jsonuuaa_mm_status_1 = uuaa_mm_status_convertToJSON(
		uuaa_mm_status_1);
	printf("uuaa_mm_status :\n%s\n", cJSON_Print(jsonuuaa_mm_status_1));
	uuaa_mm_status_t *uuaa_mm_status_2 = uuaa_mm_status_parseFromJSON(
		jsonuuaa_mm_status_1);
	cJSON *jsonuuaa_mm_status_2 = uuaa_mm_status_convertToJSON(
		uuaa_mm_status_2);
	printf("repeating uuaa_mm_status:\n%s\n",
	       cJSON_Print(jsonuuaa_mm_status_2));
}

int main() {
	test_uuaa_mm_status(1);
	test_uuaa_mm_status(0);

	printf("Hello world \n");
	return 0;
}

#endif // uuaa_mm_status_MAIN
#endif // uuaa_mm_status_TEST
