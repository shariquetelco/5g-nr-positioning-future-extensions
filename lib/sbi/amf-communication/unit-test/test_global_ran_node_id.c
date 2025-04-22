#ifndef global_ran_node_id_TEST
#define global_ran_node_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define global_ran_node_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/global_ran_node_id.h"
global_ran_node_id_t *instantiate_global_ran_node_id(int include_optional);

#include "test_plmn_id.c"
#include "test_gnb_id.c"


global_ran_node_id_t *instantiate_global_ran_node_id(int include_optional) {
	global_ran_node_id_t *global_ran_node_id = NULL;
	if(include_optional) {
		global_ran_node_id = global_ran_node_id_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			// false, not to have infinite recursion
			instantiate_gnb_id(0),
			"SMacroNGeNB-34B89",
			"a",
			"a",
			"a",
			"a"
			);
	} else {
		global_ran_node_id = global_ran_node_id_create(
			NULL,
			"a",
			NULL,
			"SMacroNGeNB-34B89",
			"a",
			"a",
			"a",
			"a"
			);
	}

	return global_ran_node_id;
}


#ifdef global_ran_node_id_MAIN

void test_global_ran_node_id(int include_optional) {
	global_ran_node_id_t *global_ran_node_id_1 =
		instantiate_global_ran_node_id(include_optional);

	cJSON *jsonglobal_ran_node_id_1 = global_ran_node_id_convertToJSON(
		global_ran_node_id_1);
	printf("global_ran_node_id :\n%s\n",
	       cJSON_Print(jsonglobal_ran_node_id_1));
	global_ran_node_id_t *global_ran_node_id_2 =
		global_ran_node_id_parseFromJSON(jsonglobal_ran_node_id_1);
	cJSON *jsonglobal_ran_node_id_2 = global_ran_node_id_convertToJSON(
		global_ran_node_id_2);
	printf("repeating global_ran_node_id:\n%s\n",
	       cJSON_Print(jsonglobal_ran_node_id_2));
}

int main() {
	test_global_ran_node_id(1);
	test_global_ran_node_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // global_ran_node_id_MAIN
#endif // global_ran_node_id_TEST
