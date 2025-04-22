#ifndef cag_info_1_TEST
#define cag_info_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cag_info_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cag_info_1.h"
cag_info_1_t *instantiate_cag_info_1(int include_optional);



cag_info_1_t *instantiate_cag_info_1(int include_optional) {
	cag_info_1_t *cag_info_1 = NULL;
	if(include_optional) {
		cag_info_1 = cag_info_1_create(
			list_createList()
			);
	} else {
		cag_info_1 = cag_info_1_create(
			list_createList()
			);
	}

	return cag_info_1;
}


#ifdef cag_info_1_MAIN

void test_cag_info_1(int include_optional) {
	cag_info_1_t *cag_info_1_1 = instantiate_cag_info_1(include_optional);

	cJSON *jsoncag_info_1_1 = cag_info_1_convertToJSON(cag_info_1_1);
	printf("cag_info_1 :\n%s\n", cJSON_Print(jsoncag_info_1_1));
	cag_info_1_t *cag_info_1_2 = cag_info_1_parseFromJSON(jsoncag_info_1_1);
	cJSON *jsoncag_info_1_2 = cag_info_1_convertToJSON(cag_info_1_2);
	printf("repeating cag_info_1:\n%s\n", cJSON_Print(jsoncag_info_1_2));
}

int main() {
	test_cag_info_1(1);
	test_cag_info_1(0);

	printf("Hello world \n");
	return 0;
}

#endif // cag_info_1_MAIN
#endif // cag_info_1_TEST
