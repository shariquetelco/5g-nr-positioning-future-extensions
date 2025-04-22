#ifndef assign_ebi_data_TEST
#define assign_ebi_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assign_ebi_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assign_ebi_data.h"
assign_ebi_data_t *instantiate_assign_ebi_data(int include_optional);

#include "test_guami.c"


assign_ebi_data_t *instantiate_assign_ebi_data(int include_optional) {
	assign_ebi_data_t *assign_ebi_data = NULL;
	if(include_optional) {
		assign_ebi_data = assign_ebi_data_create(
			0,
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_guami(0),
			list_createList()
			);
	} else {
		assign_ebi_data = assign_ebi_data_create(
			0,
			list_createList(),
			list_createList(),
			NULL,
			list_createList()
			);
	}

	return assign_ebi_data;
}


#ifdef assign_ebi_data_MAIN

void test_assign_ebi_data(int include_optional) {
	assign_ebi_data_t *assign_ebi_data_1 = instantiate_assign_ebi_data(
		include_optional);

	cJSON *jsonassign_ebi_data_1 = assign_ebi_data_convertToJSON(
		assign_ebi_data_1);
	printf("assign_ebi_data :\n%s\n", cJSON_Print(jsonassign_ebi_data_1));
	assign_ebi_data_t *assign_ebi_data_2 = assign_ebi_data_parseFromJSON(
		jsonassign_ebi_data_1);
	cJSON *jsonassign_ebi_data_2 = assign_ebi_data_convertToJSON(
		assign_ebi_data_2);
	printf("repeating assign_ebi_data:\n%s\n",
	       cJSON_Print(jsonassign_ebi_data_2));
}

int main() {
	test_assign_ebi_data(1);
	test_assign_ebi_data(0);

	printf("Hello world \n");
	return 0;
}

#endif // assign_ebi_data_MAIN
#endif // assign_ebi_data_TEST
