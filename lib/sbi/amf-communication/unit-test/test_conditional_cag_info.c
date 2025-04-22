#ifndef conditional_cag_info_TEST
#define conditional_cag_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define conditional_cag_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/conditional_cag_info.h"
conditional_cag_info_t *instantiate_conditional_cag_info(int include_optional);

#include "test_valid_time_period.c"


conditional_cag_info_t *instantiate_conditional_cag_info(int include_optional) {
	conditional_cag_info_t *conditional_cag_info = NULL;
	if(include_optional) {
		conditional_cag_info = conditional_cag_info_create(
			list_createList(),
			1,
			// false, not to have infinite recursion
			instantiate_valid_time_period(0)
			);
	} else {
		conditional_cag_info = conditional_cag_info_create(
			list_createList(),
			1,
			NULL
			);
	}

	return conditional_cag_info;
}


#ifdef conditional_cag_info_MAIN

void test_conditional_cag_info(int include_optional) {
	conditional_cag_info_t *conditional_cag_info_1 =
		instantiate_conditional_cag_info(include_optional);

	cJSON *jsonconditional_cag_info_1 = conditional_cag_info_convertToJSON(
		conditional_cag_info_1);
	printf("conditional_cag_info :\n%s\n",
	       cJSON_Print(jsonconditional_cag_info_1));
	conditional_cag_info_t *conditional_cag_info_2 =
		conditional_cag_info_parseFromJSON(jsonconditional_cag_info_1);
	cJSON *jsonconditional_cag_info_2 = conditional_cag_info_convertToJSON(
		conditional_cag_info_2);
	printf("repeating conditional_cag_info:\n%s\n",
	       cJSON_Print(jsonconditional_cag_info_2));
}

int main() {
	test_conditional_cag_info(1);
	test_conditional_cag_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // conditional_cag_info_MAIN
#endif // conditional_cag_info_TEST
