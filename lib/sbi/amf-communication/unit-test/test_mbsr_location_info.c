#ifndef mbsr_location_info_TEST
#define mbsr_location_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mbsr_location_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mbsr_location_info.h"
mbsr_location_info_t *instantiate_mbsr_location_info(int include_optional);



mbsr_location_info_t *instantiate_mbsr_location_info(int include_optional) {
	mbsr_location_info_t *mbsr_location_info = NULL;
	if(include_optional) {
		mbsr_location_info = mbsr_location_info_create(
			list_createList(),
			list_createList()
			);
	} else {
		mbsr_location_info = mbsr_location_info_create(
			list_createList(),
			list_createList()
			);
	}

	return mbsr_location_info;
}


#ifdef mbsr_location_info_MAIN

void test_mbsr_location_info(int include_optional) {
	mbsr_location_info_t *mbsr_location_info_1 =
		instantiate_mbsr_location_info(include_optional);

	cJSON *jsonmbsr_location_info_1 = mbsr_location_info_convertToJSON(
		mbsr_location_info_1);
	printf("mbsr_location_info :\n%s\n",
	       cJSON_Print(jsonmbsr_location_info_1));
	mbsr_location_info_t *mbsr_location_info_2 =
		mbsr_location_info_parseFromJSON(jsonmbsr_location_info_1);
	cJSON *jsonmbsr_location_info_2 = mbsr_location_info_convertToJSON(
		mbsr_location_info_2);
	printf("repeating mbsr_location_info:\n%s\n",
	       cJSON_Print(jsonmbsr_location_info_2));
}

int main() {
	test_mbsr_location_info(1);
	test_mbsr_location_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // mbsr_location_info_MAIN
#endif // mbsr_location_info_TEST
