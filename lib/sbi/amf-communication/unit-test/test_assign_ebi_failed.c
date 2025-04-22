#ifndef assign_ebi_failed_TEST
#define assign_ebi_failed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assign_ebi_failed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assign_ebi_failed.h"
assign_ebi_failed_t *instantiate_assign_ebi_failed(int include_optional);



assign_ebi_failed_t *instantiate_assign_ebi_failed(int include_optional) {
	assign_ebi_failed_t *assign_ebi_failed = NULL;
	if(include_optional) {
		assign_ebi_failed = assign_ebi_failed_create(
			0,
			list_createList()
			);
	} else {
		assign_ebi_failed = assign_ebi_failed_create(
			0,
			list_createList()
			);
	}

	return assign_ebi_failed;
}


#ifdef assign_ebi_failed_MAIN

void test_assign_ebi_failed(int include_optional) {
	assign_ebi_failed_t *assign_ebi_failed_1 =
		instantiate_assign_ebi_failed(include_optional);

	cJSON *jsonassign_ebi_failed_1 = assign_ebi_failed_convertToJSON(
		assign_ebi_failed_1);
	printf("assign_ebi_failed :\n%s\n",
	       cJSON_Print(jsonassign_ebi_failed_1));
	assign_ebi_failed_t *assign_ebi_failed_2 =
		assign_ebi_failed_parseFromJSON(jsonassign_ebi_failed_1);
	cJSON *jsonassign_ebi_failed_2 = assign_ebi_failed_convertToJSON(
		assign_ebi_failed_2);
	printf("repeating assign_ebi_failed:\n%s\n",
	       cJSON_Print(jsonassign_ebi_failed_2));
}

int main() {
	test_assign_ebi_failed(1);
	test_assign_ebi_failed(0);

	printf("Hello world \n");
	return 0;
}

#endif // assign_ebi_failed_MAIN
#endif // assign_ebi_failed_TEST
