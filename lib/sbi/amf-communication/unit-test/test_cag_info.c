#ifndef cag_info_TEST
#define cag_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cag_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cag_info.h"
cag_info_t *instantiate_cag_info(int include_optional);



cag_info_t *instantiate_cag_info(int include_optional) {
	cag_info_t *cag_info = NULL;
	if(include_optional) {
		cag_info = cag_info_create(
			list_createList(),
			1
			);
	} else {
		cag_info = cag_info_create(
			list_createList(),
			1
			);
	}

	return cag_info;
}


#ifdef cag_info_MAIN

void test_cag_info(int include_optional) {
	cag_info_t *cag_info_1 = instantiate_cag_info(include_optional);

	cJSON *jsoncag_info_1 = cag_info_convertToJSON(cag_info_1);
	printf("cag_info :\n%s\n", cJSON_Print(jsoncag_info_1));
	cag_info_t *cag_info_2 = cag_info_parseFromJSON(jsoncag_info_1);
	cJSON *jsoncag_info_2 = cag_info_convertToJSON(cag_info_2);
	printf("repeating cag_info:\n%s\n", cJSON_Print(jsoncag_info_2));
}

int main() {
	test_cag_info(1);
	test_cag_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // cag_info_MAIN
#endif // cag_info_TEST
