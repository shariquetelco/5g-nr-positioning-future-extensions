#ifndef invalid_param_TEST
#define invalid_param_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invalid_param_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invalid_param.h"
invalid_param_t *instantiate_invalid_param(int include_optional);



invalid_param_t *instantiate_invalid_param(int include_optional) {
	invalid_param_t *invalid_param = NULL;
	if(include_optional) {
		invalid_param = invalid_param_create(
			"0",
			"0"
			);
	} else {
		invalid_param = invalid_param_create(
			"0",
			"0"
			);
	}

	return invalid_param;
}


#ifdef invalid_param_MAIN

void test_invalid_param(int include_optional) {
	invalid_param_t *invalid_param_1 = instantiate_invalid_param(
		include_optional);

	cJSON *jsoninvalid_param_1 =
		invalid_param_convertToJSON(invalid_param_1);
	printf("invalid_param :\n%s\n", cJSON_Print(jsoninvalid_param_1));
	invalid_param_t *invalid_param_2 = invalid_param_parseFromJSON(
		jsoninvalid_param_1);
	cJSON *jsoninvalid_param_2 =
		invalid_param_convertToJSON(invalid_param_2);
	printf("repeating invalid_param:\n%s\n", cJSON_Print(
		       jsoninvalid_param_2));
}

int main() {
	test_invalid_param(1);
	test_invalid_param(0);

	printf("Hello world \n");
	return 0;
}

#endif // invalid_param_MAIN
#endif // invalid_param_TEST
