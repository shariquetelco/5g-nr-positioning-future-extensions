#ifndef prev_sub_info_TEST
#define prev_sub_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define prev_sub_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/prev_sub_info.h"
prev_sub_info_t *instantiate_prev_sub_info(int include_optional);



prev_sub_info_t *instantiate_prev_sub_info(int include_optional) {
	prev_sub_info_t *prev_sub_info = NULL;
	if(include_optional) {
		prev_sub_info = prev_sub_info_create(
			"0",
			"0",
			"0",
			list_createList(),
			list_createList()
			);
	} else {
		prev_sub_info = prev_sub_info_create(
			"0",
			"0",
			"0",
			list_createList(),
			list_createList()
			);
	}

	return prev_sub_info;
}


#ifdef prev_sub_info_MAIN

void test_prev_sub_info(int include_optional) {
	prev_sub_info_t *prev_sub_info_1 = instantiate_prev_sub_info(
		include_optional);

	cJSON *jsonprev_sub_info_1 =
		prev_sub_info_convertToJSON(prev_sub_info_1);
	printf("prev_sub_info :\n%s\n", cJSON_Print(jsonprev_sub_info_1));
	prev_sub_info_t *prev_sub_info_2 = prev_sub_info_parseFromJSON(
		jsonprev_sub_info_1);
	cJSON *jsonprev_sub_info_2 =
		prev_sub_info_convertToJSON(prev_sub_info_2);
	printf("repeating prev_sub_info:\n%s\n", cJSON_Print(
		       jsonprev_sub_info_2));
}

int main() {
	test_prev_sub_info(1);
	test_prev_sub_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // prev_sub_info_MAIN
#endif // prev_sub_info_TEST
