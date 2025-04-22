#ifndef roaming_info_TEST
#define roaming_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define roaming_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/roaming_info.h"
roaming_info_t *instantiate_roaming_info(int include_optional);

#include "test_plmn_id_nid.c"


roaming_info_t *instantiate_roaming_info(int include_optional) {
	roaming_info_t *roaming_info = NULL;
	if(include_optional) {
		roaming_info = roaming_info_create(
			// false, not to have infinite recursion
			instantiate_plmn_id_nid(0),
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		roaming_info = roaming_info_create(
			NULL,
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return roaming_info;
}


#ifdef roaming_info_MAIN

void test_roaming_info(int include_optional) {
	roaming_info_t *roaming_info_1 = instantiate_roaming_info(
		include_optional);

	cJSON *jsonroaming_info_1 = roaming_info_convertToJSON(roaming_info_1);
	printf("roaming_info :\n%s\n", cJSON_Print(jsonroaming_info_1));
	roaming_info_t *roaming_info_2 = roaming_info_parseFromJSON(
		jsonroaming_info_1);
	cJSON *jsonroaming_info_2 = roaming_info_convertToJSON(roaming_info_2);
	printf("repeating roaming_info:\n%s\n",
	       cJSON_Print(jsonroaming_info_2));
}

int main() {
	test_roaming_info(1);
	test_roaming_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // roaming_info_MAIN
#endif // roaming_info_TEST
