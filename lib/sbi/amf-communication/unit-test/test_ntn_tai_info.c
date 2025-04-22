#ifndef ntn_tai_info_TEST
#define ntn_tai_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ntn_tai_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ntn_tai_info.h"
ntn_tai_info_t *instantiate_ntn_tai_info(int include_optional);

#include "test_plmn_id_nid.c"


ntn_tai_info_t *instantiate_ntn_tai_info(int include_optional) {
	ntn_tai_info_t *ntn_tai_info = NULL;
	if(include_optional) {
		ntn_tai_info = ntn_tai_info_create(
			// false, not to have infinite recursion
			instantiate_plmn_id_nid(0),
			list_createList(),
			"a"
			);
	} else {
		ntn_tai_info = ntn_tai_info_create(
			NULL,
			list_createList(),
			"a"
			);
	}

	return ntn_tai_info;
}


#ifdef ntn_tai_info_MAIN

void test_ntn_tai_info(int include_optional) {
	ntn_tai_info_t *ntn_tai_info_1 = instantiate_ntn_tai_info(
		include_optional);

	cJSON *jsonntn_tai_info_1 = ntn_tai_info_convertToJSON(ntn_tai_info_1);
	printf("ntn_tai_info :\n%s\n", cJSON_Print(jsonntn_tai_info_1));
	ntn_tai_info_t *ntn_tai_info_2 = ntn_tai_info_parseFromJSON(
		jsonntn_tai_info_1);
	cJSON *jsonntn_tai_info_2 = ntn_tai_info_convertToJSON(ntn_tai_info_2);
	printf("repeating ntn_tai_info:\n%s\n",
	       cJSON_Print(jsonntn_tai_info_2));
}

int main() {
	test_ntn_tai_info(1);
	test_ntn_tai_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // ntn_tai_info_MAIN
#endif // ntn_tai_info_TEST
