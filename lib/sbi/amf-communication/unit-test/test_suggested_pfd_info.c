#ifndef suggested_pfd_info_TEST
#define suggested_pfd_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define suggested_pfd_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/suggested_pfd_info.h"
suggested_pfd_info_t *instantiate_suggested_pfd_info(int include_optional);

#include "test_domain_name_protocol.c"


suggested_pfd_info_t *instantiate_suggested_pfd_info(int include_optional) {
	suggested_pfd_info_t *suggested_pfd_info = NULL;
	if(include_optional) {
		suggested_pfd_info = suggested_pfd_info_create(
			"0",
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			0
			);
	} else {
		suggested_pfd_info = suggested_pfd_info_create(
			"0",
			list_createList(),
			list_createList(),
			list_createList(),
			null,
			0
			);
	}

	return suggested_pfd_info;
}


#ifdef suggested_pfd_info_MAIN

void test_suggested_pfd_info(int include_optional) {
	suggested_pfd_info_t *suggested_pfd_info_1 =
		instantiate_suggested_pfd_info(include_optional);

	cJSON *jsonsuggested_pfd_info_1 = suggested_pfd_info_convertToJSON(
		suggested_pfd_info_1);
	printf("suggested_pfd_info :\n%s\n",
	       cJSON_Print(jsonsuggested_pfd_info_1));
	suggested_pfd_info_t *suggested_pfd_info_2 =
		suggested_pfd_info_parseFromJSON(jsonsuggested_pfd_info_1);
	cJSON *jsonsuggested_pfd_info_2 = suggested_pfd_info_convertToJSON(
		suggested_pfd_info_2);
	printf("repeating suggested_pfd_info:\n%s\n",
	       cJSON_Print(jsonsuggested_pfd_info_2));
}

int main() {
	test_suggested_pfd_info(1);
	test_suggested_pfd_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // suggested_pfd_info_MAIN
#endif // suggested_pfd_info_TEST
