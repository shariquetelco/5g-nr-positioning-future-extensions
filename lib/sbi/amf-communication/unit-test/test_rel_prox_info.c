#ifndef rel_prox_info_TEST
#define rel_prox_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rel_prox_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rel_prox_info.h"
rel_prox_info_t *instantiate_rel_prox_info(int include_optional);

#include "test_time_to_collision_info.c"


rel_prox_info_t *instantiate_rel_prox_info(int include_optional) {
	rel_prox_info_t *rel_prox_info = NULL;
	if(include_optional) {
		rel_prox_info = rel_prox_info_create(
			"2013-10-20T19:20:30+01:00",
			56,
			list_createList(),
			list_createList(),
			list_createList(),
			// false, not to have infinite recursion
			instantiate_time_to_collision_info(0)
			);
	} else {
		rel_prox_info = rel_prox_info_create(
			"2013-10-20T19:20:30+01:00",
			56,
			list_createList(),
			list_createList(),
			list_createList(),
			NULL
			);
	}

	return rel_prox_info;
}


#ifdef rel_prox_info_MAIN

void test_rel_prox_info(int include_optional) {
	rel_prox_info_t *rel_prox_info_1 = instantiate_rel_prox_info(
		include_optional);

	cJSON *jsonrel_prox_info_1 =
		rel_prox_info_convertToJSON(rel_prox_info_1);
	printf("rel_prox_info :\n%s\n", cJSON_Print(jsonrel_prox_info_1));
	rel_prox_info_t *rel_prox_info_2 = rel_prox_info_parseFromJSON(
		jsonrel_prox_info_1);
	cJSON *jsonrel_prox_info_2 =
		rel_prox_info_convertToJSON(rel_prox_info_2);
	printf("repeating rel_prox_info:\n%s\n", cJSON_Print(
		       jsonrel_prox_info_2));
}

int main() {
	test_rel_prox_info(1);
	test_rel_prox_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // rel_prox_info_MAIN
#endif // rel_prox_info_TEST
