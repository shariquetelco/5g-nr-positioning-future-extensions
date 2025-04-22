#ifndef flow_direction_any_of_TEST
#define flow_direction_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flow_direction_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flow_direction_any_of.h"
flow_direction_any_of_t *instantiate_flow_direction_any_of(
	int include_optional);



flow_direction_any_of_t *instantiate_flow_direction_any_of(int include_optional)
{
	flow_direction_any_of_t *flow_direction_any_of = NULL;
	if(include_optional) {
		flow_direction_any_of = flow_direction_any_of_create(
			);
	} else {
		flow_direction_any_of = flow_direction_any_of_create(
			);
	}

	return flow_direction_any_of;
}


#ifdef flow_direction_any_of_MAIN

void test_flow_direction_any_of(int include_optional) {
	flow_direction_any_of_t *flow_direction_any_of_1 =
		instantiate_flow_direction_any_of(include_optional);

	cJSON *jsonflow_direction_any_of_1 =
		flow_direction_any_of_convertToJSON(flow_direction_any_of_1);
	printf("flow_direction_any_of :\n%s\n",
	       cJSON_Print(jsonflow_direction_any_of_1));
	flow_direction_any_of_t *flow_direction_any_of_2 =
		flow_direction_any_of_parseFromJSON(jsonflow_direction_any_of_1);
	cJSON *jsonflow_direction_any_of_2 =
		flow_direction_any_of_convertToJSON(flow_direction_any_of_2);
	printf("repeating flow_direction_any_of:\n%s\n",
	       cJSON_Print(jsonflow_direction_any_of_2));
}

int main() {
	test_flow_direction_any_of(1);
	test_flow_direction_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // flow_direction_any_of_MAIN
#endif // flow_direction_any_of_TEST
