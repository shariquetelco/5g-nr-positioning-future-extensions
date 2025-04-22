#ifndef loc_update_subs_TEST
#define loc_update_subs_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_update_subs_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_update_subs.h"
loc_update_subs_t *instantiate_loc_update_subs(int include_optional);



loc_update_subs_t *instantiate_loc_update_subs(int include_optional) {
	loc_update_subs_t *loc_update_subs = NULL;
	if(include_optional) {
		loc_update_subs = loc_update_subs_create(
			"0",
			"0",
			"a",
			"a"
			);
	} else {
		loc_update_subs = loc_update_subs_create(
			"0",
			"0",
			"a",
			"a"
			);
	}

	return loc_update_subs;
}


#ifdef loc_update_subs_MAIN

void test_loc_update_subs(int include_optional) {
	loc_update_subs_t *loc_update_subs_1 = instantiate_loc_update_subs(
		include_optional);

	cJSON *jsonloc_update_subs_1 = loc_update_subs_convertToJSON(
		loc_update_subs_1);
	printf("loc_update_subs :\n%s\n", cJSON_Print(jsonloc_update_subs_1));
	loc_update_subs_t *loc_update_subs_2 = loc_update_subs_parseFromJSON(
		jsonloc_update_subs_1);
	cJSON *jsonloc_update_subs_2 = loc_update_subs_convertToJSON(
		loc_update_subs_2);
	printf("repeating loc_update_subs:\n%s\n",
	       cJSON_Print(jsonloc_update_subs_2));
}

int main() {
	test_loc_update_subs(1);
	test_loc_update_subs(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_update_subs_MAIN
#endif // loc_update_subs_TEST
