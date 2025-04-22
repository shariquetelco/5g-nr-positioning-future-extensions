#ifndef loc_accuracy_info_TEST
#define loc_accuracy_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define loc_accuracy_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/loc_accuracy_info.h"
loc_accuracy_info_t *instantiate_loc_accuracy_info(int include_optional);



loc_accuracy_info_t *instantiate_loc_accuracy_info(int include_optional) {
	loc_accuracy_info_t *loc_accuracy_info = NULL;
	if(include_optional) {
		loc_accuracy_info = loc_accuracy_info_create(
			list_createList(),
			0,
			1,
			0
			);
	} else {
		loc_accuracy_info = loc_accuracy_info_create(
			list_createList(),
			0,
			1,
			0
			);
	}

	return loc_accuracy_info;
}


#ifdef loc_accuracy_info_MAIN

void test_loc_accuracy_info(int include_optional) {
	loc_accuracy_info_t *loc_accuracy_info_1 =
		instantiate_loc_accuracy_info(include_optional);

	cJSON *jsonloc_accuracy_info_1 = loc_accuracy_info_convertToJSON(
		loc_accuracy_info_1);
	printf("loc_accuracy_info :\n%s\n",
	       cJSON_Print(jsonloc_accuracy_info_1));
	loc_accuracy_info_t *loc_accuracy_info_2 =
		loc_accuracy_info_parseFromJSON(jsonloc_accuracy_info_1);
	cJSON *jsonloc_accuracy_info_2 = loc_accuracy_info_convertToJSON(
		loc_accuracy_info_2);
	printf("repeating loc_accuracy_info:\n%s\n",
	       cJSON_Print(jsonloc_accuracy_info_2));
}

int main() {
	test_loc_accuracy_info(1);
	test_loc_accuracy_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // loc_accuracy_info_MAIN
#endif // loc_accuracy_info_TEST
