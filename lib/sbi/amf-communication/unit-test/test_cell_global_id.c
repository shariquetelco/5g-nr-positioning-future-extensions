#ifndef cell_global_id_TEST
#define cell_global_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cell_global_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cell_global_id.h"
cell_global_id_t *instantiate_cell_global_id(int include_optional);

#include "test_plmn_id.c"


cell_global_id_t *instantiate_cell_global_id(int include_optional) {
	cell_global_id_t *cell_global_id = NULL;
	if(include_optional) {
		cell_global_id = cell_global_id_create(
			// false, not to have infinite recursion
			instantiate_plmn_id(0),
			"a",
			"a"
			);
	} else {
		cell_global_id = cell_global_id_create(
			NULL,
			"a",
			"a"
			);
	}

	return cell_global_id;
}


#ifdef cell_global_id_MAIN

void test_cell_global_id(int include_optional) {
	cell_global_id_t *cell_global_id_1 = instantiate_cell_global_id(
		include_optional);

	cJSON *jsoncell_global_id_1 = cell_global_id_convertToJSON(
		cell_global_id_1);
	printf("cell_global_id :\n%s\n", cJSON_Print(jsoncell_global_id_1));
	cell_global_id_t *cell_global_id_2 = cell_global_id_parseFromJSON(
		jsoncell_global_id_1);
	cJSON *jsoncell_global_id_2 = cell_global_id_convertToJSON(
		cell_global_id_2);
	printf("repeating cell_global_id:\n%s\n",
	       cJSON_Print(jsoncell_global_id_2));
}

int main() {
	test_cell_global_id(1);
	test_cell_global_id(0);

	printf("Hello world \n");
	return 0;
}

#endif // cell_global_id_MAIN
#endif // cell_global_id_TEST
