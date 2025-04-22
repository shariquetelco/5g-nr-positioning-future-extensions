#ifndef ue_in_area_filter_TEST
#define ue_in_area_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ue_in_area_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ue_in_area_filter.h"
ue_in_area_filter_t *instantiate_ue_in_area_filter(int include_optional);

#include "test_ue_type.c"


ue_in_area_filter_t *instantiate_ue_in_area_filter(int include_optional) {
	ue_in_area_filter_t *ue_in_area_filter = NULL;
	if(include_optional) {
		ue_in_area_filter = ue_in_area_filter_create(
			null,
			1,
			1
			);
	} else {
		ue_in_area_filter = ue_in_area_filter_create(
			null,
			1,
			1
			);
	}

	return ue_in_area_filter;
}


#ifdef ue_in_area_filter_MAIN

void test_ue_in_area_filter(int include_optional) {
	ue_in_area_filter_t *ue_in_area_filter_1 =
		instantiate_ue_in_area_filter(include_optional);

	cJSON *jsonue_in_area_filter_1 = ue_in_area_filter_convertToJSON(
		ue_in_area_filter_1);
	printf("ue_in_area_filter :\n%s\n",
	       cJSON_Print(jsonue_in_area_filter_1));
	ue_in_area_filter_t *ue_in_area_filter_2 =
		ue_in_area_filter_parseFromJSON(jsonue_in_area_filter_1);
	cJSON *jsonue_in_area_filter_2 = ue_in_area_filter_convertToJSON(
		ue_in_area_filter_2);
	printf("repeating ue_in_area_filter:\n%s\n",
	       cJSON_Print(jsonue_in_area_filter_2));
}

int main() {
	test_ue_in_area_filter(1);
	test_ue_in_area_filter(0);

	printf("Hello world \n");
	return 0;
}

#endif // ue_in_area_filter_MAIN
#endif // ue_in_area_filter_TEST
