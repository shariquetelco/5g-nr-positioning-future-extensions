#ifndef tac_info_TEST
#define tac_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tac_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tac_info.h"
tac_info_t *instantiate_tac_info(int include_optional);



tac_info_t *instantiate_tac_info(int include_optional) {
	tac_info_t *tac_info = NULL;
	if(include_optional) {
		tac_info = tac_info_create(
			list_createList()
			);
	} else {
		tac_info = tac_info_create(
			list_createList()
			);
	}

	return tac_info;
}


#ifdef tac_info_MAIN

void test_tac_info(int include_optional) {
	tac_info_t *tac_info_1 = instantiate_tac_info(include_optional);

	cJSON *jsontac_info_1 = tac_info_convertToJSON(tac_info_1);
	printf("tac_info :\n%s\n", cJSON_Print(jsontac_info_1));
	tac_info_t *tac_info_2 = tac_info_parseFromJSON(jsontac_info_1);
	cJSON *jsontac_info_2 = tac_info_convertToJSON(tac_info_2);
	printf("repeating tac_info:\n%s\n", cJSON_Print(jsontac_info_2));
}

int main() {
	test_tac_info(1);
	test_tac_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // tac_info_MAIN
#endif // tac_info_TEST
