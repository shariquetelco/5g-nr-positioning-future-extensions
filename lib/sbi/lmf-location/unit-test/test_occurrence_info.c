#ifndef occurrence_info_TEST
#define occurrence_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define occurrence_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/occurrence_info.h"
occurrence_info_t *instantiate_occurrence_info(int include_optional);



occurrence_info_t *instantiate_occurrence_info(int include_optional) {
	occurrence_info_t *occurrence_info = NULL;
	if(include_optional) {
		occurrence_info = occurrence_info_create(
			);
	} else {
		occurrence_info = occurrence_info_create(
			);
	}

	return occurrence_info;
}


#ifdef occurrence_info_MAIN

void test_occurrence_info(int include_optional) {
	occurrence_info_t *occurrence_info_1 = instantiate_occurrence_info(
		include_optional);

	cJSON *jsonoccurrence_info_1 = occurrence_info_convertToJSON(
		occurrence_info_1);
	printf("occurrence_info :\n%s\n", cJSON_Print(jsonoccurrence_info_1));
	occurrence_info_t *occurrence_info_2 = occurrence_info_parseFromJSON(
		jsonoccurrence_info_1);
	cJSON *jsonoccurrence_info_2 = occurrence_info_convertToJSON(
		occurrence_info_2);
	printf("repeating occurrence_info:\n%s\n",
	       cJSON_Print(jsonoccurrence_info_2));
}

int main() {
	test_occurrence_info(1);
	test_occurrence_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // occurrence_info_MAIN
#endif // occurrence_info_TEST
