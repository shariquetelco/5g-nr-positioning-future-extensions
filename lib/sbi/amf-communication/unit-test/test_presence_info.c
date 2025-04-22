#ifndef presence_info_TEST
#define presence_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define presence_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/presence_info.h"
presence_info_t *instantiate_presence_info(int include_optional);

#include "test_presence_state.c"


presence_info_t *instantiate_presence_info(int include_optional) {
	presence_info_t *presence_info = NULL;
	if(include_optional) {
		presence_info = presence_info_create(
			"0",
			"0",
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	} else {
		presence_info = presence_info_create(
			"0",
			"0",
			null,
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList(),
			list_createList()
			);
	}

	return presence_info;
}


#ifdef presence_info_MAIN

void test_presence_info(int include_optional) {
	presence_info_t *presence_info_1 = instantiate_presence_info(
		include_optional);

	cJSON *jsonpresence_info_1 =
		presence_info_convertToJSON(presence_info_1);
	printf("presence_info :\n%s\n", cJSON_Print(jsonpresence_info_1));
	presence_info_t *presence_info_2 = presence_info_parseFromJSON(
		jsonpresence_info_1);
	cJSON *jsonpresence_info_2 =
		presence_info_convertToJSON(presence_info_2);
	printf("repeating presence_info:\n%s\n", cJSON_Print(
		       jsonpresence_info_2));
}

int main() {
	test_presence_info(1);
	test_presence_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // presence_info_MAIN
#endif // presence_info_TEST
