#ifndef ng_ran_target_id_TEST
#define ng_ran_target_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ng_ran_target_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ng_ran_target_id.h"
ng_ran_target_id_t *instantiate_ng_ran_target_id(int include_optional);

#include "test_global_ran_node_id.c"
#include "test_tai.c"


ng_ran_target_id_t *instantiate_ng_ran_target_id(int include_optional) {
	ng_ran_target_id_t *ng_ran_target_id = NULL;
	if(include_optional) {
		ng_ran_target_id = ng_ran_target_id_create(
			// false, not to have infinite recursion
			instantiate_global_ran_node_id(0),
			// false, not to have infinite recursion
			instantiate_tai(0)
			);
	} else {
		ng_ran_target_id = ng_ran_target_id_create(
			NULL,
			NULL
			);
	}

	return ng_ran_target_id;
}


#ifdef ng_ran_target_id_MAIN

void test_ng_ran_target_id(int include_optional) {
	ng_ran_target_id_t *ng_ran_target_id_1 = instantiate_ng_ran_target_id(
		include_optional);

	cJSON *jsonng_ran_target_id_1 = ng_ran_target_id_convertToJSON(
		ng_ran_target_id_1);
	printf("ng_ran_target_id :\n%s\n", cJSON_Print(jsonng_ran_target_id_1));
	ng_ran_target_id_t *ng_ran_target_id_2 = ng_ran_target_id_parseFromJSON(
		jsonng_ran_target_id_1);
	cJSON *jsonng_ran_target_id_2 = ng_ran_target_id_convertToJSON(
		ng_ran_target_id_2);
	printf("repeating ng_ran_target_id:\n%s\n",
	       cJSON_Print(jsonng_ran_target_id_2));
}

int main() {
	test_ng_ran_target_id(1);
	test_ng_ran_target_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // ng_ran_target_id_MAIN
#endif // ng_ran_target_id_TEST
