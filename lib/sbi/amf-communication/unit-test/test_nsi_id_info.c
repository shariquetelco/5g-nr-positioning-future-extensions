#ifndef nsi_id_info_TEST
#define nsi_id_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nsi_id_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nsi_id_info.h"
nsi_id_info_t *instantiate_nsi_id_info(int include_optional);

#include "test_snssai.c"


nsi_id_info_t *instantiate_nsi_id_info(int include_optional) {
	nsi_id_info_t *nsi_id_info = NULL;
	if(include_optional) {
		nsi_id_info = nsi_id_info_create(
			// false, not to have infinite recursion
			instantiate_snssai(0),
			list_createList()
			);
	} else {
		nsi_id_info = nsi_id_info_create(
			NULL,
			list_createList()
			);
	}

	return nsi_id_info;
}


#ifdef nsi_id_info_MAIN

void test_nsi_id_info(int include_optional) {
	nsi_id_info_t *nsi_id_info_1 =
		instantiate_nsi_id_info(include_optional);

	cJSON *jsonnsi_id_info_1 = nsi_id_info_convertToJSON(nsi_id_info_1);
	printf("nsi_id_info :\n%s\n", cJSON_Print(jsonnsi_id_info_1));
	nsi_id_info_t *nsi_id_info_2 = nsi_id_info_parseFromJSON(
		jsonnsi_id_info_1);
	cJSON *jsonnsi_id_info_2 = nsi_id_info_convertToJSON(nsi_id_info_2);
	printf("repeating nsi_id_info:\n%s\n", cJSON_Print(jsonnsi_id_info_2));
}

int main() {
	test_nsi_id_info(1);
	test_nsi_id_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // nsi_id_info_MAIN
#endif // nsi_id_info_TEST
