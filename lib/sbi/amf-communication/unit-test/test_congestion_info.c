#ifndef congestion_info_TEST
#define congestion_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define congestion_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/congestion_info.h"
congestion_info_t *instantiate_congestion_info(int include_optional);

#include "test_congestion_type.c"
#include "test_time_window.c"
#include "test_threshold_level.c"


congestion_info_t *instantiate_congestion_info(int include_optional) {
	congestion_info_t *congestion_info = NULL;
	if(include_optional) {
		congestion_info = congestion_info_create(
			null,
			// false, not to have infinite recursion
			instantiate_time_window(0),
			// false, not to have infinite recursion
			instantiate_threshold_level(0),
			0,
			list_createList(),
			list_createList()
			);
	} else {
		congestion_info = congestion_info_create(
			null,
			NULL,
			NULL,
			0,
			list_createList(),
			list_createList()
			);
	}

	return congestion_info;
}


#ifdef congestion_info_MAIN

void test_congestion_info(int include_optional) {
	congestion_info_t *congestion_info_1 = instantiate_congestion_info(
		include_optional);

	cJSON *jsoncongestion_info_1 = congestion_info_convertToJSON(
		congestion_info_1);
	printf("congestion_info :\n%s\n", cJSON_Print(jsoncongestion_info_1));
	congestion_info_t *congestion_info_2 = congestion_info_parseFromJSON(
		jsoncongestion_info_1);
	cJSON *jsoncongestion_info_2 = congestion_info_convertToJSON(
		congestion_info_2);
	printf("repeating congestion_info:\n%s\n",
	       cJSON_Print(jsoncongestion_info_2));
}

int main() {
	test_congestion_info(1);
	test_congestion_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // congestion_info_MAIN
#endif // congestion_info_TEST
