#ifndef flow_direction_TEST
#define flow_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flow_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flow_direction.h"
flow_direction_t *instantiate_flow_direction(int include_optional);



flow_direction_t *instantiate_flow_direction(int include_optional) {
	flow_direction_t *flow_direction = NULL;
	if(include_optional) {
		flow_direction = flow_direction_create(
			);
	} else {
		flow_direction = flow_direction_create(
			);
	}

	return flow_direction;
}


#ifdef flow_direction_MAIN

void test_flow_direction(int include_optional) {
	flow_direction_t *flow_direction_1 = instantiate_flow_direction(
		include_optional);

	cJSON *jsonflow_direction_1 = flow_direction_convertToJSON(
		flow_direction_1);
	printf("flow_direction :\n%s\n", cJSON_Print(jsonflow_direction_1));
	flow_direction_t *flow_direction_2 = flow_direction_parseFromJSON(
		jsonflow_direction_1);
	cJSON *jsonflow_direction_2 = flow_direction_convertToJSON(
		flow_direction_2);
	printf("repeating flow_direction:\n%s\n",
	       cJSON_Print(jsonflow_direction_2));
}

int main() {
	test_flow_direction(1);
	test_flow_direction(0);

	printf("Hello world \n");
	return 0;
}

#endif // flow_direction_MAIN
#endif // flow_direction_TEST
