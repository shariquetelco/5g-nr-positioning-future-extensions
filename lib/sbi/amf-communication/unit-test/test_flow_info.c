#ifndef flow_info_TEST
#define flow_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flow_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flow_info.h"
flow_info_t *instantiate_flow_info(int include_optional);



flow_info_t *instantiate_flow_info(int include_optional) {
	flow_info_t *flow_info = NULL;
	if(include_optional) {
		flow_info = flow_info_create(
			56,
			list_createList(),
			"0"
			);
	} else {
		flow_info = flow_info_create(
			56,
			list_createList(),
			"0"
			);
	}

	return flow_info;
}


#ifdef flow_info_MAIN

void test_flow_info(int include_optional) {
	flow_info_t *flow_info_1 = instantiate_flow_info(include_optional);

	cJSON *jsonflow_info_1 = flow_info_convertToJSON(flow_info_1);
	printf("flow_info :\n%s\n", cJSON_Print(jsonflow_info_1));
	flow_info_t *flow_info_2 = flow_info_parseFromJSON(jsonflow_info_1);
	cJSON *jsonflow_info_2 = flow_info_convertToJSON(flow_info_2);
	printf("repeating flow_info:\n%s\n", cJSON_Print(jsonflow_info_2));
}

int main() {
	test_flow_info(1);
	test_flow_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // flow_info_MAIN
#endif // flow_info_TEST
