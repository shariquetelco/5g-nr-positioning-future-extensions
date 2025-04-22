#ifndef loc_accuracy_req_TEST
#define loc_accuracy_req_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_accuracy_req_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_accuracy_req.h"
loc_accuracy_req_t *instantiate_loc_accuracy_req(int include_optional);

#include "test_matching_direction.c"
#include "test_matching_direction.c"
#include "test_positioning_method.c"


loc_accuracy_req_t *instantiate_loc_accuracy_req(int include_optional) {
	loc_accuracy_req_t *loc_accuracy_req = NULL;
	if(include_optional) {
		loc_accuracy_req = loc_accuracy_req_create(
			0,
			null,
			0,
			null,
			null
			);
	} else {
		loc_accuracy_req = loc_accuracy_req_create(
			0,
			null,
			0,
			null,
			null
			);
	}

	return loc_accuracy_req;
}


#ifdef loc_accuracy_req_MAIN

void test_loc_accuracy_req(int include_optional) {
	loc_accuracy_req_t *loc_accuracy_req_1 = instantiate_loc_accuracy_req(
		include_optional);

	cJSON *jsonloc_accuracy_req_1 = loc_accuracy_req_convertToJSON(
		loc_accuracy_req_1);
	printf("loc_accuracy_req :\n%s\n", cJSON_Print(jsonloc_accuracy_req_1));
	loc_accuracy_req_t *loc_accuracy_req_2 = loc_accuracy_req_parseFromJSON(
		jsonloc_accuracy_req_1);
	cJSON *jsonloc_accuracy_req_2 = loc_accuracy_req_convertToJSON(
		loc_accuracy_req_2);
	printf("repeating loc_accuracy_req:\n%s\n",
	       cJSON_Print(jsonloc_accuracy_req_2));
}

int main() {
	test_loc_accuracy_req(1);
	test_loc_accuracy_req(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_accuracy_req_MAIN
#endif // loc_accuracy_req_TEST
