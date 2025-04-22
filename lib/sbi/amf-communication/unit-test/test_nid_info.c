#ifndef nid_info_TEST
#define nid_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nid_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nid_info.h"
nid_info_t *instantiate_nid_info(int include_optional);



nid_info_t *instantiate_nid_info(int include_optional) {
	nid_info_t *nid_info = NULL;
	if(include_optional) {
		nid_info = nid_info_create(
			list_createList()
			);
	} else {
		nid_info = nid_info_create(
			list_createList()
			);
	}

	return nid_info;
}


#ifdef nid_info_MAIN

void test_nid_info(int include_optional) {
	nid_info_t *nid_info_1 = instantiate_nid_info(include_optional);

	cJSON *jsonnid_info_1 = nid_info_convertToJSON(nid_info_1);
	printf("nid_info :\n%s\n", cJSON_Print(jsonnid_info_1));
	nid_info_t *nid_info_2 = nid_info_parseFromJSON(jsonnid_info_1);
	cJSON *jsonnid_info_2 = nid_info_convertToJSON(nid_info_2);
	printf("repeating nid_info:\n%s\n", cJSON_Print(jsonnid_info_2));
}

int main() {
	test_nid_info(1);
	test_nid_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // nid_info_MAIN
#endif // nid_info_TEST
