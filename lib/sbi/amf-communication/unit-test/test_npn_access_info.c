#ifndef npn_access_info_TEST
#define npn_access_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define npn_access_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/npn_access_info.h"
npn_access_info_t *instantiate_npn_access_info(int include_optional);



npn_access_info_t *instantiate_npn_access_info(int include_optional) {
	npn_access_info_t *npn_access_info = NULL;
	if(include_optional) {
		npn_access_info = npn_access_info_create(
			list_createList()
			);
	} else {
		npn_access_info = npn_access_info_create(
			list_createList()
			);
	}

	return npn_access_info;
}


#ifdef npn_access_info_MAIN

void test_npn_access_info(int include_optional) {
	npn_access_info_t *npn_access_info_1 = instantiate_npn_access_info(
		include_optional);

	cJSON *jsonnpn_access_info_1 = npn_access_info_convertToJSON(
		npn_access_info_1);
	printf("npn_access_info :\n%s\n", cJSON_Print(jsonnpn_access_info_1));
	npn_access_info_t *npn_access_info_2 = npn_access_info_parseFromJSON(
		jsonnpn_access_info_1);
	cJSON *jsonnpn_access_info_2 = npn_access_info_convertToJSON(
		npn_access_info_2);
	printf("repeating npn_access_info:\n%s\n",
	       cJSON_Print(jsonnpn_access_info_2));
}

int main() {
	test_npn_access_info(1);
	test_npn_access_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // npn_access_info_MAIN
#endif // npn_access_info_TEST
