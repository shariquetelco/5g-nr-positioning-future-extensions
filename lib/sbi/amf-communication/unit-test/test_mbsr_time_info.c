#ifndef mbsr_time_info_TEST
#define mbsr_time_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mbsr_time_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mbsr_time_info.h"
mbsr_time_info_t *instantiate_mbsr_time_info(int include_optional);



mbsr_time_info_t *instantiate_mbsr_time_info(int include_optional) {
	mbsr_time_info_t *mbsr_time_info = NULL;
	if(include_optional) {
		mbsr_time_info = mbsr_time_info_create(
			list_createList(),
			list_createList()
			);
	} else {
		mbsr_time_info = mbsr_time_info_create(
			list_createList(),
			list_createList()
			);
	}

	return mbsr_time_info;
}


#ifdef mbsr_time_info_MAIN

void test_mbsr_time_info(int include_optional) {
	mbsr_time_info_t *mbsr_time_info_1 = instantiate_mbsr_time_info(
		include_optional);

	cJSON *jsonmbsr_time_info_1 = mbsr_time_info_convertToJSON(
		mbsr_time_info_1);
	printf("mbsr_time_info :\n%s\n", cJSON_Print(jsonmbsr_time_info_1));
	mbsr_time_info_t *mbsr_time_info_2 = mbsr_time_info_parseFromJSON(
		jsonmbsr_time_info_1);
	cJSON *jsonmbsr_time_info_2 = mbsr_time_info_convertToJSON(
		mbsr_time_info_2);
	printf("repeating mbsr_time_info:\n%s\n",
	       cJSON_Print(jsonmbsr_time_info_2));
}

int main() {
	test_mbsr_time_info(1);
	test_mbsr_time_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // mbsr_time_info_MAIN
#endif // mbsr_time_info_TEST
