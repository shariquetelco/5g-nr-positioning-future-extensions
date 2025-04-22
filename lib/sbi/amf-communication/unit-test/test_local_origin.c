#ifndef local_origin_TEST
#define local_origin_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define local_origin_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/local_origin.h"
local_origin_t *instantiate_local_origin(int include_optional);

#include "test_geographical_coordinates.c"


local_origin_t *instantiate_local_origin(int include_optional) {
	local_origin_t *local_origin = NULL;
	if(include_optional) {
		local_origin = local_origin_create(
			"0",
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0)
			);
	} else {
		local_origin = local_origin_create(
			"0",
			NULL
			);
	}

	return local_origin;
}


#ifdef local_origin_MAIN

void test_local_origin(int include_optional) {
	local_origin_t *local_origin_1 = instantiate_local_origin(
		include_optional);

	cJSON *jsonlocal_origin_1 = local_origin_convertToJSON(local_origin_1);
	printf("local_origin :\n%s\n", cJSON_Print(jsonlocal_origin_1));
	local_origin_t *local_origin_2 = local_origin_parseFromJSON(
		jsonlocal_origin_1);
	cJSON *jsonlocal_origin_2 = local_origin_convertToJSON(local_origin_2);
	printf("repeating local_origin:\n%s\n",
	       cJSON_Print(jsonlocal_origin_2));
}

int main() {
	test_local_origin(1);
	test_local_origin(0);

	printf("Hello world \n");
	return 0;
}

#endif // local_origin_MAIN
#endif // local_origin_TEST
