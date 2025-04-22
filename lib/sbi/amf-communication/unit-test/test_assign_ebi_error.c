#ifndef assign_ebi_error_TEST
#define assign_ebi_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assign_ebi_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assign_ebi_error.h"
assign_ebi_error_t *instantiate_assign_ebi_error(int include_optional);

#include "test_problem_details.c"
#include "test_assign_ebi_failed.c"


assign_ebi_error_t *instantiate_assign_ebi_error(int include_optional) {
	assign_ebi_error_t *assign_ebi_error = NULL;
	if(include_optional) {
		assign_ebi_error = assign_ebi_error_create(
			// false, not to have infinite recursion
			instantiate_problem_details(0),
			// false, not to have infinite recursion
			instantiate_assign_ebi_failed(0)
			);
	} else {
		assign_ebi_error = assign_ebi_error_create(
			NULL,
			NULL
			);
	}

	return assign_ebi_error;
}


#ifdef assign_ebi_error_MAIN

void test_assign_ebi_error(int include_optional) {
	assign_ebi_error_t *assign_ebi_error_1 = instantiate_assign_ebi_error(
		include_optional);

	cJSON *jsonassign_ebi_error_1 = assign_ebi_error_convertToJSON(
		assign_ebi_error_1);
	printf("assign_ebi_error :\n%s\n", cJSON_Print(jsonassign_ebi_error_1));
	assign_ebi_error_t *assign_ebi_error_2 = assign_ebi_error_parseFromJSON(
		jsonassign_ebi_error_1);
	cJSON *jsonassign_ebi_error_2 = assign_ebi_error_convertToJSON(
		assign_ebi_error_2);
	printf("repeating assign_ebi_error:\n%s\n",
	       cJSON_Print(jsonassign_ebi_error_2));
}

int main() {
	test_assign_ebi_error(1);
	test_assign_ebi_error(0);

	printf("Hello world \n");
	return 0;
}

#endif // assign_ebi_error_MAIN
#endif // assign_ebi_error_TEST
