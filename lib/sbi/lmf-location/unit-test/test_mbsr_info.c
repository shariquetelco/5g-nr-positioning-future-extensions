#ifndef mbsr_info_TEST
#define mbsr_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mbsr_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mbsr_info.h"
mbsr_info_t *instantiate_mbsr_info(int include_optional);

#include "test_ncgi.c"
#include "test_ecgi.c"


mbsr_info_t *instantiate_mbsr_info(int include_optional) {
	mbsr_info_t *mbsr_info = NULL;
	if(include_optional) {
		mbsr_info = mbsr_info_create(
			// false, not to have infinite recursion
			instantiate_ncgi(0),
			// false, not to have infinite recursion
			instantiate_ecgi(0)
			);
	} else {
		mbsr_info = mbsr_info_create(
			NULL,
			NULL
			);
	}

	return mbsr_info;
}


#ifdef mbsr_info_MAIN

void test_mbsr_info(int include_optional) {
	mbsr_info_t *mbsr_info_1 = instantiate_mbsr_info(include_optional);

	cJSON *jsonmbsr_info_1 = mbsr_info_convertToJSON(mbsr_info_1);
	printf("mbsr_info :\n%s\n", cJSON_Print(jsonmbsr_info_1));
	mbsr_info_t *mbsr_info_2 = mbsr_info_parseFromJSON(jsonmbsr_info_1);
	cJSON *jsonmbsr_info_2 = mbsr_info_convertToJSON(mbsr_info_2);
	printf("repeating mbsr_info:\n%s\n", cJSON_Print(jsonmbsr_info_2));
}

int main() {
	test_mbsr_info(1);
	test_mbsr_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // mbsr_info_MAIN
#endif // mbsr_info_TEST
