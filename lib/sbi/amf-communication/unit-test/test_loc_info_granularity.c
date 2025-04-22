#ifndef loc_info_granularity_TEST
#define loc_info_granularity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_info_granularity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_info_granularity.h"
loc_info_granularity_t *instantiate_loc_info_granularity(int include_optional);



loc_info_granularity_t *instantiate_loc_info_granularity(int include_optional) {
	loc_info_granularity_t *loc_info_granularity = NULL;
	if(include_optional) {
		loc_info_granularity = loc_info_granularity_create(
			);
	} else {
		loc_info_granularity = loc_info_granularity_create(
			);
	}

	return loc_info_granularity;
}


#ifdef loc_info_granularity_MAIN

void test_loc_info_granularity(int include_optional) {
	loc_info_granularity_t *loc_info_granularity_1 =
		instantiate_loc_info_granularity(include_optional);

	cJSON *jsonloc_info_granularity_1 = loc_info_granularity_convertToJSON(
		loc_info_granularity_1);
	printf("loc_info_granularity :\n%s\n",
	       cJSON_Print(jsonloc_info_granularity_1));
	loc_info_granularity_t *loc_info_granularity_2 =
		loc_info_granularity_parseFromJSON(jsonloc_info_granularity_1);
	cJSON *jsonloc_info_granularity_2 = loc_info_granularity_convertToJSON(
		loc_info_granularity_2);
	printf("repeating loc_info_granularity:\n%s\n",
	       cJSON_Print(jsonloc_info_granularity_2));
}

int main() {
	test_loc_info_granularity(1);
	test_loc_info_granularity(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_info_granularity_MAIN
#endif // loc_info_granularity_TEST
