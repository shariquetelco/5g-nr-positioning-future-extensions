#ifndef loc_info_granularity_any_of_TEST
#define loc_info_granularity_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_info_granularity_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_info_granularity_any_of.h"
loc_info_granularity_any_of_t *instantiate_loc_info_granularity_any_of(
	int include_optional);



loc_info_granularity_any_of_t *instantiate_loc_info_granularity_any_of(
	int include_optional) {
	loc_info_granularity_any_of_t *loc_info_granularity_any_of = NULL;
	if(include_optional) {
		loc_info_granularity_any_of =
			loc_info_granularity_any_of_create(
				);
	} else {
		loc_info_granularity_any_of =
			loc_info_granularity_any_of_create(
				);
	}

	return loc_info_granularity_any_of;
}


#ifdef loc_info_granularity_any_of_MAIN

void test_loc_info_granularity_any_of(int include_optional) {
	loc_info_granularity_any_of_t *loc_info_granularity_any_of_1 =
		instantiate_loc_info_granularity_any_of(include_optional);

	cJSON *jsonloc_info_granularity_any_of_1 =
		loc_info_granularity_any_of_convertToJSON(
			loc_info_granularity_any_of_1);
	printf("loc_info_granularity_any_of :\n%s\n",
	       cJSON_Print(jsonloc_info_granularity_any_of_1));
	loc_info_granularity_any_of_t *loc_info_granularity_any_of_2 =
		loc_info_granularity_any_of_parseFromJSON(
			jsonloc_info_granularity_any_of_1);
	cJSON *jsonloc_info_granularity_any_of_2 =
		loc_info_granularity_any_of_convertToJSON(
			loc_info_granularity_any_of_2);
	printf("repeating loc_info_granularity_any_of:\n%s\n",
	       cJSON_Print(jsonloc_info_granularity_any_of_2));
}

int main() {
	test_loc_info_granularity_any_of(1);
	test_loc_info_granularity_any_of(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_info_granularity_any_of_MAIN
#endif // loc_info_granularity_any_of_TEST
