#ifndef ladn_info_TEST
#define ladn_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ladn_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ladn_info.h"
ladn_info_t *instantiate_ladn_info(int include_optional);

#include "test_presence_state.c"


ladn_info_t *instantiate_ladn_info(int include_optional) {
	ladn_info_t *ladn_info = NULL;
	if(include_optional) {
		ladn_info = ladn_info_create(
			"0",
			null
			);
	} else {
		ladn_info = ladn_info_create(
			"0",
			null
			);
	}

	return ladn_info;
}


#ifdef ladn_info_MAIN

void test_ladn_info(int include_optional) {
	ladn_info_t *ladn_info_1 = instantiate_ladn_info(include_optional);

	cJSON *jsonladn_info_1 = ladn_info_convertToJSON(ladn_info_1);
	printf("ladn_info :\n%s\n", cJSON_Print(jsonladn_info_1));
	ladn_info_t *ladn_info_2 = ladn_info_parseFromJSON(jsonladn_info_1);
	cJSON *jsonladn_info_2 = ladn_info_convertToJSON(ladn_info_2);
	printf("repeating ladn_info:\n%s\n", cJSON_Print(jsonladn_info_2));
}

int main() {
	test_ladn_info(1);
	test_ladn_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // ladn_info_MAIN
#endif // ladn_info_TEST
