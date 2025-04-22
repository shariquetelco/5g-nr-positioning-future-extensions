#ifndef mov_behav_info_TEST
#define mov_behav_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mov_behav_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mov_behav_info.h"
mov_behav_info_t *instantiate_mov_behav_info(int include_optional);

#include "test_geographical_coordinates.c"


mov_behav_info_t *instantiate_mov_behav_info(int include_optional) {
	mov_behav_info_t *mov_behav_info = NULL;
	if(include_optional) {
		mov_behav_info = mov_behav_info_create(
			// false, not to have infinite recursion
			instantiate_geographical_coordinates(0),
			list_createList(),
			0
			);
	} else {
		mov_behav_info = mov_behav_info_create(
			NULL,
			list_createList(),
			0
			);
	}

	return mov_behav_info;
}


#ifdef mov_behav_info_MAIN

void test_mov_behav_info(int include_optional) {
	mov_behav_info_t *mov_behav_info_1 = instantiate_mov_behav_info(
		include_optional);

	cJSON *jsonmov_behav_info_1 = mov_behav_info_convertToJSON(
		mov_behav_info_1);
	printf("mov_behav_info :\n%s\n", cJSON_Print(jsonmov_behav_info_1));
	mov_behav_info_t *mov_behav_info_2 = mov_behav_info_parseFromJSON(
		jsonmov_behav_info_1);
	cJSON *jsonmov_behav_info_2 = mov_behav_info_convertToJSON(
		mov_behav_info_2);
	printf("repeating mov_behav_info:\n%s\n",
	       cJSON_Print(jsonmov_behav_info_2));
}

int main() {
	test_mov_behav_info(1);
	test_mov_behav_info(0);

	printf("Hello world \n");
	return 0;
}

#endif // mov_behav_info_MAIN
#endif // mov_behav_info_TEST
